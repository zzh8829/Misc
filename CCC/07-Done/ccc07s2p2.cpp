#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <set>
#include <vector>
#include <string>
using namespace std;

int fk[6];
set< vector<int> > si;

int main()
{
	int n;
	cin >> n;
	for(int t=0;t!=n;t++)
	{
		int min = 0;
		int pos = 0;
		vector<int> flkz;
		vector<int> flkn;
		for (int i = 0; i < 6; ++i)
		{
			cin >> fk[i];
			if(fk[i]>min){
				min = fk[i];
				pos = i;
			}
		}
		for (int i = 0; i < 6; ++i)
		{
			flkz.push_back(fk[(i+pos)%6]);
		}
		for (int i = pos+6; i > pos; i--)
		{
			flkn.push_back(fk[i%6]);
		}
		if(si.count(flkz)>0 || si.count(flkn)>0){
			cout << "Twin snowflakes found." << endl;
			return 0;
		}
		si.insert(flkz);
		si.insert(flkn);
	}
	cout << "No two snowflakes are alike." << endl;	
	return 0;
}