/*这是我在这里帮落尘改写的程序，今天又吧它改写成了c的
借鉴一下吧*/
#include <stdio.h>
#include <malloc.h>

typedef struct node{ 
int data; 
struct node *lchild,*rchild; 
}*treetp,tree; 
treetp create (treetp t,int c); 
void print1(treetp); 
void print2(treetp);
void print3(treetp);
int number=0;
void main() 
{
  treetp t=0,r; 
  r=create (t,0); 
  printf("前序排列 ：");
  print1  (r); 
  printf("\n中序排列 ：");
  print2 (r);
  printf("\n后序排列 ：");
  print3 (r);
} 

treetp  create(treetp t,int c) 
{ 
treetp p,di; 
do{ 
scanf("%d",&c); 
if (t==0) 
 { 
 t=(treetp)malloc(sizeof(tree)); 
 t->lchild=t->rchild=0; 
 t->data=c; 
 } 
else 
 {   p=t; 
  while(p!=0) 
  { 
  di=p; 
  if(c<(p->data)) 
  p=p->lchild; 
  else 
  p=p->rchild; 
  } 
if(c<(di->data)) 
{ 
treetp NEWdi=(treetp) malloc(sizeof(tree)); 
NEWdi->lchild=NEWdi->rchild=0; 
NEWdi->data=c; 
di->lchild=NEWdi; 
} 
else 
{ 
treetp NEWdi=(treetp) malloc(sizeof(tree)); 
NEWdi->lchild=NEWdi->rchild=0; 
NEWdi->data=c; 
di->rchild=NEWdi; 
} 
 } 
++number;
}while(c!=0); 
printf("叶子的数量：%d",number);
return t;
}   
void print1(treetp  t) 
{ 
   if (t!=0) 
  {     
   printf("%d ",t->data);
   print1(t->lchild); 
   print1(t->rchild); 
   } 
} 
void print2(treetp  t) 
{ 
   if (t!=0) 
  {     
   print2(t->lchild); 
   printf("%d ",t->data); 
   print2(t->rchild); 
   } 
} 
void print3(treetp  t) 
{ 
   if (t!=0) 
  {     
   print3(t->lchild);  
   print3(t->rchild); 
   printf("%d ",t->data);
   } 
} 