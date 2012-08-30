#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
	int n;
	while(cin >> n && n != 0)
	{
		int len = n-1;
		int tmp[21];
		int c[21];
		for(int i=0;i!=n;i++)
		cin >> tmp[i];
		for(int i=0;i!=len;i++)
		c[i] = tmp[i+1]-tmp[i];
		
		if(len == 0)
		cout << 0 <<endl;
		for(int i=1;i<=len;i++)
		{
			bool ok = true;
			for(int j=i;j<len;j++)
				if(c[j] != c[j % i] ) 
				{ 
					ok = false;
					break;
				}
			if(ok) { cout << i <<endl;break;}
		}
	}
	return 0;
}
