#include <iostream>
#include <string>
using namespace std;

int main()
{
	int pos = 1;
	string pre = "You are now on square ";
	int in ;
	while(cin >> in )
	{
		if(in == 0)
		{
			cout << "You Quit!" <<endl;
			break;
		}
		pos += in;
		
		if(pos==54) pos =19;
		if(pos==90) pos = 48;
		if(pos==99) pos = 77;
		if(pos = 9) pos = 34;
		if(pos = 40) pos = 64;
		if(pos = 67)pos = 86;
		if(pos>=100)
		{
		cout << pre << 100 <<endl;
		cout << "You Win!" <<endl;
		break;
		}
		cout << pre << pos << endl;
	}
	return 0;
}
		