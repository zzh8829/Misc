#include <iostream>
#include <string>
#include <map>
using namespace std;
int m[101][101],n,pgcode;
map<string,int> mp;
int main()
{
	cin >> n;
	while(cin.get()!='\n'); // WEIRD SPACE!!! dammm.
	for(int pg = 0;pg!=n;pg++)
	{
		string html,tmp;
		getline(cin,html);
		if(!mp.count(html))mp.insert(make_pair(html,pgcode++));
		string page="";
		while(getline(cin,tmp))
		{
			page+=tmp;
			if(tmp=="</HTML>") break;
		}
		int found = 0;
		while(true)
		{
			found=page.find("<A HREF=",found+1);
			if(found==-1)break;
			int pos = page.find("\"",found+9);
			if(pos==-1)break;
			string lk = page.substr(found+9,pos-found-9);
			if(!mp.count(lk))mp.insert(make_pair(lk,pgcode++));
			cout << "Link from "<< html << " to "<<lk<<endl;
			m[mp[html]][mp[lk]]=1;		
		}
	}
	for(int k=0;k!=pgcode;k++)
	for(int i=0;i!=pgcode;i++)
	for(int j=0;j!=pgcode;j++)
	if(m[i][k]&&m[k][j]) m[i][j]=1;
	while(true)
	{
		string s1,s2;
		getline(cin,s1);
		if(s1=="The End") break;
		getline(cin,s2);
		cout << (m[mp[s1]][mp[s2]]?"Can surf from ":"Can't surf from ")<< s1 <<" to " <<s2 << endl;
	}
	return 0;
}
	 
