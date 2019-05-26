#include <bits/stdc++.h>
using namespace std;

#define MAXN 10010

int n,m,vis[MAXN],ans[MAXN],skipu,skipv,dfs_order[MAXN],dfn;
vector<int> edge[MAXN],onloop;

void treedfs(int u,int fa)
{
	dfs_order[++dfn]=u;
	for(int i=0;i<edge[u].size();++i)
	{
		int v=edge[u][i];
		if(v!=fa)treedfs(v,u);
	}
}

int findloop(int u,int fa)
{
	vis[u]=true;
	for(int i=0;i<edge[u].size();++i)
	{
		int v=edge[u][i];
		if(v==fa)continue;
		if(vis[v])
		{
			onloop.push_back(u);
			return v;
		}
		int tmp;
		if(tmp=findloop(v,u))
		{
			onloop.push_back(u);
			return tmp==u?0:tmp;
		}
	}
	return 0;
}

void loopdfs(int u,int fa)
{
	dfs_order[++dfn]=u;
	for(int i=0;i<edge[u].size();++i)
	{
		int v=edge[u][i];
		if(v!=fa && !(u==skipu && v==skipv) && !(u==skipv && v==skipu))loopdfs(v,u);
	}
}

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	if(m==n-1)
	{
		for(int i=1;i<=n;++i)sort(edge[i].begin(),edge[i].end());
		treedfs(1,0);
		for(int i=1;i<=n;++i)printf("%d ",dfs_order[i]);
	}
	else//m==n
	{
		findloop(1,0);
		for(int i=1;i<=n;++i)sort(edge[i].begin(),edge[i].end());
		skipu=onloop[0];
		skipv=onloop[onloop.size()-1];
		loopdfs(1,0);
		for(int i=1;i<=n;++i)ans[i]=dfs_order[i];
		for(int i=1;i<onloop.size();++i)
		{
			dfn=0;
			skipu=onloop[i-1];
			skipv=onloop[i];
			loopdfs(1,0);
			bool small=false;
			for(int j=1;j<=n;++j)
			{
				if(ans[j]!=dfs_order[j])
				{
					if(dfs_order[j]<ans[j])
					{
						small=true;
					}
					break;
				}
			}
			if(small)for(int j=1;j<=n;++j)ans[j]=dfs_order[j];
		}
		for(int i=1;i<=n;++i)printf("%d ",ans[i]);
	}
}
