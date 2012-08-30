#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;


int main()
{
	int r;
	while(cin >> r && r != 0)
	{
		int lu=0;
		for(int i=1;i!=r;i++)
		{
			int h = sqrt(r*r-i*i);
			lu+=h;
		}
		int sum = r*4+1+lu*4;
		cout << sum <<endl;
	}
	system("pause");
	return 0;
}
