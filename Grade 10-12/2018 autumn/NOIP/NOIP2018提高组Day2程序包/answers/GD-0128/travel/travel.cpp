#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define pr pair<int,int>
#define fr first
#define se second
#define F for (int ii=1;ii<=g[now][0].fr;ii++) if (g[now][ii].fr!=lst&&g[now][ii].se!=i)
#define N 5005
bool vis[N];
pr g[N][N];
int tot,n,m,i,zw,p[N];
void dfs2(int now,int lst)
{
	vis[now]=true;tot++;
	F{
		if (!vis[g[now][ii].fr]) dfs2(g[now][ii].fr,now);
	}
}
void dfs(int now,int lst)
{
	tot++;
	if (zw==1) p[tot]=now;
	if (zw==0){
		if (now<p[tot]) zw=1,p[tot]=now;
		else if (now>p[tot]) zw=-1;
	}
	if (zw==-1) return;
	F{
		dfs(g[now][ii].fr,now);
		if (zw==-1) return;
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (i=1;i<=m;i++){
		int x,y;scanf("%d%d",&x,&y);
		g[x][++g[x][0].fr].fr=y;g[x][g[x][0].fr].se=i;
		g[y][++g[y][0].fr].fr=x;g[y][g[y][0].fr].se=i;
	}for (i=1;i<=n;i++) p[i]=n+1-i;
	for (i=1;i<=n;i++) sort(g[i]+1,g[i]+g[i][0].fr+1);
	if (m==n-1) zw=0,i=0,dfs(1,0);
	else for (i=1;i<=m;i++){
		tot=0;memset(vis,false,sizeof(vis));dfs2(1,0);
		if (tot==n) tot=0,zw=0,dfs(1,0);
	}
	for (i=1;i<=n;i++) printf("%d ",p[i]);
	return 0;
}
