/*
ID: zzh8829
PROG: game1
LANG: C++
*/
#include <iostream>
#include <fstream>
using namespace std;

int sum[101][101],dp[101][101],n;

int main()
{
#ifndef LOCAL
	ifstream cin("game1.in");
	ofstream cout("game1.out");
#endif
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> dp[i][i];
		sum[i][i]=dp[i][i];
	}
	for(int i=1;i<=n;i++)
	for(int j=i+1;j<=n;j++)
		sum[i][j]=sum[i][j-1]+dp[j][j];
	for(int len=1;len<n;len++)
	for(int i=1;i+len<=n;i++)
		dp[i][i+len]=sum[i][i+len]-min(dp[i][i+len-1],dp[i+1][i+len]);
	cout << dp[1][n] << " " << sum[1][n]-dp[1][n] << endl;
	return 0;
}
