/*
ID: zzh8829
PROG: spin
LANG: C++
*/
#include <iostream>
#include <fstream>
using namespace std;

struct W{
	int v,wn,ws[10],wl[10];
}w[5];

int main()
{
#ifndef LOCAL
	ifstream cin("spin.in");
	ofstream cout("spin.out");
#endif
	for(int i=0;i!=5;i++)
	{
		cin >> w[i].v >> w[i].wn;
		for(int j=0;j!=w[i].wn;j++)
			cin >> w[i].ws[j] >> w[i].wl[j];
	}
	for(int t=0;t<360;t++)
	{
		int c[361]={0};
		for(int i=0;i!=5;i++)
		{
			int sp = t*w[i].v%360;
			for(int j=0;j!=w[i].wn;j++)
			{
				for(int k=w[i].ws[j];k<=w[i].ws[j]+w[i].wl[j];k++)
				{
					int q = (k+sp)%360;
					c[q]++;
					if(c[q]==5)
					{
						cout << t << endl;
						return 0;
					}
				}
			}
		}
	}
	cout << "none" << endl;
	return 0;
}
