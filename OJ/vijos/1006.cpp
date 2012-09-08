#include <cstdio>
int n,m[1001][1001],t[1002][1002];
int d[10] = {0,-1, 0,1, -1,0, -1,-1 };
inline int min(int a,int b){
	return a<b?a:b;
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i!=n;i++)
	for(int j=0;j!=i+1;j++)
	{
		scanf("%d",&m[i][j]);
		t[i][j] = 1<<18;
	}
	t[n-1][0] = m[n-1][0];
	for(int x=n-1;x!=0;x--)
	{
		for(int y=0;y!=x+1;y++)
		for(int dr=0;dr!=2;dr++)
		{
			int i=y,ti;
			do{
				ti = (i+d[dr*2+1]+x+1)%(x+1);
				if(t[x][i]+m[x][ti] < t[x][ti])
					t[x][ti] = t[x][i]+m[x][ti];
				else break;
			}while(i=ti,i!=y);
		}
		for(int y=0;y!=x+1;y++)
		for(int dr=2;dr!=4;dr++)
		{
			int tx = (x+d[dr*2]);
			int ty = (y+d[dr*2+1]+tx+1)%(tx+1);
			t[tx][ty] = min(t[x][y]+m[tx][ty], t[tx][ty]);
		}
	}
	printf("%d\n",t[0][0]);
	return 0;
}
