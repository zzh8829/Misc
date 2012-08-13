#include<stdio.h>
main() 
{int a[6],i,j,k=2520/6; 
for(i=0,j=8;i<6;i++,j--) 
  {if(i==0) 
     a[i]=k/2*j/(j-1); 
   else 
     a[i]=k*j/(j-1);} 
for(i=5,j=4;i>=0;i--,j++) 
  {if(i!=0) 
     a[i]=a[i]-a[i-1]/j; 
   printf("NO:%d=%d\n",i+1,a[i]);} 
} 