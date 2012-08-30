#include <iostream>
#include <cstdio>
#include <cstring> 
#define B 0
#define W 1
#define E 2
using namespace std;
int ma[9][9] = {
	{E,E,E,E,E,E,E,E},
	{E,E,E,E,E,E,E,E},
	{E,E,E,E,E,E,E,E},
	{E,E,E,W,B,E,E,E},
	{E,E,E,B,W,E,E,E},
	{E,E,E,E,E,E,E,E},
	{E,E,E,E,E,E,E,E},
	{E,E,E,E,E,E,E,E}};
int mb[9][9] = {
	{B,E,E,E,E,E,E,W},
	{E,B,E,E,E,E,W,E},
	{E,E,B,E,E,W,E,E},
	{E,E,E,B,W,E,E,E},
	{E,E,E,W,B,E,E,E},
	{E,E,W,E,E,B,E,E},
	{E,W,E,E,E,E,B,E},
	{W,E,E,E,E,E,E,B}};
int mc[9][9] = {
	{E,E,B,B,W,W,E,E},
	{E,E,B,B,W,W,E,E},
	{E,E,B,B,W,W,E,E},
	{E,E,B,B,W,W,E,E},
	{E,E,B,B,W,W,E,E},
	{E,E,B,B,W,W,E,E},
	{E,E,B,B,W,W,E,E},
	{E,E,B,B,W,W,E,E}};

int black,white,m[9][9],dm[20] = {-1,0,1,0,0,-1,0,1,1,1,1,-1,-1,1,-1,-1};

void go(int oor,int oc,int w)
{
	m[oor][oc]=w;
	int gr,gc;
	for(int d=0;d!=8;d++)
	{
		int num=0,ok=false;
		gr=dm[d*2];
		gc=dm[d*2+1];
		int r=oor,c=oc;
		while(r+gr>=0 && r+gr<=7 && c+gc>=0 && c+gc<=7)
		{
			r+=gr;c+=gc;
			if(m[r][c] == E)
				break;
			if(m[r][c] !=w)
				num++;
			if(m[r][c] ==w)
			{
				ok=true;
				break;
			}
		}
		r=oor,c=oc;
		if(ok)
		for(int i=0;i!=num;i++)
		{
			r+=gr;c+=gc;
			m[r][c] = w;
		}
	}
}

int main()
{
	char sb;
	int n;
	cin >> sb>>n;
	if(sb=='a')
		memcpy(m,ma,sizeof(ma));
	else if(sb=='b')
		memcpy(m,mb,sizeof(mb));
	else if(sb=='c')
		memcpy(m,mc,sizeof(mc));
	for(int t=0;t!=n;t++)
	{
		int r,c;
		cin >> r >> c;
		go(r-1,c-1,t%2); 
	}
	for(int i=0;i!=8;i++)
		for(int j=0;j!=8;j++)
		{
			if(m[i][j]==0)
				black++;
			if(m[i][j]==1)
				white++;
		}
	cout << black << " " <<white <<endl;
	system("pause");
	return 0;
}
