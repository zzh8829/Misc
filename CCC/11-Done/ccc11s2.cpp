#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n;
	cin >> n;
	string a="";
	int mark = 0;
	for(int i=0;i!=n;i++)
	{
		string in;
		cin >> in;
		a+=in;
	}
	for(int i=0;i!=n;i++)
	{
		char in;
		cin >> in;
		if(in == a[i])
		 mark ++;
	}
	cout << mark <<endl;
	
	system("pause");
	return 0;
}

