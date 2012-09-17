/*
ID: zzh8829	
PROG: milk2
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

const int MAX=5001;
int start[MAX],end[MAX],maxNo=0,maxOne=0,s,e,n;
int beginT=1000000,endT=0,No=0,One=0;

int main()
{
	ifstream fin("milk2.in");
	ofstream fout("milk2.out");
	fin >> n;

	for(int N=0;N!=n;N++)
	{
		fin>>s>>e;
		if(s<beginT)
		beginT=s;
		if(e>endT)
		endT=e;
		start[N]=s;
		end[N]=e;
	}
    int j;
	for(int i=beginT;i!=endT;i++)
	{

		for(j=0;j!=n;j++)
		{
			if(end[j]>i && start[j]<=i)
			{
				
				No=0;
				One++;           
                break;
            }
		}
        if(j==n)
        {
           One=0;
		   No++;
		}
        if(maxOne<One)
            maxOne=One;
        if(maxNo<No)
            maxNo=No;			
	}
    if(maxOne<One)maxOne=One;
	fout << maxOne <<" "<< maxNo<<endl;
	//system("pause");
	return 0;
}
