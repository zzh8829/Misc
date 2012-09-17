#include <stdio.h>
int factr(int n) 
{ 
	int result,r; 
	if (n==1) return 1; 
		result=factr(n-1)*n; 
	return result; 
} 

main() 
{ 
	int a;
 	a=factr(5); 
 	printf("%d",a); 
} 