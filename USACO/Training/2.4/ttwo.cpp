/*
ID: zzh8829
PROG: ttwo
LANG: C++
*/
#include <iostream>
#include <fstream>
using namespace std;

int m[11][11],cx,cy,fx,fy,cd,fd,n;
int d[8]= {-1,0, 0,1, 1,0, 0,-1};

int main()
{
	ifstream cin("ttwo.in");
	ofstream cout("ttwo.out");
	char in;
	for(int i=0;i!=10;i++)
	for(int j=0;j!=10;j++)
	{
		cin >> in;
		if(in=='*')
			m[i][j] = -1;
		if(in=='C')
			cx = i,	cy = j;
		if(in=='F')
			fx = i,	fy = j;
	}		
	while(!(cx==fx && cy==fy))
	{
		n++;
		int tcx = cx + d[cd*2];
		int tcy = cy + d[cd*2+1];
		int tfx = fx + d[fd*2];
		int tfy = fy + d[fd*2+1];
		if(tcx<0 || tcx>=10 || tcy<0 ||	tcy>=10 || m[tcx][tcy])
			cd = (cd+1)%4;	
		else
			cx = tcx,cy = tcy;
		if(tfx<0 || tfx>=10 || tfy<0 ||	tfy>=10 || m[tfx][tfy])
			fd = (fd+1)%4;	
		else
			fx = tfx,fy = tfy;
		if(n>160000)
		{
			n=0;
			break;
		}
	}
	cout << n << endl;
	return 0;
}
