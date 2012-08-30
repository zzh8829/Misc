#include <iostream>
using namespace std;
int out,m[1000010]={0};

void cal(long long i)
{
	int t=0;
	long long tmp=i;
	while(i>1000005 || m[i]==0)
	{
		t++;
		if(i&1)
			i=i*3+1;			
		else
			i=i/2;		
	}
	m[tmp]=t+m[i];
}

int main()
{
	int i;
	m[1]=1;
	for(long long i=2;i!=1000001;i++)
		cal(i);	
	cin >> i;
	cout << m[i]-1 <<endl;
	return 0;
}
