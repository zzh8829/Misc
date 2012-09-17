/*谁有兴趣一起来丰富这个程序的的功能？？*/
#include<stdio.h>
#include<stdlib.h>
#define MAX 20
#define ELEMTP int

#define v (*p)

struct node
{
	ELEMTP data;
	struct node *next;
};

struct node *p,*q,*s,*head;
int j=0,i,k;
main()
{
	int x,y,cord;
	void outlin(struct node *h);
	void create();
	void insert(struct node *h,int x,int y);
	void deletes(struct node *h,int x);
	struct node *MaxCompare(struct node *h);
	struct node *MinCompare(struct node *h);
	int delIterance(struct node *h);
	void batchInsert(struct node *h,int x);
	void batchDelete(struct node *h,int x,int y);
	void Cz(struct node*  h);
	void Xg(struct node * h);
	printf("建立链表，输入-999完成链表: \n");
	create();
	i=j;
	outlin(head);
	do{
		printf("\n        主菜单        \n");
		printf("     1   插入一个元素   \n");
		printf("     2   删除一个元素   \n");
		printf("     3   升序排序       \n");
		printf("     4   降序排序       \n");
		printf("     5   查找元素       \n");
		printf("     6   修改元素       \n");
		printf("     7   删除重复元素   \n");
		printf("     8   批量加入元素   \n");
		printf("     9   批量删除元素   \n");
		printf("     0   结束程序运行   \n");
		printf("-----------------------------------------\n");
		printf(" 请输入您的选择(1, 2, 3, 4, 5, 6, 7, 8, 9, 0) ");
		scanf("%d",&cord);
		switch(cord)
		{
			case 1:
			{
				printf("请输入插入的位置 i: ");
				scanf("%d",&x);
				printf("请输入插入的数据 y: ");
				scanf("%d",&y);
				insert(head,x,y);
				i=j;
				outlin(head);
			}break;
			case 2:
			{
				printf("x=?");
				scanf("%d",&x);
				deletes(head,x);
				i=j;
				outlin(head);
			}break;
			case 3:
			{
				printf("链表由大到小是");
				s=MaxCompare(head);
				j=i;
				outlin(s);
				//outlin(head);
			}break;
			case 4:
			{
				printf("链表由大到小是");
				s=MinCompare(head);
				j=i;
				outlin(s);
			}break;
			case 5:
			{
				Cz(head);
				outlin(head);
			}break;
			case 6:
			{
				Xg(head);
				outlin(head);
			}break;
			case 7:
			{
				k=delIterance(head);
				i=i-k;
				j=i;
				outlin(head);
			}break;
			case 8:
			{
				printf("请输入插入的位置 i: ");
				scanf("%d",&x);
				batchInsert(head,x);
				i=j;
				outlin(head);
			}break;
			case 9:
			{
				printf("请输入删除的起始位置 i: ");
				scanf("%d",&x);
				printf("请输入删除的结束位置 y: ");
				scanf("%d",&y);
				batchDelete(head,x,y);
				i=j;
				outlin(head);
			}break;
			case 0:
			{
				exit(0);
			}break;
		}
	}while(cord<=9&&cord>=0);
}

void outlin(struct node *h)
{
	p=h->next;
	while(p!=NULL)
	{
		printf(" data=%4d ",p->data);
		p=p->next;
	}
	printf("\n输出结束\n\n");
}

void deletes(struct node *h,int x)//删除节点
{
	p=h;
	while(p->next!=NULL&&p->next->data!=x)		p=p->next;
	if(p->next==NULL)
		printf("x 不存在 !");
	else
	{
		q=p->next;
		p->next=q->next;
		free(q);
		--j;
	}

}

void insert(struct node *h,int x,int y)
{
	s=(struct node*)malloc(sizeof(struct node));
	s->data=y;
	q=h;p=h->next;
	while(p!=NULL&&p->data!=x)
	{
		q=p;
		p=p->next;
	}
	q->next=s;
	s->next=p;
	++j;
}

void create()//建立链表
{
	int x;
	head=(struct node*)malloc(sizeof(struct node));
	head->next=NULL;
	p=head;
	printf("x=?");
	scanf("%d",&x);
	while(x!=-999)
	{
		s=(struct node*)malloc(sizeof(struct node));
		s->data=x;
		s->next=NULL;
		p->next=s;
		p=s;
		printf("x=?");++j;
		scanf("%d",&x);
	}
}

