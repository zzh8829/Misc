#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct bitnode
{
char data;
struct bitnode *lchild, *rchild;
}bitnode, *bitree;

void createp(t)
bitnode **t;
{
char x;
bitnode *q;
printf("\n  x=:");
x=getchar();
if (x!='\n') getchar();
q=(bitnode*)malloc(sizeof(bitnode));
q->data=x;
q->lchild=NULL;
q->rchild=NULL;
*t=q;
if (q->data!='$') printf("%o,%c,%o,%o",q,q->data,q->lchild,q->rchild);
return;
}

void find(p,t)
bitnode *p,**t;
{
bitnode *q,*f;
if (*t==NULL) *t=p;
else
   {q=*t;f=NULL;
    while (q!=NULL)
     {if (p->data > q->data)
	 {f=q; q=q->rchild;}
      else {f=q;q=q->lchild;}
     }
    if (p->data>f->data) f->rchild=p;
    else f->lchild=p;
    }
}
void createbst(t)
char **t;
{
bitnode *p;
while (p->data!='$')
{
createp(&p);
if (p->data=='$') return;
find(p,t);
}
}

void visit(e)
bitnode *e;
{
printf("         %o,%c,%o,%o\n",e,e->data,e->lchild,e->rchild);
}

void preordertraverse(t)
bitnode *t;
{
if(t)
{visit(t);
 preordertraverse(t->lchild);
 preordertraverse(t->rchild);
 return ;
}else return ;
}

void searchbst(t,k)
bitnode *t;
char k;
{
if (!t) printf("\n can not find it\n");
else if  (k==t->data)
     printf("\nfind it is %o  %c  %o   %o\n",t,t->data,t->lchild,t->rchild);

     else if (k<t->data) searchbst(t->lchild,k);
     else searchbst(t->rchild,k);
}

main()
{
bitnode *t=NULL;
char k;
printf("input char; input '$' for end:"  );
createbst(&t);
preordertraverse(t);
printf("\ninput char for searchbst:");
k=getchar();
searchbst(t,k);
}