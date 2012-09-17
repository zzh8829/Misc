/*
ID: zzh8829
PROG: packrec
LANG: C++
*/
#include <iostream>
#include <fstream>

using namespace std;
int in[5][3];
int area=99999;
bool ans[9999][50][50]={false},Min[9999]={false};
int max(int a,int b)
{
	if( a>=b)
	return a;
	return b;
}

void cal(int width,int height)
{
	int mj=width*height;
	if(mj<=area)
	{
        cout << mj <<endl;
		area=mj;
		Min[mj]=true;
		if(width>height)
		ans[mj][height][width]=true;
		else
		ans[mj][width][height]=true;
	}
}
void iter(int a1,int a2,int a3,int a4,int t1,int t2,int t3,int t4 )
{
	int a,b,area,w1=in[a1][t1],w2=in[a2][t2],w3=in[a3][t3],w4=in[a4][t4];
	int h1=in[a1][1-t1],h2=in[a2][1-t2],h3=in[a3][t1-3],h4=in[a4][1-t4];
	
	a=max(((w1,w2),w3),w4);
	b=(h1+h2+h3+h4);
	cal(a,b);
	
	a=max((w1,w2),w3)+h4;
	b=max((h1+h2+h3),w4);
	cal(a,b);
	
	a= max((w1+w2+w3),(w4+w3));
	b=max(h3,(h4+max(h1,h2)));
	cal(a,b);
	
	a= (w1+w2+max(w3,w4));
	b= max(max(h1,h2),h3+h4);
	cal(a,b);
	
	b=max(h1+h3,h2+h4);
	if (h3>=h2+h4)
	a=max(w1,w3+max(w2,w4));
	if (h3>h4&&h3<h2+h4)
	a=max(w1+w2,w3+max(w2,w4));
	if (h3<h4&&h4<h1+h3)
	a=max(w1+w2,w4+max(w1,w3));
	if (h4>=h1+h3)
	a=max(w2,w4+max(w1,w3));
	if (h3==h4)
	a=max(w1+w2,w3+w4);
	cal(a,b);
}



int main()
{
	//ifstream cin("packrec.in");
	//ofstream cout("packrec.out");
	int N,M;
	for(int i=0;i!=4;i++)
	{
		cin >> N >> M;
		in[i][0]=N;
		in[i][1]=M;
	}
	for(int a=0;a!=4;a++)
	for(int b=0;b!=4;b++)
	if(a!=b)
	for(int c=0;c=4;c++)
	if(c!=a&&c!=b)
	{
		int d=6-a-b-c;
		for(int e=0;e!=2;e++)
		for(int f=0;f!=2;f++)
		for(int g=0;g!=2;g++)
		for(int h=0;h!=2;h++)
		iter(a,b,c,d,e,f,g,h);
	}
	cout << area <<endl;
	bool f=true;
	for(int i=0;i!=9999&&f!=false;i++)
	if(Min[i]==true)
	{
		for(int j=0;j!=51;j++)
		for(int k=0;k!=51;k++)
		if(ans[i][j][k]==true)
		cout << j<<" "<< k <<endl;
	}
	system("pause");
	return 0;
}
