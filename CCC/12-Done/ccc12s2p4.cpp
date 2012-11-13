#include <cstdio>
#include <queue>
using namespace std;

int lens[100001];
int d[100001][81];
bool v[100001][81];

struct P
{
	P(int _r=0,int _c=0):r(_r),c(_c){};
	int r,c;
}p[2];

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&lens[i]);
	scanf("%d%d%d%d",&p[0].r,&p[0].c, &p[1].r,&p[1].c);
	queue<P> q;
	q.push(p[0]);
	v[p[0].r][p[0].c] = 1;
	while(!q.empty())
	{
		P cur = q.front(); q.pop();
		int tx = cur.r,ty = cur.c;
		if(tx == p[1].r && ty==p[1].c) break;
		int td = d[tx][ty];
		int nx = 0,ny = 0;
		if(ty<lens[tx]){
			ny = ty +1;
			if(!v[tx][ny]){
				d[tx][ny]=td+1;
				v[tx][ny]=1;
				q.push(P(tx,ny));
			}
		} else {
			if(tx<n){
				nx = tx+1;
				if(!v[nx][1]){
					d[nx][1]=td+1;
					v[nx][1]=1;
					q.push(P(nx,1));
				}
			}
		}
		if(ty>1){
			ny = ty-1;
			if(!v[tx][ny]){
				d[tx][ny] = td+1;
				v[tx][ny] = 1;
				q.push(P(tx,ny));
			}
		} else {
			if(tx>1){
				nx = tx-1;
				if(!v[nx][lens[nx]]){
					d[nx][lens[nx]]=td+1;
					v[nx][lens[nx]]=1;
					q.push(P(nx,lens[nx]));
				}
			}
		}
		if(tx>1){
			if(lens[tx-1]>ty){
				nx = tx-1;
				if(!v[nx][ty]){
					d[nx][ty]=td+1;
					v[nx][ty]=1;
					q.push(P(nx,ty));
				}
			} else {
				nx = tx-1;
				ny = lens[tx-1];
				if(!v[nx][ny]){
					d[nx][ny]=td+1;
					v[nx][ny]=1;
					q.push(P(nx,ny));
				}
			}
		}
		if(tx<n){
			if(lens[tx+1]>ty){
				nx = tx+1;
				if(!v[nx][ty]){
					d[nx][ty]=td+1;
					v[nx][ty]=1;
					q.push(P(nx,ty));
				}
			} else {
				nx = tx+1;
				ny = lens[tx+1];
				if(!v[nx][ny]){
					d[nx][ny]=td+1;
					v[nx][ny]=1;
					q.push(P(nx,ny));
				}
			}
		}
	}
	printf("%d\n",d[p[1].r][p[1].c]);
}