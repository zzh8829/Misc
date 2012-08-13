#include "stdio.h"
int num(int a,int i,int n)
{
int j=0,k;
if(a<=0)
  return a;
  k=num(a-i,i,n+i)+i;
  for(j=i;j<=n;j=j+i)
    printf("%d+",i);
  printf("%d\n",k);
  return k;
}
void main()
{
int number,n;
printf("input:");
scanf("%d",&number);
for(n=1;n<=number/2;n++)
    num(number-n,n,n);
}