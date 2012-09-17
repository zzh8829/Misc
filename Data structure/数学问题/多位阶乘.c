/*计算 30000 的阶乘 ！*/

/* This file "jiech2.c" 
  created at 2001-08-24 20:15:22
  by LeiPeng .
*/

#include <conio.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 0X7000

int a[MAXN];

int main(int argc,char *argv[])
{
    int n,m,i,j,c,t;
    printf("Enter n(n>=2) :");
    while(1)
    {
        scanf("%d",&n);
        if(n>=2&&n<=3276) break;
        printf("must be 2<=n<=3276");
    }
    a[0]=1; m=1;
    for(i=2;i<=n;i++)
    {
        for(c=0,j=0;j<m;j++)
        {
            t=a[j]*i+c;
            a[j]=t%10;
            c=t/10;
        }
        while(c)
        {
            a[m++]=c%10;
            c/=10;
        }
    }
    printf("%d!=\n",n);
    for(i=m-1;i>=0;i--) putchar(a[i]+0x30);    
    printf("\npress any key to continue .\n");
    getch();
    return 0;
} 
/*3000!得结果超出了电脑能显示得范围，所以最好采用数组来记录每位*/