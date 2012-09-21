/*
ID: zzh8829
PROG: nocows
LANG: C++
*/
#include <iostream>
#include <fstream>

using namespace std;

int dp[201][201];
int N,K;
const int MOD = 9901;
int main()
{
//ifstream cin("nocows.in");
//ofstream cout("nocows.out");
	cin >> N >> K;
	for (int i = 1; i <= K; ++i)
		dp[i][1] = 1;;
	for (int j = 1; j <= K; ++j)
		for (int i = 3; i <= N; i += 2)
			for (int k = 1; k <= i-2; k += 2)
				dp[j][i] = (dp[j][i]+dp[j-1][k]*dp[j-1][i-k-1])%9901;
	cout << (dp[K][N]-dp[K-1][N]+9901)%9901<< endl;
		
	return 0;
}
