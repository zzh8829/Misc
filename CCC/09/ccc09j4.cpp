#include <iostream>
#include <string>
#include <cctype>
using namespace std;
string msg="WELCOME.TO.CCC.GOOD.LUCK.TODAY";
int main()
{
	int n;
	cin >> n;
	int len=n;
	while(1)
	{
		if(len>msg.size())
		len = msg.size();
		if(len<msg.size() && msg.find(".")!=-1 && isalpha(msg[len]) )
			len = msg.substr(0,len).find_last_of(".");		
		string t =msg.substr(0,len);
		int pos=0;
		while(1)
		{
			if(t.size()>=n)
				break;	
			pos= t.find('.',pos);
			if(pos==-1)
			{
				if(t.find('.')==-1) 
				pos = t.size();
				else 
				{
				pos=0;
				continue;
				}
			}
			t.insert(pos,".");
			while( pos<t.size()&&t[pos]=='.')pos+=2;
			if(pos>=t.size()) pos=0;
		}
		cout << t <<endl;
		msg.erase(0,len+1);
		len=n;
		if(len>=msg.size()+n-1)
			break;
	}
	system("pause");
	return 0;
}
