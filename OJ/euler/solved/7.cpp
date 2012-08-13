#include <iostream>
using namespace std;

bool prime(int n)
{
if(n==2)
return true;
for(int i=2;i*i<n+1;i++)
	if(n%i==0)
		return false;
return true;
}

int main()
{
	int table[10003],num=2;
	table[1]=2;
	for(int i=3;num!=10003;i+=2)
	{
		if( prime(i) )
			table[num++]=i;
	}
	cout << table[10001] <<endl;
	return 0;
}
