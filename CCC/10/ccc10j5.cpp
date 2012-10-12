#include <iostream>
#include <queue>
using namespace std;
const int N = 9;
bool v[N][N];
struct P{
	P(){};
	P(int _x,int _y,int _t){x=_x,y=_y,t=_t;};
	int x,y,t;
}p[2];
int dx[9]={-2,-1, 1, 2, 2, 1,-1,-2};
int dy[9]={ 1, 2, 2, 1,-1,-2,-2,-1};
int main()
{
	cin >> p[0].x >> p[0].y >> p[1].x >> p[1].y;
	queue<P> Q;
	Q.push(p[0]);
	while(!Q.empty())
	{
		P pos = Q.front();Q.pop();
		v[pos.x][pos.y]=1;
		if(pos.x==p[1].x&&pos.y==p[1].y)
		{
			cout << pos.t<< endl;
			return 0;
		}
		for(int i=0;i!=8;i++)
		{
			int tx=pos.x+dx[i];
			int ty=pos.y+dy[i];
			if(tx>0&&tx<N&&ty>0&&ty<N&&!v[tx][ty])
				Q.push(P(tx,ty,pos.t+1));
		}
	}
	return 0;
}
