#include <iostream>
#include <cstdio>

using namespace std;

int p[1025][1025];
int t[1025][1025];
int t2[1025][1025];
int R,C;
const int MAXINT = 2147483645;

int main()
{
	int n;
	cin >> n;
	R=C=1;
	int max,min,maxrs,minrs,maxcs,mincs;
	max=maxrs=maxcs= -MAXINT;
	min=minrs=mincs= MAXINT;
	
	for(int  s=0;s!=n;++s)
	{
		int r,c;
		cin >> r >> c;
		if(!s)
		{
			R*=r;
			C*=c;
			for(int i=0;i!=r;i++)
			for(int j=0;j!=c;j++)
			cin >> p[i][j];
		}
		else
		{
			for(int i=0;i!=r;i++)
			for(int j=0;j!=c;j++)
			cin >> t2[i][j];
			
			for(int i=0;i!=R;i++)
			for(int j=0;j!=C;j++)
			t[i][j] = p[i][j];
			
			for(int i=0;i!=R;i++)
			for(int j=0;j!=r;j++)
			for(int k=0;k!=C;k++)
			for(int l=0;l!=c;l++)
			{
				p[i*r+j][k*c+l] = t[i][k] * t2[j][l] ;
			}
			R*=r;
			C*=c;
		}
	}
	int trsum,tcsum;
	for(int i=0;i!=R;i++)
	{
		trsum = 0;
		for(int j=0;j!=C;j++)
		{
			if(p[i][j]>max)
			max = p[i][j];
			if(p[i][j]<min)
			min = p[i][j];
			trsum+=p[i][j];			
		}
		if(trsum > maxrs)
		maxrs= trsum;
		if(trsum < minrs)
		minrs= trsum;
	}
	for(int i=0;i!=C;i++)
	{
		tcsum = 0;
		for(int j=0;j!=R;j++)
			tcsum += p[j][i];
		if(tcsum>maxcs)
		maxcs = tcsum;
		if(tcsum<mincs)
		mincs = tcsum;
	}
	printf("%d\n%d\n%d\n%d\n%d\n%d\n",max,min,maxrs,minrs,maxcs,mincs);
	system("pause");
	return 0;
}
