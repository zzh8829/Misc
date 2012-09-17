/*发个半拉作品在这里，疑问很多，怎么才能判断一个人和其他的人见过面呢？
累的我都头疼*/
#include <stdio.h>
#include <malloc.h>
struct net
{
	int nember[3];
	struct net *next;
}
main()
{
	int g=0,d=0,w=0,b=0,j,k,i=0,a[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
	//	v=0,h[]={1,8,6,5,3,12,2,13,4,9,14,11,15,7,10};
	struct net *head=NULL,*trail,*body;
	while(b<7)
	{
	for(j=0;j<5;j++)
	{
		body=(struct net*)malloc(sizeof(struct net));
	for(k=0;k<3;k++)
		{
			body->nember[k]=a[i%15];
			i+=1+w;
			/*if(b>3)
			{
			 body->nember[k]=h[v%15];
			 v+=1+d;
			}
			else
			{
			body->nember[k]=a[i%15];
			i+=1+w;
			}*/
			//(i>315)?(i-=1+w):(i+=1+w);
		}
		if(head==NULL)
		{
			head=body;
			trail=body;
		}

		else
		{
			trail->next=body;
			trail=body;
		}
	}
	w+=6;
	//(b>3)?(d+=6):(w+=6);
	b++;
	}
	trail->next=NULL;
	while(head!=NULL)
	{
        printf(" ");
		for(k=0;k<3;k++)
		{
		g++;
		(g%15)?(printf("%d ",head->nember[k])):
		(printf("%d \n",head->nember[k]));
		}
		printf(" ");
		head=head->next;
	}
}