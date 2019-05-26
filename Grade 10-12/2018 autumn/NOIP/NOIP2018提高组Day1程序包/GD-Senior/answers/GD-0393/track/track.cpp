//20%
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
using namespace std;
const int N=500000+5;
int rd[N],head[N],tot;
int dis[N],vis[N];
int n,m;
struct node
{
	int to;
	int next;
	int val;
}edge[N*2+5];
void add(int u,int v,int w)
{
	tot++;
	edge[tot].val=w;
	edge[tot].to=v;
	edge[tot].next=head[u];
	head[u]=tot;
}
int dij(int x)
{
	int maxn=0;
	memset(dis,0,sizeof(dis));
	memset(vis,0,sizeof(vis));
	priority_queue<pair<int,int>,vector<pair<int,int> >,less<pair<int,int> > >q;
	dis[x]=0;
	q.push(make_pair(0,x));
	while(!q.empty())
	{
		int u=q.top().second;
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=head[u];i;i=edge[i].next)
		{
			int v=edge[i].to;
			int w=edge[i].val;
			if(vis[v]) continue;
			if(dis[v]<dis[u]+w) dis[v]=dis[u]+w;
			q.push(make_pair(dis[v],v));
		}
	}
	for(int i=1;i<=n;i++) maxn=max(maxn,dis[i]);
	return maxn; 
}
void init()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=(n-1);i++)
	{
		int u,v,w;cin>>u>>v>>w;
		add(u,v,w);add(v,u,w);
		rd[u]++;rd[v]++;
	}
}
int main()
{
	init();
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(rd[i]==1)  ans=max(ans,dij(i));
	}
	cout<<ans;
	fclose(stdin);fclose(stdout);
	return 0;
}

