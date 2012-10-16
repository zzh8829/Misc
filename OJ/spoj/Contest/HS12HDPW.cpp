#include <iostream>
#include <bitset>
#include <string>
#include <vector>
using namespace std;

int main()
{
	int cs;
	cin >> cs;
	while(cs--)
	{
		vector<int> pos;
		int n;
		cin >> n;
		string in;
		for(int i=0;i!=n;i++)
		{
			cin >> in;
			bitset<6> b1(0),b2(0);
			for(int j=0;j!=in.size();j++)
			{
				bitset<6> bs(in[j]);
				b1[j]=bs[j];
				b2[j]=bs[(j+3)%6];
			}
			pos.push_back(b1.to_ulong());
			pos.push_back(b2.to_ulong());
		}
		cin.ignore();
		getline(cin,in);
		string word = "";
		for(int i=0;i!=pos.size();i++)
			word+=in[pos[i]];
		cout << word << endl;		
	}
	return 0;
}
