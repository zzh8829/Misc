#include <iostream>
#include <cstdio>

using namespace std;

int f[10000];
int n,x,y,d;
bool v[10000];
bool go(int a,int b,int s)
{
	if(v[a]) return 0;
	v[a]=1;
	if(a==b){d=s; return 1;};
	if(go(f[a],b,s+1)==1)
		return 1;
	return 0;
}

int main()
{

	cin >> n;
	for(int i=0;i!=n;i++)
	{
		scanf("%d",&x);
		scanf("%d",&f[x]);
	}
	while(cin >> x >> y && x!=0)
	{
		for(int i=0;i!=10000;i++)
			v[i]=0;
		d=0;
		if(go(x,y,d))
 			printf("Yes %d\n",d-1);
		else
			printf("No\n");
	}	
	system("pause");
	return 0;
}
