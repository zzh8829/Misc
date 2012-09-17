/*
ID: zzh8829
PROG: namenum
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
char key[27]={'2','2','2','3','3','3','4','4','4','5','5','5','6','6','6','7','0','7','7','8','8','8','9','9','9','0'};
string convert(string a)
{
	string num="";
	for(size_t i=0;i!=a.size();i++)
		num +=key[25-('Z'-(int)a[i])];
	return num;
}
int main()
{
	ifstream cin("namenum.in");
	ofstream cout("namenum.out");
	ifstream dic("dict.txt");
	vector<string> dict;
	string word,in;
	while (dic>>word)
		dict.push_back(word);
	cin >> in;
	bool run=true;
	for(size_t i=0;i!=dict.size();i++)
		if(in == convert(dict[i])){
			run = false;
			cout<<dict[i] <<endl;
		}
	if(run)
		cout << "NONE" <<endl;
	return 0;
}
