#include <iostream>
#include <cstdio>
#include <string>
using namespace std;


int main()
{
	int n;
	cin >> n;
	for(int t=0;t!=n;t++)
	{
		string a,b,c;
		cin >> a >> b >>c;
		if(a.find(b)==0 || a.find(c)==0|| b.find(a)==0|| 
		   b.find(c)==0|| c.find(a)==0 ||c.find(b)==0 ||
			(a.rfind(b)!=-1 && a.rfind(b)+b.size()==a.size())||
			(a.rfind(c)!=-1 && a.rfind(c)+c.size()==a.size())|| 
			(b.rfind(a)!=-1 && b.rfind(a)+a.size()==b.size())|| 
			(b.rfind(c)!=-1 && b.rfind(c)+c.size()==b.size())|| 
		 	(c.rfind(a)!=-1 && c.rfind(a)+a.size()==c.size())||
			(c.rfind(b)!=-1 && c.rfind(b)+b.size()==c.size()))
			cout << "No" <<endl;
		else
			cout <<"Yes" <<endl;
	}
	system("pause");
	return 0;
}
