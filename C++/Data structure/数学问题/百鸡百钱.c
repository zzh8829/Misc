#include<stdio.h>
main()
{
	int x,y,z,j=0;
	for(x=0;x<=20;x++)
	{
		y=(100-7*x)/4;
		z=100-x-y;
		if(z%3==0&&y>0&&5*x+3*y+z/3==100)
			printf("%2d: cock=%2d hen=%2d chicken=%2d\n",++j,x,y,z);
	}
}