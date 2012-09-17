#include<stdio.h>
#include<math.h>
main()
{
double y;
int x,m;
for(y=10;y>=-10;y--)
{
m=2.5*sqrt(100-y*y);
for(x=1;x<30-m;x++)
printf(" ");
printf("*");
for(;x<30+m;x++)
printf(" ");
printf("*\n");
}
}