/*
ID: zzh8829
PROG: contact
LANG: C++
*/
#include <iostream>
#include <bitset>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;
const int BN = 13;
int t[9005];

struct B{
	B(bitset<BN> bs,int _t)
	{
		int len = 0;
		for(int i=12;i>=0;i--)if(bs[i])
		{
			len = i;
			break;
		}
		str = bs.to_string().substr(BN-len);
		t = _t;
	}
	string str;
	int t;
};

bool cmp(const B &a,const B &b)
{         
	if(a.t!=b.t)
	return a.t > b.t;
	if(a.str.size()!=b.str.size())
	return a.str.size()<b.str.size();
	return a.str < b.str;		   
}

int main()
{
#ifndef LOCAL
	ifstream cin("contact.in");
	ofstream cout("contact.out");
#endif
	int a,b,n;
	vector< B > vb;
	string seq="",in;
	cin >> a>> b>> n;
	cin.ignore();
	while(getline(cin,in))
		seq+=in;
	for(int i=0;i!=seq.size();i++)
	for(int j=a;j<=b;j++) if(i+j-1 < seq.size())
	{
		bitset<BN> bs(seq.substr(i,j));
		bs[j]=1;
		t[bs.to_ulong()]++;
	}
	for(int i=0;i!=9000;i++)if(t[i])
		vb.push_back(B(bitset<BN>(i),t[i]));
	sort(vb.begin(),vb.end(),cmp);
	vb.push_back(B(bitset<BN>(0),-1));
	int p = 0,last = -1;
	while(n--)
	{
		if( vb[p].t == -1) break;
		if( vb[p].t != last)
		{
			cout << vb[p].t << endl << vb[p].str; 
			last = vb[p].t;
			n++;
		}
		else
		{
			int cnt = 0;
			while(vb[++p].t==last)
			{
				if(((++cnt)%6)==0) cout << endl;
				else cout << " ";
				cout << vb[p].str;
			}
			cout << endl;
		}		
	}
	return 0;
}

