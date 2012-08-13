#include <iostream>
using namespace std;
const int n=1000;

bool valid(int i)
{
	if(i%3==0)
		return true;
	if(i%5==0)
		return true;
	return false;
}
int main()
{
	int sum=0;
	for(int i=1;i!=n;i++)
		if(valid(i))
			sum+=i;
	cout << sum;
	return 0;
}
