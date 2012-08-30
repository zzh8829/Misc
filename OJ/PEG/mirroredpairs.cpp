#include <iostream>
#include <cstdio>
#include <string>

using namespace std;
char m[256];

int main()
{
	m['q'] = 'p';
	m['p'] = 'q';
	m['d'] = 'b';
	m['b'] = 'd';
	string line;
	cout << "Ready" <<endl;
	while(getline(cin,line)!=0)
	{
		if(line[0]==' '&&line[1]==' ')
		break;	
		if(m[line[0]] == line[1])
		cout << "Mirrored pair" <<endl;
		else
		cout << "Ordinary pair" <<endl;
	}	
	system("pause");
	return 0;
}
