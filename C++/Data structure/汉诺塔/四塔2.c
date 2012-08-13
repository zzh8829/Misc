#include <stdio.h>
#include <math.h>
#define MAX_N 1000

int main()
{
double f[MAX_N];
int n,i,j;
double maxvalue,curvalue;
printf("Please input count:");
scanf("%d",&n);
if(n>=MAX_N){
printf("Out of range\n");
return -1;
}
f[1]=1.0,f[2]=3.0;
for(j=3;j<=n;j++){
maxvalue=pow(2,j);
for(i=1;i<j;i++){
curvalue=2*f[i]+pow(2,j-i)-1;
if(curvalue<maxvalue)
maxvalue=curvalue;
else
break;
}
f[j]=maxvalue;
}
for(i=1;i<=n;i++)
printf("m[%d]=%f\n",i,f[i]);
return 0;
} 