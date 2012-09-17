/*这是一个大正数加法问题TC中应该完全可以运行。 */

#include<stdio.h> 
#include<malloc.h> 

#define HUN 10000

typedef struct node 
{ 
	int data; 
	struct node *next; 
}NODE;

NODE *insert(NODE *u,int num) /*声明返回指针函数*/
{ 
	NODE *v; /*声明结构指针*/
	v=(NODE*)malloc(sizeof(NODE)); 
	v->data=num; 
	u->next=v; 
	return(v); 
} 

NODE *addint(NODE *p,NODE *q) 
{ 
	NODE *pp,*qq,*r,*s,*t; 
	int total,number,carry; 
	pp=p->next;
	qq=q->next; 
	s=(NODE*)malloc(sizeof(NODE)); 
	s->data=-1; 
	t=s; 
	carry=0; 
	while(pp->data!=-1&&qq->data!=-1) 
	{ 
		total=pp->data+qq->data+carry; 
		number=total%HUN; 
		carry=total/HUN; 
		t=insert(t,number); 
		pp=pp->next;     
		qq=qq->next; 
	} 
	r=(pp->data!=-1)?pp:qq; 
	while(r->data!=-1) 
	{ 
		total=r->data+carry; 
		number=total%HUN; 
		carry=total/HUN; 
		t=insert(t,number); 
		r=r->next; 
	} 
	if(carry) 
		t=insert(t,1); 
	t->next=s; 
return(s); 
} 

NODE *inputint(void) 
{ 
	NODE *s,*ps,*qs; 
	struct number 
	{ 
		int num; 
		struct number *np; 
	}*p,*q; 

	int i,j,k; 
	long sum; 
	char c; 
	p=NULL; 
	while((c=getchar())!='\n') 
		if(c>='0'&& c<='9') 
		{ 
			q=(struct number *)malloc(sizeof(struct number)); 
			q->num=c-'0'; 
			q->np=p; 
			p=q; 
		}
		 
	s=(NODE*)malloc(sizeof(NODE)); 
	s->data=-1; 
	ps=s; 
	while(p!=NULL) 
	{ 
		sum=0;i=0;k=1; 
		while(i<4&&p!=NULL) 
		{ 
			sum=sum+k*(p->num); 
			i++;p=p->np;k=k*10; 
		} 
		qs=(NODE*)malloc(sizeof(NODE)); 
		qs->data=sum; 
		ps->next=qs; 
		ps=qs; 
	} 
	ps->next=s; 
	return(s); 
} 

printint(NODE *s) 
{ 
	if(s->next->data!=-1) 
	{ 
		printint(s->next); 
		if(s->next->next->data==-1) 
			printf("%d",s->next->data); 
		else
		{ 
			int i,k=HUN; 
			for(i=1;i<=4;i++,k/=10) 
				putchar('0'+s->next->data%(k)/(k/10)); 
		} 
	} 
} 

main() 
{ 
	NODE *s1,*s2,*s; 
	NODE *inputint(),*addint(),*insert_after(); 
	s1=inputint(); 
	s2=inputint(); 
	printf("S1="); 
	printint(s1); 
	printf("\n"); 
	printf("S2="); 
	printint(s2); 
	printf("\n"); 
	s=addint(s1,s2); 
	printf("S1+S2=");printint(s);printf("\n"); 
} 