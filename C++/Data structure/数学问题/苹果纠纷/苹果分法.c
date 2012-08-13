#include<stdio.h>
main()
{
	int b[6],k=2520/6,j,m,x,y,p=0;
	y=x=k-k/2;
	for(m=0,j=7;m<6;m++,j--)
	{
		b[m]=(k-x)+y/j;
		x=y/j;
		y=k;
	}
	for(m=0,y=1;m<6;m++,y++)
	{
		p=p+b[m];
		printf("%d原来有: %d\n",y,b[m]);
	}
	printf("合为: %d\n",p);
	getch();
}