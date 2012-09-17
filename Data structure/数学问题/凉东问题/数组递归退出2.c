#include <stdio.h>
void f2();
int a[13],k,j=1,b=13,n=0;
main()
{	
for(k=0;k<b;k++)
a[k]=j++;
f2();
for(k=0;k<b;k++)
if(a[k]!=0)
printf("第%d个人没有出局\n",k+1);
getch();
}
void f2()
{
for(k=0;k<b;k++)
	{
		if(a[k]%10==3)
		{
			a[k]=0;
			n++;

		}
		if(a[k]!=0)
			a[k]=j++;
		
	}
if (n<b-1)
			f2();
}