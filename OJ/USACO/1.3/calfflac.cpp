/*
ID: zzh8829
PROG: calfflac
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <cstdio>
#include <cctype>
using namespace std;
char yc[20001],tc[20001],ans[2001],in='1';
int pos1,pos2,yp=0,tp=0,pc[20001],len=1;

void pro(int i)
{
	int p1,p2,tlen=1;
	p1=i;
	p2=i;
	if(p1!=tp-1&&tc[p1]==tc[p1+1])
	{p2++;tlen++;}
	while(p1!=0 && p2!= (tp-1))
	{
		p1--;
		p2++;
		if(tc[p1]==tc[p2])
			tlen+=2;
		else
		{
			p1++;
			p2--;
			break;
		}

	}
	if(tlen>len)
	{
		pos1=p1;
		pos2=p2;
		len=tlen;
	}
}
int main()
{
	ifstream cin("calfflac.in");
	ofstream cout("calfflac.out");
	while(cin.good()) 
	{
		in = cin.get();     
		yc[yp]=in;
		if(isalpha(in))
		{ 
			if(isupper(in))
			in=tolower(in);
			tc[tp]=in;
			pc[tp]=yp;
			tp++;
		}
		yp++;		
	}
	if(tp!=1)
	{
		for(int i=1;i!=tp;i++)
		pro(i);
		cout << len <<endl;
		for(int i=pc[pos1];i!=(pc[pos2]+1);i++)
		cout << yc[i];
		cout <<endl;
	}
	else
	cout << len <<endl << yc[pc[0]] <<endl;	
	return 0;
}
