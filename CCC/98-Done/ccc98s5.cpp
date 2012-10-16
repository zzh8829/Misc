#include    <cstdio>
#include    <cstdlib>
#include    <iostream>
#include 	<cmath>
using namespace std;

int m[26][26];
int o[26][26];
int r,n;
int d[8]= {1,0, 0,1, -1 ,0, 0,-1};

void go(int x,int y,int ox)
{
	if(ox< o[x][y]) o[x][y] = ox;
	else return;
	for(int i=0;i!=4;i++)
	{
		int tx = x+d[i*2];
		int ty = y+d[i*2+1];
		if(tx <n || ty<n || tx>=0 || ty >=0)
		if( abs(m[tx][ty] - m[x][y]) <= 2)
		{
			if( m[tx][ty] > r || m[x][y] > r)
				go(tx,ty,ox+1);
			else
				go(tx,ty,ox);
		}
	}
}
int main ( int argc, char *argv[] )
{
    int cs;
    cin >> cs;
    while(cs--)
    {
        cin >> n;
        for(int i=0;i!=n;i++)
        for(int j=0;j!=n;j++)
        {
            cin >> m[i][j];
            o[i][j]=1<<18;
		}
        r=m[0][0];
        go(0,0,0);
        if(o[n-1][n-1]!=1<<18)
        cout << o[n-1][n-1] <<endl;
        else
        cout << "CANNOT MAKE THE TRIP" <<endl;
        cout <<endl;
    }
    return 0;
}
