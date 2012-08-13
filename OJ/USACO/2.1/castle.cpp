/*
ID: zzh8829
PROG: castle
LANG: C++
*/
#include <iostream>
#include <fstream>

using namespace std;
//ifstream cin("castle.in");
//ofstream cout("castle.out");
int M,N,castle[51][51];


int main()
{	
	cin >> M >> N ;
	int in;
	for(int i=0;i!=M;i++)
		for(int j=0;j!=N;j++)
		{
		cin >> in;
		castle[i][j]=in;
		}


	system("pause");
	return 0;
}