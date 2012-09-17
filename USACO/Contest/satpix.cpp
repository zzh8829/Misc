/* 
PROG: satpix
LANG: C++
ID: zzh88291
*/

//#include <iostream>
#include <fstream>
#include <cstdio>
#include <queue>

using namespace std;

bool v[1001][81];
int r,c;
int dir[8] = {-1,0, 0,1, 1,0, 0,-1};
struct P{
	P(int _a,int _b){r=_a,c=_b;}
	int r,c;
};
int main()
{
	ifstream cin("satpix.in");
	ofstream cout("satpix.out");
	cin >> c >> r;
	char in;
	for(int i=0;i!=r;i++)
	for(int j=0;j!=c;j++)
	{
		cin >> in;
		if (in == '.' ) 
		v[i][j] = 1;
	}
	int max = 0;
	for(int i=0;i!=r;i++)
	for(int j=0;j!=c;j++)
	{
		if(!v[i][j])
		{
			queue<P> Q;
			Q.push(P(i,j));
			int co = 0;
			while(!Q.empty())
			{
				P cur = Q.front();
				Q.pop();
				if(v[cur.r][cur.c]) continue;
				v[cur.r][cur.c] = 1;
				co++;
				for(int i=0;i!=4;i++)
				{
					int tr = cur.r + dir[i*2];
					int tc = cur.c + dir[i*2+1];
					if(tr < 0 || tc < 0 || tr>=r||tc>=c||v[tr][tc])
						continue;
					Q.push(P(tr,tc));
				}
			}
			if( co > max ) max = co;						
		}
	}
	cout << max <<endl;
	return 0;
}
