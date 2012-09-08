#include<cstdio>
#define N 1000
#define MAXINT 1<<18
using namespace std;
int min(int a,int b)
{
	return a<b?a:b;
} 
int d[N+1][N+1];//从点n-1,0到N,N点的状态描述 
int a[N+1][N+1];
int main()
{
	int n,i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	for(j=0;j<=i;j++)
	{
		scanf("%d",&a[i][j]);
		d[i][j]=MAXINT;
	}

	for(i=0;i<n;i++)d[n-1][i]=a[n-1][i];
	for(i=1;i<n;i++)d[n-1][i]=d[n-1][i-1]+a[n-1][i];

	for(i=n-2;i>=0;i--)
	{
		//上层移动规则 
		for(j=0;j<=i+1;j++)
		d[i][j]=min(d[i+1][(j+1)%(i+1)],d[i+1][j%(i+1)])+a[i][j%(i+1)];
		//同层移动规则 
		for(j=0;j<=i+1;j++)
		d[i][j%(i+1)]=min(d[i][(j+1)%(i+1)]+a[i][j%(i+1)],d[i][j%(i+1)]);
		for(j=i+1;j>=1;j--)
		d[i][j%(i+1)]=min(d[i][(j-1)%(i+1)]+a[i][j%(i+1)],d[i][j%(i+1)]);
	}
	for(i=0;i<n;i++)
	{
		printf("\n");
		for(j=0;j<=i;j++)
		printf("%d ",a[i][j]);}
	for(i=0;i<n;i++)
	{
		printf("\n");
		for(j=0;j<=i;j++)
		printf("%d ",d[i][j]);} 
	printf("%d",d[0][0]);
	return 0; 
}
