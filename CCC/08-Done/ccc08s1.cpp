#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
	string city;
	int min = 100000;
	string mincity;
	while(cin >> city)
	{
		bool minus = false;
		string te;
		cin >> te;
		if(te[0] == '-')
		{
			minus = true;
			te.erase(0,1);
		}
		stringstream ss;
		ss<< te;
		int temp;
		ss >> temp;
		if(minus)
		temp = -temp;
		if( temp < min)
		{
			mincity = city;
			min = temp;
		}
	}
	cout << mincity << endl;
	system("pause");
	return 0;
}
