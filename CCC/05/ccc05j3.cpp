
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string route[1000];
	string in;
	int num=0;
	while(cin >> in )
	{
		route[num++]= in;
		if(in == "SCHOOL")
		break;
	}
	for(int i=num-2;i!=-1;i--)
	{
		if(i&1)
		cout << " onto " << route[i] <<" street.\n";
		else 
		{
			if( route[i] == "R")
			cout << "Turn LEFT";
			else
			cout << "Turn RIGHT";
		}
	}
	cout << " into your HOME.\n";
	return 0;
}