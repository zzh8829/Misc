/*
ID: zzh8829
PROG: lamps
LANG: C++
*/
//#include <iostream>
#include <fstream>
#include <vector>
#include <set>
using namespace std;
ifstream cin("lamps.in");
ofstream cout("lamps.out");

int n,c,in,on[101],ons,off[101],offs;

struct cmp
{	
	bool operator() (vector<int> v1,vector<int> v2)
	{
		for(int i=0;i!=v1.size();i++)
			if(v1[i]!=v2[i]) return v1[i]<v2[i];
		return false;
	}
};

set< vector<int> ,cmp > answer;

void check(int s1,int s2,int s3,int s4,int sn)
{
	int b[6]={1,1,1,1,1,1};
	if(sn>c) return;
	if(s1) for(int i=0;i!=6;i++)
		b[i] = !b[i];
	if(s2)for(int i=0;i<6;i+=2)
		b[i] = !b[i];
	if(s3) for(int i=1;i<6;i+=2)
		b[i] = !b[i];
	if(s4)
	{
		b[0] = !b[0];
		b[3] = !b[3];
	}
	for(int i=0;i!=ons;i++)
		if(b[( (on[i]%6?on[i]%6:7) -1 )]!=1) return;
	for(int i=0;i!=offs;i++)
		if(b[( (off[i]%6?off[i]%6:7) -1 )]!=0) return;
	vector<int> vi;
	for(int i=0;i!=n;i++)
	vi.push_back(b[i%6]);
	answer.insert(vi);
}

int main()
{
	cin >> n >> c;
	while(cin >> in && in !=-1)
		on[ons++] = in;
	while(cin >> in && in !=-1)
		off[offs++] = in;
	for(int s1=0;s1!=2;s1++)
	for(int s2=0;s2!=2;s2++)
	for(int s3=0;s3!=2;s3++)
	for(int s4=0;s4!=2;s4++)
	check(s1,s2,s3,s4,s1+s2+s3+s4);
	if(!answer.empty())
	{
		set< vector<int> ,cmp >::iterator it= answer.begin();
		for(;it!=answer.end();it++)
		{
			for(int j=0;j!=(*it).size();j++)
			cout << (*it)[j];
			cout << endl;
		}
	}
	else
		cout << "IMPOSSIBLE" <<endl;
	return 0;
}
