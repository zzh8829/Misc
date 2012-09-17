   # include "stdio.h" 
 # include "stdlib.h" 
    struct node{ 
      int values; 
        struct node *next; 
       }; 
    struct node *create(int [],int); 
      void sort (struct node **); 
       int test_data[20000]={5,9,3,4,5,7,8}; 
   main() 
 { struct node *h,*p; 
h=create(test_data,20000); 
for(p=h;p;p=p->next) printf("%2d",p->values); 
printf("\n"); 
sort(&h); 
  for(p=h;p;p=p->next) printf("%2d" ,p->values); 
    printf("\n"); 
} 
struct node *create (int a[],int n) 
{struct node *h,*q; 
for(h=NULL;n;n--) 
{ q=(struct node *) malloc(sizeof(struct node)); 
q->values=a[n-1]; 
q->next=h; 
h=q; 
} 
return h; 
} 
void sort (struct node **h) 
{ struct node *q,*p,*r,*s,*h1; 
h1=p=(struct node *)malloc(sizeof(struct node)); 
p->next=*h; 
while(p->next!=NULL) 
{ q=p->next; 
 r=p;                   
while (q->next!=NULL) 
{ if(q->next->values<r->next->values) r=q; 
  q=q->next; 
  } 
  if(r!=p) 
   { s=r->next;       
     r->next=s->next; 
     s->next=p->next; 
     p->next=s; 
     }                           
     p=p->next; 
     } 
     *h=h1->next;/*问题：h1在程序中做了啥用？  */
     free(h1);                  
     } 
 
