#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

int main()
{
#ifndef LOCAL
	ifstream cin("DATA4.txt");
	ofstream cout("OUT4.txt");
#endif
	for(int i=0;i!=5;i++)
	{
		int he = 0;
		int pe = 0;
		string bt;
		getline(cin,bt);
		string tr="";
		for(int i=0;i<bt.size();i++)
		{
			if(isdigit(bt[i]))
			{
				if(isdigit(bt[i+1]))
				{
					he+=10*(bt[i]-'0')+bt[i+1]-'0';
					i+=1;
				}
				else
					he+=bt[i]-'0';
				tr+="x";
			} else {
				tr+=bt[i];
			}
		}
		for(int i=0;i!=tr.size();i++)
		{
			if(tr[i]!='x') pe++;
		}
		cout << pe <<" " << he << endl;
	}
	return 0;
}