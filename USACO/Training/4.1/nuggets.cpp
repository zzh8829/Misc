/*
ID: zzh8829
PROG: nuggets
LANG: C++
*/
#include <iostream>
#include <fstream>

using namespace std;

const int N = 256*256;
bool k[N+260];
int s[11],n,g;

int gcd(int a,int b)
{
	if(a==0) return b;
	while(b!=0)
	{
		int t = b;
		b = a%b;
		a = t;
	}
	return a;
}

int main()
{
#ifndef LOCAL
	ifstream cin("nuggets.in");
	ofstream cout("nuggets.out");
#endif
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> s[i];
		g = gcd(g,s[i]);
		if(s[i]==1){ cout << 0 << endl; return 0;}
	}
	if(g>1){ cout << 0 << endl; return 0;}
	k[0]=1;
	for (int i = 0; i < n; ++i)
		for (int j = s[i]; j<=N; ++j)
			k[j] = max(k[j-s[i]],k[j]);
	for(int i=N-1;i>=0;i--)
		if(!k[i]){ cout << i << endl; return 0;}
	return 0;
}