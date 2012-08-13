#include<stdio.h> 
int sub(int n) 
{ 
if(n==1){ 
static int i=0; 
do 
{ 
i++; 
} 
while(i%5!=0); 
//printf("*%d*",i); 
return(i+1); 
} 
else 
{ 
int temp; 
do 
{ 
temp=sub(n-1); 
} 
while(temp%4!=0); 
//printf("*%d*",temp); 
return(temp/4*5+1); 
} 
} 
main() 
{ 
int total; 
total=sub(5); 
printf(" %d\n",total); 
} 

