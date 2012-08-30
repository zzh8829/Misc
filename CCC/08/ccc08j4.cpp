#include <iostream>
#include <string>
#include <stack>
#include <cctype>
using namespace std;

int main()
{
	int i;
	string s;
	while(getline(cin,s) && s!="0")
	{
		stack<string> ss;
		for(int i=0;i!=s.size();i++)
			if(s[i] ==' ')
				s.erase(i,1);
		string s1,s2;
		for(int i=s.size()-1;i!=-1;i--)
		{
			if( isdigit(s[i]))
				ss.push(s.substr(i,1));
			else
			{
				s1=ss.top(); ss.pop();
				s2=ss.top(); ss.pop();
				ss.push(s1+s2+s[i]);
			}
		}
		string o = ss.top();
		for(int i=0;i!=o.size();i++)
			cout << o[i] <<" ";
		cout <<endl;
	}
	return 0;
}
