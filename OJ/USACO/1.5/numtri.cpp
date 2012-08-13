/*
ID: zzh8829
PROG: numtri
LANG: C++
*/
#include <iostream>
#include <fstream>
using namespace std;
long long n,num,dp[1001][1001];

long long max(long long a, long long b)
{
	if (a>b)
	return a;
	return b;
}

int  main()
{
	ifstream cin("numtri.in");
	ofstream cout("numtri.out");
	cin >> n;
	for(long long i=0;i!=n;i++)
		for(long long j=0;j!=i+1;j++)
		{
			cin>>num;
			dp[i][j]=num;
		}
	for(long long i=n-2;i!=-1;i--)
		for(long long j=0;j!=i+1;j++)
			dp[i][j]+= max(dp[i+1][j],dp[i+1][j+1]);
	cout << dp[0][0] <<endl;
	return 0;
}
