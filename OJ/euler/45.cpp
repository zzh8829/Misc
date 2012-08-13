#include <iostream>
#include <cstdio>
using namespace std;

long long tri(long long n)
{
	return n*(n+1)/2;
}

long long penta(long long n)
{
	return n*(3*n-1)/2;
}

long long hex(long long n)
{
	return n*(2*n-1);
}

bool ch(long long n,long long p)
{
for(long long i=0;i!=n;i++)
	if(i*(2*i-1) == p )
		return true;
return false;
}
bool cp(long long i,long long n)
{
for(long long a=100;a!=i;a++)
{	
	long long p = penta(a);
    if(p==n)
    {
    	//cout << a <<endl;
        if(ch(a,p))
        	return true;
        return false;
    }
}
return false;
}

int  main()
{

long long ans = 0;

for(int i=286;i!=1000000&&ans==0;i++)
{
int t= tri(i);
if(cp(i,t))
{
ans = t;
break;
}
}
cout << ans <<endl;
return 0;
}


