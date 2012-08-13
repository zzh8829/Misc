#include <stdio.h>

#define TYPE struct stu
#define LEN sizeof(struct stu)

struct stu
{
      int num;
      int age;
      struct stu *next;
};

TYPE * creatlink(int n);
TYPE * deletelink(TYPE * head,int num);
TYPE * insertlink(TYPE * head,TYPE * pi);
void printlink(TYPE * head);
void destroylink( TYPE * head );

void main(void)
{
    TYPE *head=NULL,*pnum=NULL;
    int n=3,num;

    /* 创建一个含 n 个节点的链表 */
    printf("input number of node:");
 
    head=creatlink(n);
    printlink(head);
    
    /* 删除链表中值为 num 的节点 */
    printf("Input the deleted number:");
    scanf("%d",&num);
    head=deletelink(head,num);
    printlink(head);

    /* 在链表中插入一个节点 */
    printf("Insert a record\n");
    pnum=(TYPE *)malloc(LEN);
    if(pnum==NULL)
      printf("Pointer is NULL--memory alloc fail!");
    printf("Input the inserted number:");
    scanf("%d",&pnum->num);
    printf("Input the inserted age:");
    scanf("%d",&pnum->age);
    head=insertlink(head,pnum);
    printlink( head );

    /* 销毁链表, 释放动态分配的内存 */
    destroylink( head );
}

/* 创建一个含 n 个节点的链表 */
TYPE * creatlink(int n)
{
    TYPE *head=NULL, *pf, *pb;
    int i;
    for(i=0;i<n;i++)
    {
        pb=(TYPE *)malloc(LEN);
		printf("record %d\n",i);
        printf("input Number:");
        scanf("%d",&pb->num);
        printf("input age:");
        scanf("%d",&pb->age);
        if(i==0)
          pf=head=pb;
        else 
          pf->next=pb;
        pb->next=NULL;
        pf=pb;
    }
    return(head);
}

/* 删除链表中值为 num 的节点 */
TYPE * deletelink(TYPE * head,int num)
{
    TYPE *pf, *pb;
    if(head==NULL)
    {
        printf("\nempty list!\n");
        return NULL;
    }
    pb=head;
    while (pb->num!=num && pb->next!=NULL)
    {
       pf=pb;
       pb=pb->next;
    }
    if(pb->num==num)
    {
        if(pb==head)
          head=pb->next;
        else
          pf->next=pb->next;
        free(pb);
        printf("The node is deleted\n");
    }
    else
      printf("The node not been found!\n");

    return head;
}

/* 在链表中插入一个节点 */
TYPE * insertlink(TYPE * head,TYPE * pi)
{
    TYPE *pb, *pf;
    pb=head;
    if(head==NULL)
    { 
        head=pi;
        pi->next=NULL; 
    }
    else
    {
      while((pi->num > pb->num)&&(pb->next!=NULL))
      {
          pf=pb;
          pb=pb->next;
      }
      if(pi->num <= pb->num)
      {
          if(head==pb)
            head=pi;
          else
            pf->next=pi;
          pi->next=pb;
      }
      else
      {
          pb->next=pi;
          pi->next=NULL;
      }
   }
   return head;
}

/* 打印链表中各节点信息 */
void printlink(TYPE * head)
{
    printf("Number\t\tAge\n");
    while(head!=NULL)
    {
        printf("%d\t\t%d\n",head->num,head->age);
	    head=head->next;
    }
}

/* 销毁链表, 释放动态分配的内存 */
void destroylink(TYPE * head)
{
    TYPE *p, *q;
     
    p = head;
    while( p != NULL )
    {
         q = p->next;
         free(p);
         p = q;
    }
}