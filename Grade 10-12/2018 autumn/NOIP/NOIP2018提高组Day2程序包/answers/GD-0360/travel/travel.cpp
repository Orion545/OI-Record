#include<cstdio>
#include<cstring>
#include<iostream>
#include<cctype>
#include<algorithm>
#include<vector>
using namespace std;

const int maxn=5010;
int n,m,tot,head[maxn],ans[maxn],cntt,cnt,dfn[maxn],num,low[maxn],t[maxn];
vector <int> p[maxn];
bool vis[maxn],c[maxn][maxn],b[maxn][maxn],fl;
struct node
{
	int nxt,to,fr;
}edge[maxn<<1];

int rd()
{
	int x=0,f=1;
	char c=getchar();
	while (!isdigit(c))
		f=c=='-'?-1:1,c=getchar();
	while (isdigit(c))
		x=(x<<1)+(x<<3)+(c^48),c=getchar();
	return x*f;
}

void add(int u,int v)
{
	edge[++tot]=(node){head[u],v,u};
	head[u]=tot;
}

void tarjan(int u,int ie)
{
	int i,v;
	low[u]=dfn[u]=++num;
	for (i=head[u];i;i=edge[i].nxt)
	{
		v=edge[i].to;
		if (!dfn[v])
		{
			tarjan(v,i);
			low[u]=min(low[u],low[v]);
			if (low[v]>dfn[u])
				b[u][v]=b[v][u]=1;
		}
		else
		if (i!=(ie^1))
			low[u]=min(low[u],dfn[v]);
	}
}

void dfs1(int u)
{
	vis[u]=1;
	ans[++cntt]=u;
	int i,v;
	for (i=0;i<p[u].size();i++)
	{
		v=p[u][i];
		if (!vis[v])
			dfs1(v);
	}
}

void dfs2(int u)
{
	int i,v;
	vis[u]=1;
	t[++cnt]=u;/*
	if (ans[cnt]==0||t[cnt]<ans[cnt]||fl)
		fl=1;
	if (fl==0)
		return;*/
	if (cnt==n)
	{
		bool tmp=0;
		for (i=1;i<=n;i++)
		{
			if (t[i]==ans[i])
				continue;
			if (t[i]<ans[i])
			{
				tmp=1;
				break;
			}
			if (t[i]>ans[i])
			{
				tmp=0;
				break;
			}
		}
		if (tmp==1||ans[1]==0)
		for (i=1;i<=n;i++)
			ans[i]=t[i];
		return;
	}
	for (i=0;i<p[u].size();i++)
	{
		v=p[u][i];
		if (vis[v]||c[u][v]||c[v][u])
			continue;
		dfs2(v);
	}
	
}

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int i,j,u,v;
	n=rd();
	m=rd();
	tot=1;
	for (i=1;i<=m;i++)
	{
		u=rd();
		v=rd();
		add(u,v);
		add(v,u);
		p[u].push_back(v);
		p[v].push_back(u);
	}
	for (i=1;i<=n;i++)
		sort(p[i].begin(),p[i].end());
	if (m==n-1)
	{
		dfs1(1);
		for (i=1;i<=n;i++)
			printf("%d ",ans[i]);
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	tarjan(1,0);
	for (i=2;i<=tot;i+=2)
	{
		u=edge[i].fr;
		v=edge[i].to;
		if (!b[u][v]&&!b[v][u])
		{
			cnt=0;
			fl=0;
			memset(vis,0,sizeof(vis));
			memset(t,0,sizeof(t));
			c[u][v]=c[v][u]=1;
			dfs2(1);
			c[u][v]=c[v][u]=0;
		}
	}
	for (i=1;i<=n;i++)
		printf("%d ",ans[i]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
