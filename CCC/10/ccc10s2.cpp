#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

string code[256];
char m[256];
int s;
int main()
{
	int n;
	cin >> n;
	char c;
	string in;
	for(int i=0;i!=n;i++)
	{
		cin >> c >> in;
		code[c] = in;
		m[s++]=c;
	}
	string encode;
	string decode="";
	cin >> encode;
	while(encode.size()>0)
	{
		int pos;
		for(int i=0;i!=s;i++)
		{
			pos = encode.find(code[m[i]]);
			if(pos==0)
			{
				decode+=m[i];
				encode.erase(0,code[m[i]].size());
				break;
			}
		}
	}
	cout << decode <<endl;
	system("pause");
	return 0;
}
