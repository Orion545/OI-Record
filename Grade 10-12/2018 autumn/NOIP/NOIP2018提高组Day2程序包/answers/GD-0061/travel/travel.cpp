#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<set>
#include<queue> 
using namespace std;

inline long long read()
{
	int ch=getchar(),f=1;
	long long ans=0;
	for(;ch<'0'||ch>'9';ch=getchar())
		if(ch=='-')f=0;
	for(;ch>='0'&&ch<='9';ch=getchar())
		ans=(((ans<<2)+ans)<<1)+(ch^'0');
	return f?ans:-ans;
}

int n,m;
const int maxn=5000;
vector<int> e[maxn];

namespace tree
{
	void dfs(int u,int fa)
	{
		printf("%d ",u);
		for(int i=0;i<e[u].size();++i)
		{
			int v=e[u][i];
			if(v==fa)continue;
			dfs(v,u);
		}
	}
	void solve()
	{
		for(int i=1;i<=n;++i)
		{
			sort(e[i].begin(),e[i].end());
		}
		dfs(1,0);
		printf("\n");
	}
}
namespace ring
{
	int ring[maxn];
	int root=0;
	int vis[maxn];
	void dfs2(int u,int fa)
	{
		vis[u]=1;
		if(root)return;
		for(int i=0;i<e[u].size();++i)
		{
			int v=e[u][i];
			if(v==fa)continue;
			if(vis[v])
			{
				root=v;
			}
			if(root)
			{
				break;
			}
			dfs2(v,u);
			if(root)
			{
				break;
			}
		}
	}
	int du[maxn];
	queue<int> q;
	void topu()
	{
		for(int i=1;i<=n;++i)
			for(int j=0;j<e[i].size();++j)
			{
				du[e[i][j]]++;
			}
		for(int i=1;i<=n;++i)
			if(du[i]==1)
				q.push(i);
		while(!q.empty())
		{
			int f=q.front();q.pop();
			du[f]--;
			du[e[f][0]]--;
			if(du[e[f][0]]==1)
				q.push(e[f][0]);
		}
		for(int i=1;i<=n;++i)
		{
			if(du[i]==2)
				ring[i]=1;
		}
	}
	int b;
	void dfs(int u,int fa,int rs)
	{
		printf("%d ",u);
		vis[u]=1;
		if(!b)
		{
			/*
			for(int i=0;i<e[u].size();++i)
			{
				int v=e[u][i];
				if(v==fa)continue;
				if(!ring[v])
					dfs(v,u,rs);
			}
			*/
			for(int i=0;i<e[u].size();++i)
			{
				int v=e[u][i];
				if(v==fa)continue;
				//if(!ring[v])continue;
				if(ring[v]&&v>rs)
				{
					b=1;continue;
				}
				dfs(v,u,rs);
			}
		}
		else
		{
			for(int i=0;i<e[u].size();++i)
			{
				int v=e[u][i];
				if(v==fa)continue;
				if(vis[v])continue;
				dfs(v,u,rs);
			}
		}
	}
	void solve()
	{
		for(int i=1;i<=n;++i)
		{
			sort(e[i].begin(),e[i].end());
		}
		memset(vis,0,sizeof vis);
		dfs2(1,0);
		topu();
		memset(vis,0,sizeof vis);
		int rs;
		for(int i=0;i<e[root].size();++i)
		{
			int v=e[root][i];
			if(ring[v])rs=v;
		}
		for(int i=0;i<e[root].size();++i)
		{
			int v=e[root][i];
			if(ring[v]&&v!=rs)rs=v;
		}
		//printf("%d,%d\n",root,rs);
		dfs(1,0,rs);
		printf("\n");
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=m;++i)
	{
		int u=read();
		int v=read();
		e[u].push_back(v);
		e[v].push_back(u);
	}
	if(m==n-1)
		tree::solve();
	if(m==n)
		ring::solve();
	return 0;
}
