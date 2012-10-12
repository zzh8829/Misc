/*
ID: zzh8829
PROG: range
LANG: C++
*/
#include <iostream>
#include <fstream>
using namespace std;
int dp[251][251],m[251][251];
int a[251],n;
int main()
{
	ifstream cin("range.in");
	ofstream cout("range.out");
	cin >> n;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	{
		char t = cin.get();
		if(t=='\n') t = cin.get();
		if(t=='1')
		{
			m[i][j]=1;
			if(i==n||j==n)
				dp[i][j]=1;
		}
	}
	for(int i=n-1;i>0;i--)
	for(int j=n-1;j>0;j--)
	if(m[i][j])
	{
		dp[i][j]= min(min(dp[i+1][j],dp[i][j+1]),dp[i+1][j+1])+1;
		int t = dp[i][j];
		while(t>=2)
			a[t--]++;			
	}
	for(int i=2;i<=n;i++) if(a[i])
		cout << i << " " << a[i] << endl;
	return 0;
}
