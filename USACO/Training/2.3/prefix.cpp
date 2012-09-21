/*
ID: zzh8829
PROG: prefix
LANG: C++
*/
//#include <iostream>
#include <fstream>
#include <string>
using namespace std;
ifstream cin("prefix.in");
ofstream cout("prefix.out");

string p[201],w;
int pn,dp[200050];

int main()
{
	string in;
	while(cin>> in && in !=".")
		p[pn++]=in;
	cin.ignore();
	while(getline(cin,in))
		w+=in;
	dp[0]=1;
	for(int i=0;i!=w.size();i++) if(dp[i])
	for(int j=0;j!=pn;j++)
		if( p[j]==w.substr(i,p[j].size()) )
			dp[i+p[j].size()] = 1;
	for(int i=w.size();i>=0;i--) if(dp[i])
	{
		cout << i << endl;
		break;
	}
	return 0;
}
