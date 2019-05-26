#include<iostream>
#include<string>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;

const int maxn=5100;

vector <int> e[maxn];
bool vis[maxn];

int fa[maxn];
bool ring[maxn];
bool flag=0;

int a[maxn];
int num=0;

int Ans[maxn];
int ans[maxn];
int len;

int n,m;

void Find(int node)
{
	vis[node]=1;
	for (int i=0; i<e[node].size(); i++)
	{
		int son=e[node][i];
		if (son==fa[node]) continue;
		if (!vis[son]) fa[son]=node,Find(son);
		else
			if (!flag)
			{
				int x=node;
				while (x!=fa[son]) a[++num]=x,ring[x]=1,x=fa[x];
				flag=1;
			}
	}
}

void Dfs(int node,int u,int v)
{
	vis[node]=1;
	ans[++len]=node;
	if (u!=node) swap(u,v);
	
	for (int i=0; i<e[node].size(); i++)
	{
		int son=e[node][i];
		if (vis[son]) continue;
		if ( node==u && son==v ) continue;
		Dfs(son,u,v);
	}
}

bool Comp()
{
	for (int i=1; i<=n; i++)
	{
		if (Ans[i]<ans[i]) return 0;
		if (Ans[i]>ans[i]) return 1;
	}
	return 0;
}

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	for (int i=1; i<=m; i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	for (int i=1; i<=n; i++) sort(e[i].begin(),e[i].end());
	
	fa[1]=0;
	Find(1);
	
	Ans[1]=2;
	a[num+1]=a[1];
	for (int i=1; i<=max(num,1); i++)
	{
		for (int j=1; j<=n; j++) vis[j]=0;
		len=0;
		Dfs(1,a[i],a[i+1]);
		if ( Comp() ) for (int j=1; j<=n; j++) Ans[j]=ans[j];
	}
	
	for (int i=1; i<n; i++) printf("%d ",Ans[i]);
	printf("%d\n",Ans[n]);
	
	return 0;
}




























