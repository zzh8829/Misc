/*
ID: zzh8829
PROG: ratios
LANG: C++
*/
#include <iostream>
#include <fstream>
using namespace std;

int r[4][4];

int check(int t[3])
{
	for(int i=0;i!=3;i++)
		if(r[0][i] && t[i]%r[0][i] != 0)
			return 0;
	int ra;
	if(r[0][0]!=0)	ra = t[0]/r[0][0];
 	else if(r[0][1]!=0)	ra = t[1]/r[0][1];
 	else if(r[0][2]!=0)	ra = t[2]/r[0][2];
	else ra = 0;
	if(r[0][1]*ra!=t[1]||r[0][2]*ra!=t[2])
		return 0;
	return ra;
}

int main()
{
#ifndef LOCAL
	ifstream cin("ratios.in");
	ofstream cout("ratios.out");
#endif
	for(int i=0;i!=4;i++)
	for(int j=0;j!=3;j++)
		cin >> r[i][j];
	int k[3];
	for(k[0]=0;k[0]!=100;k[0]++)
	for(k[1]=0;k[1]!=100;k[1]++)
	for(k[2]=0;k[2]!=100;k[2]++)
	{
		int t[3]={0};
		for(int i=1;i!=4;i++)
			for(int j=0;j!=3;j++)
				t[j]+=r[i][j]*k[i-1];	
		int c = check(t) ;
		if(c)
		{
			cout << k[0] <<" "<< k[1] <<" "
				<< k[2]<<" " << c << endl;
			return 0;
		}	
	}
	cout << "NONE" <<endl;
	return 0;
	
}
