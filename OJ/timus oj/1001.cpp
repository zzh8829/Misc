#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

double ans[1000000];
double error = 1e-4;
double SQRT(long long a)
{
	if(a==0) return 0;
	long double x =a;
	long double t;
	while(1)
	{
		t = a/x;
		if((x>t?x-t:t-x) < error) break;
		x = (x+t)/2;
	}
	return x;
}
int main()
{
	long long in;
	int n = 0;
	while(cin>>in)
	{
		ans[n++] = SQRT(in);
	}
	for(int i=n-1;i>=0;i--)
		printf("%.4f\n",ans[i]);
	return 0;
}
