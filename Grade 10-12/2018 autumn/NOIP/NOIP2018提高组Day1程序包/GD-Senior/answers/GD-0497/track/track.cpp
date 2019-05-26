#include<iostream>
#include<cstdio>
#include<fstream>
#include<cstring>
#include<cmath>
#include<string>
#include<queue>
using namespace std;
const int maxn=5e4+5;
int n,m,ans;
struct yan
{
	int to,nxt,va;
}edge[maxn];
int tot,head[maxn],dis[maxn];
bool vis[maxn];
inline void add(int u,int v,int k)
{
	tot++;
	edge[tot].to=v;
	edge[tot].va=k;
	edge[tot].nxt=head[u];
	head[u]=tot;
}
void spfa(int w)
{
	memset(vis,0,sizeof(vis));
	memset(dis,120,sizeof(dis));
	queue<int> q;
	q.push(w);
	dis[w]=0;
	vis[w]=1;
	while (!q.empty())
	{
		int u=q.front();
		q.pop();
		vis[u]=0;
		for (int i=head[u];i;i=edge[i].nxt)
		{
			int v=edge[i].to;
			if (dis[v]>dis[u]+edge[i].va)
			{
				dis[v]=dis[u]+edge[i].va;
				if (!vis[v])
				{
					q.push(v);
					vis[v]=1;
				}
			}
		}
	}
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<n;i++)
	{
		int u,v,k;
		scanf("%d%d%d",&u,&v,&k);
		add(u,v,k);
		add(v,u,k);
	}
	for (int i=1;i<=n;i++)
	{
		spfa(i);
		for (int j=1;j<=n;j++)
		{
			ans=max(ans,dis[j]);
		}
	}
	printf("%d",ans);
	return 0;
}
