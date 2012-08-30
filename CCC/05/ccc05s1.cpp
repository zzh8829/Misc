#include <iostream>
#include <string>
#include <cctype>
using namespace std;

char num[27] = {'2','2','2','3','3','3','4','4','4','5','5','5','6','6','6','7','7','7','7','8','8','8','9','9','9','9'};

int main()
{
	int n;
	cin >> n;
	for(int t=0;t!=n;t++)
	{
		string in;
		cin >> in;
		for(int i=0;i!=in.size();i++)
		{
			if(in[i] == '-')
			in.erase(i,1);
		}
		for(int i=0;i!=in.size();i++)
		{
			if(isalpha(in[i]))
			{
				in[i] = num[(char)in[i]-'A'];
			}
		}
		for(int i=0;i!=10;i++)
		{
			cout << in[i];
			if(i==2 || i==5)
			cout << "-" ;
		}
		
		cout << endl;
	}
	return 0;
}
