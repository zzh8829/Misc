/*
ID:zzh88291
PROB:friday
LANG:C++
*/
#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("friday.in");
ofstream fout("friday.out");
int month[12]={31,28,31,30,31,30,31,31,30,31,30,31};
int Days[7]={0};
int first =0;
	
bool isLeap(int n)
{
     if(n%4==0&&((n%100!=0)||(n%400)==0))
         return true;
     else return false;
}

void year(int n)
{
	for(int i=1900;i!=1900+n;i++)
	{
		for(int j=0;j!=12;j++)
		{
			int thir=(first+13)%7;
			first=(first+month[j])%7;
			if(isLeap(i)&&j==1)
				first=(first+29)%7;
			Days[thir]++;
		}
	}
	fout << Days[6];
	for(int k=0;k!=6;k++)
        fout <<" " <<Days[k];
    fout <<endl;
}

int main()
{
	int n;
	fin >>n;
	year(n);
	//system("pause");
	return 0;
}
