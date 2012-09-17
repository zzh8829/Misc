#include <cstdio>
#include <cstring>
#include <ccytpe>
using namespace std;
const int MAXN 5010;
char buf[MAXN], s[MAXN];
int p[MAXN];
int main()
{
	int n,m = 0 , max = 0,x,y;
	fgets(buf,sizeof(s),stdin);
	n = strlen(buf);
	for(int i=0;i!=n;i++)
	{
		if(isalpha(buf[i]))
		{
			p[m] = i;
			s[m++] = toupper(buf[i]);
		}
	}
	for(int i=0;i!=m;i++)
	{
		for(int j=0;i-j>=0 && i+j<m;j++)
		{
			if(s[i-j] != s[i+j])break;
			if(j*2+1>max)
			{
				max = j*2+1;
				x = p[i-j];
				y = p[i+j];
			}
		}
		for(int j=0;i-j>=0 && i-j+1 < m ;j++)
		{
			if(s[i-j] != s[i-j+1]) break;
			if(j*2+2 > max)
			{
				max = j*2+2;
				x= p[i-j];
				y = p[i+j+1];
			}
		}
	}
	for(int i=x;i<=y;i++)
		printf("%c",buf[i]);
	printf("\n");
	return 0;
}