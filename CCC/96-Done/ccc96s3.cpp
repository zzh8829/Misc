#include <cstdio>
#include <algorithm>
using namespace std;

int s[100];
int len,k;

int main()
{
	int n;
	scanf("%d",&n);
	for(int t=0;t!=n;t++)
	{
		scanf("%d%d",&len,&k);
		for(int i=0;i!=len;i++)
			s[i] = 1;
		for(int i=0;i!=k;i++)
			s[i] = 0;
		printf("The bit patterns are\n");
		do{
			for(int i=0;i!=len;i++)
			printf("%d",!s[i]);
			printf("\n");
		}while(next_permutation(s,s+len) );
		printf("\n");
	}	
	return 0;
}
