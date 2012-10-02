/*
ID: zzh8829
PROG: comehome
LANG: C++
*/
#include <iostream>
#include <fstream>
using namespace std;
int d[128][128];
int main()
{
	ifstream cin("comehome.in");
	ofstream cout("comehome.out");
	int n;
	cin >> n;
	for(int i='A';i<='z';i++)
	for(int j='A';j<='z';j++)
		d[i][j]=1<<20;
	for(int i=0;i!=n;i++)
	{
		char a,b;
		int dis;
		cin >> a >> b >> dis;
		if(d[a][b]>dis)
			d[a][b]=d[b][a]=dis;		
	}
	for(int k='A';k<='z';k++)if(k<='Z' || k>='a')
	for(int i='A';i<='z';i++)if(i<='Z' || i>='a')
	for(int j='A';j<='z';j++)if(j<='Z' || j>='a')
		if(d[i][k]+d[k][j] < d[i][j])
			d[i][j] = d[i][k] + d[k][j];	
	int minn = 1<<25;
	char minc;
	for(int i='A';i<'Z';i++) if( d[i]['Z']< minn)
	{
		minn = d[i]['Z'];
		minc = i;
	}
	cout << char(minc) << " " << minn << endl;
	return 0;
}
