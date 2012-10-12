/*
ID: zzh8829
PROG: kimbits
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <bitset>
#include <algorithm>
using namespace std;

long long n,l,i,c,b,t;

int main()
{
#ifndef LOCAL
	ifstream cin("kimbits.in");
	ofstream cout("kimbits.out");
#endif
	cin >> n >> l >> i;
	for(;;b++)
	{
		bitset<32> bs(b);
		if(bs.count()<=l)
		{
			string s = bs.to_string();
			int  p = s.find_first_of("1");
			if(p<n||p>s.size()-n) p =s.size()-n;
			s = s.substr(p);
			if(++c==i)
			{
				cout << s << endl;
				break;
			}
			long long c1 = 0;
			for(int p=0;p<n-1;p++)
			{
				if(s[p]=='1') c1++;
				if(c1 && l-c1 >= n-p  )
				{
					t= bitset<32>(string(n-p-1,'1')).to_ulong();
					if(c+t<=i) b+=t-1,c+=t-1;
					else b+=(i-c)-1,c=i-1;
					break;
				}
			}	
		}
	}
	return 0;
}
	

