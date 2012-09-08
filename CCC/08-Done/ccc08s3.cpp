#include <iostream>
#include <cstdio>

using namespace std;

char m[21][21];
int d[21][21];
int r,c,has;
void go(int x,int y,int s)
{
	
	if(m[x][y] =='*') return ;
	if(x>=r || x<0 || y>=c || y<0 ) return ;
	if(s<d[x][y]) d[x][y] = s;
	else return ;
	if(x==r-1 && y==c-1)
	{
		has = true;
		return ;
	}
	if(m[x][y] =='|')
	{
		go(x+1,y,s+1);
		go(x-1,y,s+1);
	}
	else if(m[x][y] =='-')
	{
		go(x,y+1,s+1);
		go(x,y-1,s+1);
	}
	else
	{
		go(x,y+1,s+1);
		go(x+1,y,s+1);
		go(x,y-1,s+1);
		go(x-1,y,s+1);
	}
	return ;
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		has=0;
		cin >> r >>c;
		for(int i=0;i!=r;i++)
		for(int j=0;j!=c;j++)
		{
			cin >> m[i][j];
			d[i][j]=1<<18;
		}
		go(0,0,1);
		if(!has)
			cout << -1 <<endl;
		else
			cout << d[r-1][c-1] <<endl;		
	}	
	system("pause");
	return 0;
}
