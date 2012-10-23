/*
ID: zzh8829
PROG: rockers
LANG: C++
*/
#include <iostream>
#include <fstream>
using namespace std;

int dp[40][40][40];
int m[40];
int N,T,M;

int main()
{
#ifndef LOCAL
	ifstream cin("rockers.in");
	ofstream cout("rockers.out");
#endif
	cin >> N >> T >> M;
	for(int i=1;i<=N;i++)
		cin >> m[i];
	
	for(int i=1;i<=N;i++)
	for(int j=1;j<=M;j++)
	for(int k=1;k<=T;k++)
	{
		dp[i][j][k] = max(dp[i-1][j][k],dp[i][j-1][T]);
		if(m[i]<k)
		dp[i][j][k] = max(dp[i][j][k],dp[i-1][j][k-m[i]]+1);  
		if(m[i]==k)
		dp[i][j][k] = max(dp[i][j][k],dp[i-1][j-1][T]+1);  
	}
	
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=M;j++)
		{
			for(int k=1;k<=T;k++)
				cout << dp[i][j][k] <<" ";
			cout << endl;
		}
		cout << endl;
	}
	
	cout << dp[N][M][T] << endl;
	return 0;
}