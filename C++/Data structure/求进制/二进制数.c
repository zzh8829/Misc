/*递归法求二进制数*/

#include<stdio.h>

void printb(int x,int n);

void main()
{
    int x;
    printf("input number:");
    scanf("%d",&x);
    printf("number of decimal form: %d\n",x);
    
    printb(x,sizeof(int)*8);
    putchar('\n');
}


void printb(int x,int n)
{
    if(n>0)
    {
        putchar('0'+( (unsigned)(x & (1<<(n-1) ) )>>(n-1)));
        printb(x,n-1);
    }
}