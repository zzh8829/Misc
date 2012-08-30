#include <iostream>
#include <cstdio>
using namespace std;
char m[376][81],ds[30001];
int n,mr,mc,dir[9] = {-1,0, 0,1, 1,0, 0,-1};
bool go(int &r,int &c,int d)
{
	for(int i=0;i!=n;i++)
	{
		if(ds[i] == 'R')
		d=(d+1)%4;
		else if(ds[i] == 'L')
		d=(d+3)%4;
		else if(ds[i] == 'F')
		{
			r+=dir[2*d];
			c+=dir[2*d+1];
			if(r<0 || r>=mr || c<0 || c>=mc || m[r][c]=='X')
			return false;
		}
	}
	return true;
}

int main()
{

	scanf("%d%d",&mr,&mc);
	for(int i=0;i!=mr;i++)
	for(int j=0;j!=mc;j++)
		cin >> m[i][j];
	scanf("%d",&n);
	for(int i=0;i!=n;i++)
		scanf("\n%c",ds+i);
	for(int i=0;i!=mr;i++)
	for(int j=0;j!=mc;j++)
	{
		if(m[i][j] == 'X')
			continue;
		for(int k=0;k!=4;k++)
		{
			int r=i,c=j;
			if(go(r,c,k))
			{
				m[r][c]='*';
				break;
			}
		}
	}
	for(int i=0;i!=mr;i++)
	{
		for(int j=0;j!=mc;j++)	
			printf("%c",m[i][j]);
		printf("\n");
	}
	system("pause");
	return 0;
}
