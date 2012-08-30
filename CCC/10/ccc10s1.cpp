#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

struct PC
{
	string n;
	int s;
};

bool cmp(PC a, PC b)
{
	if(a.s!=b.s)
		return a.s>=b.s;
	return a.n<b.n;
}

PC p[10000];
	
int main()
{
	int n, r,c,d;
	cin >> n;
	string name;
	for(int i=0;i!=n;i++)
	{
		cin>> p[i].n>>r>>c>>d;
		p[i].s =2*r+3*c+d;
	}
	sort(p,p+n,cmp);
	for(int i=0;i!=2;i++)
		if(p[i].s!=0)
			cout <<p[i].n <<endl;
	system("pause");
	return 0;
}
