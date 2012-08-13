#include <iostream>
using namespace std;

bool prime(int n)
{
	if(n%2==0)
	return false;
	for(int i=3;i*i<n+2;i+=2)
	if(n%i==0)
	return false;
	return true;
}

int main()
{
	int n;
	cin >> n;
	for(int i=0;i!=n;i++)
	{
		int x;
		cin >> x;
		if(x<2)
		{
			cout << "0" <<endl;
			continue;
		}
		if(x==2)
		{
			cout << "1" <<endl;
			continue;
		}
		if(prime(x))
		cout << "1"<<endl;
		else
		cout << "0"<<endl;
	}
	return 0;
}
