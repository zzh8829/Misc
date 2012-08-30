#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
char map[256];
int main()
{
	string a,b,c;
	getline(cin,a);
	getline(cin,b);
	getline(cin,c);
	for(int i=0;i!=a.size();i++)
		map[b[i]] = a[i];
	for(int i=0;i!=c.size();i++)
	{
		if(map[c[i]])
		cout << map[c[i]];
		else
		cout << '.';
	}
	cout <<endl;
	system("pause");
	return 0;
}
