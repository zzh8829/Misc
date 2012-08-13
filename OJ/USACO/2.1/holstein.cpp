/*
ID: zzh8829
PROG: helstein
LANG: C++
*/
#include <iostream>
#include <fstream>

using namespace std;
//ifstream cin("holstein.in");
//ofstream cout("holstein.out");
int V,cow[26],G,feed[16][26];

int main()
{
	cin>>V;
	int in;
	for(int i=0;i!=V;i++)
	{
		cin >> in;
		cow[i]=in;
	}
	cin >> G;
	for(int i=0;i!=G;i++)
		for(int j=0;j!=V;j++)
		{
			cin >> in;
			feed[i][j]=in;
		}
	
	
	

	system("pause");
	return 0;
}