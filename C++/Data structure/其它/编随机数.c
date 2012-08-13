/*自编随机数*/

#include"sys\types.h"
#include"sys\timeb.h"
#include<stdio.h>

#define ALPHA 3.95 /*宏定义ALPHA值为3.95*/

double init_value(void);
double random(void);

void main()
{
    float rdnmb;int m;
    rdnmb=random()*10+1; /* random()得到0--0.9的小数*/
    m=rdnmb;
    printf("\n%f\n",rdnmb);
    printf("\n%d\n",m);
    getch();
}

double random(void)
{
   static double f=-1.0;
   if(f==-1.0)
     f=init_value();
   else
     f=ALPHA*f*(1.0-f);
   return f;
}

double init_value(void)
{
   double f0;
   struct timeb *pr;
   for(;;)
     {
       ftime(pr);
       f0=pr->millitm*0.9876543*0.001;
       if(f0<0.001)
         continue;
       break;
     }
   return f0;
}