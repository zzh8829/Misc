/*
ID: zzh8829
PROG: runround
LANG: C++
*/
//#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
ifstream cin("runround.in");
ofstream cout("runround.out");
bool check(int n)
{
	if(n==0) return true;
	int v[10]={0};
	int a[10];
	int len=0;
	while(n>0)
	{
		a[len++] = n%10;
		if(a[len-1] ==0 ) return false;
		n/=10;
	}
	for(int i=0;i!=len/2;i++)
		swap(a[i],a[len-1-i]);
	int p = 0;
	while(1)
	{	
		if(v[a[p]]) return false;
		v[a[p]] = 1;
		p=(p + a[p] ) %len;
		if( p==0 ) 
		{
			int cnt = 0;
			for(int i=0;i!=10;i++)if( v[i] )
				cnt++;
			if(cnt == len)return true;
			else return false;
		}
	}	
}

int main()
{
	int n;
	cin >> n;
	n++;
	while(!check(n))
		n++;
	cout << n << endl;
	//system("pause");
	return 0;
}
