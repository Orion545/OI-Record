#include <bits/stdc++.h>
using namespace std;
const int maxn=5005,INF=0x7FFFFFFF;
int n,m,p,t,A,B,times,dfn[maxn],dad[maxn],ring[maxn],now[maxn],ans[maxn],e[maxn][maxn];
void dfs(int u,int last)
{
	now[++t]=u;
	for (int i=1,v;i<=e[u][0];i++)
	{
		v=e[u][i];
		if (v==last || u==A && v==B || u==B && v==A) continue;
		dfs(v,u);
	}
}
void predfs(int u,int last)
{
	dad[u]=last;
	dfn[u]=++times;
	for (int i=1,v;i<=e[u][0];i++)
	{
		v=e[u][i];
		if (v==last) continue;
		if (dfn[v])
		{
			if (dfn[v]<dfn[u])
			{
				for (int w=u;w!=v;w=dad[w]) ring[++p]=w;
				ring[++p]=v;
				ring[p+1]=u;
			}
			continue;
		}
		predfs(v,u);
	}
}
void pro1()
{
	dfs(1,0);
	for (int i=1;i<=n;i++) printf("%d ",now[i]);
}
void pro2()
{
	predfs(1,0);
	ans[1]=INF;
	for (int i=1;i<=p;i++)
	{
		t=0;
		A=ring[i];
		B=ring[i+1];
		dfs(1,0);
		for (int j=1;j<=n;j++)
		{
			if (now[j]==ans[j]) continue;
			if (now[j]<ans[j]) for (int k=j;k<=n;k++) ans[k]=now[k];
			break;
		}
	}
	for (int i=1;i<=n;i++) printf("%d ",ans[i]);
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1,x,y;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		e[x][++e[x][0]]=y;
		e[y][++e[y][0]]=x;
	}
	for (int i=1;i<=n;i++) sort(e[i]+1,e[i]+1+e[i][0]);
	if (m==n-1) pro1(); else pro2();
	printf("\n");
	return 0;
}
