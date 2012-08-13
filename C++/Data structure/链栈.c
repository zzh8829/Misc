# define null 0
  typedef struct stacknode{int data;
		struct stacknode *next;}stacklink;
  typedef struct {stacklink *top;int stacksize;}stackk;

  initlink(stackk *s)
  {s->top=(stacklink *)malloc(sizeof(stacklink));
   s->top->data=0;
   s->top->next=null;
  }

  int poplink(stackk *s)
  {stackk *p;int v;
   if(s->top->next==null) printf("the stackis empty\n");
   else {v=s->top->next->data;
   p=s->top->next;
   s->top=s->top->next;
   free(p);
   return v;
  }
    }

  int pushlink(stackk *s,int x)
      {stackk *p;
      p=(stacklink *)malloc(sizeof(stacklink));
      p->data=x;
      p->next=s->top->next;
      s->top->next=p;
	 }

  int gettop(stackk *s)
    {int e;
     if(s==null) printf("the stack is empty!\n");
     e=s->top->next->data;
     return e;
   }
   display(stackk *s)
   {stackk *p;
    p=s->top->next;
    printf("display the stacklink:\n");
    if (s->top=null) printf("the stacklink is empty!\n");
    else {while(p)
	 {printf("->%d",p->data);
	  p=p->next;}
	  }
   }
   main(stacklink *p)
   {int n,k,i,select,h,x1,x2;
    printf("create a empty stacklink!\n");
    initlink(p);
    printf("input a stacklink length:\n");
    scanf("%d",&n);
    for (i=1;i<=n;i++)
   {printf("input a stacklink value:\n");
    scanf("%d",&k);
    pushlink(p,k);
   }
    printf("select 1:display()\n");
    printf("select 2:pushlink()\n");
    printf("select 3:poplink()\n");
    printf("select 4:gettop()\n");
    printf("input a your select(1-4):\n");
    scanf("%d",&select);
    switch(select)
   {case 1:{display(p);break;}
    case 2:{printf("input a push a value :\n");
	    scanf("%d",&h);
	    pushlink(p,h);
	    display(p);
	    break;}
     case 3:{x1=poplink(p);printf("x1->%d\n",x1);
	     display(p);
	     break;}
     case 4: {x2=gettop(p);printf("x2->%d",x2);
	      break;}
	    }
   }