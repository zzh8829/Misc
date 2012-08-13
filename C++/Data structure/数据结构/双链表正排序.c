#include<stdio.h> 
#include<stdlib.h> 
#include<malloc.h> 
struct list{ 
  int data; 
  struct list *next; 
  struct list *pre; 
  }; 
typedef struct list node; 
typedef node *link; 
link front=NULL,rear,ptr,head=NULL; 

link push(int item){ 
link newnode=malloc(sizeof(node)); 
 newnode->data=item; 
 if(head==NULL)
 {
 head=newnode; 
 head->next=NULL; 
 head->pre=NULL;
 rear=head;
 }
 else
 {
 rear->next=newnode;
 newnode->pre=rear;
 newnode->next=NULL;
 rear=newnode;
 }
 return head; 
 } 

void makenull(){           
 front=NULL; 
 rear=NULL; 
 } 

empty(){ 
  if(front==NULL) 
   return 1; 
  else 
   return 0; 
  } 

int tops(){ 
   if(empty()) 
    return NULL; 
   else 
    return rear->data; 
   } 

void pop(){ 
   if(empty()) 
    printf("stack is empty!\n"); 
   else 
    rear=rear->pre; 
   } 

void display(link l){ 
    link p; 
    p=l; 
    while(p!=NULL){ 
      printf("%d->",p->data); 
      p=p->next; 
    } 
} 


void main(){ 
int n,i; 
printf("input your first data!\n"); 
scanf("%d",&n); 
front=push(n); 
   /*another data*/ 
for(i=0;i<3;i++) 
{ 
 printf("input:\n"); 
 scanf("%d",&n); 
 push(n); 
} 
 ptr=front; 
 display(ptr); 
 printf("\n Please enter any key to pop"); 
getch();
 pop(); 
 ptr=front; 
 display(ptr); 
getch();

} 