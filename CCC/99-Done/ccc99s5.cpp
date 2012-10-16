#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

int c[11];
int t[256];
int cn,tn;
int aa[21],bb[21],cc[21];

int main()
{
	int n;
	cin >> n;
	while(n--)
	{
		cn=tn=0;
		for(int i=0;i!=11;i++)
		c[i]=0;
		for(int i=0;i!=256;i++)
		t[i]=0;
		string a,b,an;
		cin >> a >> b >> an;
		string p=a+b+an;
		for(int i=0;i!=p.size();i++)
			if(p.find_first_of(p[i])==i)
				t[p[i]]=tn++;
		for(int i=1;i!=12;i++)
			c[i]=i%10;
		do
		{
			if(c[t[a[0]]] == 0 || c[t[b[0]]] == 0 || c[t[an[0]]] == 0) continue;
			if( ( c[t[a[a.size()-1]]] + c[t[b[b.size()-1]]] )%10!=c[t[an[an.size()-1]]]) continue;
			for(int i=0;i!=21;i++)
				aa[i]=bb[i]=cc[i]=0;
			for(int i=0;i!=a.size();i++)
				aa[a.size()-i-1]= c[t[a[i]]];
			for(int i=0;i!=b.size();i++)
				bb[b.size()-i-1]= c[t[b[i]]];
			for(int i=0;i!=an.size();i++)
				cc[an.size()-i-1]= c[t[an[i]]];
		
			for(int i=0;i!=an.size();i++)
			{
				bb[i]+=aa[i];
				if(bb[i]>9)
				{
					bb[i]-=10;
					bb[i+1]+=1;
				}
			}	
			int ok=0;
			for(int i=0;i!=an.size();i++)
			if(bb[i]!=cc[i])
			{
				ok=1;
				break;
			}
			if(ok) continue;
			for(int i=0;i!=a.size();i++)
				cout << c[t[a[i]]];
			cout <<endl;
			for(int i=0;i!=b.size();i++)
				cout << c[t[b[i]]];
			cout <<endl;
			for(int i=0;i!=an.size();i++)
				cout << c[t[an[i]]];
			cout <<endl;
			break;
		}while(next_permutation(c,c+10));
	}							
	system("pause");
	return 0;
}
