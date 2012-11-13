#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
#ifndef LOCAL
	ifstream cin("DATA2.txt");
	ofstream cout("OUT2.txt");
#endif
	for (int t=0;t!=5;t++)
	{
		int y,n;
		cin >> y >> n;
		int ratio = (y*10)/(y+n);
		for(int i=0;i!=ratio;i++)
			cout << "*";
		for(int i=0;i!=10-ratio;i++)
			cout << ".";
		cout << endl;
	}
	return 0;
}