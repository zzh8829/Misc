#include <iostream>
#include <string>
using namespace std;

string p = "ABCDE";

void b1(int n)
{
	for(int i=0;i!=n;i++)
	{
		string t(1,p[0]);
		p.erase(0,1);
		p.insert(4,t);
	}
}

void b2(int n)
{
	for(int i=0;i!=n;i++)
	{
		string t(1,p[4]);
		p.insert(0,t);
		p.erase(5,1);
	}
}

void b3(int n)
{
	if(n%2!=0)
	{
		string t(1,p[0]);
		p[0] = p[1];
		p.replace(1,1,t);
	}
}


int main()
{
	int in;
	int n;
	while(cin >> in)
	{
		if(in == 4 )break;
		cin >> n;
		switch(in)
		{
		case 1: b1(n); break;
		case 2: b2(n); break;
		case 3: b3(n); break;
		}
	}
	for(int i=0;i!=5;i++)
	{
		if(i)
		cout << " ";
		cout << p[i] ;
	}
	cout << endl;
	return 0;
}
