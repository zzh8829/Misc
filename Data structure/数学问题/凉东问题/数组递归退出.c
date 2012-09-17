#include <stdio.h>
void f2();
int a[13],i,j,b=13;
main()
{	
f2();
for(j=0;j<b;j++)
  a[j]=j+1;
for(j=0;j<b;j++)
printf("%d\n",a[j]);
getch();
}
void f2()
{

int n=0;
for(i=0;i<b;i++)
	{
       a[i]=i+1; 
		if(a[i]%10==3)
		{
			n++;
		}
		
	}
     b=i-n;
	for(j=0;j<b;j++)
		if(a[j]%10==3)
			f2();
}

