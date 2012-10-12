/*
ID: zzh8829
PROG: agrinet
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
const int INF = 1<<20;
int d[110][110],ps,len;  // distance, point selected, length
bool v[110];			// visited

int main()
{
	ifstream cin("agrinet.in");
	ofstream cout("agrinet.out");
	int n;
	cin >> n;
	for(int i=0;i!=n;i++)
	for(int j=0;j!=n;j++)
	{
		cin >> d[i][j];
		if(d[i][j]==0) d[i][j]=INF;
	}
	sort(int i =0;)
	
	
	cout << len << endl;	
	return 0;
}
