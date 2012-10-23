#include <cstdio>
#include <vector>
using namespace std;

const int N=100001;
int v[N];
int guyn,girln;
int n,m,t;

vector<int> gout;
vector<int> bout;

int main()
{
	scanf("%d%d",&guyn,&m);
	for(int i=0;i!=m;i++)
	{
		scanf("%d",&t);
		printf("ENTER GUY %d\n",t);
		v[t]=1;
	}
	for(int i=1;i<=guyn;i++)
		if(!v[i]) bout.push_back(i);
	scanf("%d%d",&girln,&n);
	for(int i=0;i!=n;i++)
	{
		scanf("%d",&t);
		gout.push_back(t);
	}
	int dq = 0;
	while(dq!=bout.size()&&dq!=gout.size())
	{
		printf("GIVE GIRL %d GUY %d\n",gout[dq],bout[dq]);
		printf("ENTER GUY %d\n",bout[dq]);
		dq++;	
	}
	return 0;
}
