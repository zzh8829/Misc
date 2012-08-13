#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

long double poly[102];

long double solve(int max,long double x)
{
	long double tmp3 = 0.0;
	do
	{
		long double tmp = 0.0;
		for(int i=0;i!=max+1;i++)
		{
			if(poly[i])
			tmp += poly[i]*pow(x,i);
		}
		
		long double tmp2 = 0.0;
		for(int i=1;i!=max+1;i++)
		{
			if(poly[i])
			tmp2 += i*poly[i]*pow(x,i-1);
		}
		
		x=x-tmp/tmp2;
		tmp3 = 0.0;
		for(int i=0;i!=max+1;i++)
		{
			if(poly[i])
			tmp3 += poly[i]*pow(x,i);
		}
		tmp3 = fabs(tmp3);
	}while(tmp3>0.000001);
	return x;
}

int main()
{
	int n;
	cin >> n;
	int pow,coe;
	int max = 0;
	for(int i=0;i!=n;i++)
	{
		scanf("%d%d",&coe,&pow);
		poly[pow] = coe;
		if(!max)
			max = pow;
	}
	long double ans[10] ;
	int nans=0;
	float a = solve(max,-10000.0);
	ans[nans++]=a;
	float b = solve(max,-100.0);
	if( b!= a)
	ans[nans++]=b;
	
 	a = solve(max,0);
	if(a!= b)
	ans[nans++]=a;
	b = solve(max,100.0);
	if(b!= a)
	ans[nans++]=b;
	a = solve(max,10000.0);
	if(a!= b)
	ans[nans++]=a;
	
	for(int i=0;i!=nans;i++)
	cout << ans[i] << endl;
	
	
	system("pause");
	return 0;
}
