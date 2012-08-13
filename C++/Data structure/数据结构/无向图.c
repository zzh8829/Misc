#include<stdio.h>
#include<stdlib.h>
#define MaxSize 20
struct ArcNode
{
	int adjvex;
	struct ArcNode *nextarc;
};

struct Vnode
{
	int data;
	struct ArcNode *firstarc;
};

struct Vnode AdjList[MaxSize];
int m,n,v,cord;

main()
{
	void creatgraph(struct Vnode A[MaxSize]);
	void dfs(struct Vnode A[MaxSize]);
	void bfs(struct Vnode A[MaxSize]);
	do
	{
		printf("\n            主菜单");
		printf("\n      1     建立无向图的邻接表");
		printf("\n      2     按深度遍历图");
		printf("\n      3     按广度遍历图");
		printf("\n      4     结束程序运行");
		printf("\n-----------------------------------");
		printf("\n    请输入您的选择  1, 2, 3, 4 ");
		scanf("%d",&cord);
		switch(cord)
		{
		case 1:
			creatgraph(AdjList);
			break;
		case 2:
			dfs(AdjList);
			break;
		case 3:
			bfs(AdjList);
			break;
		case 4:
			exit(0);
		}
	}while(cord<=4);
}//main end

void creatgraph(struct Vnode A[MaxSize])
{
	int i,j,k;
	struct ArcNode *p;
	printf("input arces and vexes");
	scanf("%d %d",&m,&n);
	for(k=0;k<n;k++)
	{
		printf("\ninput arc");
		scanf("%d%d",&i,&j);
		p=(struct ArcNode*)malloc(sizeof(struct ArcNode));
		p->adjvex=j;
		p->nextarc=A[i-1].firstarc;
		A[i-1].firstarc=p;
		p=(struct ArcNode*)malloc(sizeof(struct ArcNode));
		p->adjvex=i;
		p->nextarc=A[j-1].firstarc;
		A[j-1].firstarc=p;
	}
	printf("\n");
	for(k=0;k<n;k++)
	{
		printf("%d",A[k].data);
		p=A[k].firstarc;
		while(p)
		{
			printf("%d",p->adjvex);
			p=p->nextarc;
		}
		printf("\n");
	}
}///creatgraph end

void dfs(struct Vnode A[MaxSize])
{
	struct ArcNode *p,*ar[MaxSize];

	int x,i,y,top=-1;
	int visited[MaxSize];
	for(i=0;i<n;i++)
		visited[i]=0;
	printf("\ninput x");
	scanf("%d",&x);
	printf("%d",x);
	visited[x-1]=1;
	p=A[x-1].firstarc;
	while((p)||(top>=0))
	{
		if(!p)
		{
			p=ar[top];
			top--;
		}
		y=p->adjvex;
		if(visited[y-1]==0)
		{
			visited[y-1]=1;
			printf("->%d",y);
			p=p->nextarc;
			if(p)
			{
				top++;
				ar[top]=p;
			}
			p=A[y-1].firstarc;
		}
		else p=p->nextarc;
	}
}

void bfs(struct Vnode A[MaxSize])
{}