#include <iostream>
#include <cstdio>
using namespace std;

int m[10000];

int main()
{
	int a,b;
	cin >> a >> b;
	m[0]=a;
	m[1]=b;
	int i=1;
	while(1)
	{
		if(m[i-1]<m[i])
			break;
		m[i+1]=m[i-1]-m[i];
		i++;
	}
	cout << i+1 <<endl;
	system("pause");
	return 0;
}
