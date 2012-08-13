#include <iostream>
using namespace std;
int m[1000010]={0};

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
	int i=1,j=1000001,out = 0,num=0;
	m[1]=1;
	for(long long i=2;i!=1000002;i++)
	    cal(i);	
	for(int n=i;n!=j+1;n++)
	if(m[n]>out)
	{
	out=m[n];
	num=n;
	}
	cout << num << endl;
	return 0;
}
