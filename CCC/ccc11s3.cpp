#include <iostream>
#include <cmath>
using namespace std;
int height[6]={-1,0,1,0,-1};
bool inside(int m,int a,int b)
{
	if(m==1)
	{
		if( b<=height[a] )
			return true;
		else
			return false;
	}
	float side = pow(5.0,m);
	float as = a/side;
	float bs =b/side;	
	/*
	if(m==2)
	cout << as << " " << bs <<endl;
	*/	
	if( as < 0.2 || as > 0.8 ||	bs > 0.6)
		return false;
	if( (as>=0.2 && as <0.4) ||
			(as>0.6 && as <=0.8) )
	{
		if( bs <= 0.2) 
			return true;
		if( bs > 0.4)
			return false;
	}
	if( as >=0.4 && as <=0.6 && bs <=0.4)
		return true; 
	int ma = side/5;
	return inside(m-1,a%ma,b%ma);
}

int main()
{
	int n;
	cin >> n;
	for(int i=0;i!=n;i++)
	{
		int m,a,b;
		cin >> m >> a >>b;
		if( inside(m,a,b) )
		cout << "crystal" <<endl;
		else 
		cout << "empty" <<endl;
	}
	system("pause");
	return 0;
}
