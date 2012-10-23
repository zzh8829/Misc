/*
ID: zzh8829
PROG: camelot
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;

struct P{
	P(int a=0,int b=0):r(a),c(b){};
	int r,c;
}kni[1001],kin;
int kn,R,C;
int m[32][32][32][32],kstep[32][32];
int dr[9]={-2,-1,1,2,2,1,-1,-2};
int dc[9]={1,2,2,1,-1,-2,-2,-1};

int main()
{
#ifndef LOCAL
	ifstream cin("camelot.in");
	ofstream cout("camelot.out");
#endif
	cin >>  R >> C;
	char c;
	int r;
	cin >> c >> r;
	kin.r=r;kin.c=c-'A'+1;
	while(cin >> c >> r)
	{
		kni[++kn].c =c-'A'+1;
		kni[kn].r = r;
	}
	memset(m,1,sizeof(m)); 
	// memset will set memory for each 'char' so 1 means 0x01010101 in int
	for(int i=1;i<=R;i++)
	for(int j=1;j<=C;j++)
	{
		queue<P> Q;
		Q.push(P(i,j));
		m[i][j][i][j]=0;
		while(!Q.empty())
		{
			P p = Q.front(); Q.pop();
			for(int d=0;d!=8;d++)
			{
				int tr = p.r+ dr[d];
				int tc = p.c+ dc[d];
				if(tr>0&&tc>0&&tr<=R&&tc<=C&&m[i][j][tr][tc]==0x01010101)
				{
					m[i][j][tr][tc]=m[i][j][p.r][p.c]+1;
					Q.push(P(tr,tc));
				}		
			}
		}		
	}
	int l = 2;	// bound of search
	int ksr = kin.r-l<1?1:kin.r-l;
	int ksc = kin.c-l<1?1:kin.c-l;
	int ker = kin.r+l>R?R:kin.r+l;
	int kec = kin.c+l>C?C:kin.c+l;
	int minstep = 1<<25;
	for(int i=1;i<=R;i++)
	for(int j=1;j<=C;j++)
	{
		int step = 0;
		for(int k=1;k<=kn;k++)
		step+=m[kni[k].r][kni[k].c][i][j];
		int minn=max(abs(kin.r-i),abs(kin.c-j));
		for(int pi=ksr;pi<=ker;pi++)
		for(int pj=ksc;pj<=kec;pj++)
		for(int k=1;k<=kn;k++)
		{
			int tmp = max(abs(kin.r-pi),abs(kin.c-pj))
				+m[kni[k].r][kni[k].c][pi][pj]
				+m[pi][pj][i][j]
				-m[kni[k].r][kni[k].c][i][j];
			if(tmp<minn)minn = tmp;	
		}						
		if(step+minn<minstep)minstep=minn+step;
	}
	cout << minstep  << endl;
	return 0;
}
