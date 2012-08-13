#include <cstdio>
#include <iostream>
using namespace std;
int nums[32002];

int main()
{
int n;
int in;
scanf("%d",&n);
for(int i=0;i!=n;i++)
{
scanf("%d",&in);
nums[in]++;
}
for(int i=1;i!=32001;i++)
if(nums[i])
printf("%d\n",i);
system("pause");
return 0;
}
