#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

string name[101];
int t[101],best[101],group[101],lines[101];
int m,n,tot=0;

inline int max(int a,int b){
	return a>b?a:b;
}
int main()
{
	cin >> m>>n;
	for(int i=0;i!=n;i++)
		cin >> name[i]>>t[i];
	for(int i=0;i<=n;i++)
	{
		best[i] = 1<<18;
		group[i]=-1;
	}
	best[0]=group[0]=0;
	for(int i=0;i<n+1;i++)
	{
		int cur = 0;
		for(int j=1;j<=m && i+j-1 < n;j++)
		{
			cur = max(cur,t[i+j-1]);
			if(best[i] + cur < best[i+j])
			{
				best[i+j] = best[i]+cur;
				group[i+j] = j;
			}
		}
	}	
	printf("Total Time: %d\n",best[n]);
	int k = n;
	int x=0;
	while(group[k]!=0)
	{
		lines[x++] = group[k];
		k = k-group[k];
	}
	int z= 0;
	for(int i=x-1;i>=0;i--)
	{
		for(int j=0;j<lines[i];j++)
			cout << name[z++] <<" ";
		cout <<endl;
	}	
	return 0;
}
