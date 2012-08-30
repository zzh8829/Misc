#include <iostream>
using namespace std;

int g(int a,int b)
{
while( 1 )
    {
        a = a % b;
		if( a == 0 )
			return b;
		b = b % a;

        if( b == 0 )
			return a;
    }
}
int main()
{
int a,b;
cin >> a >> b;
int s =  a/b;
cout << s ;
int c = a-b*s;
if(c!=0)
{
int gcd = g(c,b);
cout <<" "<< c/gcd <<"/" << b/gcd <<endl;
}
return 0;
}