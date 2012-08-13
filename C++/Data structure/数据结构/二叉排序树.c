#include<stdio.h>
#include<stdlib.h>

struct nodb
{
	int data;
	struct nodb *lch,*rch;
};
struct nodb *root,*q,*p;

void insert1(struct nodb *s);

void creat()
{
	struct nodb *s;
	int i,n,k;
	printf("n=?");
	scanf("%d",&n);
	
	for(i=1;i<n;i++)
	{
		printf("k%d=?",i);
		scanf("%d",&k);
		s=(struct nodb *)malloc(sizeof(struct nodb));
		s->data=k;s->lch=NULL;s->rch=NULL;
		insert1(s);
	}
}


void insert1(struct nodb *s)
{  //非递归插入
	struct nodb *p,*q;
	if(root==NULL)
		root=s;
	else
	{
		p=root;
		while(p!=NULL)
		{
			q=p;//当p向子数节点移动时，q记录p的双亲的位置
			if(s->data<p->data)
				p=p->lch;
			else
				p=p->rch;
		}
		if(s->data<q->data)
			q->lch=s;
		else 
			q->rch=s;//当p为空时，q就是可插入的地方
	}
}

void print(struct nodb *t)
{
	if(t!=NULL)
	{
		print(t->lch);
		printf("%6d",t->data);
		print(t->rch);
	}
}

void bstsrch(struct nodb*t,int k)
{
	int flag;
	p=NULL;
	q=t;
	flag=0;
	while((q!=NULL)&&(flag==0))
	{
		if(q->data==k)
		{
			printf("发现 %5d",q->data);
			flag=1;
		}
		else if(k<q->data)
		{
			p=q;
			q=q->lch;
		}
		else
		{
			p=q;
			q=q->rch;
		}
	}
	if(flag==0)printf("没有发现节点");
}

void bstins(struct nodb *t,int k)
{
	struct nodb *r;
	bstsrch(root,k);
	if(q==NULL)
	{
		r=(struct nodb*)malloc(sizeof(struct nodb));
		r->data=k;
		r->lch=NULL;
		r->rch=NULL;
		if(root==NULL)
			root=r;
		else if(k<p->data)
			p->lch=r;
		else
			p->rch=r;
	}
}

main()
{
	int n;
	root=0;
	creat();
	print(root);
	printf("请出入关键值n=?");
	scanf("%d",&n);
	bstsrch(root,n);
	printf("\n");
	bstins(root,n);
	print(root);
}