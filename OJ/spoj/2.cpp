#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

int  p[32000],pn=0;

bool prime(int n)
{
	if(!n&1)
	return false;
	for(int i=3;i*i<n+2;i+=2)
	if(n%i==0)
	return false;
	return true;
}

int main()
{
	p[pn++]=2;
	for(int i=3;i<32000;i+=2)
	if(prime(i))
	p[pn++]=i;
	int a,b;
	int nums;
	cin >> nums;
	for(int t = 0;t!=nums;t++)
	{
		bool out[100001] = {false};
		cin >> a >> b;
		if(a<2) a=2;
		int maxp = b-a+1;	
		for(int i=0;i!=pn;i++)
		{
			int begin = a/p[i]; 
			if(begin < 2) begin = 2;
			for(int j=begin;j*p[i]-a<maxp;j++)
			{
				if(j*p[i]-a < 0)
				continue;
				out[j*p[i]-a]=true;	 
			}
		}		
		for(int i=0;i!=maxp;i++)
		if(!out[i])
			printf("%d\n",i+a);
		printf("\n");
	}
	return 0;
}
