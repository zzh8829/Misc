#include <iostream>
using namespace std;

int main()
{
	int a,b,c=0;
	cin >> a >> b;
	for(int i=1;i!=a+1;i++)
	for(int j=1;j!=b+1;j++)
	{
		if(i>10||j>10)
		continue;
		if(i+j ==10)
		c++;
	}
	if(c==1)
	cout <<"There is 1 way to get the sum 10."<<endl;
	else
	cout <<"There are "<<c<<" ways to get the sum 10." <<endl;
	return 0;
}