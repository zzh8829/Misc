/*
ID: zzh8829
PROG: butter
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 801;
const int INF = 1<<20;
int n,p,c;
int m[MAX][MAX];
int d[MAX][MAX];
int cow[MAX];
vector<int> con[MAX];

void SPFA(int v0)
{
	queue<int> Q;
	bool v[MAX]={0};
	Q.push(v0);
	while(!Q.empty())
	{
		int cur = Q.front();
		Q.pop();
		for(int i=0;i!=con[cur].size();i++)
		{
			int cp = con[cur][i]; // connected point
			if(d[v0][cur]+m[cur][cp] < d[v0][cp])
			{
				d[v0][cp] = d[v0][cur]+m[cur][cp];
				if(!v[cp])
				{
					Q.push(cp);
					v[cp]=1;
				}
			}
		}
		v[cur] = 0;
	}
}

int main()
{
#ifndef LOCAL
	ifstream cin("butter.in");
	ofstream cout("butter.out");
#endif	
	cin >> n >> p >> c;
	for(int i=0;i!=n;i++)
		cin >> cow[i];
	int x,y,dis;
	for(int i=1;i<=c;i++)
	{
		cin >> x >> y >> dis;
		m[x][y]=m[y][x] = dis;
		con[x].push_back(y);
		con[y].push_back(x);
	}
	for(int i=1;i<=p;i++)
	for(int j=1;j<=p;j++)
		d[i][j] = INF;
	for(int i=1;i<=p;i++)
		m[i][i]=d[i][i]=0;
	for(int i=1;i<=p;i++)
		SPFA(i);
	int min = INF;
	for(int i=1;i<=p;i++)
	{
		int sum =0;
		for(int j=0;j!=n;j++)
			sum+= d[cow[j]][i];
		if (sum<min) min = sum;
	}
	cout << min << endl;
	return 0;
}
