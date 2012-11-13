#include <iostream>
#include <cmath>
using namespace std;
int height[6]={-1,0,1,0,-1};
int next[6] = {-1,1,2,1,-1};
bool inside(int m,int a,int b)
{
	if(m==1)
	{
		if( b<=height[a] )	return true;
		else return false;
	}
	float side = pow(5.0,m-1);
	int as = a/side;
	int bs = b/side;
	if( bs <= height[as] ) return true;
	if( bs > next[as] ) return false;	
	int ma = side;
	return inside(m-1,a%ma,b%ma);
}

int main()
{
	int n,m,a,b;;
	cin >> n;
	for(int i=0;i!=n;i++)
	{
		cin >> m >> a >>b;
		if( inside(m,a,b) )
		cout << "crystal" <<endl;
		else 
		cout << "empty" <<endl;
	}
	system("pause");
	return 0;
}
