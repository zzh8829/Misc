/*
ID: zzh8829
PROG: transform
LANG: C++
*/
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
int n;
char before[11][11],after[11][11],temp[11][11];
bool cmp( char a[11][11],char b[11][11] )
{
	for (int i=0;i!=n;i++)
	for(int j=0;j!=n;j++)
	if(a[i][j]!=b[i][j])
	return false;
	return true;
}
void r90(char b[11][11])
{
	char a[11][11];
	memcpy(a,b,sizeof(char)*121);
	for(int i=0;i!=n;i++)
	for(int j=0;j!=n;j++)
	temp[j][n-i-1]=a[i][j];      
}
void ref(char a[11][11])
{
	
	for(int i=0;i!=n;i++)
	for(int j=0;j!=n;j++)
	temp[i][j]=a[i][n-j-1];
}
int main()
{
	ifstream fin("transform.in");
	ofstream fout("transform.out");
	fin >> n;
	char in;
	for(int i=0;i!=n;i++)
	for(int j=0;j!=n;j++)
	{
		fin >> in;
		before[i][j]=temp[i][j]=in;
	}
	for(int i=0;i!=n;i++)
	for(int j=0;j!=n;j++)
	{
		fin >> in;
		after[i][j]=in;
	}
	bool run=true;
	for(int i=0;i!=3;i++)
	{
		r90(temp);
		if( cmp(temp,after) && run )
		{ 
			fout << i+1 <<endl;
			run = false;
		}
	}
	if(run)
	{
		ref(before);
		if( cmp(temp,after))
		{ 
			fout << 4 <<endl;
			run = false;
		}
	}
	if(run)
	{
		ref(before);
		for(int i=0;i!=3 && run ;i++)
		{
			r90(temp);
			if( cmp(temp,after) && run )
			{ 
				fout << 5 <<endl;
				run = false;
			}
		}
	}
	if( cmp(before,after) && run )
	{ 
		fout <<6 <<endl;
		run = false;
	}
	if(run)
	fout << 7 <<endl;
	//system("pause");
	return 0;
}