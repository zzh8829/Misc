#include <stdio.h> 
#include <stdlib.h> 

void main() 
{ 
int total = 0; 
int n,b;
scanf("%d%d",&n,&b);
while(1) 
{ 
int i = ++total; 
int j; 
for(j = 0; j< n;j++, i = (i-b)*(n-1)/n) 
{ 
  if((i - b) % n == 0) 
      continue; 
  else 
      break; 
 } 
 if ( j == n ) 
     break; 
} 
printf("The result is %d", total); 
} 
