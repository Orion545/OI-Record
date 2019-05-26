#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cmath>
using namespace std;
const int maxn=50010;
const int maxm=100010;
struct data{
	int next,to,len;
};
int head[maxm],vis[maxn],d[maxn],p[maxn];
int f[maxn][20];
data g[maxm];
int t=0,n;
void add(int from,int to,int len)
{
	++t;
	g[t].next=head[from];
	g[t].to=to;
	g[t].len=len;
	head[from]=t;
	return;
}
void bfs(int root)
{
	queue<int> q;
	memset(vis,0,sizeof(vis));
	q.push(root); vis[root]=1; d[root]=1; f[root][0]=0; p[root]=0;
	while (!q.empty())
	{
		int v=q.front();
		q.pop();
		for (int i=head[v];i!=0;i=g[i].next)
		{
			int j=g[i].to;
			if (!vis[j]) 
			{
				d[j]=d[v]+1;
				vis[j]=1;
				f[j][0]=v;
				p[j]=p[v]+g[i].len;
				q.push(j);
			}
		}
	}
	return;
}
void prelca()
{
	for (int j=0;(1<<(j+1))<n;++j)
	 for (int i=1;i<=n;++i)
	 if (f[i][j]==0) f[i][j+1]=0;
	  else f[i][j+1]=f[f[i][j]][j];
	return;
}
int lca(int u,int v)
{
	if (d[u]<d[v]) swap(u,v); 
	for (int i=(int)log2(n*1.0);i>=0;--i)
	if (d[f[u][i]]>=d[v]) u=f[u][i];
	if (u==v) return u;
	for (int i=(int)log2(n*1.0);i>=0;--i)
	if (f[u][i]!=f[v][i]) 
	u=f[u][i],v=f[v][i];
	return f[u][0];
}
int main()
{
	int m,x,y,v;
	int ans=0;
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	memset(head,0,sizeof(head));
	memset(d,0,sizeof(d));
	cin>>n>>m;
	for (int i=1;i<n;++i) 
	{
		cin>>x>>y>>v;
		add(x,y,v);
		add(y,x,v);
	}
	bfs(1);
	prelca();
	for (int i=1;i<=n;++i)
	 for (int j=1;j<=n;++j)
	  ans=max(ans,p[i]+p[j]-2*p[lca(i,j)]);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
