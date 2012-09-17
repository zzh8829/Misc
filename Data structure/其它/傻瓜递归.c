#include <stdio.h>
main() 
{ int m=1,n=1,s; 
 s=akm(m,n); 
printf("%d",s); 
} 

akm(int m,int n) 
{ if(m==0) 
    return n+1; 
else if(m!=0&&n==0) 
   akm(m-1,1); 
else if(m!=0&&n!=0) 
   akm(m-1,akm(m,n-1)); 
} 