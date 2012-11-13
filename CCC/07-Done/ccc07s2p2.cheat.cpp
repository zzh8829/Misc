#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

set< vector<int> > si;

int main()
{
	int n,m;
	cin >> n;
	for(int t=0;t!=n;t++)
	{
		vector<int> fk;
		for (int i = 0; i < 6; ++i)
		{
			cin >> m;
			fk.push_back(m);
		}
		sort(fk.begin(),fk.end());
		if(si.count(fk)>0){
			cout << "Twin snowflakes found." << endl;
			return 0;
		}
		si.insert(fk);
	}
	cout << "No two snowflakes are alike." << endl;	
	return 0;
}