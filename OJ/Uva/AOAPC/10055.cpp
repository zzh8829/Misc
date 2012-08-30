#include <iostream>
using namespace std;
int main()
{
	int a,b;
	while(cin >> a >> b)
	{
		int t = a-b;
		if(t<0)
		t=-t;
		cout <<t <<endl;
	}
	return 0;
}
