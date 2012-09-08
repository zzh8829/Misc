#include <iostream>
#include <cstdio>
#include <string>
#include <cctype>
using namespace std;

int s[11][10];
int f[11][10][12][2];
bool v[11][10];
int go(int r,int c,int rr,int rc)
{
	if(s[r][c] || v[r][c]) return s[r][c];
	for(int i=1;i<=f[r][c][0][0];i++)
		if( rr==f[r][c][i][0] && rc==f[r][c][i][1])
			return -1;
	for(int i=1;i<=f[r][c][0][0];i++)
	{
		int t=go( f[r][c][i][0], f[r][c][i][1],r,c);
		if(t==-1){v[r][c]=1; s[r][c]=-1; return -1;}
		s[r][c]+=t;
	}	
	v[r][c]=1;
	return s[r][c];
}
int main()
{
	for(int r=0;r!=10;r++)
	for(int c=0;c!=9;c++)
	{
		string in;
		cin >> in;
		if(isdigit(in[0]))
		for(int i=0;i!=in.size();i++)
		{
			int d=1;
			for(int j=0;j!=i;j++)
				d*=10;
			s[r][c]+= (in[in.size()-i-1]-'0')*d;
			v[r][c]=1;
		}
		else
		{
			int pos=0;
			while(pos<in.size())
			{
				f[r][c][++f[r][c][0][0] ][0] = in[pos]-'A';
				f[r][c][  f[r][c][0][0] ][1]= in[pos+1] -'1';
				pos+=3;
			}
		}
	}
	
	for(int i=0;i!=10;i++)
	for(int j=0;j!=9;j++)
	if(f[i][j][0][0]!=0 && v[i][j]==0)
		s[i][j]=go(i,j,i,j);
	
	for(int i=0;i!=10;i++)
	{
		for(int j=0;j!=9;j++)
		if(s[i][j]==-1)
		cout << "* ";
		else
		cout << s[i][j] <<" ";
		cout <<endl;
	}
	system("pause");
	return 0;
}
