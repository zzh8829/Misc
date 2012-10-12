#include <iostream>
#include <set>
using namespace std;

const int INF = 1<<20;

int m[51][51];
int d[51][51];

int main()
{
	char st;
	int x,y,t;
	set<int> si;
	int c[25][2]={6,2, 6,1, 6,3, 6,4, 6,5, 6,7,
			3,4, 3,5, 4,5, 3,15, 15,13, 13,14,
			13,12, 12,11, 12,9, 10,11, 10,9, 
			9,8, 8,7, 16,17 ,17,18 ,16,18};
	for(int t=0;t!=22;t++)
		m[c[t][0]][c[t][1]]=m[c[t][1]][c[t][0]]=1;
	while(cin >> st && st!='q')	switch(st)
	{
	case 'i':
		cin >> x >> y;
		m[x][y]=m[y][x]=1;
		break;
	case 'd':
		cin >> x >> y;
		m[x][y]=m[y][x]=0;
		break;
	case 'n':
		cin >> x;
		t=0;
		for(int i=1;i<=50;i++)
			if(m[x][i]) t++;
		cout << t << endl;
		break;
	case 'f':
		cin >> x;
		si.clear();
		for(int i=1;i!=51;i++)if(m[x][i])
			for(int j=1;j!=51;j++)if(m[i][j])
				if(j!=x)si.insert(j);
		for(int i=1;i!=51;i++)if(m[x][i])
			if(si.count(i))si.erase(i);
		cout << si.size() << endl;
		break;
	case 's':
		cin >> x >>y;
		for(int i=1;i<=50;i++)
		for(int j=1;j<=50;j++)
		{
			if(m[i][j] || i==j ) d[i][j]=1;
			else d[i][j] = INF;
		}	
		for(int k=1;k<=50;k++)
		for(int i=1;i<=50;i++)
		for(int j=1;j<=50;j++)
		if(d[i][k]+d[k][j]<d[i][j])
			d[i][j] = d[i][k]+d[k][j];				
		if(d[x][y]==INF)
			cout << "Not connected" << endl;
		else cout << d[x][y] << endl;
		break;
	}	
	return 0;
}
	
