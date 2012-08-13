#include <iostream>
#include <cmath>
using namespace std;

int T;
long long int x,a,b;
long long int xl,temp;
long long int a1,b1;
long long int a2,b2;
long long int a3,_b2;
long long int ra,rb;

int main()
{
	//scanf("%d",&T);
	cin>>T;

	while(T--)
	{
		//scanf("%lld %lld %lld\n",&x,&a,&b);
		cin>>x>>a>>b;
		xl = log10(x) + 1;

		a1 = a,b1=b,temp = xl;
		while(temp--) a1/=10,b1/=10;

		temp = xl,a2=a1,b2=b1;
		while(temp--) a2*=10,b2*=10;

		a2+=x,b2+=x;
		if(a2>=a) ra = a1;
		else ra = a1 +1;

		if(b2<=b) rb = b1;
		else rb = b1 - 1;
		cout<<rb-ra+1<<endl;
	}
	return 0;
}
