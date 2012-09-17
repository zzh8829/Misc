/*
ID: zzh8829
PROG: clocks
LANG: C++
*/
#include <iostream>
#include <fstream>
using namespace std;
int A,B,C,D,E,F,G,H,I,ans=19999,answer[20000];

void ch(int& i)
{
	i=i/3;
}

int t(int i,int n)
{
	i+=n;
	if(i%4==0)
	return 4;
	return i%4;
}

bool done(int a,int b,int c,int d,int e,int f,int g,int h,int i)
{
	if(a+b+c+d+e+f+g+h+i==36)
	return true;
	return false;
}

int main()
{
	ifstream cin("clocks.in");
	ofstream cout("clocks.out");
	cin >>A>>B>>C>>D>>E>>F>>G>>H>>I;
	ch(A);ch(B);ch(C);ch(D);ch(E);ch(F);ch(G);ch(H);ch(I);
	for(int a=0;a!=4;a++)
	for(int b=0;b!=4;b++) 
	for(int c=0;c!=4;c++) 
	for(int d=0;d!=4;d++) 
	for(int e=0;e!=4;e++) 
	for(int f=0;f!=4;f++) 
	for(int g=0;g!=4;g++) 
	for(int h=0;h!=4;h++) 
	for(int i=0;i!=4;i++) 
	{
		if(done(t(A,a+b+d),t(B,a+b+c+e),t(C,b+c+f),t(D,a+d+e+g),t(E,a+c+e+g+i),t(F,c+e+f+i),t(G,d+g+h),t(H,e+g+h+i),t(I,f+h+i)))
		if((a+b+c+d+e+f+g+h+i+1)<ans)
		{
			ans=a+b+c+d+e+f+g+h+i;
			for(int n=0;n!=a;n++) answer[n]=1;
			for(int n=0;n!=b;n++) answer[n+a]=2;
			for(int n=0;n!=c;n++) answer[n+a+b]=3;
			for(int n=0;n!=d;n++) answer[n+a+b+c]=4;
			for(int n=0;n!=e;n++) answer[n+a+b+c+d]=5;
			for(int n=0;n!=f;n++) answer[n+a+b+c+d+e]=6;
			for(int n=0;n!=g;n++) answer[n+a+b+c+d+e+f]=7;
			for(int n=0;n!=h;n++) answer[n+a+b+c+d+e+f+g]=8;
			for(int n=0;n!=i;n++) answer[n+a+b+c+d+e+f+g+h]=9;
		}				
	}
	for(int i=0;i!=ans ;i++)
	{
		cout << answer[i];
		if(i!=ans-1)
		cout << " ";
	}
	cout << endl;
	return 0;
}
