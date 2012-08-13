
#include <stdio.h>
main() 
{ 
int n,s,j,k,p; 
int a[100];//最多允许100人 
printf("请输入人数："); 
scanf("%d",&n); 
printf("请输入数字："); 
scanf("%d",&s); 
for(j=0;j<100;j++) 
a[j]=0; 
for(j=0;j<n;j++) 
a[j]=j+1; 
k=s-1; 
a[s-1]=0; 
for(j=0;j<n;j++) 
printf("%d,",a[j]); 
printf("\n"); 
for(j=0;j<n-2;j++) 
{ 
for(p=0;p<s;p++) 
{ 
do 
{ 
if(k==n-1) 
k=0; 
else 
k++; 
} 
while(a[k]==0); 
} 
a[k]=0;//将报S者清零 
for(p=0;p<n;p++)//显示清零后结果 
printf("%d,",a[p]); 
printf("\n"); 

} 
for(j=0;j<n;j++) 
{ 
if(a[j]!=0) 
printf("最后剩下的数是：%d",a[j]); 
} 
printf("\n"); 
} 