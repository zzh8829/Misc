#include <stdio.h>
int c(x,y);
main()
{
int i,j,n=13;
printf("N=");
while(n>12)
scanf("%d",&n);
for(i=0;i<=n;i++)
{
for(j=0;j<12-i;j++)
printf(" ");
for(j=1;j<i+2;j++)
printf("%6d",c(i,j));
printf("\n");
}
}

int c(x,y)
int x,y;
{
int z;
if((y==1)||(y==x+1))return(1);
z=c(x-1,y-1)+c(x-1,y);

return(z);
}