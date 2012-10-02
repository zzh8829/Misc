/*
ID: zzh8829
PROG: humble
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <set>
using namespace std;

int pn,p[101],n;
set<int> si;

int main()
{
#ifndef LOCAL
	ifstream cin("humble.in");
	ofstream cout("humble.out");
#endif
	cin >> pn >> n;
	for(int i=0;i!=pn;i++)
	{
		cin >> p[i];
		si.insert(p[i]);
	}
	for(int i=0;i!=pn;i++)
	{
		set<int>::iterator it = si.begin();
		while(1)
		{
			int t = (*it)*p[i];
			if(t<0) break;
			if(si.size()>n)
			{
				si.erase(--si.end());
				if(t>(*(--si.end()))) break;
			}
			si.insert(t);
			it++;
		}
	}
	cout << *(--si.end())<< endl;
	return 0;
}
