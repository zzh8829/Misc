#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cctype>
using namespace std;

int main()
{
	int n;
	cin >> n;
	cin.ignore();
	for(int i=0;i!=n;i++)
	{
		vector<string> exp;
		string in;
		int p=0;
		getline(cin,in);
		for(int i=0;i!=in.size();i++)
		{
			if(ispunct(in[i])||in[i]=='X'||i==in.size()-1)
			{
				exp.push_back(in.substr(p,i+1-p));
				p=i+2;
			}
		}
		for(int i=0;i!=exp.size()-1;)
		{
			if(exp.size()==2) break;
			if(exp[i][exp[i].size()-1] == 'X')
			{
				string tmp= exp[i]+" "+exp[i+1];
				tmp.insert(tmp.begin(),'(');
				tmp.insert(isdigit(tmp[tmp.size()-1])?tmp.end():tmp.end()-2,')');
				exp[i] = tmp;
				exp.erase(exp.begin()+i+1);
			}
			else i++;
		}
		for(int i=0;i!=exp.size()-1;)
		{
			if(exp.size()==2) break;
			if(ispunct(exp[i][exp[i].size()-1]))
			{
				string tmp= exp[i]+" "+exp[i+1];
				tmp.insert(tmp.begin(),'(');
				tmp.insert(isdigit(tmp[tmp.size()-1])?tmp.end():tmp.end()-2,')');
				exp[i] = tmp;
				exp.erase(exp.begin()+i+1);
			}
			else i++;
		}
		for(int i=0;i!=exp.size();i++)
		{
			if(i) cout << " ";
			cout << exp[i];
		}
		cout <<endl;
	}	
	system("pause");
	return 0;
}
