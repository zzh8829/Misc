/*
ID: zzh8829
PROG: beads
LANG: C++
*/
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

int n;

int pre(int i)
{
	if(i!=0)
	return i-1;
	else return n-1;
}

int nex(int i)
{
	if(i!=n-1)
	return i+1;
	else return 0;
}

int cal(string rings,int i)
{
	int at=0;
	int cnt=0;
	int forw=i,back=pre(i);
	if(rings[i]=='w')
	{
		while(rings[forw]=='w')
		{
			cnt++;
			forw=nex(forw);
			if(forw==i)
			break;
		}
		return cnt;
	}
	
	if(rings[i]=='r')
	{
		while(rings[forw]=='r'||rings[forw]=='w')
		{
			cnt++;
			forw=nex(forw);
			if(forw==i)
			break;
		}
		at=i+cnt;
		if(at>n-1)
			at=at-n-1;
		while(rings[back]=='b'||rings[back]=='w')
		{
			cnt++;
			back=pre(back);
			if(back==at)
			break;
		}
		
	}
	
	if(rings[i]=='b')
	{
		while(rings[forw]=='b'||rings[forw]=='w')
		{
			cnt++;
			forw=nex(forw);
			if(forw==i)
			break;
		}
		at=i+cnt;
		if(at>n-1)
			at=at-n-1;
		
		while(rings[back]=='r'||rings[back]=='w')
		{
			cnt++;
			back=pre(back);
			if(back==at)
			break;
		}
	}

	return cnt;
}


int main()
{
	ifstream fin("beads.in");
	ofstream fout("beads.out");
	fin >> n;
	string rings;
	fin >>rings;
	vector<int> num;
	for(int i=0;i!=n;i++)
	{
		num.push_back(cal(rings,i));
	}
	sort(num.begin(),num.end());
	fout <<num[n-1]<<endl;
	return 0;
}
