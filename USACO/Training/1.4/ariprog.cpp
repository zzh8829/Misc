/*
ID: zzh8829
PROG: ariprog
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
int N, M,n[125001],c=0,cnt=0;
bool done[125001]={false};

struct ANS
{
	int l,r;
}ans[100001];

int main()
{
	ifstream cin("ariprog.in");
	ofstream cout("ariprog.out");
	cin >> N >> M ;
	for(int i=0;i!=M+1;i++)
	for(int j=0;j!=M+1;j++)
	{
		int p=i*i+j*j;
		if(done[p]==false)
		{
			n[c]=p;
			c++;
		}
		done[p]=true;
	}
	sort(n,n+c);
	for(int a=0;a!=c;a++)
	for(int b=a+1;b!=c;b++)
	{
		bool k=true;
		int f=n[a],d=n[b]-n[a];
		if(f+(N-1)*d>n[c-1])break;
		for(int i=N-1;i!=-1;i--)
			if(done[f+i*d]==false)
			{
				k=false;
				break;
			}		
		if(k==true)
		{
			ans[cnt].l=f;
			ans[cnt].r=d;
			cnt++;
		}
	}
	if(cnt==0)
	cout << "NONE" <<endl;
	if(cnt!=0)
	{
		for (int k = 1; k != cnt; k++)
		{
			int key = ans[k].r;
			int key2 = ans[k].l;
			int i = k - 1;
			while ( (i >= 0) && (key < ans[i].r)) 
			{
				ans[i + 1].r = ans[i].r;
				ans[i + 1].l = ans[i].l;
				--i;
			}
			ans[i + 1].r = key;
			ans[i + 1].l = key2;
		}
		for(int i=0;i!=cnt;i++)
		cout << ans[i].l << " " << ans[i].r <<endl;
	}    
return 0;
}
