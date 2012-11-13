#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
using namespace std;

int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		int t;
		cin >> t;
		string a,b;
		cin >> a >> b;
		string c="";
		for (int i = 0; i < t; ++i)
		{
			c += a[i];
			c += b[i];
		}
		for(int i=c.size()-1;i>=0;i--)
			cout << c[i];
		cout << endl;
	}	
	
	return 0;
}