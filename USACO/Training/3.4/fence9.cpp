/*
ID: zzh8829
PROG: fence9
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int x,y,p,t;
int gcd(int a,int b)
{
	if(a==0) return b;
	while(b!=0)
	{
		t = b;
		b = a%b;
		a = t;
	}
	return a;
}

int main()
{
#ifndef LOCAL
	ifstream cin("fence9.in");
	ofstream cout("fence9.out");
#endif
	cin >> x >> y >> p;
	cout << p*y/2+1-(gcd(x,y)+gcd(abs(x-p),y)+p)/2 << endl;
	return 0;
}
