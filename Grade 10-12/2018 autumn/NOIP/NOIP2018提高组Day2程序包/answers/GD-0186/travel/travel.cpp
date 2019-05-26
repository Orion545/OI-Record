#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct EDGE
{
	int t,n;
} edge[10005];

int n,m,k,u[5005],v[5005],U,V,
	order[5005],ans[5005],sn[5005],sons[5005][5005],
	cur,last[5005];
bool vis[5005];

void AddEdge(int u,int v)
{
	++cur;
	edge[cur].t=v;
	edge[cur].n=last[u];
	last[u]=cur;
	return;
}

void DFS(int u)
{
	order[++k]=u; vis[u]=true; sn[u]=0;
	for (int tmp=last[u];tmp;tmp=edge[tmp].n)
	{
		int v=edge[tmp].t;
		if (u==U && v==V || u==V && v==U) continue;
		sons[u][++sn[u]]=v;
	}
	
	sort(sons[u]+1,sons[u]+1+sn[u]);
	
	for (int i=1;i<=sn[u];i++)
		if (!vis[sons[u][i]]) DFS(sons[u][i]);
	
	return ;
}

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d",&u[i],&v[i]);
		AddEdge(u[i],v[i]),AddEdge(v[i],u[i]);
	}
	
	for (int i=1;i<=n;i++) ans[i]=n+1;
	
	if (m==n-1)
	{
		k=0,U=0,V=0;
		DFS(1);
		for (int i=1;i<=n;i++)
			ans[i]=order[i];
	} else
	{
		for (int i=1;i<=m;i++)
		{
			k=0,U=u[i],V=v[i];
			memset(vis,false,sizeof vis);
			DFS(1);
			
			if (k!=n) continue;
			
			bool Update=false;
			for (int j=1;j<=n;j++)
				if (order[j]<ans[j])
				{
					Update=true;
					break;
				} else
				if (order[j]>ans[j]) break;
			
			if (Update)
				for (int j=1;j<=n;j++)
					ans[j]=order[j];
		}
	}
	
	for (int i=1;i<=n;i++)
		printf("%d ",ans[i]);
	printf("\n");
	
	return 0;
}
