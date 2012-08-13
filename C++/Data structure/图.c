# define true 1
# define false 0
# define ok 1
# define error 0
# define overflow -2
# define null 0
typedef int status;

# include <stdio.h>
# include <stdlib.h>
# include <conio.h>
# define maxlen 10
# define large 999

typedef struct
{
 int a[maxlen],b[maxlen],h[maxlen];/*第K边的起点,终点,权值*/
 char vexs[maxlen];/*顶点信息集合*/
 int vexnum,arcnum;/*顶点数和边数*/
 int kind;/*图的类型*/
 int arcs[maxlen][maxlen];/*邻接矩阵*/
}graph;

typedef struct node/*表结点结构*/
{
 int adjvex;/*存放与头结点相邻接的顶点在数组中的序号*/
 int info;/*权值*/
 struct node *next;/*指向与头结点相邻接下一个顶点的表结点*/
}edgenode;

typedef struct/*头结点结构*/
{
 int id;/*顶点入度*/
 char data;/*顶点信息*/
 edgenode *link;/*指向头结点对应的单链表中的表结点*/
}vexnode;

typedef struct/*邻接表结构*/
{
 vexnode adjs[maxlen];/*邻接表的头结点集合*/
 int vexnum,arcnum;/*顶点数,边数*/
 int kind;
}adjlist;

typedef struct qnode/*队列存储结构*/
{int data;
 struct qnode *next;
}linkqlist;

typedef struct
{linkqlist *front;/*队头指针*/
 linkqlist *rear;/*队尾指针*/
} linkqueue;



typedef struct/*栈结构*/
{int stack[maxlen];
 int top;
}stackstru;

int cnull=-1;
graph g;
adjlist adjl;
stackstru *t;/*拓扑序列顶点栈*/
stackstru *s;/*零入度顶点栈*/
linkqueue *q;



graph printf_adjmatrix(graph g)/*输出邻接矩阵*/
 {
 int i,j;
 printf("邻接矩阵:\n");
 printf("vertex\t");
 for (i=0;i<g.vexnum;i++) printf("%4c",g.vexs[i]);
 printf("\n");
 for(i=0;i<g.vexnum;i++)
  { printf("% 4c \t",g.vexs[i]);
    for(j=0;j<g.vexnum;j++) printf("%4d",g.arcs[i][j]);
    printf("\n");
   }
 return g;
}

void create_1(graph g)
{
  int i,j,k,c=0;
  for (i=0;i<g.vexnum;i++)
     for(j=0;j<g.vexnum;j++)
      g.arcs[i][j]=c;
  for(k=0;k<g.arcnum;k++)
    g.arcs[g.a[k]-1][g.b[k]-1]=1;
  printf_adjmatrix(g);

 }
void create_2(graph g)
{
   int i,j,k,c=0;
   for (i=0;i<g.vexnum;i++)
     for(j=0;j<g.vexnum;j++)
      g.arcs[i][j]=c;
   for(k=0;k<g.arcnum;k++)
    { g.arcs[g.a[k]-1][g.b[k]-1]=1;
      g.arcs[g.b[k]-1][g.a[k]-1]=1;
     }
   printf_adjmatrix(g);

}
graph create_3(graph g)
{
  int i,j,k,c=999;
  for (i=0;i<g.vexnum;i++)
     for(j=0;j<g.vexnum;j++)
      g.arcs[i][j]=c;
  for(k=0;k<g.arcnum;k++)
	g.arcs[g.a[k]-1][g.b[k]-1]=g.h[k];
  printf_adjmatrix(g);
  return g;

}
graph create_4(graph g)
{
  int i,j,k,c=999;
  for (i=0;i<g.vexnum;i++)
     for(j=0;j<g.vexnum;j++)
      g.arcs[i][j]=c;
  for (k=0;k<g.arcnum;k++)
   { g.arcs[g.a[k]-1][g.b[k]-1]=g.h[k];
      g.arcs[g.b[k]-1][g.a[k]-1]=g.h[k];
     }
 printf_adjmatrix(g);
 return g;
}

void creategraph(graph g)/*邻接矩阵*/
{
 switch(g.kind)
    {
     case 1:create_1(g);break;
     case 2:create_2(g);break;
     case 3:create_3(g);break;
     case 4:create_4(g);break;
     default:printf("Error\n");
     }
}

