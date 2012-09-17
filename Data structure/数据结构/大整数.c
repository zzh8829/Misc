#include<stdio.h>
#include<malloc.h>
#define HUN 10000
typedef struct node
{
int data;
struct node *next;
}NODE;   //定义链表结构

NODE *insert(u,num)//在u节点之后插入一个新的NODE，其值为NUM
NODE *u;
int num;
{
	NODE *v;
	v=(NODE*)malloc(sizeof(NODE));//分配内存
	v->data=num;      //赋值
	u->next=v;        //在u后面加入一个NODE
	return(v);
}

NODE *addint(p,q)   //完成加法操作返回指向*p+*q结果的指针
NODE *p,*q;
{
	NODE *pp,*qq,*r,*s,*t;
	int total,number,carry;
	pp=p->next;qq=q->next;
	s=(NODE*)malloc(sizeof(NODE));//建立存放和的链表表头
	s->data=-1;
	t=s;
	carry=0;                 //进位变量
	while(pp->data!=-1&&qq->data!=-1)//都不是表头
	{
		total=pp->data+qq->data+carry;//对应位和上次进位数求和
		number=total%HUN;      //记录可以存入链表的数
		carry=total/HUN;       //多出的为进位数
		t=insert(t,number);    //把可存入的数插入链表
		pp=pp->next;      //取后面的数
		qq=qq->next;      //
	}
	r=(pp->data!=-1)?pp:qq;//两数大小不一取尚未处理的指针
	while(r->data!=-1)     //判断另一个是否到头
	{
		total=r->data+carry;//与进位数相加
		number=total%HUN;   //记录可存入的数
		carry=total/HUN;    //记录进位数
		t=insert(t,number); //插入链表
		r=r->next;
	}
	if(carry)     //如果还有进位数
		t=insert(t,1);//最后一次处理
	t->next=s;   //完成链表
	return(s);   //返回求和指针
}

NODE *inputint(void) //输入超大正整数
{
	NODE *s,*ps,*qs;
	struct number    //定义临时中间结构
	{
		int num;
		struct number *np;
	}*p,*q;

	int i,j,k;
	long sum;
	char c;
	p=NULL;     //链首为个位，链尾为高位
	while((c=getchar())!='\n')  //按字符接受数字
		if(c>='0'&&c<='9')      //若为数字就存入
		{
			q=(struct number *)malloc(sizeof(struct number));
			q->num=c-'0';       //存入一位整数
			q->np=p;
			p=q;
		}
	s=(NODE*)malloc(sizeof(NODE));//建立正式链表的表头
	s->data=-1;                 //表头
	ps=s;
	while(p!=NULL)      //临时链表不为空是
	{
		sum=0;i=0;k=1;
			while(i<4&&p!=NULL) //按四位合并临时链表
			{
				sum=sum+k*(p->num);
				i++;p=p->np;k=k*10;
			}
			qs=(NODE*)malloc(sizeof(NODE));//正式链表的主体
			qs->data=sum;
			ps->next=qs;
			ps=qs;
	}
	ps->next=s;    //完成链表

	return(s);
}

printint(s)
NODE *s;
{
	if(s->next->data!=-1)
	{
		printint(s->next);
		if(s->next->next->data==-1)
			printf("%d",s->next->data);
		else{
			int i,k=HUN;
			for(i=1;i<=4;i++,k/=10)
				putchar('0'+s->next->data%(k)/(k/10));
		}
	}
}

main()
{
	NODE *s1,*s2,*s;
	NODE *inputint(),*addint(),*insert_after();
	s1=inputint();
	s2=inputint();
	printf("S1=");
	printint(s1);
	printf("\n");
	printf("S2=");
	printint(s2);
	printf("\n");
	s=addint(s1,s2);
	printf("S1+S2=");printint(s);printf("\n");
}