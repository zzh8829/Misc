#include "stdio.h" 
main() 
{ 
int n,s,j,k,p; 
int a[100],b[100];//最多允许100人 
printf("请输入人数："); 
scanf("%d",&n); 
printf("请输入数字："); 
scanf("%d",&s); 
for(k=0;k<n;k++) 
a[k]=k+1; 
for(j=0;j<n-1;j++) 
{ 
p=s%(n-j); 
for(k=0;k<n-p-j;k++)//从新变换数组 
b[k]=a[p+k]; 
for(k=n-p-j;k<n-1-j;k++) 
b[k]=a[k-n+p+j]; 
for(k=0;k<n-1;k++) 
a[k]=b[k]; 
for(k=0;k<n-j-1;k++)//显示数组每次变化后的排列顺序 
printf("%d,",a[k]); 
printf("\n"); 
} 
printf("最后所剩的数字是：%d\n",a[0]); 
} 