adjlist  createlist (graph g ,adjlist adjl)/*邻接表*/
{
  int i;
  edgenode *p;
  if(g.kind==1||g.kind==3)
    { for(i=0;i<adjl.arcnum;i++)
      { p=(edgenode*)malloc(sizeof(edgenode));
	p->adjvex=g.b[i];
	p->info=g.h[i];
	p->next=adjl.adjs[g.a[i]-1].link;
	adjl.adjs[g.a[i]-1].link=p;
	}
     }
 if(g.kind==2||g.kind==4) 
   { for(i=0;i<adjl.arcnum;i++)
      { p=(edgenode*)malloc(sizeof(edgenode));
	p->info=g.h[i];
        p->adjvex=g.b[i];
       	p->next=adjl.adjs[g.a[i]-1].link;
        adjl.adjs[g.a[i]-1].link=p;
       
        p=(edgenode*)malloc(sizeof(edgenode));
        p->info=g.h[i];
        p->adjvex=g.a[i];
       	p->next=adjl.adjs[g.b[i]-1].link;
	adjl.adjs[g.b[i]-1].link=p;
	}
     }
printf("邻接表为:\n");
for(i=0;i<g.vexnum;i++)
 { printf("[%d,%c]=>",i+1,adjl.adjs[i].data);
   p=adjl.adjs[i].link;
   while(p!=cnull)
    {printf("[%c,%d]-->",adjl.adjs[(p->adjvex)-1].data,p->info);
   p=p->next;
 }
printf("^\n");
}
return adjl;
}
 void initqueue(linkqueue *p)
{    p->front=(linkqlist *)malloc(sizeof(linkqlist));
     p->rear=p->front;
     (p->front)->next=null;
     }

status empty(linkqueue *q)
{int v;
 if(q->front==q->rear) v=true;
 else   v=false;
 return v;
}
status addqueue(linkqueue *q,int e)/*入队列*/
{
 q->rear->next=(linkqlist *)malloc(sizeof(linkqlist));
 q->rear=q->rear->next;
 if(!q->rear) return -1;
 q->rear->data=e;
 q->rear->next=null;
}

status delqueue(linkqueue *q)/*出队列*/
{
  linkqlist *p;
  int e;
  if (q->front==q->rear)
      printf("the linklist is overflow");
  else p=(q->front)->next;
       (q->front)->next=p->next;
  e=p->data;
  if(q->rear==p)
       q->rear=q->front;
  free(p);/*释放P所指的内存区*/
 return(e);
}


void DFS(int i, adjlist adjl)/*深度优先搜索*/
{edgenode *p;
 int j;
 int visited[maxlen];/*访问标志数组,访问过为1,未访问过为0*/
 for(j=0;j<adjl.vexnum;j++) visited[j]=0;/*初始化,所有点都未访问*/
  printf("%4c->",adjl.adjs[i-1].data);
  visited[i-1]=1;
  p=adjl.adjs[i-1].link;
  while(p!=cnull)
  {if (visited[(p->adjvex)-1]!=1) DFS((p->adjvex),adjl);
     p=p->next;
   }
}

void BFS(int i,adjlist adjl)/*广度优先搜索*/
{ edgenode *p;
  int j;
  int visited[maxlen];
  for (j=0;j<adjl.vexnum;j++) visited[j]=0;/*初始化所有点*/

  initqueue(q);
  printf("%4c->",adjl.adjs[i-1].data);
  visited[i-1]=1;
  addqueue(q,i);
  while(!empty(q))
    {i=delqueue(q);
     p=adjl.adjs[i-1].link;
     while(p!=cnull)
       {if (visited[(p->adjvex)-1]==0)
          {printf("%4c->",adjl.adjs[p->adjvex-1].data);
           visited[(p->adjvex)-1]=1;
           addqueue(q,p->adjvex);
           p=p->next;
           }
        }
     }
}

status initstack(stackstru *s)/*构造空栈*/
{s->top=0;
 return ok;
}

status push(stackstru *s,int x)/*入栈*/
{if (s->top==maxlen)
 printf("the stack is overflow!\n");
 else{ s->top=s->top+1;
       s->stack[s->top]=x;
      }
}
status pop(stackstru *s)
{ int y;
  if(s->top==0)printf("the stack is empty!\n");
  else {y=s->stack[s->top];
	s->top=s->top-1;
	}
  return y;
}

status stackempty(stackstru *s)
{ if (s->top==maxlen) return (true);
  else return (false);
}


 

status topsort(adjlist adjl)/*拓扑排序*/
{
  int i,k,count;
  edgenode *p;
  
  printf("拓扑排序序列为:\n");
  initstack(s);
  
  for(i=0;i<adjl.vexnum;i++)
    if(adjl.adjs[i].id==0) push(s,adjl.adjs[i].data);
  count=0;
  while(!stackempty(s))
    { i=pop(s);
      printf("%4c->",adjl.adjs[i].data);
      ++count;
      for(p=adjl.adjs[i].link;p;p=p->next)
         { k=p->adjvex;
	   if(!(--adjl.adjs[k-1].id)) push(s,k-1);
          }
     }
  if(count<adjl.vexnum)
    { printf("\n网中有环!\n"); /*拓扑排序输出的顶点数<图中的顶点数*/
      return error;
     }
  else return ok;
}






 

