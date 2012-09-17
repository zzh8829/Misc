#include <math.h>
#include <stdio.h>
main()
{
double x,d,t;
scanf("%lf",&x);
d=pow(x,x);
t=d-(x-1);
printf("%lf\n",t);
}