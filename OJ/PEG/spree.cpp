#include <iostream>

using namespace std;


int f[1001][1001];
int w[1001][2];
int main()
{
	int n,t;
	cin >> n >> t;
	for(int i=1;i<=n;i++)
		cin >> w[i][0] >> w[i][1];
	for(int i=1;i<=n;i++)
	for(int j=0;j<=t;j++)
	{
		f[i][j] = f[i-1][j];
		if(j>=w[i][1])
		f[i][j]=max(f[i][j],f[i-1][j-w[i][1]]+w[i][0]);
	}
	cout << f[n][t] << endl;
	return 0;
}