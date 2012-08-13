#include<iostream>
#include<cmath>
using namespace std;

double diedai(double a,double b,double c,double d,double e,double x);

int main()
{	
	double a,b,c,d,e;
	double x=10000.0;
	cin>>a>>b>>c>>d>>e;
	x=diedai(a,b,c,d,e,x);
	cout<<x<<endl;
	system("pause");
	return 0;
}

double diedai(double a,double b,double c,double d,double e,double x)
{
	while(abs(a*x*x*x*x+b*x*x*x+c*x*x+d*x+e)>0.000001)
	{
		x=x-(a*x*x*x*x+b*x*x*x+c*x*x+d*x+e)/(3*a*x*x*x+2*b*x*x+c*x+d);
	}
	return x;
}
