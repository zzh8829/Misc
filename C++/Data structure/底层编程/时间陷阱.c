/********
使用过basic语言的朋友都知道,basic中有一种重要的功能,就是时间陷阱.它能是主程序的运行和对事件的处理异步进行.通过设置时间陷阱.可以在规定的时间间隔到达后自动执行某个子程序.子程序运行结束后又回到主程序的断点处继续执行.basic语言提供了有关时间陷阱的语句.可以直接调拥獵语言没有这样的功能,为了能实现上述功能,这里给出了几个子函数以帮助实现.

    on_timer(t,p):    设定定时时间间隔为t(以秒为单位).并规定了事件处理子函数的入口点.t是整
                      型数,p是指向子函数的指针.
    timer_on():      启动定时器开始计时.以后每个t秒,指针p所指向的子函数运行一次.
    timer_off():    关闭定时器.

下面是子函数清单.
***************/
/*timer 模块源程序清单*/

#include<dos.h>

#define Sizeprogram 375
void interrupt (*oldtimer)();
void interrupt newtimer();
static struct SREGS seg;
unsigned intsp,intss;
unsigned myss,stack;
unsigned vseg;
int running=0;
int m1,m2,m3=0;
int (*sub_ptr)();
void on_timer();
void timer_on();
void timer_off();

void on_timer(t,pp)
int t;
int (*pp)();
{
    sub_ptr=pp;
    m1=t;
    segread(&seg);
    stack=(Sizeprogram-(seg.ds-seg.cs))*16-300;
    myss=_SS;
    oldtimer=getvect(0x1c);
}

void timer_on()
{
    m2=0;
    m3=1;
    setvect(0x1c,newtimer);
}
void timer_off()
{
    m3=0;
    setvect(0x1c,oldtimer);
}
void interrupt newtimer()
{
    (*oldtimer)();
    if(running==0)
        running=1;
        disable();
        intsp=_SP;
        intss=_SS;
        _SP=stack;
        _SS=myss;
        enable();
        if(m3==1){
            if(m2==m1*18){
            m2=0;
	    (*sb_ptr)();
            }
            m2+=1;
        }
        disable();
        _SP=intsp;
        _SS=intss;
        enable();
        running=0;
    }
}