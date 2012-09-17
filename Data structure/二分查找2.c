#include "stdio.h"

typedef struct
{
	char *elem;
	int length;
}sstable;

void create(char **t)
{
	int i;
	static char a[11];
	*t=a;
	for(i=1;i<=10;i++)
	{
		printf("A[%d] is:",i);
		scanf("%c",&a[i]);
  		if (a[i] != '\n') getchar();
	}
}

int searth(char *t,char k)
{
	int i;
	for (i=10;i>=0 && t[i]!=k ;i--);
		return i;
}

void output(char *t)
{
	int i;
	for (i=1;i<=10;i++)
		printf("\n            A[%d] is %c",i,t[i]);
}

void px(char *t)
{
	char s;
	int i,j;
	for (i=1;i<=10;i++)
  		for (j=i+1;j<=10;j++)
  		{
  			if (t[i]>t[j])  {s=t[i];t[i]=t[j];t[j]=s;}
  		}
}

int search_bin(char *t,char k)
{
	int low=1,high=10,mid;
	while (low<=high)
	{
		mid=(low+high)/2;
		if (k==t[mid]) return mid;
		else if (k<t[mid]) high=mid-1;
     		else low=mid+1;
	}
	return 0;
}

main()
{
	char *t,k;
	int s;
	create(&t);
	output(t);
	
	printf("\nplease input you search char:");
	k=getchar();
	s=searth(t,k);
	
	if (s>=0) printf("1: use search find is A[%d]\n",s);
	else printf("1:can not find it\n");

	px(t);
	output(t);

	s=search_bin(t,k);
	if(s==0) printf("\n1:can not find it \n");
	else printf("\n2:use search_bin find is A[%d]\n",s);

	getchar();
}
