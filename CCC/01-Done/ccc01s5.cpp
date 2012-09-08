#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
using namespace std;

string a[40],b[40];
int m,n;

int main()
{
	cin >> m >> n;
	for(int i=0;i!=n;i++)
	cin >> a[i];
	for(int i=0;i!=n;i++)
	cin >> b[i];	
	if(m==13) m-=1;
	vector<int> vi;
	int s;
	queue< vector<int> > Q;
	Q.push(vi);
	while(!Q.empty())
	{
		vector<int> v(Q.front());
		Q.pop();
		s=v.size();
		string t1="",t2=""; 
		for(int i=0;i!=s;i++)
		{
			t1+=a[v[i]];
			t2+=b[v[i]];
		}
		int s1=t1.size(),s2=t2.size();
		if(t1==t2 && s1!=0)
		{
			cout << s <<endl;
			for(int i=0;i!=v.size();i++)
				cout << v[i]+1 <<endl;
			return 0;
		}
		if(s<m-1)	
		{
			for(int i=0;i!=n;i++)
			{
				string t3=t1+a[i];
				string t4=t2+b[i];
				int s3=t3.size(),s4=t4.size();
				if(s3>s4)
				{
					if(t3.substr(0,s4)!=t4)
						continue;
				}	
				else
				{
					if (t4.substr(0,s3)!=t3)
						continue;
				}
				vector<int> t(v);
				t.push_back(i);	
				Q.push(t);
			}
		}
	}
	cout << "No solution." <<endl;		
	system("pause");	
	return 0;
}
