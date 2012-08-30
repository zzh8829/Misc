#include <iostream>
#include <cstdio>
#include <string>
#include <cctype>
using namespace std;

string tmp[256];
char tn='A';

void post(string& exp)
{
	if(exp.size()<3) return ;
	int p;
	for(p=exp.size()-3;p!=-1;p--)
	{
		if(ispunct(exp[p]) && !ispunct(exp[p+1]) && !ispunct(exp[p+2]))
		{
			string t="";
			t+=exp[p+1];
			t+=exp[p+2];
			t+=exp[p];
			exp[p]=tn;
			exp.erase(p+1,2);
			tmp[tn++]=t;
			break;
		}
	}
	if(p==-1)
		return;
	post(exp);
}

string expend(string o)
{
	string n;
	for(int i=0;i!=o.size();i++)
	{
		if(isupper(o[i]))
		n+=tmp[o[i]];
		else
		n+=o[i];
	}
	return n;
}	
int main()
{
	char t;
	while(1)
	{
		string exp="";
		int n=0;
		while(t=getchar())
		{
			if(t==' ') continue;
			if(t=='\n') break;
			exp+=t;
		}
		if( exp[0] == '0')
			break;
		post(exp);
		string now = expend(exp);
		while(1)
		{
			bool ok=true;
			for(int i=0;i!=now.size();i++)
			{
				if(isupper(now[i]))
				{
				ok=false;
				break;
				}
			}
			if(ok)
			break;
			now=expend(now);
		}
		for(int i=0;i!=now.size();i++)
			cout << now[i] <<" ";
		cout <<endl;	
	}	
	system("pause");
	return 0;
}
