#include<stdio.h>
#include<stdlib.h>
typedef struct ele{ 
             int vno; /*物品号*/ 
           struct ele *link; /*另一物品的指针*/ 
         }ELE; 
typedef struct hnode{ 
        int remainder;/*箱子尚剩空间*/ 
        ELE *head; /*箱内物品链首元指针*/ 
        struct hnode *next;/*箱子链的后继箱子指针*/ 
 }HNODE; 
main() 
{   
  int n,i,box_count,box_volume,*a; 
 HNODE *box_h,*box_t,*j; 
 ELE *p,*q; 
printf("输入箱子容积 "); 
scanf("%d",&box_volume); 
printf("输入物品种数 "); 
scanf("%d",&n); 
a=(int *)malloc(sizeof(int )*n);/*存储物品体积信息的数组*/ 
printf( "请按体积大小顺序输入各物品的体积： "); 
for(i=0;i<n;i++) 
 scanf("%d",a+i); 
box_h=box_t=NULL; /*预置已用箱子链为空*/ 
box_count=0; /*预置已用箱子计数器为0*/ 
for(i=0;i<n;i++) 
{               /*从第一只箱子开始顺序寻找能放入物品i 的箱子j*/ 
 p=(ELE *)malloc(sizeof(ELE)); 
 p->vno=i; 
 for(j=box_h;j!=NULL;j=j->next) 
      if(j->remainder>=a[i ]) 
         break;     /*找到还可以装物品i的箱子*/ 
  if(j==NULL) 
    {            /*已用箱子都不能装物品i*/ 
      j=(HNODE *)malloc(sizeof(HNODE));  /*使用一只新的箱子*/ 
      
      j->remainder=box_volume-a[i ]; 
      j->head=NULL; 
      if(box_h==NULL) 
        box_h=box_t=j;   /* box-t有什么用处，能解释一下吗？*/ 
      else box_t=box_t->next=j; /*此外box-t又有什么用（在程序中），请说详一细*/ 
        j->next=NULL; 
         box_count++; 
     } 
else 
   j->remainder=a[i ];           /*将物品i放入箱子j*/ 
  for(q=j->head;q!=NULL&&q->link!=NULL;q=q->link);/*从这里起是放入物品号*/ 
    if(q==NULL) 
      { 
        p->link=j->head; 
        j->head=p; 
       } 
    else 
        { 
       p->link=NULL; 
       q->link=p; 
        } 
  }/*for i*/ 
}           