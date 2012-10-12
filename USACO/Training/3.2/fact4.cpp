/*
ID: zzh8829
PROG: fact4
LANG: C++
*/
#include <iostream>
#include <fstream>
using namespace std;

const int N = 501;
int n[N],f;

int main()
{
#ifndef LOCAL
	ifstream cin("fact4.in");
	ofstream cout("fact4.out");
#endif
	n[0]=1;
	cin >> f;
	for(int i=1;i<=f;i++)
	{
		for(int j=0;j!=N-1;j++)
			n[j]*=i;
		for(int j=0;j!=N-1;j++)
		if(n[j]>=10)
		{
			n[j+1]+=n[j]/10;
			n[j]%=10;
		}
	}
	for(int i=0;i!=N-1;i++)	if(n[i])
	{
		cout << n[i] << endl;
		break;
	}
	return 0;
}

/*
// Another way
int main()
{
	ifstream cin("fact4.in");
	ofstream cout("fact4.out");
    int f,mod = 100000,b=1;
	cin >> f;
	for(int i=2;i<=f;i++)
	{
		b=b*i%mod;
		while(b%10==0) b/=10;
	}
	cout << b%10 << endl;
	return 0;
}
//