/////////////以下函数由七绝玩家编写/////////////

struct node *MaxCompare(struct node *h)//由大到小排序
{        
	struct node *t;
	int x;
	t=h;s=NULL;
	while(j!=0)
	{
	x=t->next->data;
	q=t->next;
	while(q!=NULL)
	{
		if(q->data<=x)
			x=q->data;
		else
			x=x;
		q=q->next;	
	}
	p=t;
	while(p->next!=NULL&&p->next->data!=x)
		p=p->next;
	q=p->next;
	p->next=q->next;
	t=p;t=h;
	p=q;p->next=s;
	s=p;
	j--;
	}
	t->next=s;
	head=t;
	return (t);
}

struct node *MinCompare(struct node *h)//由小到大排序
{
	struct node *t;
	int x;
	t=h;s=NULL;
	while(j!=0)
	{
	x=t->next->data;
	q=t->next;
	while(q!=NULL)
	{
		if(q->data>=x)
			x=q->data;
		else
			x=x;
		q=q->next;	
	}
	p=t;
	while(p->next!=NULL&&p->next->data!=x)
		p=p->next;
	q=p->next;
	p->next=q->next;
	t=p;t=h;
	p=q;p->next=s;
	s=p;
	j--;
	}
	t->next=s;
	head=t;
	return (t);
}

int delIterance(struct node *h)//删除重复元素
{
	int x,y=0;
	--j;
	s=h->next;
	while(j>0)
	{	
		x=s->data;
		p=s;
		while(p->next!=NULL)
		{
			if(p->next==NULL)
			{
				x=x;
			}
			else if(p->next->data==x)
			{
				q=p->next;
				p->next=q->next;
				free(q);
				--j;
				++y;
			}
			else
			{
				p=p->next;
			}
		}
		s=s->next;
		--j;
	}
	return y;
}

void batchInsert(struct node *h,int x)//批量加入
{
	int y=0;
	q=h;p=h->next;
	while(p!=NULL&&p->data!=x)
	{
		q=p;
		p=p->next;
	}
	printf("y=?");
	scanf("%d",&y);
	while(y!=-999)
	{
	s=(struct node*)malloc(sizeof(struct node));
	s->data=y;
	q->next=s;
	s->next=p;
	q=s;
	printf("y=?");
	scanf("%d",&y);
	++j;
	}
}

void batchDelete(struct node *h,int x,int y)//批量删除
{
	int k=0,w=0;
	struct node *t;
	p=h;q=h;
	while(p->next!=NULL&&p->next->data!=x)
	{
		++k;
		p=p->next;
	}
	while(q->next!=NULL&&q->next->data!=y)
	{
		++w;
		q=q->next;
	}
	if(p->next==NULL||q->next==NULL)
		printf("输入的位置不正确，请重新开始！");
	else if(k<w)
	{
		s=q->next;
		while(p->next!=s)
		{
			t=p->next;
			p->next=t->next;
			free(t);
			--j;
		}

	}
	else if(w=k)
	{
		printf("没有删除元素");
	}
	else
	{
		s=p->next;
		while(q->next!=s)
		{
			t=q->next;
			q->next=t->next;
			free(t);
			--j;
		}
	}
}

//////////////七绝玩家编写结束//////////////

//////////////以下函数由lihk编写////////////
void Cz(struct node*  h)            //查找// 
{
	struct node * num;int i; 
	num=head ; 
	printf("输入您要查找的号码:"); 
	scanf("%d",&i); 
	while(i!=num->data && num->next!=NULL) 
	{   
		num=num->next; 
	} 
	if (i==num->data) 
 		printf("号码:%d",num->data); 
	else 
 		printf("该号码不在链表里."); 
} 

void Xg(struct node * h) //修改// 
{ 
	struct node * num; int i; 
	num=head; 
	printf("查找您要修改的号码:"); 
	scanf("%d",&i); 
	while(i!=num->data&&num->next!=NULL){ 
		num=num->next;} 
	if (i==num->data)
	{ 
   		printf(":%d\n",num->data); 
   		printf("输入您要修改的新信息:"); 
		printf("号码:"); 
   		scanf("%d",&num->data); 
   		printf("\n修改成功!");
   	} 
	else 	
   		printf("该号码不在链表里!");  
} 

//////////////lihk编写结束/////////////////