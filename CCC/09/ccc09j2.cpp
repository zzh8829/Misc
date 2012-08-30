#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int b,n,y,t,w=0;
	scanf("%d%d%d%d",&b,&n,&y,&t);
	for(int i=0;i*b<=t;i++)
	for(int j=0;j*n<=t;j++)
	for(int k=0;k*y<=t;k++)
	if(i*b+j*n+k*y <= t && (i!=0||j!=0||k!=0))
	{
	printf("%d Brown Trout, %d Northern Pike, %d Yellow Pickerel\n",i,j,k);
	w++;
	}
	printf("Number of ways to catch fish: %d\n",w);	
	system("pause");
	return 0;
}