void prim(graph g)/*最小生成树*/
{
  int i,j,k,min;
  int lowcost[maxlen];/*权值*/
  int closet[maxlen];/*最小生成树结点*/
  printf("最小生成树的边为:\n");
  for(i=1;i<g.vexnum;i++)
   {
     lowcost[i]=g.arcs[0][i];
     closet[i]=1;
    }
  closet[1]=0;
  j=1;
  for(i=1;i<g.vexnum;i++)
   {
     min=lowcost[j];
     k=i;
     for(j=1;j<g.vexnum;j++)
       if(lowcost[j]<min&&closet[j]!=0)
         {
	  min=lowcost[j];
	  k=j;
	 }
      printf("(%c,%c),",g.vexs[k-1],g.vexs[closet[k-1]]);
      closet[k]=0;
      for(j=1;j<g.vexnum;j++)
        if(g.arcs[k][j]<lowcost[j]&&closet[j]!=0)
           {
              lowcost[j]=g.arcs[k][j];
              closet[j]=k;
	    }
     }
}

int ve[maxlen];/*最早发生时间*/
int vl[maxlen];/*最迟发生时间*/
 
status toporder(adjlist adjl,stackstru *t)/*求各顶点事件的最早发生时间ve*/
{ int i,j,count,k;
  edgenode *p;
  initstack(s);
  initstack(t);
  for(i=0;i<adjl.vexnum;i++)
    if(adjl.adjs[i].id==0) push(s,i);

  count=0;
  for(i=0;i<adjl.vexnum;i++) ve[i]=0;
  while(!stackempty(s))
    { j=pop(s);push(t,j);++count;
      for(p=adjl.adjs[j].link;p;p=p->next)
        { k=p->adjvex;
          if(--adjl.adjs[k-1].id==0) push(s,k-1);
	  if(ve[j]+(p->info)>ve[k-1]) ve[k-1]=ve[j]+(p->info);
         }
     }
  if(count<adjl.vexnum) return error;
   else return ok;
}

status criticalpath(adjlist adjl)/*关键路径*/
{  int i,j,k,dut,ee,el;
   edgenode *p;
   
   if(!toporder(adjl,t)) return error;
   for(i=0;i<adjl.vexnum;i++) vl[i]=ve[i-1];/*初始化顶点事件的最迟发生时间*/
   printf("关键路径为:\n");
  while(!stackempty(t))/*按拓扑排序的逆序求各顶点的最迟发生时间ve值*/
    for(j=pop(t), p=adjl.adjs[j].link;p;p=p->next)
       { k=p->adjvex; dut=(p->info);
         if(vl[k]-dut<vl[j]) vl[j]=vl[k]-dut;
        }
  for(j=0;j<adjl.vexnum;++j)/*求ee,el和关键活动*/
    for(p=adjl.adjs[j].link;p;p=p->next)
      { k=p->adjvex;dut=p->info;
        ee=ve[j];el=vl[k-1]-dut;
        if(ee==el) printf("(%c,%c)->",adjl.adjs[j].data,adjl.adjs[k-1].data);
       }
}

void shortpath_dijkstra(graph g)
{ int cost[maxlen][maxlen];
  int dist[maxlen];/*某源点到各顶点的最短路径长度*/
  int path[maxlen];/*某源点到终点经过的顶点集合的数组*/
  int s[maxlen];/*最短路径的终点集合*/
  int i,j,n,v0,min,u;/*U存放最短路径的终点*/
  printf("\n请输入起点的编号:");
  scanf("%d",&v0);
  v0--;
  for(i=0;i<g.vexnum;i++)
    {for(j=0;j<g.vexnum;j++)
      cost[i][j]=g.arcs[i][j];
     }
  for(i=0;i<g.vexnum;i++)
    { dist[i]=cost[v0][i];
      if(dist[i]<large&&dist[i]>0) path[i]=v0;
      s[i]=0;
     }
  s[v0]=1;
  for(i=0;i<g.vexnum;i++)
    { min=large;
      u=v0;
      for(j=0;j<g.vexnum;j++)
        if(s[j]==0&&dist[j]<min)
          {min=dist[j];u=j;}
      s[u]=1;   /*U顶点是求得最短路径的顶点编号*/
      for(j=0;j<g.vexnum;j++)
         if(s[j]==0&&dist[u]+cost[u][j]<dist[j])
           { dist[j]=dist[u]+cost[u][j];
             path[j]=u;
            }
      }
  printf("\n顶点%d到各顶点的最短路径长度为:\n",v0);
  for(i=0;i<g.vexnum;i++)/*输入结果*/
     if(s[i]==1)
       { u=i;
         while(u!=v0)
            { printf("%4c<-",g.vexs[u]);
              u=path[u];
             }
          printf("%4c",g.vexs[u]);
          printf(":%d\n",path[i]);
         }
      else printf("%4c<-%4c:无路径\n",g.vexs[i],g.vexs[v0]);
}

