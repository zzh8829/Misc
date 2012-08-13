#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;
int nr1,np1,np2,A,B;
int r1s[5010],p1s[5010],p2s[5010];
int main()
{
	int in;
	scanf("%d",&nr1);
	for(int i=0;i!=nr1;i++)
	{
		scanf("%d",&in);
		r1s[i]=in;
	}
	scanf("%d",&np1);
	for(int i=0;i!=np1;i++)
	{
		scanf("%d",&in);
		p1s[i]=in;
	}
	scanf("%d",&np2);
	for(int i=0;i!=np2;i++)
	{
		scanf("%d",&in);
		p2s[i]=in;
	}
	
	scanf("%d%d",&A,&B);
	
	sort(r1s,r1s+nr1);
	sort(p1s,p1s+np1);
	sort(p2s,p2s+np2);
	float ratio = p1s[np1-1]/(((float)A/B)*p2s[0]);
	float r2=(r1s[nr1-1]*r1s[nr1-1]*ratio)/(1+ratio);
	printf("%0.6f\n",sqrt(r2));
	system("pause");
	return 0;
}
