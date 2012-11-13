#include <iostream>
using namespace std;

int gcd(int a,int b)
{
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
	int n;
	while(cin >> n && n!=0)
	{
		int c[101] = {0},con[101],v[101]={0};
		int cn = 0,t,nxt,tot;
		for (int i = 0; i < n; ++i)
		{
			cin >> t;
			cin >> con[t];
		}
		for(int i=1;i<=n;i++) if(!v[i])
		{
			v[i]=1;
			c[++cn]++;
			nxt = con[i];
			while(nxt!=i)
			{
				c[cn]++;
				v[nxt]=1;
				nxt = con[nxt];
			}
		}
		tot = c[1];
		for(int i=2;i<=cn;i++)
			tot = tot*c[i]/gcd(tot,c[i]);
		cout << tot << endl;
	}
	return 0;
}