/*
ID: zzh8829
PROG: inflate
LANG: C++
*/
#include <iostream>
#include <fstream>
using namespace std;

int t[10001];
inline int max(int a,int b){
	return a>b?a:b;
}
int main()
{
	ifstream cin("inflate.in");
	ofstream cout("inflate.out");
	int n,m,p,len;
	cin >> n >> m;
	for(int i=0;i!=m;i++)
	{	
		cin >> p >> len;
		for(int j=len;j<=n;j++)
			t[j] = max(t[j],t[j-len]+p);
	}
	cout << t[n] << endl;	
	return 0;
}
