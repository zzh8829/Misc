#include <cstdio>
using namespace std;

int s[20][20];

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	int x=10,y=10;
	int sx,sy,bx,by;
	sx=sy=20;
	bx=by=0;
	char d='l';
	for(int i=a;i!=b+1;i++)
	{
		if(x>bx) bx=x;
		if(x<sx) sx=x;
		if(y>by) by=y;
		if(y<sy) sy=y; 
		s[x][y]=i;
		if(d=='d')
		{
			if(!s[x][y+1])
			{
				d='r';
				y++;
				continue;
			}
			x++;
		}
		else if(d=='r')
		{
			if(!s[x-1][y])
			{
				d='u';
				x--;
				continue;
			}
			y++;
		}
		else if(d=='u')
		{
			if(!s[x][y-1])
			{
				d='l';
				y--;
				continue;
			}
			x--;
		}
		else if(d=='l')
		{
			if(!s[x+1][y])
			{
				d='d';
				x++;
				continue;
			}
			y--;
		}
	}
	for(int i=sx;i<=bx;i++)
	{
		for(int j=sy;j<=by;j++)
		if(s[i][j])
		printf("%2d ",s[i][j]);
		else
		printf("   ");
		printf("\n");
	}
	return 0;
}
