#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

int main()
{
	string f="aeiouAEIOU ";
	int n;
	cin >> n;
	cin.ignore();
	for(int i=0;i!=n;i++)
	{
		string p[5];
		string in;
		for(int j=0;j!=4;j++)
		{
		getline(cin,in);
		for(int k=0;k!=in.size();k++)
		{
			if(isupper(in[k]) )
			in[k] = tolower(in[k]);
		}
		int pos = in.find_last_of(f);
		if(pos==-1)
		pos = 0;
		if(in[pos]==' ')
		++pos;
		p[j] = in.substr(pos);
		}
		if(p[0]==p[1] && p[1] == p[2] && p[2]==p[3])
			cout << "perfect" <<endl;
		else if( p[0]==p[1] && p[2]==p[3])
			cout << "even" <<endl;
		else if( p[0]==p[2] && p[1]==p[3])
			cout << "cross" <<endl;
		else if( p[0]==p[3] && p[1]==p[2])
			cout << "shell" <<endl;
		else 
			cout << "free" <<endl;	
	}
	system("pause");
	return 0;
}
