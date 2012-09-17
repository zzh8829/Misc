/*** P402 ***/

#include <stdio.h>
#include <malloc.h>

#define MAXN 1000

void pnext(int a[],int k)
{
	int *b,m=a[0],i,j,r,carry;
	b=(int *)malloc(sizeof(int)*(m+1));
	for(i=1;i<=m;i++)
		b[i]=a[i];
	for(j=1;j<k;j++)
	{
		for(carry=0,i=1;i<=m;i++)
		{
			r=(i<=a[0]?a[i]+b[i]:a[i])+carry;
			a[i]=r%10;
			carry=r/10;
		}
		if(carry)
			a[++m]=carry;
	}
	free(b);
	a[0]=m;
}

void write(int *a,int k)
{
	int i;
	printf("%4d!=",k);
	for(i=a[0];i>0;i--)
		printf("%d",a[i]);
	printf("\n\n");
}

void main()
{
	int a[MAXN],n,k;
	printf("Enter the number n:  ");
	scanf("%d",&n);
	a[0]=1;
	a[1]=1;
	write(a,1);
	for(k=2;k<=n;k++)
	{
		pnext(a,k);
		write(a,k);
		getchar();
	}
}