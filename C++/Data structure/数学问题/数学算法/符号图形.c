#include<stdlib.h> 
#include<stdio.h>
#include<math.h> 
void just(int); 
void fall(int); 
void diamond(int); 
main() 
{ 
int hose,row; 
char ch; 
//clrscr(); 
printf("\t\t\t1.jut     2.fall     3.diamond\n"); 
printf("请输入选择，和宽度："); 
scanf("%d%d",&hose,&row); 
while(row!=0)
{
if(row<17&&row>-17)
{
switch(hose) 
{ 
case 1: 
{
   printf("Ensample:"); 
   just(row);
}
break; 
case 2: 
{
   printf("Ensample:"); 
   fall(row); 
}
   break; 
case 3: 
{
    printf("Ensample:"); 
    diamond(row); 
}break; 
default: 
	{
    printf("Error Enter!!"); 
    getch(); 
    exit(1); 
	}
} 
}//end if
else
{
	getch();
	exit(1);
}
printf("请输入选择，和宽度："); 
scanf("%d%d",&hose,&row); 
}
}
///***********define function*********/  

void just(int choose) 
{ 
	int i,s,j; 
      for(i=1;i<=choose;i++) 
      { 
         printf("\n\t\t\t\t\t"); 
          for(j=1;j<=2*i-1;j++) 
           { 
             printf("\b"); 
            } 
          for(s=1;s<=2*i-1;s++) 
          { 
          printf("* ");  /*注意这里面的空格，一定要空一格，不然结果全然不对*/ 
          } 
        } 
printf("\n"); 
} 

void fall(int choose) 
{ 
int i,s,j; 
for(i=abs(choose);i>=1;i--) 
{ 
printf("\n\t\t\t\t\t"); 
for(j=1;j<=2*i-1;j++) 
{ 
printf("\b"); 
} 
for(s=1;s<=2*i-1;s++) 
{ 
printf("* ");  ///**一样的请注意空一格***/ 
} 
} 
printf("\n"); 
} 

void diamond(int choose) 
{ 
int i,s,j; 
int a,b,c; 
for(i=1;i<=abs(choose);i++) 
{ 
printf("\n\t\t\t\t\t"); 
for(j=1;j<=2*i-1;j++) 
{ 
printf("\b"); 
} 
for(s=1;s<=2*i-1;s++) 
{ 
printf("* "); 
} 
} 

for(a=abs(choose);a>=1;a--) 
{ 
if(a==abs(choose))
printf("\r\t\t\t\t\t"); 
else 
printf("\n\t\t\t\t\t"); 
for(b=1;b<=2*a-1;b++) 
{ 
printf("\b"); 
} 
for(c=1;c<=2*a-1;c++)
{ 
printf("* "); 
} 
} 
printf("\n"); 
} 