// COOL! BTW: Thanks Wikipedia ...
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

int V,T,R1,R2,n,s;
char var,val,v1,v2;
string line;
char v[27],t[27];
vector<pair<char, char> > r1;
vector<pair<char, pair<char,char> > > r2;
bool mhoc[31][31][128];

int main()
{
	cin >> V >> T;
	for(int i=0;i!=V;i++)
		cin >> v[i];
	for(int i=0;i!=T;i++)
		cin >> t[i];
	cin >> R1;
	for(int i=0;i!=R1;i++)
	{
		cin >> var >> val;
		r1.push_back(make_pair(var,val));
	}
	cin >> R2;
	for(int i=0;i!=R2;i++)
	{
		cin >> var >> v1 >> v2;
		r2.push_back(make_pair(var,make_pair(v1,v2)));
	}
	cin >> n;
	cin.ignore();
	for(int i=0;i!=n;i++)
	{
		memset(mhoc,0,sizeof(mhoc));
		getline(cin,line);
		s = line.size();
		for(int i=0;i!=R1;i++)
		for(int j=0;j!=s;j++)
		if(line[j]==r1[i].second)
			mhoc[j][1][r1[i].first]=1;
		for(int len=2;len<=s;len++)
		for(int st=0;st+len<=s;st++)
		for(int pt=1;pt<len;pt++)
		for(int r=0;r!=R2;r++)
		if(mhoc[st][pt][r2[r].second.first] 
		    && mhoc[st+pt][len-pt][r2[r].second.second])
			mhoc[st][len][r2[r].first]=1;
		cout << mhoc[0][s][v[0]] << endl;
	}
	return 0;
}
