#include <iostream>
#include <cstdio>

using namespace std;


int main()
{
	int n;
	cin >> n;
	for(int t=0;t!=n;t++)
	{
		int k;
		cin >> k;
		while(1)
		{
			k++;
			int m = k%1000;
			int c = m*m*m;
			if(c%1000 == 888)
			{
				cout << k <<endl;
				break;
			}
		}
	}
	return 0;
}
