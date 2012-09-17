有一段时间直接读取汉字库，以期不用汉字系统也能显示汉字，是很流行的技术，现在也就在工控行业用得上了。这是硬件发展、大肆浪费内存的结果。暂且不论，让我们看看汉字库。
16X16点阵的字库按照内码顺序排列，每个字用32字节（256BIT）存放点阵信息。格式如下：

                 第一字节第二字节
                 第三字节第四字节
                 第五字节第六字节
                 第七字节第八字节



你看程序吧，很清楚的。
但是，又不是每个字库都一样。可能是因为有些字库把英文字模也放在一起吧。我所用的是UCDOS的字库


#include < io.h>
#include < fcntl.h>
#include < stdio.h>
#include < dos.h>
#define CCLIB "c:\hzk16"

display(unsignedchar *hzmp, int x, int y, int color, int bkcolor)
 { charfar *p; 
 int i, j, k;
 p= (char far *)(0xa0000000+80*y+x/8); 
 for (i= 0; i < 16; i++) 
	for(j = 0; j < 2; j++)
	 { outport(0x3ce, 0x0205);	// kernel here
		k=*(p+80*i+j);
		outportb(0x3ce, 0x08); 
		outportb(0x3cf, hzmp[2*i+j]); 
		*(p+80*i+j)=color; 
		k=*(p+80*i+j);
		outportb(0x3ce, 0x08); 
		outportb(0x3cf, ~hzmp[2*i+j]); 
		*(p+80*i+j)=bkcolor;
		} 
outport(0x3ce, 0x005);	//reset
outport(0x3ce, 0xff08); 
} 

main()
{
 union REGS r;
 int handle, mode;
 int i;
 int qh, wh, col, row;
 long offset;
 unsigned char *hz, hzm[32];
 handle=open(CCLIB, O_RDONLY|O_BINARY);
 r.h.ah=0x0f;int86(0x10, &r, &r);
 mode=r.h.al;
 r.x.ax= 0x0012; 
 int86(0x10, &r, &r);
 for(i=0; i < 20; i++){
	 col=0;row=20*i; 
	 hz="希望电脑公司：为了检验此程序的执行速度特意如此但是没有标点符号这里是写字软件"; 
	 
	while(*hz){ /*find theqh, wh*/
		 qh = *hz-0xa0;
		 wh = *(hz+1)-0xa0;
		 offset = (94l*(qh-1)+(wh-1))*32l;
		 lseek(handle, offset, SEEK_SET); 
		 read(handle, hzm, 32);/*display*/
		 display(hzm, col, row, 4, 3);
		 col += 16;
		 hz += 2; 
	 } 
 } 
 r.h.ah=0x00;
 r.h.al= mode;
 int86(0x10, &r, &r);
 } 


