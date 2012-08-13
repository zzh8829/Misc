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
	int i,j;
	m[1]=1;
	for(long long i=2;i!=1000001;i++)
		cal(i);	
	while(cin >> i>> j)
	{
		out =0;
		if(i<=j)
			for(int n=i;n!=j+1;n++)
				if(m[n]>out)
					out=m[n];
		if(i>j)
			for(int n=j;n!=i+1;n++)
				if(m[n]>out)
					out=m[n];
		cout << i << " " << j <<" " << out << endl;
	}
	return 0;
}
