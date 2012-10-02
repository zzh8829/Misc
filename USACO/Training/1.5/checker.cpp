/*
ID: zzh8829
PROG: checker
LANG: C++
*/
//#include <iostream>
#include <fstream>

using namespace std;
ifstream cin("checker.in");
ofstream cout("checker.out");
int n,table[15],bin,ans=0;


void dfs(int y,int l,int r,int i)
{
	int pos,p;
	if(y!=bin)
	{
		pos = bin&(~(y|l|r));
		while(pos!=0)
		{
			p=pos&(pos^(pos-1));
			pos-=p;
			if(ans<3)
			{
				int q=1,w=p;
				while(w!=1)
				{
					w=w>>1;
					q++;
				}
				table[i]=q;
			}
			dfs(y|p,(l|p)<<1,(r|p)>>1,i+1);
		}
	}
	else
	{
		ans++;
		if(ans<=3)
		{
			cout << table[1];
			for(int o=2;o<=n;o++)
			cout <<" "<< table[o];
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
	return 0;
}