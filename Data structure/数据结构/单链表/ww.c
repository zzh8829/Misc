/*我不知道我这样做合适不合适，好象自己在帮助别人干坏事
我不可能给你说得很细，学习到的东西是自己的，难道对自己
也可以作弊吗？好好努力吧*/

#include<stdio.h>
#include <stdlib.h>
#include<malloc.h>

struct f                             //数据结构
{
	double data;
	struct f *next;
};

main() 
{ 
	int n;
	scanf("%d",&n);
	fun(n);
} 

fun(n)
{
	double y=0.00,x=1.00;           //这里用双精度实数定义可以容纳更大的数据
	struct f *head,*cthis,*a;
	int number,i,j=0;
	do{	
		a=(struct f*)malloc(sizeof(struct f));
		if(head==NULL)
			head=a;
		else
		{
			cthis=head;
			cthis=cthis->next;
		}
		cthis=a;
		cthis->data=j;        //这里定义存处在各个链表里的数据
		                      //你可以用(int)rand()随机数来代替j
		number=cthis->data;
		for(i=0;i<j;i++)
			x=x*n;
		y+=number*x;       
		j++;
	}while(j<n);
	printf("%.0lf",y);
}