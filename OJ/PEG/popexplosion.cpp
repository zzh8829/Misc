#include <iostream>
#include <cstdio>

using namespace std;


int main()
{
	float p;
	long long a,y,b,i;
	cin >> p>> a >>y >>b;	
	for(i=1;;i++)
	{
		long long add=a/100*p;
		a+=add;
		if(a>=b)
		break;
	}
	cout << y+i <<endl;	
	system("pause");
	return 0;
}
