#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

int s[101][101];
bool v[101][101];
int n,r,c,kr,kc,pr,pc;

int dr[20] = {-2,1, -1,2, 1,2, 2,1, 2,-1, 1,-2, -1,-2, -2,-1};

struct P{
	P(){}
	P(int _r,int _c){
		r=_r;
		c=_c;
	}
	int r;
	int c;
};

int main()
{
	cin >> n;
	while(n--)
	{
		cin >> r >> c >> pr >> pc >> kr >> kc;
		for(int i=1;i<=r;i++)
		{
			for(int j=1;j<=c;j++)
			{
				s[i][j]=-1;
				v[i][j]=0;
			}
		}
		s[kr][kc] = 0;
		v[kr][kc] = 1;
		queue<P> Q;
		Q.push(P(kr,kc));
		while(!Q.empty() )
		{
			P cur = Q.front();
			Q.pop();
			int d = s[cur.r][cur.c];
			for(int i=0;i!=8;i++)
			{
				int tx = cur.r + dr[i*2];
				int ty = cur.c + dr[i*2+1];
				if(tx>r || tx < 1 || ty>c || ty<1)
					continue;
				if(v[tx][ty]) continue;
				v[tx][ty] = 1;
				s[tx][ty] = d+1;	
				Q.push(P(tx,ty));
			}
		}
		bool win = 0;
		int min=1000;
		for(int i=1;i<r-pr;i++)
		{
			if( s[i+pr][pc]>=0 && i >= s[i+pr][pc] && (i - s[i+pr][pc] )%2==0)
			{
				win = 1;
				min = i;
				break;
			}
		}
		if(win) printf("Win in %d knight move(s).\n",min);
		else { 
			bool sta = 0;
			for(int i=0;i<r-pr;i++)
			{
				if(s[i+pr+1][pc]!=-1 && i>= s[i+pr+1][pc]&& (i - s[i+pr+1][pc])%2==0)
				{
					sta = 1;
					min = i;
					break;
				}
			}
			if(sta) printf("Stalemate in %d knight move(s).\n",min);
			else printf("Loss in %d knight move(s).\n",r-pr-1);
		}
	}
	system("pause");
	return 0;
}
