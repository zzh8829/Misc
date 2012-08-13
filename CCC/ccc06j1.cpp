#include <cstdio>
#include <iostream>
int main()
{

int a[]={461,431,420,0,0};
int b[]={100,57,70,0,0};
int c[]={130,160,118,0};
int d[]={167,266,75,0,0};

int aa,bb,cc,dd;
scanf("%d%d%d%d",&aa,&bb,&cc,&dd);
printf("Your total Calorie count is %d.\n",a[aa-1]+b[bb-1]+c[cc-1]+d[dd-1]);
system("pause");
return 0;
}
