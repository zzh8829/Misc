/*
ID: zzh8829
PROG: concom
LANG: C++
*/
#include <iostream>
#include <fstream>
using namespace std;

const int N = 100;
int com[102][102],a,b,n,c[105],v[105];

void dfs(int x)
{
	v[x] = 1;
	for(int i=1;i<=N;i++)
		c[i] += com[x][i];	
	for(int i=1;i<=N;i++)
		if(c[i]>=50 && v[i]!=1 && i!=x)
			dfs(i);
}

int main()
{
	ifstream cin("concom.in");
	ofstream cout("concom.out");
	cin >> n;
	for(int i=0;i!=n;i++)
	{
		cin >> a >> b;
		cin >> com[a][b];
	}
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=N;j++)
			c[j]=v[j]=0;
		dfs(i);
		for(int j=1;j<=N;j++)
		if(c[j]>=50 && i!=j)
		cout <<i <<" " << j << endl;	
	}
	return 0;
}
