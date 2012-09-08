#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
vector<int>  w[10000];
int m[10000];
int n,r;
int go(int s)
{
	if(s == n)
		return 1;
	if(m[s])
	{
		if(m[s] == -1)
			return 0;
		return m[s];
	}
	for(int i=0;i!=w[s].size();i++)
		m[s]+=go(w[s][i]);
	if(m[s]==0)
	m[s] = -1;
	return m[s];	
}

int main()
{
	int x,y;
	scanf("%d%d%d",&n,&x,&y);
	while(x*y)
	{
		w[x].push_back(y);
		scanf("%d%d",&x,&y);
	}
	r = go(1);
	if(r==-1)
	printf("0\n");
	else
	printf("%d\n",r);
	return 0;
}
