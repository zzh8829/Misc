#include <iostream>
#include <cstdio>
#include <string>
#include <map>
using namespace std;

map<string,int> dict;
int d;

int main()
{
	int n;
	cin >> n;
	cin.ignore();
	for(int cs=0;cs!=n;cs++)
	{
		dict.clear();
		d=0;
		string line;
		while(getline(cin,line) && !line.empty())
		{
			int last=0;
			for(int i=0;i!=line.size();i++)
			{
				if(line[i+1]==' ' || i==line.size()-1)
				{
					string word = line.substr(last,i+1-last);
					if(dict.find(word)==dict.end())
					{
						dict.insert(make_pair(word,++d));
						cout << word << " ";
					}
					else
					{
						cout << dict[word] <<" ";	
					}	
					last = i+2;			
				}
			}
			cout << endl;
		}
	}
	system("pause");
	return 0;
}
