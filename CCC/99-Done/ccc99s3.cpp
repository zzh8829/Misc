#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

int m[250][250];

void dig(int r,int c,int n)
{
	if(n==0) return;
	int t = pow(3.0,n-1);
	for(int i=r+t;i!=r+2*t;i++)
	for(int j=c+t;j!=c+2*t;j++)
		m[i][j] = 1;
	dig(r,c,n-1);
	dig(r+t,c,n-1);
	dig(r+2*t,c,n-1);
	dig(r,c+t,n-1);
	dig(r+2*t,c+t,n-1);
	dig(r,c+2*t,n-1);
	dig(r+t,c+2*t,n-1);
	dig(r+2*t,c+2*t,n-1);
}

int main()
{
	int cs,n,b,t,l,r;
	cin >> cs;
	while(cs--)
	{
		cin >> n >> b >> t >> l >> r;
		memset(m,0,sizeof(m));
		dig(1,1,n);
		n = pow(3.0,n);
		for(int i=n-t+1;i<=n-b+1;i++)
		{
			for(int j=l;j<=r;j++)
				cout << (m[i][j]?' ':'*') <<" ";
			cout << endl;
		}
		cout << endl;
	}
	return 0;
}
