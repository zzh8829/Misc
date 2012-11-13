#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

typedef pair<int, int> ii;
const int INF = 1<<25;
const int maxn = 5001;
ii cost[maxn];
int dis[maxn];
bool done[maxn];
int n,t,k,d,x,y,c,minc = INF;
vector<ii> G[maxn];
priority_queue<ii,vector<ii>,greater<ii> >Q;

int main(int argc, char const *argv[])
{
	scanf("%d%d",&n,&t);
	for (int i = 0; i < t; ++i)
	{
		scanf("%d%d%d",&x,&y,&c);
		G[x].push_back(ii(c,y));
		G[y].push_back(ii(c,x));
	}
	scanf("%d",&k);
	for (int i = 0; i < k; ++i)
	{
		scanf("%d%d",&x,&c);
		cost[i] = ii(x,c);
	}
	scanf("%d",&d);
	for (int i = 0; i <= n; ++i)
		dis[i]=INF;
	dis[d]=0;
	Q.push(ii(0,d));
	while(!Q.empty())
	{
		int u  = Q.top().second; Q.pop();
		if(done[u]) continue;
		done[u] = 1;
		for (int i = 0; i < G[u].size(); ++i)
		if(dis[G[u][i].second]>dis[u]+G[u][i].first)
		{
			dis[G[u][i].second] = dis[u] + G[u][i].first;
			Q.push(ii(dis[G[u][i].second],G[u][i].second));
		}
	}
	for (int i = 0; i < k; ++i)
		minc = min(cost[i].second+dis[cost[i].first],minc);
	printf("%d\n", minc);
	return 0;
}