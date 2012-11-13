#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
using namespace std;

string f = "Fox";
string bf = "Foxen";
string s = "Scissors";
string r = "Rock";
string p = "Paper";

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		string in;
		cin >> in;
		if(in==f)
			cout << bf << endl;
		else if (in==s)
			cout << r << endl;
		else if(in==r)
			cout << p << endl;
		else if (in == p)
			cout << s << endl;
		else return 0;
	}
	
	return 0;
}