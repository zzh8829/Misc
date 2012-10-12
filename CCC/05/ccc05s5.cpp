#include <cstdio>
#include <algorithm>
using namespace std;
pair<int,int> s[100001];
int bit[100001],p[100001];
int n,t;
long long sum;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&(s[i].first));
		s[i].second = i;
	}
	sort(s+1,s+n+1);
	for(int i=1;i<=n;i++)
		p[s[i].second]=n-i+1;
	for(int i=1;i<=n;i++)
	{
		t= p[i];
		while(t>0)
		{
			sum+=bit[t];
			t-= (t&(-t));
		}
		t = p[i];
		while(t<=n)
		{
			bit[t]+=1;
			t+= (t&(-t));
		}
	}
	printf("%.2f",(sum+n)/(float)n);
}
