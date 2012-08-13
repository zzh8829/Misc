#include "stdio.h"
void num(int number,int i)
{
int k,n=number;
while(n>i)
{
  n=n-i;
  if((n+i)!=number)
    {
      for(k=0;number-k>n;k=k+i)
          printf("%d+",i);
      printf("%d\n",n);
  }
  else
    printf("%d+%d\n",i,n);
}
}
void main()
{
int j,m;
printf("input:");
scanf("%d",&m);
for(j=1;j<=m/2;j++)
    num(m,j);
}