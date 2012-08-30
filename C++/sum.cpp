#include <iostream>
#include <fstream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

typedef vector<int> vi;
int sumn ;
ofstream fout;
int num[500];
int n;
int total=0;
void search(vi u,int c)
{
	if(total >= 20 )
		return;
	if(u[0] == sumn )
	{
		total++;
		cout << "Found "<< total << " answers\n";
		for(int i=1;i!=u.size();i++)
		{
			fout << u[i]/1000.0 << "\t";	
		}
		fout << endl;
		return;
	}
	if(u[0] > sumn)
		return;
	for(int i=c+1;i!=n;i++)
	{
		vi newu(u);
		newu[0]+=num[i];
		newu.push_back(num[i]);
		search(newu,i);
	}
}

int main()
{
	fout.open("out.txt");
	while(1)
	{
		total = 0;
		system("cls");
		printf("**************×Ô¶¯¼ÆËã***************\n\n"); 
		float in;
		printf("Enter sum\n");
		cin >> in;
		sumn=(int) (in * 1000.0);
		if(sumn %10 == 9)
			sumn+=1;
		int inn;
		printf("Enter N\n");
		cin >> inn;
		printf("Enter all numbers\n");

		for(int i=0;i!=inn;i++)
		{
			cin >> in;
			int t = int(in*=1000.0);
			if(t%10==9)
				t+=1;
			if( find(num,num+n,t)== num+n )
		 		num[n++] = t;
		}
		system("cls");
		fout <<"Sum: " <<sumn/1000.0 << endl;
		cout <<"Sum: " <<sumn/1000.0 << endl;
		vi u;
		u.push_back(0);
		search(u,0);	
		fout << "Search Done\n" <<endl <<endl;
		cout << "Search Done\n***Result saved in out.txt***\n";
		system("pause"); 
	}
	system("pause");
	return 0;
}
