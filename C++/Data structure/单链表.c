/*单链表的各种操作*/

# define null 0

typedef char ElemType; /* 字符型数据*/

typedef struct LNode
{
	ElemType data;
	struct LNode *next;
};
		
setnull(struct LNode **p);
int length (struct LNode **p);
ElemType get(struct LNode **p,int i);
void insert(struct LNode **p,ElemType x,int i);
int delete(struct LNode **p,int i);
void display(struct LNode **p);

main()
{
	struct LNode *head,*q;  /*定义静态变量*/
	int select,x1,x2,x3,x4;
	int i,n; 
	int m,g;
	char e,y; 
	
 	head=setnull(&head);  /*建议链表并设置为空表*/
 	printf("请输入数据长度: ");
 	scanf("%d",&n);
 	for(i=1;i<n;i++);
 	{
 		printf("将数据插入到单链表中: ");
 		scanf("%d",&y);
 		insert(&head,y,i);}  /*插入数据到链表*/
 		display(&head);	 /*显示链表所有数据*/
 		
 		printf("select 1 求长度 length()\n");
 		printf("select 2 取结点 get()\n");
 		printf("select 3 求值查找 locate()\n");
 		printf("select 4 删除结点 delete()\n");
 		printf("input your select: ");
 		scanf("%d",&select);	
		switch(select)
		{
			case 1:
			{
				x1=length(&head);
				printf("输出单链表的长度%d ",x1);
	 			display(&head);
	 		}break;
	 		
	 		case 2:
	 		{
	 			printf("请输入要取得结点: ");
         			scanf("%d",&m);
         			x2=get(&head,m);
         			printf(x2);
	 			display(&head);
	 		}break;
	 	
 			case 3:
 			{
 				printf("请输入要查找的数据: ");
         			scanf("%d",&e);
         			x3=locate(&head,e);
         			printf(x3);
	 			display(&head);
	 		}break;
 			
 			case 4:
 			{
 				printf("请输入要删除的结点: ");
         			scanf("%d",&g);
         			x4=delete(&head,g);
         			printf(x4);
	 			display(&head);
	 		}break;
		}
	}
}


setnull(struct LNode **p)
{
	*p=null;
}

int length (struct LNode **p)
{
	int n=0;
 	struct LNode *q=*p;
 	while (q!=null)
 	{
 		n++;
  		q=q->next;
 	}
 	return(n);
}

ElemType get(struct LNode **p,int i)
{
	int j=1;
	struct LNode *q=*p;
	while (j<i&&q!=null)
 	{
 		q=q->next;
  		j++;
 	}
 	if(q!=null)
   		return(q->data);
 	else
 		printf("位置参数不正确!\n");
}

int locate(struct LNode **p,ElemType x)
{
	int n=0;
 	struct LNode *q=*p;
	while (q!=null&&q->data!=x)
 	{
 		q=q->next;
  		n++;
 	}
 	if(q==null)
 		return(-1);
 	else
 		return(n+1);
}

void insert(struct LNode **p,ElemType x,int i)
{
	int j=1;
 	struct LNode *s,*q;
  	s=(struct LNode *)malloc(sizeof(struct LNode));
  	s->data=x;
  	q=*p;
  	if(i==1)
  	{
  		s->next=q;
   		p=s;
  	}
  	else
  	{
  		while(j<i-1&&q->next!=null)
   		{
   			q=q->next;
    			j++;
   		}
   		if(j==i-1)
    		{
    			s->next=q->next;
     			q->next=s;
    		}
   		else 
   			printf("位置参数不正确!\n");
  	}	
}

int delete(struct LNode **p,int i)
{
	int j=1;
 	struct LNode *q=*p,*t;
 	if(i==1)
  	{
  		t=q;
  		*p=q->next;
  	}
 	else
  	{
  		while(j<i-1&&q->next!=null)
   		{
   			q=q->next;
    			j++;
   		}
    		if(q->next!=null&&j==i-1)
     		{
     			t=q->next;
      			q->next=t->next;
     		}
    		else 
    			printf("位置参数不正确!\n");
  	}
   	if(t=null)	
   		free(t);
}

void display(struct LNode **p)
{	
	struct LNode *q;
 	q=*p;
 	printf("单链表显示: ");
 	if(q==null)
  		printf("链表为空!");
 	else if (q->next==null)
       		printf("%c\n",q->data);
      	else
      	{
      		while(q->next!=null)
	    	{
	    		printf("%c->",q->data);
	     		q=q->next;
	    	}
	   	printf("%c",q->data);
	}
 	printf("\n");
}

