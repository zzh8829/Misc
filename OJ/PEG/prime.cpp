#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

int  p[32000],pn=0;
bool out[5000001];

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
	scanf("%d%d",&a,&b);
	if(a<2) a=2;
	int maxp = b-a+1;	
	for(int i=0;i!=pn;i++)
	{
		int begin = a/p[i]; 
		if(begin < 2) begin = 2;
		for(int j=begin;j*p[i]-a<maxp;j++)
		{
			out[j*p[i]-a]=true;	 
		}
	}		
	for(int i=0;i!=maxp;i++)
		if(!out[i])
			printf("%d\n",i+a);
	system("pause");
	return 0;
}
