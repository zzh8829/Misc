/*
ID: zzh8829
PROG: pprime
LANG: C++
*/
#include <iostream>
using namespace std;
int table[100001],d1,d2,d3,num=0;

bool prime(int n)
{
for(int i=2;i*i<n+1;i++)

	if(n%i==0)
		return false;
return true;
}
int main()
{
	table[num++]=2;
	table[num++]=3;
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
	int a,b;
	while(cin >> a >> b)
	{
	int pn=0;
	for(int i=0;i!=num;i++)
		if(table[i]>=a&&table[i]<=b)
			pn++;
	cout << pn <<endl;
	}

	//system("pause");
	return 0;
}
