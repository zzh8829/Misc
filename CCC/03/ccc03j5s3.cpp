#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int m[26][26],rooms[500];
int f,r,c;

int floor(int a,int b)
{
	if(m[a][b] || a>= r || b>=c || a<0 || b <0)
	return 0;
	int t = 1;
	m[a][b] = 1;
	t+= floor(a+1,b);
	t+= floor(a-1,b);
	t+= floor(a,b+1);
	t+= floor(a,b-1);
	return t;
}

int main()
{
	int n=0;
	cin >> f >>r >>c;
	char in;
	for(int i=0;i!=r;++i)
	for(int j=0;j!=c;++j)
	{
		cin >> in;
		m[i][j] = 1;
		if(in=='.')
		m[i][j] = 0;
	}
	for(int i=0;i!=r;++i)
	for(int j=0;j!=c;++j)
	{
		int area = floor(i,j);
		if(area!=0)
		{
			rooms[n++] = area;
		}			
	}
	sort(rooms,rooms+n);
	for(int i=n-1;i!=-1;--i)
	{
		f-=rooms[i];
		if(f<0)
		{
			f+=rooms[i];
			n-=(i+1);
			break;
		}
	}
	if(n==1)
	printf("%d room, %d square metre(s) left over\n",n,f);	
	else
	printf("%d rooms, %d square metre(s) left over\n",n,f);	
	system("pause");
	return 0;
}
