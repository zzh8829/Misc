#include <iostream>
using namespace std;
int main()
{
	int c,r;
	cin >> c >> r;
	int x =0,y=0;
	int a,b;
	while(cin >> a >> b)
	{
		if(a==0 && b==0)
		break;
		x+=a;
		y+=b;
		if(x<0)
		x=0;
		if(x>c)
		x=c;
		if(y<0)
		y=0;
		if(y>r)
		y=r;
		cout << x << " " << y <<endl;
	}
	return 0;
}