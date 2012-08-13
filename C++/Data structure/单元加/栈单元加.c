#include<stdio.h>
#include<stdlib.h>
typedef struct node
{ int data;
  struct node *next;
} st;
st *top=NULL,*p=NULL;

void print()
{ while(p)
  { printf("%d ",p->data);
    p=p->next;
  }
  printf("\n");
}

void fun(int m,int n)
{ if(m==n)
  { p=(st *)malloc(sizeof(st));
    p->next=top;
    p->data=n;
    print();
    free(p);return;
  }
  else if(m>n) return;
  else
  { int i;
    p=(st *)malloc(sizeof(st));
    p->next=top;
    top=p;
    for(i=m;i<=n/2;i++)
    { top->data=i;fun(i,n-i);
    }
    if(top->next)
    { top->data=n;p=top;print();
      p=top;top=top->next;free(p);
    }
  }
}

void main()
{ int n;
  printf("Please type a number(>=2):");
  scanf("%d",&n);
  printf("\n");
  fun(1,n);
} 