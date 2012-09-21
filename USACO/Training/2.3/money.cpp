/*
ID: zzh8829
PROG: money 
LANG: C++
*/
//#include <iostream>
#include <fstream>
using namespace std;
ifstream cin("money.in");
ofstream cout("money.out");

long long dp[10001],c[26],cn,n;

int main()
{
	cin >> cn >> n;
	for(int i=0;i!=cn;i++)
	cin >> c[i];
	dp[0]=1;
	for(int i=0;i!=cn;i++)
		for(int j=c[i];j<=n;j++)
			dp[j]+=dp[j-c[i]];
	cout << dp[n] << endl;
	return 0;
}
