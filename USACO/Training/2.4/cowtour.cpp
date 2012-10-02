/*
ID: zzh8829
PROG: cowtour
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
using namespace std;

const int INF = 1<<20;
double d[151][151],dt[151];
int p[151][2];

inline double dis(int x1,int y1,int x2,int y2){
	return sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
}

int main()
{
	ifstream cin("cowtour.in");
	ofstream cout("cowtour.out");
	int n;
	cin >> n;
	for(int i=0;i!=n;i++)
		cin >> p[i][0] >> p[i][1] ;
	cin.ignore();
	for(int i=0;i!=n;i++)
	{
		for(int j=0;j!=n;j++)
		{
			if(cin.get()=='1')
				d[i][j] = dis(p[i][0],p[i][1],p[j][0],p[j][1]);
			else
				d[i][j] = INF;
		}
		cin.get();
	}
	for(int k=0;k!=n;k++)
	for(int i=0;i!=n;i++)
	for(int j=0;j!=n;j++)
	{
		if(d[i][k]+d[k][j] < d[i][j])
			d[i][j] = d[i][k]+d[k][j];
	}
	for(int i=0;i!=n;i++)
		d[i][i] = INF;
	
	double tmax = 0;
	for (int i=0;i!=n;i++)
	{
		double pmax = 0;
		for(int j=0;j!=n;j++)
			if(d[i][j]>pmax && d[i][j]!=INF)
				pmax = d[i][j];
		dt[i] = pmax;
		if(pmax > tmax ) tmax = pmax;
	}
	
	double pmin = INF;
	for(int i=0;i!=n-1;i++)
	for(int j=i+1;j!=n;j++)
	{
		if(d[i][j]==INF && i!=j)
		{
			double tmp = dis(p[i][0],p[i][1],p[j][0],p[j][1]);
			if( dt[i] + dt[j] + tmp < pmin)
				pmin = dt[i]+dt[j]+tmp;
		}
	}
	cout << fixed << setprecision(6) << (pmin>tmax?pmin:tmax)<< endl;
	return 0;
}
