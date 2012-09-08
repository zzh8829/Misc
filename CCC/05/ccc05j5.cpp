#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

bool mk(string w)
{
	if(w[0]!='A' && w[0] !='B') return false;
	if(w[0]=='A')
	{
		if(w.size()==1 ) return true;
		if( w[1]!='N' || !mk(w.substr(2)) )
			return false;
	}
	if(w[0]=='B')
	{
		int b=0,s=0,p;
		for(p=0;p!=w.size();p++)
		{
			if(w[p]=='B') b++;
			if(w[p]=='S') s++;
			if(b==s) break;
		}
		if(p==w.size() || p==1  || !mk(w.substr(1,p-1)) ) return false;
		if(p!=w.size()-1 &&( w[p+1]!='N' || !mk(w.substr(p+2)) )) return false;
	}
	return true;
}

int main()
{
	string word;
	while(cin >> word && word!="X")
		cout << (mk(word)?"YES":"NO") << endl;		
	system("pause");
	return 0;
}
