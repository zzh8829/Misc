#include <cstdio>
using namespace std;
int s[9];
int ch[11][2],cn;
bool check()
{
	for(int i=1;i!=8;i++)
		for(int j=1;j!=8;j++)
			if(s[i]==s[j] && i!=j )
				return false;
	for(int i=0;i!=cn;i++)
		if(s[ch[i][0]] > s[ch[i][1]])
			return false;
	return true;
}
	
int main()
{
	int p[11] = { 1,7,1,4,2,1,3,4,3,5};
	int n[11] = { 0,1,2,3,4,5,6,7};
	for(int i=0;i!=5;i++)
	{
		ch[cn][0] = p[i*2];
		ch[cn++][1] = p[i*2+1];
	}
	int t1,t2,a,b,c,d,e,f,g;
	while(scanf("%d%d",&t1,&t2) && t1!=0)
	{
		ch[cn][0] = t1;
		ch[cn++][1] = t2;
	}
	for(a=1;a!=8;a++)
	for(b=1;b!=8;b++)
	{
		if(a==b)
			continue;
		for(c=1;c!=8;c++)
		{
			if(c==b || c==a)
				continue;
			for(d=1;d!=8;d++)
			{
				if(d==a || d==b || d==c)
					continue;
				for(e=1;e!=8;e++)
				for(f=1;f!=8;f++)
				for(g=1;g!=8;g++)
				{
					s[n[a]] = 1;s[n[b]] = 2;s[n[c]] = 3;s[n[d]] = 4;
					s[n[e]] = 5;s[n[f]] = 6;s[n[g]] = 7;
					if(check())
					{
						int out[8];
						for(int i=1;i!=8;i++)
							out[ s[i] ] = i;
						for(int i=1;i!=8;i++)
							printf("%d ",out[i]);
						return 0;
					}	
				}
			}
		}
	}
	printf("Cannot complete these tasks. Going to bed.\n");
	return 0;
}
