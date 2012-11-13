#include <iostream>
#include <fstream>

using namespace std;

int main()
{
#ifndef LOCAL
	ifstream cin("DATA1.txt");
	ofstream cout("OUT1.txt");
#endif
	int n;
	for(int t=0;t!=5;t++)
	{
		cin >> n;
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j!=i;j++)
			{
				cout << '*';
			}
			cout << endl;
		}
		for(int i=n-1;i>0;i--)
		{
			for(int j=0;j!=i;j++)
				cout << '*';
			cout << endl;
		}
	}
	return 0;
}