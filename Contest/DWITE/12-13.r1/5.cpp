#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <vector>
#include <queue>
#include <cstring>
#include <cstdlib>
using namespace std;

char m[15][15];
int dx[5] = {1,-1,0,0};
int dy[5] = {0,0,1,-1};

struct W
{
	W(int _t=0,int _s = 999999):t(_t),s(_s){}
	int t,s;
};


struct P
{
	P(int _r=0,int _c=0,W _w=W(),set<pair<int,int> > _got=set<pair<int,int> >()):r(_r),c(_c),w(_w),got(_got){}
	int r,c;
	W w;
	set<pair<int,int> > got;
};


W w[15][15];

bool cmp(W a, W b)
{
	if(a.t != b.t)
		if(a.t>b.t)
			return true;
		else
			return false;
	if(a.s <= b.s)
		return true;
	return false;
}

int main()
{
#ifndef LOCAL
	ifstream cin("DATA5.txt");
	ofstream cout("OUT5.txt");
#endif
	for (int t=0;t!=5;t++)
	{
		int n;
		cin >> n;
		queue<P> q;
		for(int i=0;i!=n;i++)
		for(int j=0;j!=n;j++)
		{
			cin >> m[i][j];
			w[i][j] = W();
			if(m[i][j]=='B')
			{
				q.push(P(i,j,W(0,0)));
				w[i][j] = W(0,0);
			}
		}

		while(!q.empty())
		{
			P c = q.front();q.pop();
			for(int i=0;i!=4;i++)
			{
				int tr = c.r + dx[i];
				int tc = c.c + dy[i];
				if(tr>=0 && tc >= 0 && tr<n && tc < n)
				{
					if(m[tr][tc]=='#') continue;
					if(m[tr][tc]=='*'){
						if(c.got.count(make_pair(tr,tc))>0) continue;
						W tw(c.w.t+1,c.w.s+1);
						if(cmp(tw,w[tr][tc]))
						{
							
							c.got.insert(make_pair(tr,tc));
							P nx = P(tr,tc,tw,c.got);
							q.push(nx);
							w[tr][tc] = tw;
						}	
					} else if(m[tr][tc]=='.'){
						W tw(c.w.t,c.w.s+1);
						if(cmp(tw,w[tr][tc]))
						{
							q.push(P(tr,tc,tw,c.got));
							w[tr][tc] = tw;
						}
					} else {
						int wall = m[tr][tc]-'a'+1;
						if(c.w.t>=wall){
							W tw(c.w.t,c.w.s+1);
							if(cmp(tw,w[tr][tc]))
							{
								q.push(P(tr,tc,tw,c.got));
								w[tr][tc] = tw;
							}
						}
					}
				}
			}		
		}
		W maxw = W(-1,999999);
		int ok = 0;
		for(int i=0;i!=n;i++)
		for(int j=0;j!=n;j++)
		if(cmp(w[i][j],maxw))
		{
			maxw = w[i][j];
			ok = 1;
		}
		if(ok)cout << maxw.t <<" " <<maxw.s << endl;
		else cout << "0 0" << endl;
	}
	return 0;
}