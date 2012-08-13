#include <cstdio>
#include <algorithm>
using namespace std;
int nums[500000];
int main()
{
int n = 0;
scanf("%d",&n);
int in;
int t=0;
for(int i=0;i!=n;i++)
{
scanf("%d",&in);
nums[t++]=in;
}
sort(nums,nums+t);
for(int i=0;i!=t;i++)
{
printf("%d\n",nums[i]);
}
system("pause");
return 0;
}
