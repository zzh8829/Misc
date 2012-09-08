#include <iostream>
#include <cstdio>
using namespace std;
int pins[30003];
int sum[30003];
int dp[503][30003];
inline int MAX(int a,int b)
{
	return a>b? a:b;
}
int main()
{
	int t,n,k,w;
	cin >> t;
	for(int cs=0;cs!=t;cs++)
	{
		cin >> n >> k >>w;
		for(int i=0;i!=n;i++)
			scanf("%d",&pins[i]);
		int s=0;
		for(int i=0;i!=w;i++)
			s += pins[i];
		sum[0]=s;
		for (int i=1; i!=n-w+1;i++)
		{
			s= s-pins[i-1]+pins[i+w-1];
			sum[i] = s;
		}
		for(int i=n-w+1;i!=n;i++)
		{
			s= s- pins[i-1];
			sum[i] = s;
		}
		for(int i = 1; i<=k;i++)
		for(int j= n-1 ; j>=0;j--)
		{
			if(j>=n-w)
			dp[i][j] = sum[j];
			else
			dp[i][j]=MAX(dp[i-1][j+w]+sum[j],dp[i][j+1]);
		}
		cout << dp[k][0] <<endl;			
	}	
	system("pause");
	return 0;
}
