#include <iostream>
using namespace std;

int nmax=1000,pmax=0;
bool pal(int n)
{
if( n/100000==n%10 && (n/10000%10)==(n%100)/10 && (n/1000)%10==(n%1000)/100)
return true;
return false;
}

int main()
{
	for(int i=800;i!=nmax;i++)
	for(int j=800;j!=nmax;j++)
	{
	int pv=i*j;
	if(pal(pv)&&pv>pmax)
		pmax=pv;
	}
	cout << pmax <<endl;
	return 0;
}
	
