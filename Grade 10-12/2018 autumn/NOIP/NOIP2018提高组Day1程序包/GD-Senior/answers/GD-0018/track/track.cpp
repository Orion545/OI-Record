#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
int tot;
long long ans=0;
int fir[50010],vis[50010];
struct edge
{
	int to;
	int dis;
	int next;
}e[100010];
void add(int x,int y,int z)
{
	tot++;
	e[tot].to=y;
	e[tot].dis=z;
	e[tot].next=fir[x];
	fir[x]=tot;
}
void dfs(int p,long long s)
{
	if(vis[p]) return;
	else vis[p]=1;
	ans=max(ans,s);
	for(int i=fir[p];i;i=e[i].next)
		dfs(e[i].to,s+(long long)(e[i].dis));
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	int n,m,a,b,c;
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		add(a,b,c);
		add(b,a,c);
	}
	for(int i=1;i<=n;i++)
	{
		memset(vis,0,sizeof(vis));
		dfs(i,0);
	}
	printf("%lld\n",ans);
	return 0;
}
