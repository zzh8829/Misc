#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <vector>
using namespace std;

int main()
{
#ifndef LOCAL
	ifstream cin("DATA3.txt");
	ofstream cout("OUT3.txt");
#endif
	for (int t=0;t!=5;t++)
	{
		int n;
		cin >> n;
		set<string> cus;
		vector<string> change;
		for(int i=0;i!=n;i++)
		{
			string nm,cs;
			cin >> nm >> cs;
			if(cus.count(cs)>0)
			{
				change.push_back(nm);
			} else {
				cus.insert(cs);
			}
		}
		if(change.size()==0)
			cout << "SPOOKY" << endl;
		else
		{
			for(int i=0;i!=change.size();i++)
			{
				cout << change[i] <<" ";
			}
			cout << endl;
		}
	}
	return 0;
}