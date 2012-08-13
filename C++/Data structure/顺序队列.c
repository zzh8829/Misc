#define maxsize 100
typedef struct
{
	int data[maxsize];
 	int front;
 	int rear;
}sqqueue;

int sqinit(sqqueue *p)   /*装入队列*/
{
	p->front=0;
	p->rear=0;
	return 1;
}

int enqueue(sqqueue *q, int e)   /*入队*/
{
	if((q->rear+1)%maxsize==q->front)
       		return 0;
       	else
       		q->data[q->rear]=e;
       		q->rear=(q->rear+1)%maxsize;
       	return 1;
}

int dequeue(sqqueue *q)   /*出队*/
{
	int e;
	if (q->front==q->rear)
		return 0;
	e=q->data[q->front];
	q->front=(q->front+1)%maxsize;
	return e;
}

int empty(sqqueue *q)
{
	int v;
        if (q->front==q->rear)
		v=1;
       	else
       		v=0;

      	return v; 
}

int gethead(sqqueue *q)
{
	int e;
        if (q->front==q->rear) 
        	e=-1;
       	else
       		e=q->data[q->front];
       	
       	return e;
}

void display(sqqueue *q)
{
	int s;
       	s=q->front;
       	printf("the sequeue is display:\n");
       	if (q->front==q->rear)
		printf("the sequeue is empty!");
       	else
       	{
       		while(s<q->rear)
	       	{
			printf("->%d", q->data[s]);
			s=(s+1)%maxsize;
		}	
		printf("\n");
	}
}

main(sqqueue *head)
{
	int n,i,m,x,y,select,xq;
  	printf("create a empty sequeue\n");
 	sqinit(head);
  	printf("please input the sequeue length:\n");	
  	scanf("%d",&n);
  	for (i=0;i<n;i++)
  	{
  		printf("please input a sequeue value:\n");
   		scanf("%d",&m);
   		enqueue(head,m);}
 		printf("head->rear:%d\n",head->rear);
 		printf("head->front:%d\n",head->front);
 		display(head);
 		printf("select 1 **** enqueue() \n");
 		printf("select 2 **** dequeue() \n");
 		printf("select 3 **** empty  () \n");
 		printf("select 4 **** gethead() \n");
 		printf("select 5 **** display() \n");
 		printf("please select (1--5):");
 		scanf("%d",&select);
 		switch(select)
 		{
 			case 1:
 			{ 
 				printf("please input a value :\n ");
	   			scanf("%d",&x);
	   			enqueue(head,x);
	   			display(head);
	   			break;
	   		}
  			case 2:
  			{
  				dequeue(head);
	   			display(head);
	   			break;
	   		}
  			case 3:
  			{
  				if(empty(head))
	   				printf("the sequeue is empty");
	   			else
	   				printf("the sequeue is full");
	   		}
  			case 4:
  			{
  				y=gethead(head);
	   			printf("output head value:%d\n",y);
	   			break;
	   		}
  			case 5:
  			{
  				display(head);
	   			break;
	   		}
		}
	}
}	