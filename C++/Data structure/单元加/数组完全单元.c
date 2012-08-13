#include "stdio.h"
#include"conio.h"
int k=0;
int a[100];
void num(int number)
{
int n1,j,temp=k,i;
for(j = 1 ; j <= number/2 + 1 ; j ++)
{
	if(number-j <= 0)  
		break;
	n1 = number - j;
	a[k ++] = j;
	if(n1 > 1)
		num(n1);
	else
	{
		a[k ++] = 1;
		printf("\n");
		for(i = 0 ; i < k-1 ; i ++)
			printf("%d+",a[i]);
		printf("%d",a[k-1]);
	}
	k=temp;
}
printf("\n");
for(i = 0 ; i < k ;i ++)
printf("%d+",a[i]);
printf("%d",number);
}
void main()
{
int m;
scanf("%d",&m);
num(m);
}  