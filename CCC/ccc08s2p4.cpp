#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <vector>
#include <string>
#include <set>
using namespace std;

char m[1001][1001];
int v[1001][1001];
vector< vector<int> >cir;

int dr[256]={1,0,0,-1,0};
int dc[256]={0,1,-1,0,0};
int R,C;

struct P
{
	int r,c;
	P(int _r,int _c):r(_r),c(_c){}
};

void redfs(int r,int c,int f,int wf)
{
	queue<P> Q;
	Q.push(P(r,c));
	while(!Q.empty())
	{
		P p=Q.front();Q.pop();
		if(v[p.r][p.c]==f) continue;
		v[p.r][p.c]=f;
		for(int d=0;d!=4;d++)
		{
			int nr = dr[d]+p.r;
			int nc = dc[d]+p.c;
			if(nr>=0 && nc>=0 && nr<R && nc<C)
			{
				int tr = nr+dr[m[nr][nc]];
				int tc = nc+dc[m[nr][nc]];
				if(tr==p.r && tc==p.c) Q.push(P(nr,nc));
			}
		}
	}
}

void dfs(int r,int c,int f)
{
	if(v[r][c] == f ) return;
	v[r][c]=f;
	int nr = r+dr[m[r][c]];
	int nc = c+dc[m[r][c]];
	if(nr>=0 && nc>=0 && nr<R && nc<C && v[nr][nc]!=f)
	{
		if(!v[nr][nc]) dfs(nr,nc,f);
		else redfs(r,c,v[nr][nc],f);
	}
}

int main()
{
	dr['S']=1;
	dr['N']=-1;
	dc['E']=1;
	dc['W']=-1;
	string line;
	cin >> R >> C; while(cin.get()!='\n');
	for (int i = 0; i < R; ++i)
	{
		getline(cin,line);
		for(int j=0;j!=line.size();j++)
			m[i][j]=line[j];
	}
	int cn=0;
	for (int i = 0; i < R; ++i)
		for (int j = 0; j < C; ++j)if(!v[i][j])
			dfs(i,j,++cn);
	set<int> color;
	for (int i = 0; i < R; ++i)
		for (int j = 0; j < C; ++j)
			color.insert(v[i][j]);	
	cout << color.size() << endl;
	return 0;
}