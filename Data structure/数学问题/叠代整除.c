#include <stdio.h>
quyu(long int m)
{
 int x=0,y=0,z=0,he=0;
	 if(m%3==0)
		 x=1;
	 if(m%5==0)
		 y=2;
	 if(m%7==0)
		 z=4;
 he=x+y+z;
 return he;
}
main()
{
long int m;
scanf("%d",&m);
switch(quyu(m))
{
case 0:
	printf("不能被任何数整除 ");
	break;
case 1:
	printf("能被3整除 ");
    break;
case 2:
	printf("能被5整除 ");
	break;
case 3:
	printf("能被3，5整除 ");
    break;
case 4:
	printf("能被7整除 ");
	break;
case 5:
	printf("能被3，7整除 ");
    break;
case 6:
	printf("能被5，7整除 ");
	break;
case 7:
	printf("能被3，5，7整除 ");
    break;
}
}