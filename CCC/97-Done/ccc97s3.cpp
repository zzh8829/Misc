#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	for(int cases=0;cases!=n;cases++)
	{
		int r=0,p,u=0,o=0,e=0;
		scanf("%d",&p);
		u=p;
		while(1)
		{
			printf("Round %d: %d undefeated, %d one-loss, %d eliminated\n",r,u,o,e);
			if(u==1 && o==1) break;
			e+=o/2;
			o-=o/2;		
			o+=u/2;
			u-=u/2;	
			r++;		
		}
		printf("Round %d: %d undefeated, %d one-loss, %d eliminated\n",++r,--u,++o,e);
		printf("Round %d: %d undefeated, %d one-loss, %d eliminated\n",++r,u,--o,++e);
		printf("There are %d rounds.\n\n",r);
	}
	system("pause");
	return 0;
}
