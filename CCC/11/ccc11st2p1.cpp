#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct Score
{
	long long s;
	double r;
	long long p;
}s[100005];

bool cmp(const Score& a,const Score& b)
{
	return b.s < a.s;
}

int main()
{
	int n;
	long long k;
	scanf("%d",&n);
	s[0].p=0;
	for(int i=1;i<=n;i++)
		scanf("%lld%lf",&s[i].s,&s[i].r);
	sort(s+1,s+n+1,cmp);
	scanf("%lld",&k);
	for(int i=1;i<=n;i++)
	{
		s[i].p = 2*s[i].r-s[i-1].p-1;
		if(s[i].s==k)
		{
			printf("%lld\n%lld\n",s[i-1].p+1,s[i].p);
			break;
		}
	}
	system("pause");
	return 0;
}
