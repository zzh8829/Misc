#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;
bool cmp(string a,string b)
{
	for(int i=0;i!=a.size();i++)
	{
		if(isupper(a[i]))
			a[i] = tolower(a[i]);
	}
	for(int i=0;i!=b.size();i++)
	{
		if(isupper(b[i]))
			b[i] = tolower(b[i]);
	}
	return a<b;
}


int main()
{
	int n;
 	cin >> n;
	for(int i=0;i!=n;i++)
	{
		int a,b,c;
		cin >> a >> b >> c;
		string sa[22];
		string sb[22];
		string sc[22];
		string ans[20000];
		int ns = 0;
		cin.ignore();
		for(int j=0;j!=a;j++)
			getline(cin, sa[j]) ;
		for(int j=0;j!=b;j++)
			getline(cin,  sb[j]);
		for(int j=0;j!=c;j++)
			getline(cin, sc[j]);
		sort(sa,sa+a,cmp);
		sort(sb,sb+b,cmp);
		sort(sc,sc+c,cmp);
		for(int j=0;j!=a;j++)
		for(int k=0;k!=b;k++)
		for(int l=0;l!=c;l++)
		{
			cout << sa[j] + " "+ sb[k] + " "+ sc[l] + "." <<endl;;
		}
		//sort(ans,ans+ns);
	//	for(int j=0;j!=ns;j++)
	//	cout << ans[j] <<endl;
		cout <<endl;
	}
	system("pause");
	return 0;
}
