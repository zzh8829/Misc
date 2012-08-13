#include<stdio.h>

void comp(int k[],int m,int l)
{
	int i=10,j=0,z=1,y=1,x,w,b[500][10];
	for(w=0;w<m;w++)
		for(x=0;x<10;x++)
		{
			b[w][x]=-1;
		}
	while(z>0)
	{
		z=l/i;
		i=i*10;
		++j;  //记录最大数的位数
	}
	i=10;
	while(j>0)
	{
		for(z=0;z<=m;z++)
		{
			x=(k[z]/y)%i;
			b[z][x]=k[z];
		}
		w=0;
		for(z=0;z<10;z++)
			for(x=0;x<m;x++)
			{
				if(b[x][z]>=0)
				{
					k[w]=b[x][z];
					b[x][z]=-1;
					w++;
				}
			}
		--j;
		y=y*10;
	}
	for(z=0;z<m;z++)
	{
		printf("%d ",k[z]);
	}
}

main()
{
	int n,m=0,l=0;
	int a[500];
	printf("请输入正整数,负数表示结束:");
	scanf("%d",&n);
	while(n>=0)
	{
		a[m]=n;
		++m;
		if(n>l)
			l=n;//记录最大数
		scanf("%d",&n);
	}

	comp(a,m,l);
}