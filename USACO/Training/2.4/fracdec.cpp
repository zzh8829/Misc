/*
ID: zzh8829
PROG: fracdec
LANG: C++
*/
#include <iostream>
#include <fstream>
using namespace std;

int a,b,z,q;		   // a,b,int of a/d ,quotient
int r[100005],rp,cycp; // remainders' position, cycle end/begin position
int de[100005],dn;	   // decimals , decimal count

int main()
{
	ifstream cin("fracdec.in");
	ofstream cout("fracdec.out");
	cin >> a>> b;
	z=a/b;
	a-= z*b;
	while(1)
	{	
		if(r[a])
		{
			cycp=r[a];
			break;
		}
		r[a]=++rp;
		a*=10;
		q = a/b;
		a = a-q*b;
		de[++dn]=q;
		if(a==0)
		{
			rp=-1;
			break;
		}		
	}
	int cnt =2;
	for(int i=z;i>9;i/=10)
		cnt++;
	cout << z << ".";
	for(int i=1;i<=dn;i++,cnt++)
	{
		if(cnt%76==0)
		cout << endl;
		if(i==cycp)
		{
			cout << "(";
			cnt++;
		}
		cout << de[i];
		if(i==rp)
			cout << ")";
	}	
	cout << endl;
	return 0;
}
