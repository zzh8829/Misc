#include <iostream>
#include <string>
using namespace std;
int main()
{
	int n;
	string star = "****",in;
	cin >> n;
	cin.ignore();
	for(int t=0;t!=n;t++)
	{
		getline(cin,in);
		int pos=0;
		for(int i=0;i!=in.size()+1;i++)
		if(i==in.size() || in[i] == ' ')
		{
			if( i - pos == 4 )
			in.replace(pos,4,star);
			pos = i+1;
		}
		cout << in <<endl;
	}
	return 0;
}
			
