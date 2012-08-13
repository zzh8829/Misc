# define null 0
typedef int status;
typedef struct qnode{int data;
		      struct qnode *next;}linkqlist;
typedef struct
{linkqlist *front;
 linkqlist *rear;} linkqueue;
 void init(linkqueue *p)
{    p->front=(linkqlist *)malloc(sizeof(linkqlist));
     p->rear=p->front;
     (p->front)->next=null;
     }
status destory (linkqueue *q)
        {while (q->front)
              {q->rear=q->front->next;
               free (q->front);
               q->front=q->rear;}
	    }

status empty(linkqueue *q)
        {int v;
         if(q->front==q->rear) v=1;
             else              v=0;
                          return v;}


 status gethead(linkqueue *q)
        {int v;
	if(q->front==q->rear)
           v=-1;
      else
        v=(q->front)->next->data;
        return v;}

status enqueue(linkqueue *q,int e)
	{q->rear->next=(linkqlist *)malloc(sizeof(linkqlist));
         q->rear=q->rear->next;
         if(!q->rear) return -1;
          q->rear->data=e;
          q->rear->next=null;
                     }

status dequeue(linkqueue *q)

       {linkqlist *p;
        int e;
         if (q->front==q->rear)
             printf("the linklist is overflow");
        else p=(q->front)->next;
             (q->front)->next=p->next;
             e=p->data;
            if(q->rear==p)
               q->rear=q->front;
               free(p);
       return(e);}

 void visit(linkqueue *p)
	{linkqueue *q;
	 q=p->front->next;
     printf("display the linklist:\n");
           if (p->front==p->rear)
               printf("the linklist is empty!");
	  else {while(q)
		   {printf("%d->",q->data);
		    q=q->next;}
		    }
		    printf("\n");
		    }

 main(linkqueue *head)
 {int n,i,y;
 int select;
 int a,x1,x3,x5,e;
 int dest;
 printf("create a empty linkqlist\n");
 init(head);
 printf("please input linkqlist length:\n");
 scanf("%d",&n);
 for (i=1;i<=n;i++)
 { printf("please input linkqlist value\n");
 scanf("%d", &a);
 enqueue(head,a);}
 visit(head);
 printf("select 1 --- destory() \n");
 printf("select 2 --- empty  () \n");
 printf("select 3 --- gethead() \n");
 printf("select 4 --- enqueue() \n");
 printf("select 5 --- dequeue() \n");
 printf("please select (1--5):");
 scanf("%d",&select);
 switch (select)
   {case 1: {destory(head);
	    visit(head);
	    break;}
   case 2: {x1=empty(head);
	    if (x1==1) printf("the linklist is empty!");
		      printf("the linklist is full");
		      break;}
   case 3: {x3=gethead(head);
	    printf("head->front->%d\n",x3);
	    break;}
   case 4: {printf("please inster the value:");
		   scanf("%d",&e);
		  enqueue(head,e);
		  visit(head);
		  break;}
   case 5: {x5=dequeue(head);
	    printf("x5",x5);
	    visit(head);
	    break;}
	     }

	  }