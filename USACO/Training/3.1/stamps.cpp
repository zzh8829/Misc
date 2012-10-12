/*
ID: zzh8829
PROG: stamps
LANG: C++
*/
#include <iostream>
#include <fstream>
using namespace std;

int f[2000000];
int a[201];

int main()
{
#ifndef LOCAL
	ifstream cin("stamps.in");
	ofstream cout("stamps.out");
#endif
	int n,k,i;
	cin >> k >> n;
	for(int i=0;i!=n;i++)
		cin>> a[i];
	for(i=1;i<=k*10000;i++)
	{
		f[i]=k*10000;
		for(int j=0;j!=n;j++) if(a[j]<=i)
			if(f[i]>f[i-a[j]]+1)
				f[i]=f[i-a[j]]+1;
		if(f[i]>k)
			break;
	}
	cout << i-1 << endl;	
	return 0;
}
