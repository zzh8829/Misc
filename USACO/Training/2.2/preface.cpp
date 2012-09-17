/*
ID: zzh8829
PROG: preface
LANG: C++
*/
//#include <iostream>
#include <fstream>
#include <string>
using namespace std;
ifstream cin("preface.in");
ofstream cout("preface.out");

int cnt[256];
string r = " IVXLCDM";
struct roman_t 
{ 
	int value; 
	char* roman; 
};
roman_t data[14] = {
	1000, "M",900, "CM",500, "D",400, "CD",100, "C",90, "XC",
	50, "L",40, "XL",10, "X",9, "IX",5, "V",4, "IV",1, "I"
};
string itor(int num)
{
	string result="";
	for ( int i=0;i!=13;i++)
	{
		while( num >= data[i].value )
		{
			result += data[i].roman;
			num-=data[i].value;
		}
	}
	return result;
}

int main()
{
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		string ro = itor(i);
		for(int i=0;i!=ro.size();i++)
			cnt[ ro[i] ] ++;
	}
	for(int i=1;i<=7;i++)if(cnt[r[i]])
		cout << r[i] <<" " << cnt[r[i]] <<endl;
	//system("pause");
	return 0;
}
