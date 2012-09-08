#include <iostream>
#include <cmath>
using namespace std;

int side[6] = {0,1,2,3,4};
int height[6]={0,1,2,1,0};

bool inside(int m,int a,int b)
{
	float mag = pow(5.0,m);
	float am = a/m;
	if( b/m < 0.5 || am <0.2 || am>0.8)
		return false;
	
	float l,m,r;
	l = 1.0/5;
	m = 2.0/5;
	r = 3.0/5;
	rr = 4.0/5;
	int hm = mag/5;
	
	if( am > l && am < m)
	{
		if height[1]*hm
	}
	else if(am > m && am < r)
	{
	}
	else if(am ? r && am < rr)
	{
	}
	
	int h ;
	while( mag != 5 )
	{
	float l = a/mag;
		


}

int main()
{
	int n;
	cin >> n;
	for(int i=0;i!=n;i++)
	{
		int m;
		cin >> m;
		int a,b;
		cin >> a >>b;
		if(inside(m,a,b) )
		cout << "crystal" <<endl;
		else 
		cout << "empty" <<endl;
	}
	
	system("pause");
	return 0;
}
