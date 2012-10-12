#include <iostream>
#include <bitset>
#include <set>
#include <string>
using namespace std;

bitset<8> bs[31];
set<string> sb;

int main()
{
	int r,l,in;
	cin >> r >> l;
	for(int i=0;i!=r;i++)
	{
		for(int j=0;j!=l;j++)
		{
			cin >> in;
			bs[i][j]=in;
		}
	}
	for(int i=0;i!=r;i++)
	{
		bitset<8> bt = bs[i];
		for(int j=i+1;j<r;j++)
			bt^=bs[j];
		sb.insert(bt.to_string());
	}
	cout << sb.size() << endl;
	return 0;
} 
