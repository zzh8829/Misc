/*
ID: zzh8829
PROG: checker
LANG: C++
*/
#include <iostream>
#include <fstream>

using namespace std;
//ifstream cin("checker.in");
//ofstream cout("checker.out");
int n,table[15],bin,ans=0;


void dfs(int y,int l,int r,int i)
{
	int pos,p;
	if(y!=aim)
	{
		pos = bin&(~(y|l|r))
		while(pos!=0)
		{
			p=pos&(pos^(pos-1))
			pos-=p;
			if(ans<3)
			{
				int e=i;r=p;
				while(r!=1)
				{
					r=r>>1;
					e++;
				}
				a[i]=a
			}
			dfs(row|p,(l|p)<<1,(r|p)>>1,i+1);
		}
	}
	else
	{
		ans++;
		if(ans<=3)
		{
			cout << a[1];
			for(int o=2;o!=n+1;o++)
				cout << a[o];
			cout << endl;
		}
	}
}
	
int main()
{
	cin >> n;
	bin=(1<<n)-1;
	dfs(0,0,0,1);
	cout << ans <<endl;
	system("pause");
	return 0;
}