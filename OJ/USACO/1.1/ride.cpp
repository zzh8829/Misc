/*
ID: zzh8829	
PROG: ride
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <iterator>

using namespace std;

int cal(string name)
{
	int pro = 1;;
	string::iterator iter= name.begin();
	for( ;iter!=name.end();iter++)
	{
		pro*= (*iter-'A'+1);
	}
	return pro;
}

string compare(string a, string b)
{
	int n=cal(a);
	int m=cal(b);
	if(n%47 == m%47)
	return "GO" ;
	else
	return "STAY";
}

int main() {
	ofstream fout ("ride.out");
	ifstream fin ("ride.in");
	string a, b;
	fin >> a >> b;
	fout << compare(a,b) <<endl;
	system("pause");
	return 0;
}
