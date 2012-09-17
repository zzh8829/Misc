#include<stdio.h> 
#include<malloc.h> 
struct node{ 
        int key; 
        struct node *next; 
        }; 
void creat_link(struct node *); 
main() 
{ 
 struct node *head=NULL; 
 creat_link(head);/*这里可以这么调用吗？*/   
} 
void creat_link(struct node *head_node) 
{ 
struct node *p,*q,*Temp; 
int number; 
printf("Please input data:[-1 is End]\n"); 
scanf("%d",&number); 
while(number!=-1){ 
 q=(struct node *)malloc(sizeof(struct node)); 
 q->key=number; 
 if(head_node==NULL ){ 
           head_node=q; 
           p=q; 
          } 
  else{ 
        p->next=q; 
        p=q; 
        } 
   scanf("%d",&number); 
  } 
p->next=NULL; 
 Temp=head_node; 
 while(Temp!=NULL){ 
  printf("%d\n",Temp->key); 
  Temp=Temp->next;
 }
} 
 