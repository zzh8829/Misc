#include <iostream>
using namespace std;

bool prime(int n)
{
for(int i=2;i*i<n+1;i++)
if(n%i==0)
return false;
return true;
}

int main()
{
	long long sum=2;
	for(int i=3;i<2000000;i+=2)
	if(prime(i))
	sum+=i;
	cout << sum <<endl;
	return 0;
}
