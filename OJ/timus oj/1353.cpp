#include <iostream>
#include <cstdio>
using namespace std;
int s;
long long dp[11][91];
int main()
{
	cin >> s;
	for(int i=0;i!=10;i++)
		dp[1][i]=1;
	for(int i=2;i<=9;i++)
	for(int j=0;j<=72;j++)
	for(int k=0;k<=9;k++)
		dp[i][j+k]+=dp[i-1][j];
	dp[9][1]=10;
	cout << dp[9][s] << endl;
}
