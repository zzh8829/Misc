#include <stdio.h> 
#include <stdlib.h>

struct node
{
	long factorarray;
	struct node *next;
};
struct node *head,*q,*p;

void factoring(long n) 
{ 
long i; 
for(i=2; i<=n/2; i++)
{ 
	if(n%i==0)
	{  
		q=(struct node*)malloc(sizeof(struct node));
		q->factorarray=i;
		q->next=NULL;
		if(head==NULL)
		{
			head=q;
			p=q;
		}
		else
		{
			p->next=q;
			p=q;
		} 
	} 
} 
}

void deletes()
{
	while(head!=NULL)
	{
		p=head;
		head=p->next;
		free(p);
	}
}

void main() 
{ 
long num; 
head=NULL;
printf("Please input the number you want to find factors: "); 
while(scanf("%ld", &num)) { 
printf("The factors of the number %ld is: \n", num); 
factoring(num); 
p=head;
while(p!=0) 
{
printf("* %ld", p->factorarray);
p=p->next;
} 
printf("\nPlear input the number you want to find factors: ");
deletes(); 
} 
} 