/*
ID: zzh8829
PROG: subset
LANG: C++
*/
//#include <iostream>
#include <fstream>
using namespace std;
ifstream cin("subset.in");
ofstream cout("subset.out");
long long dp[40][800];
int main()
{
	int n;
	cin >> n;
	int s = (1+n)*n/2;
	int hs = s/2;
	dp[1][1] = 1;
	if(!(s&1)) // if sum is and odd number, there is no valid subset.
	for(int i=2;i<=n;i++)
	for(int j=1;j<=((1+i)*i/2);j++)
	{
		dp[i][j] = dp[i-1][j] + (j-i>0?dp[i-1][j-i]:0);
		if(j==i) dp[i][j]++;
	}
	cout << dp[n][hs]/2 << endl;	
	//system("pause");
	return 0;
}
