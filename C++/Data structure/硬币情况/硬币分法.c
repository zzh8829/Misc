#include "stdio.h" 
main() 
{ 
	int i,j,k,s,n=0;    /*  i,j,k 分别代表 一分硬币、二分硬币和五分硬币*/ 
 	printf("%5c%5c%5c\n",'1','2','5'); 
 	for(i=1;i<100;i++) 
 		for(j=1;j<50;j++) 
 			for(k=1;k<20;k++) 
			{ 
				s=1*i+j*2+k*5; 
 				if (s==100) 
				{ 
  					printf("%5d%5d%5d\n",i,j,k);
  					++n; 
 				} 
			} 
	printf("The ways is %d\n",n); 
} 