void shortpath_floyd(graph g)
{ int path[maxlen][maxlen];
  int short3[maxlen][maxlen];/*权值*/
  int i,j,k;
  for(i=0;i<g.vexnum;i++)
     for(j=0;j<g.vexnum;j++)
       { short3[i][j]=g.arcs[i][j];
         path[i][j]=0;
        }
  printf("\n各顶点间的最短路径为:\n");
  for(k=0;k<g.vexnum;k++)
    for(i=0;i<g.vexnum;i++)
      { if(short3[i][j]>(short3[i][k]+short3[k][j]))
	  { short3[i][j]=short3[i][k]+short3[k][j];
            path[i][j]=k;
           }
	 printf("(%4c->%4c):%d",g.vexs[i-1],g.vexs[j-1],short3[i][j]);
       }
}




main()
{

int a,i,j,k,h;
printf("\n请输入图的类型(1:有向图 2:无向图 3:有向网 4:无向网):");
scanf("%d",&i);
{g.kind=i;adjl.kind=i;}
printf("请输入顶点数,边数:");
scanf("%d,%d",&i,&j);
g.vexnum=i;adjl.vexnum=i;
g.arcnum=j;adjl.arcnum=j;
for (i=0;i<g.vexnum;i++)
 { printf("第%d个顶点的信息:",i+1);
   scanf("%s",&g.vexs[i]);
   adjl.adjs[i].data=g.vexs[i];
   adjl.adjs[i].link=cnull;
   adjl.adjs[i].id=0;
   }
for (k=1;k<=g.arcnum;k++)
{label:if (g.kind==1||g.kind==3)
	 printf("第%d条边的起点编号,终点编号:",k);
       else printf("第%d条边的两个顶点的编号:",k);
       scanf("%d,%d",&i,&j);
       g.a[k-1]=i;g.b[k-1]=j;
       while (i<1||i>g.vexnum||j<1||j>g.vexnum)
       {printf("     编号超出范围,重新输入");goto label;

	}
       if (g.kind==3||g.kind==4)
       {printf("\t该边的权值:");
	scanf("%d",&h);
	g.h[k-1]=h;
	}
	else  g.h[k-1]=null;
	adjl.adjs[i].id++;
}
loop1:printf("\n1__邻接矩阵\n");
printf("2__邻接表\n");
printf("3__深度优先搜索\n");
printf("4__广度优先搜索\n");
printf("5__最小生成树\n");
printf("6__拓扑排序\n");
printf("7__关键路径\n");
printf("8__从某个源点到其余各顶点的最短路径\n");
printf("9__每一对顶点之间的最短路径\n");
loop:printf("请选择图的实现:\t");
scanf("%d",&a);
 switch(a)
 {
  case 1:creategraph(g);break;
  case 2:createlist(g,adjl);break;
  case 3:printf("请输入出发点编号:");
           scanf("%d",&k);
          createlist(g,adjl);
           printf("\n从第%d点出发深度优先搜索遍历序列:",k);
	   DFS(k,adjl);break;
  case 4:printf("请输入出发点编号:");
           scanf("%d",&k);
           createlist( g,adjl);
           printf("\n从第%d点出发广度优先搜索遍历序列:",k);	
	   BFS( k,adjl);
	   break;
  case 5:if (g.kind==4)
	       {create_4(g); prim(g);}
	   else{printf("\t不能构造最小生成树,请重新选择:\n");goto loop;}
           break;
  case 6:if (g.kind==1||g.kind==3)
	       {createlist(g,adjl); topsort(adjl);}
	   else{printf("\t不能拓扑排序,请重新选择:\n");goto loop;}
           break;
  case 7:if (g.kind==3)
	       {createlist(g,adjl);
	       criticalpath( adjl);
	       }
	   else{printf("\t没有关键路径,请重新选择:\n");goto loop;}
           break;
  case 8:if (g.kind==3)
	       {create_3(g); shortpath_dijkstra(g);}
	   else{printf("\t没有最短路径,请重新选择:\n");goto loop;}
           break;
  case 9:if (g.kind==3)
	       {create_3(g); shortpath_floyd(g);}
	   else{printf("\t没有最短路径,请重新选择:\n");goto loop;}
           break;
  default:printf(" \n\t*** wrong ***\n");
  }/*switch*/
goto loop1;
 }/*main()*/



