/*
ID: zzh8829
PROG: pprime
LANG: C++
*/
#include <iostream>
#include <fstream>
using namespace std;
int table[100001],d1,d2,d3,d4,num=0;

bool prime(int n)
{
for(int i=2;i*i<n+1;i++)

	if(n%i==0)
		return false;
return true;
}
int main()
{
	ifstream cin("pprime.in");
	ofstream cout("pprime.out");
	
	int a,b;
	cin >> a >>b;	
	
    table[num++]=5;       // 1&2
	table[num++]=7;
	table[num++]=11;
	
	for(d1=1;d1!=11;d1+=2)  // 3
	for(d2=0;d2!=10;d2++)
	{
		int pal=100*d1+10*d2+d1;
		if(prime(pal))
			table[num++]=pal;
	}
	
	for(d1=1;d1!=11;d1+=2)  //4 
	for(d2=0;d2!=10;d2++)
	{
		int pal=1000*d1+100*d2+10*d2+d1;
		if(prime(pal))
			table[num++]=pal;
	}
	
	for(d1=1;d1!=11;d1+=2)  //5
	for(d2=0;d2!=10;d2++)
	for(d3=0;d3!=10;d3++)
	{
		int pal=10000*d1+1000*d2+100*d3+10*d2+d1;
		if(prime(pal))
			table[num++]=pal;
	}
	
	for(d1=1;d1!=11;d1+=2) //6
	for(d2=0;d2!=10;d2++)
	for(d3=0;d3!=10;d3++)
	{
		int pal=100000*d1+10000*d2+1000*d3+100*d3+10*d2+d1;
		if(prime(pal))
			table[num++]=pal;
	}
	
	for(d1=1;d1!=11;d1+=2)        //7
	for(d2=0;d2!=10;d2++)
	for(d3=0;d3!=10;d3++)
	for(d4=0;d4!=10;d4++)
	{
		int pal=1000000*d1+100000*d2+10000*d3+1000*d4+100*d3+10*d2+d1;
		if(prime(pal))
			table[num++]=pal;
	}
	
	for(d1=1;d1!=11;d1+=2)   //8
	for(d2=0;d2!=10;d2++)
	for(d3=0;d3!=10;d3++)
	for(d4=0;d4!=10;d4++)
	{
		int pal=10000000*d1+1000000*d2+100000*d3+10000*d4+1000*d4+100*d3+10*d2+d1;
		if(prime(pal))
			table[num++]=pal;
	}
	
	for(int i=0;i!=num;i++)
		if(table[i]>=a&&table[i]<=b)
			cout << table[i]<<endl;

	//system("pause");
	return 0;
}
