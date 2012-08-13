#include <iostream>
using namespace std;

int pairs(int n)
{
	int pair=0;
	for(int i=1;i!=n/2+1;i++)
	if(n%i==0)
	pair+=i;
	return pair;
}

int main()
{
	int sum=0;
	for(int a=1;a!=10001;a++)
	{
	int b=pairs(a);
	int p=pairs(b);
	if(p==a && b!=a)
	sum+=a;
	}
	cout << sum <<endl;
	return 0;
}
