#include <iostream>
#include <string>
using namespace std;
int main()
{
	string in;
	while(cin >> in && in != "quit!")
	{
		int ls = in.size();
		if(ls > 4 )
		{
			if(in[ls-1] == 'r' && in[ls-2] == 'o' )
			{
				if(in[ls-3] != 'a' && in[ls-3] != 'e' && in[ls-3] != 'i' &&
						in[ls-3] != 'o' && in[ls-3] != 'u' && in[ls-3] != 'y')
				in.insert(ls-1,"u");
			}
		}
		cout << in <<endl;
	}
	return 0;
}
