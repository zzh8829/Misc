#include<stdio.h>


struct fsb
{
	int  data;
	int  flag;
    	struct fsb * next;
};
main()
{
	struct fsb  *p,*head,*sta,*end;
	int i,cishu,j;
	end=(struct fsb *)malloc(sizeof(struct fsb));
	end->data=0;
	end->flag=0;
	end->next=NULL;
	head=p=end;
	
	for (i=2;i<=10;i++)
	{
  		end=(struct fsb *)malloc(sizeof(struct fsb));
  		end->data=i-1;
  		end->flag=0;
  		end->next=NULL;
  		p->next=end;
  		p=end;
	}
	p->next=NULL;
	printf("\nµπ–Ú«∞£∫");
	p=head;	
	for(i=1;i<=10;i++)
	{
		printf("%d ",p->data);
		p=p->next;
	}
/*************************/
	p=NULL;
	while(head->next != NULL)
	{
  		sta=head; 
  		head=head->next;
  		sta->next=p;
  		p=sta;
  	}
	head->next=sta;
	printf("\nµπ–Ú∫Û£∫");
	p=head;
	for(i=1;i<=10;i++)
	{
		printf("%d ",p->data);
		p=p->next;
}
/*************************/
}