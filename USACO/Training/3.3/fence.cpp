/*
ID: zzh8829
PROG: fence
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> rd[502];
vector<int>::iterator it;
int circuit[1050];
int pos = 0;

void find_circuit(int i)
{
	if(rd[i].size()==0)
		circuit[pos++] = i;
	else 
	{
		while(rd[i].size()>0)
		{
			// Iterator minimum node
			it =min_element(rd[i].begin(),rd[i].end());
			int j = *it;
			rd[i].erase(it);
			rd[j].erase(find(rd[j].begin(),rd[j].end(),i));
			find_circuit(j);
		}
		circuit[pos++] = i;
	}
}

int main()
{
#ifndef LOCAL
	ifstream cin("fence.in");
	ofstream cout("fence.out");
#endif
	int n,x,y;
	cin >> n;
	for(int i=0;i!=n;i++)
	{
		cin >> x >>y;
		rd[x].push_back(y);
		rd[y].push_back(x);
	}
	// Select start point.
	int s=0,s1=-1,s2;
	for(int i=1;i<=500;i++)
	{
		if(rd[i].size()>0 && !s) s=i;
		if(rd[i].size()%2) s1==-1?s1=i:s2=i;
	}
	s = s1==-1?s:min(s1,s2);
	cout << s << endl;
	find_circuit(s);
	for(int i=n;i!=0;i--)
	cout << circuit[i-1] << endl;
	return 0;
}
