/* 链表建立程序 */

#include"stdio.h"
#include<malloc.h>

#define NULL  0
#define LEN sizeof(struct student)

struct student
{long num;
int score;
struct student *next;
};
int n; /*全局变量n*/
struct student *creat()
{struct student *head;
  struct student *p1,*p2;
  n=0;
  p1=p2=(struct student *)malloc(LEN);
  scanf("%ld%d",&p1->num,&p1->score);/*%d和%d之间不应该有逗号*/
  head=NULL;
  while (p1->num!=0)
    {n=n+1;
    if(n==1) head=p1;
    else p2->next=p1;
    p2=p1;
    p1=(struct student*)malloc(LEN);
    scanf("%ld%d",&p1->num,&p1->score);
    }
    p2->next=NULL;
    return(head);
  }
void print(head)
struct student *head;
{struct student *p;
  p=head;         /*在这里付值才可以*/
  printf("\Now,These %d records are:\n",n);
  if(head!=NULL)
  do
  {printf("%ld%5d\n",p->num,p->score);
  p= p->next;
  } while(p!=NULL);
}
void main()
{struct student *head;
printf("input records:\n");
head= creat();
print(head);
}