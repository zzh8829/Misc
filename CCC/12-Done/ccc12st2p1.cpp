#include <cstdio>
#include <cmath>
using namespace std;

int key[11],n,ks,ns,num,ok;

bool search(int tn,int cn)
{
	if(cn == num && tn==0)	return true;
	if(tn == 0 || cn> num || pow((float)key[ks-1],tn)*cn < num)
		return false;
	for(int i=0;i!=ks;++i)
	{
		if(search(tn-1,cn*key[i]))	return true;
		if(search(tn-1,cn+key[i]))	return true;
	}
	return false;
}
int main()
{
	scanf("%d%d",&n,&ks);
	for(int i=0;i!=ks;i++)
	scanf("%d",&key[i]);
	scanf("%d",&ns);
	while(ns--!=0)
	{
		scanf("%d",&num);
		ok = false;
		for(int i=0;i!=ks;++i)
		if(search(n,key[i]))
		{
			ok=true;
			break;
		}
		if(ok) printf("Y\n");
		else printf("N\n");
	}		
	return 0;
}
