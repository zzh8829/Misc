#include <stdio.h> 

int result=0,valuess=0,k,y=1,l; 
char a,b[1],d[50],r; 

int main (void)
{ 
	while (1)
	{
		int j=0;
       		printf ("%d",result); 
       		printf ("please input a char and number\n"); 
	   	while ((a=getchar())!='\n') 
		{   
			b[ j ]=a; 
		}
		
       		while((r=getchar())!='\n')
	   	{
			d[j]=r;
		   	j++;
	   	}
	   	for(k=0;k<j;k++)
	   	{
			   for(l=0;l<k;l++)
				   y*=10;
		   	   valuess+=((int)d[k]-48)*y;
	   	}
	   	y=1;j=0;
       		if ((b[0]=='q')||(b[0]=='Q')) 
       		{ 
			break;
		} 
       		switch (b[0]) 
       		{ 
			case '+': 
			{
               			result += valuess; 
               			break; 
			}
			case '-':
			{
           	    		result -= valuess; 
           			break; 
			}
			case '*':
			{
               			result *= valuess; 
               			break;
			}
			case '/':
			{
               			if (valuess==0) 
           				printf ("wrong ,please input a number\n"); 
               			else 
                   			result /= valuess; 
               			break;
			}
       			default:
		   	{
           			printf ("unknow the operator%c","a\n"); 
           			break;
		   	}
		}
		valuess=0;	   
	} 
	return (0); 
}
