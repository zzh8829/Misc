#include <iostream>
#include <cmath>
using namespace std;
long double roots[5];
int nroots = 0;
long double equation[5]={0};

void solve()
{
	if(equation[3] && equation [1])
	{
	roots[nroots++] = 0;
	long double tmp = -equation[1]/equation[3] ;
	if (tmp < 0) return;
	roots[nroots++] = sqrt(tmp);
	}
	else if (equation[3] && equation[0])
	{
		roots[nroots++]= pow(int(-equation[0]/equation[3]), 1.0/3.0);
	}
	else if (equation[3])
	{
		roots[nroots++] = 0;
	}
	else
	{
		int delta = equation[1]*equation[1]-4*equation[0]*equation[2];
		if (delta < 0)
		return;
		if ( delta ==0)
			roots[nroots++] = -equation[1]/(2*equation[2]);
		else 
		{
			
			long double d = sqrt(delta);	
			roots[nroots++] = (-equation[1]-d)/(2*equation[2]);
			roots[nroots++] = (-equation[1]+d)/(2*equation[2]);
		}
	}
}

int main()
{
	bool f = true;
	int n;
	long double num;
	int pow;
	cin >> n;
	if(n >4)
		f=false;
	for(int i=0;i!=n;i++)
	{
	cin >> num >> pow;
	equation[pow] = num;
	}
	if(equation[3] && equation[2])
		f=false;
	if(equation[3] && equation[1] && equation[0])
		f=false;
	if(f)
	{
	solve();	
	if(nroots == 0 )
	cout << "NO REAL ROOTS" <<endl;
	else 
	{
		for(int i=0;i!=nroots;i++)
		cout << roots[i] <<endl;
	}
	}
	system("pause");
	return 0;
}

	
	
