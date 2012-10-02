/*
ID: zzh8829
PROG: maze1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <queue>
using namespace std;
int m[203][100];
int d[9] = {-1,0, 0,1, 1,0, 0,-1};
int r,c,maxn,en;
char in;
struct P
{
	P(){r=0;c=0;t=1;};
	P(int x,int y,int z){r=x;c=y;t=z;}
	int r,c,t;
}e[2];

int main()
{
	ifstream cin("maze1.in");
	ofstream cout("maze1.out");
	cin >> c >> r;
	for(int i=0;i!=2*r+1;i++)
	for(int j=0;j!=2*c+1;j++)
	{
		in = cin.get();
		if(in=='\n')in = cin.get();
		if(in!=' ')m[i][j] = 1;
		else if(i%2!=0&&j%2!=0)m[i][j]=1<<20;		
	}
	for(int i=1;i<=2*r;i+=2)
	{
		if(m[i][0]==0)
			e[en].r = i,e[en++].c = 1;
		if(m[i][2*c]==0)
			e[en].r = i,e[en++].c = 2*c-1;
	}
	for(int j=1;j<=2*c;j+=2)
	{
		if(m[0][j]==0)
			e[en].r = 1,e[en++].c = j;
		if(m[2*r][j]==0)
			e[en].r = 2*r-1,e[en++].c = j;
	}
	for(int t=0;t!=2;t++)
	{
		bool v[203][100]={0};
		v[e[t].r][e[t].c]=true;
		m[e[t].r][e[t].c]=1;
		queue<P> Q;
		Q.push(e[t]);
		while(!Q.empty())
		{
			P cur = Q.front();
			Q.pop();
			for(int i=0;i!=4;i++)
			{
				int tr = cur.r+d[i*2];
				int tc = cur.c+d[i*2+1];
				if(tc<1||tr<1||tr>2*r||tc>2*c||m[tr][tc])
					continue;
				tr+=d[i*2];
				tc+=d[i*2+1];;
				if(!v[tr][tc] && m[tr][tc]>cur.t+1)
				{
					m[tr][tc]=cur.t+1;
					v[tr][tc]=1;
					Q.push(P(tr,tc,cur.t+1));
				}					
			}
		}
	}
	for(int i=1;i<=2*r+1;i+=2)
	for(int j=1;j<=2*c+1;j+=2)
	if(m[i][j]>maxn)maxn = m[i][j];
	cout << maxn << endl;
	return 0;
}


