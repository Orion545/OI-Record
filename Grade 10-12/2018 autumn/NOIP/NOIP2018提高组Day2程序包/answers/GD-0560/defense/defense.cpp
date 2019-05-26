#include <bits/stdc++.h>
using namespace std;

#define MAXN 300010
#define INF 1000000000

int n,q,cost[MAXN],o1,n1,o2,n2;
long long f[MAXN][3];
char tmps[10];
vector<int> edge[MAXN];

void dfs(int u,int fa)
{
	if(u==o1 || u==o2)
	{
		if(u==o1)
		{
			if(n1==1)
			{
				f[u][0]=cost[u];
				f[u][1]=INF;
			}
			else
			{
				f[u][0]=INF;
				f[u][1]=0;
			}
		}
		else
		{
			if(n2==1)
			{
				f[u][0]=cost[u];
				f[u][1]=INF;
			}
			else
			{
				f[u][0]=INF;
				f[u][1]=0;
			}
		}
	}
	else
	{
		f[u][0]=cost[u];
		f[u][1]=0;
	}
	for(int i=0;i<edge[u].size();++i)
	{
		int v=edge[u][i];
		if(v==fa)continue;
		dfs(v,u);
	}
	for(int i=0;i<edge[u].size();++i)
	{
		int v=edge[u][i];
		if(v==fa)continue;
		f[u][0]+=min(f[v][0],f[v][1]);
		f[u][1]+=f[v][0];
	}
}

int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d%s",&n,&q,tmps);
	for(int i=1;i<=n;++i)scanf("%d",cost+i);
	for(int i=1;i<n;++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	while(q--)
	{
		memset(f,0,sizeof(f));
		scanf("%d%d%d%d",&o1,&n1,&o2,&n2);
		dfs(1,0);
//		for(int i=1;i<=n;++i)printf("%d %d\n",f[i][0],f[i][1]);
		if(min(f[1][0],f[1][1])>INF)puts("-1");else printf("%lld\n",min(f[1][0],f[1][1]));
	}
}
