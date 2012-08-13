#include <iostream>
using namespace std;

int n=4000001;
int table[99999],sum=0;


int main()
{
	table[0]=1;table[1]=2;
	for(int i=2;table[i-1]<n;i++)
	{
		int a=table[i-1]+table[i-2];
		table[i]=a;
		if(a%2==0)
			sum+=a;
	}
	sum+=2;
	cout << sum<< endl;
	return 0;
}
