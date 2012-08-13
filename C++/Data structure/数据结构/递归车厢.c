/**********递归题改为非递归题实例 车厢********/
#include<stdio.h> 

#define MAX 4 

int stack[MAX],p=-1; 

struct 
{ 
  int num; 
  int sign; 
}train[MAX]; 

void sub() 
{ 
  int inc; 
  if(p==MAX-1) 
    { 
      for(inc=0;inc<=p;inc++)
        printf("%3d",stack[inc]); 
      printf("\n"); 
    }
  else 
    {  
      for(inc=0;inc<MAX;inc++) 
        if(train[inc].sign==0) 
          { 
            train[inc].sign=1; 
            stack[++p]=train[inc].num; /*进栈*/
            sub();                     /*递归*/
            train[inc].sign=0; 
            p--;                       /*出栈*/ 
          } 
    } 
} 

main() 
{ 
  int temp; 
  for(temp=0;temp<MAX;temp++) 
    { 
      train[temp].num=temp+1; 
      train[temp].sign=0; 
    } 
  printf("The result is:\n"); 
  sub(); 
} 

