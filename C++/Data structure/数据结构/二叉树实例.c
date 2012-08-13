#include<stdio.h>
#include<stdlib.h>
#define ELEMTP int

struct node
{
	ELEMTP data;
	struct node *lc,*rc;
};

struct node *root;
int m=0;

main()
{
	int cord;
	struct node* creat();
	void preorderz(struct node *t);
	void inorder(struct node *t);
	void postorder(struct node *t);
	void deletes(struct node *t,struct node *p,struct node *f);
	do
	{
		printf("\n         主菜单                   \n");
		printf("      1    建立二叉树               \n");
		printf("      2    先序非递归遍历           \n");
		printf("      3    中序递归遍历             \n");
		printf("      4    后序递归遍历，求叶节点数 \n");
		printf("      5    删除节点                 \n");
		printf("      6    结束程序运行             \n");
		printf("---------------------------------------\n");
		printf("请输入您的选择(1, 2, 3, 4, 5, 6)");
		scanf("%d",&cord);
		switch(cord)
		{
			case 1:
				{
					root=creat();  // 建立二叉树
					printf("建立二叉树程序以执行完，\n");
					printf("请返回主菜单，用遍历算法验证程序的正确性  \n");
				}break;
			case 2:
				{
					preorderz(root);
				}break;
			case 3:
				{
					inorder(root);
				}break;
			case 4:
				{
					postorder(root);
				}break;
			case 5:
				{
					//deletes(root)
				}
			case 6:
				{
					printf("二叉树程序执行完，再见！\n");
					exit(0);
				}
		}
	}while(cord<=6);
}

struct node* creat()
{
	struct node *t,*q,*s[30];
	int i,j,x;
	printf("i,x=");
	scanf("%d%d",&i,&x);//i是按满二叉树编号，x节点应有的序号，x是节点的数据
	while((i!=0)&&(x!=0))
	{
		q=(struct node*)malloc(sizeof(struct node));
		q->data=x;
		q->lc=NULL;	q->rc=NULL;
		s[i]=q;
		if(i==1)
			t=q;    //t代表树根节点
		else
		{
			j=i/2; //双亲节点的编号
			if((i%2)==0)
				s[j]->lc=q;
			else
				s[j]->rc=q;
		}
		printf("i,x=");
		scanf("%d%d",&i,&x);
	}
	return(t);
}

/*void preorderz(struct node* p)//前序非递归算法
{
	struct node *q,*s[30]; //s辅助栈
	int top,bools;
	q=p;top=0;  //栈顶指针
	bools=1;  //bools=1为真值继续循环；bools=0为假时栈空，结束循环
	do
	{
		while(q!=NULL)
		{
			printf("%6d",q->data);     //访问节点
			top++;
			s[top]=q;
			q=q->lc;
		}
		if(top==0)
			bools=0;
		else
		{
			q=s[top];
			top--;
			q=q->rc;
		}
	}while(bools);
	printf("\n");
}//////////////////////////结束preorderz*/

void preorderz(struct node* p)//前序递归遍历
{
	if(p!=NULL)
	{
		printf("%6d",p->data);
		inorder(p->lc);
		inorder(p->rc);
	}
}

void inorder(struct node* p)//中序非递归遍历
{
	struct node *s[30],*q;
	int top,bools;
	q=p;top=0;
	bools=1;
	do
	{
		while(q!=NULL)
		{
			top++;
			s[top]=q;
			q=q->lc;
		}
		if(top==0)
			bools=0;
		else
		{
			q=s[top];
			top--;
			printf("%6d",q->data);
			q=q->rc;
		}	
	}while(bools);
}

/*void inorder(struct node* p)
{
	if(p!=NULL)
	{
		inorder(p->lc);
		printf("%6d",p->data);
		inorder(p->rc);
	}
}//////////////////////////结束inorder*/

void postorder(struct node* p)
{
	struct node *s[30],*s2[30],*q;
	int top,bools;
	q=p;top=0;
	bools=1;
	do
	{
		while(q!=NULL)
		{
			top++;
			s[top]=q;
			s2[top]=1;
			q=q->lc;
		}
		if(top==0)
			bools=0;
		else
		{
			if(s2[top]==1)
			{
					s2[top]=2;
					q=s[top];
					q=q->rc;
				}
			else
			{
				q=s[top];
				s2[top]=0;
				top--;
				printf("%6d",q->data);
				q=NULL;
			}
		}
	}while(bools);
}

void deletes(struct node *t,struct node *p,struct node *f)
{
	struct node *s,*q;
	int bools=1;
	if(p->lc==NULL)
		s=p->rc;
	else if(p->rc==NULL)
	{
		s=p->rc;
		while(s->lc!=NULL)
		{
			q=s;
			s=s->rc;
		}
		if(q==p)
			q->rc=s->rc;
		else
			q->lc=s->rc;
		p->data=s->data;
		free(s);
		bools=0;
	}
	if(bools==1)
	{
		if(f==NULL)
			t=s;
		else if(f->lc==p)
			f->lc=s;
		else
			f->rc=s;
		free(p);
	}
}

/*void postorder(struct node* p)
{
	if(p!=NULL)
	{
		postorder(p->lc);
		postorder(p->rc);
		printf("%6d",p->data);
		if(p->lc==NULL&&p->rc==NULL)
			m++;    //统计叶子节点
	}
}//////////////////////////结束postorder*/