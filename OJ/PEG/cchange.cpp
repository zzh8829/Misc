#include <cstdio>
int m[10001];
int n,x,t;
int main()
{
	scanf("%d%d",&x,&n);
	for(int i=1;i<=x;i++)
		m[i]=1<<20;
	for(int i=0;i!=n;i++)
	{
		scanf("%d",&t);
		for(int j=t;j<=x;j++)
			if(m[j-t]+1 < m[j])
				m[j] = m[j-t]+1;
	}
	printf("%d",m[x]);
	return 0;
}
