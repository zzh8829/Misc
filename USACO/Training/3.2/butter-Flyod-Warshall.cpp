/*
ID: zzh8829
PROG: butter
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

const int INF = 1<<20;
int d[805][805],cow[502];
int NS,P,C,tot,a,b,MIN = INF;

int main()
{
#ifndef LOCAL
	ifstream cin("butter.in");
	ofstream cout("butter.out");
#endif
	for(int i=1;i!=801;i++)
	for(int j=1;j!=801;j++)
		d[i][j]=INF;
	for(int i=1;i!=801;i++)
		d[i][i]=0;
	cin >> NS >> P >> C;
	for(int i=0;i!=NS;i++)
		cin >> cow[i];
	for(int i=0;i!=C;i++)
	{
		cin >> a >> b;
		cin >> d[a][b];
		d[b][a]=d[a][b];
	}
	for(int k=1;k<=P;k++)
	for(int i=1;i<=P;i++)
	for(int j=1;j<=P;j++)
	if(d[i][j]>d[i][k]+d[k][j])
		d[i][j]=d[i][k]+d[k][j];
	for(int i=1;i<=P;i++)
	{
		tot=0;
		for(int j=0;j!=NS;j++)tot+=d[cow[j]][i];
		if(tot<MIN) MIN = tot;
	}
	cout << MIN << endl;
	return 0;
}
