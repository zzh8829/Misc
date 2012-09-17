/*
ID: zzh8829
PROG: frac1
LANG: C++
*/
//#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
ifstream cin("frac1.in");
ofstream cout("frac1.out");
int N,table[99999][2],num=0;

int gcd(int a,int b)
{
	int tmp;
	while(b>0)
	{
		tmp=b;
		b=a%b;
		a=tmp;
	}
	return a;      
}

void solve()
{
	int a,b;
	for(a=1;a!=N+1;a++)
	for(b=1;b!=a;b++)
	if(gcd(b,a)==1)
	{
		table[num][0]=b;
		table[num++][1]=a;
	}
	int i,j,tmp,tmp2;
	for( i=1;i<num;i++)
	{
		j=i;
		while(j>0 && table[j-1][0]*table[j][1]>table[j][0]*table[j-1][1])
		{
			tmp=table[j][0];
			tmp2=table[j][1];
			table[j][0]=table[j-1][0];
			table[j][1]=table[j-1][1];
			table[j-1][0]=tmp;
			table[j-1][1]=tmp2;
			j--;
		}
	}
}

void out()
{
	cout << "0/1" <<endl;
	for(int i=0;i!=num;i++)
		cout << table[i][0] << "/" <<table[i][1] << endl;
	cout << "1/1"<<endl;
}
int main()
{
	cin >> N;
	solve();
	out();
	//system("pause");
	return 0;
}
