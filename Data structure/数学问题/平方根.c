#define Epsilon 1.0E-6  /*控制解的精度*/ 
#include <stdio.h>
#include <math.h> 

main() 
{
	float num,pre,this; 
 	do 
	{   
 		scanf("%f",&num);/*输入要求平方根的数*/ 
	}while(num<0); 
	if (num==0) 
 		printf("the root is 0"); 
	else 
	{
		this=1; 
  		do
  		{ 
  			pre=this;
   			this=(pre+num/pre)/2; 
		}while(fabs(pre-this)>Epsilon);/*用解的精度，控制循环次数，fabs()是求绝对值的函数*/ 
	} 
	printf("the root is %f",this); 
} 