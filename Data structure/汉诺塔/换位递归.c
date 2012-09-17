#include <stdio.h>

void move(char x,char y) 
{printf("%c-->%c\n",x,y);} 
void hanoi (int n,char one ,char two,char three) 
{
if(n==1) move (one ,three); 
else 
{
hanoi (n-1,one,three,two); 
move(one,three); 
hanoi(n-1,two,one,three); 
} 
} 
main() 
{int m; 
printf("input the number of diskes:"); 
scanf("%d",&m); 
printf("the step to moving %3d diskes:\n",m); 
hanoi(m,'A','B','C'); 
} 
/*运行情况如下： 
input the number of diskes:3 回车 
the step to moving 3 diskes: 
A-->C 
A-->B 
C-->B 
A-->C 
B-->A 
B-->C 
A-->C 

书上说hanoi(n-1,one,three,two);是把“one”上的n-1个往“two”上移，接着move(one,three);然后是hanoi(n-1,two,one,three)即把“two”上的n-1个往“three”上移；
           |h(2,1,3,2)|h(1,1,2,3)=>move(1,3)   <-----1------ 
           |          |  move(1,2)             <-----2------ 
           |          |h(1,3,1,2)=>move(3,2)   <-----3------ 
           |move(1,3)                          <-----4------ 
           | 
h(3,1,2,3) |          |h(1,2,3,1)=>move(2,1)   <-----5------ 
           |h(2,2,1,3)|move(2,3)               <-----6------- 
           |          |h(1,1,2,3)=>move(1,3)       <-----7------ 
           | 
*/ 

