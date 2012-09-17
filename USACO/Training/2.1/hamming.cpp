/*
ID: zzh8829
PROG: hamming
LANG: C++
*/
//#include <iostream>
#include <fstream>
#include <bitset>
#include <vector>
using namespace std;
ifstream cin("hamming.in");
ofstream cout("hamming.out");

vector< int > ans;

int dif(int a,int b)
{
	bitset<8> bit(a^b);
	return bit.count();
}

int main()
{
	int n,b,d;
	cin >> n >> b >>d;
	ans.push_back(0);
	for(int i=0;i!=1<<b;i++)
	{
		bool ok= true;
		for(int j=0;j!=ans.size();j++)
		if( dif(i,ans[j]) < d )
		{
			ok = false;
			break;
		}
		if(ok) ans.push_back(i);
		if(ans.size()==n) break;			
	}
	for(int i=0;i!=ans.size();i++)
	{
		if(i && (i%10==0) )cout << endl;
		else if(i) cout << " ";
		cout << ans[i];
	}
	cout << endl;
//	system("pause");
	return 0;
}
