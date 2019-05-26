#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=5010;
int n,m,u,v,f[maxn],t[maxn],cnt,ans[maxn],ret[maxn];
int cur,h[maxn*2],nxt[maxn*2],p[maxn*2];
bool tf[maxn][maxn],vis[maxn];
void add_edge(int x,int y)
{
	cur++;
	nxt[cur]=h[x];
	h[x]=cur;
	p[cur]=y;
}
void build_tree(int x)
{
	ans[++cnt]=x;vis[x]=true;
	for(int j=h[x];j;j=nxt[j])if(!vis[p[j]])
	{
		//printf("%d %d %d %d\n",x,p[j],u,v);
		if(u)if((x==u&&p[j]==v)||(x==v&&p[j]==u))continue;
		build_tree(p[j]);
	}
}
bool judge()//ans<ret in dictionary-order
{
	for(int i=1;i<=n;i++)if(ans[i]!=ret[i])return ans[i]<ret[i];
	return false;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)scanf("%d%d",&u,&v),f[i]=u,t[i]=v,tf[u][v]=tf[v][u]=true;
	for(int i=1;i<=n;i++)for(int j=n;j>=1;j--)if(tf[i][j])add_edge(i,j);
	if(m==n-1)
	{
		u=v=0;
		build_tree(1);
		for(int i=1;i<n;i++)printf("%d ",ans[i]);
		printf("%d\n",ans[n]);
		return 0;
	}
	if(m==n)
	{
		for(int i=1;i<=n;i++)ret[i]=n;
		for(int i=1;i<=m;i++)
		{
			memset(vis,0,sizeof vis);
			u=f[i];v=t[i];cnt=0;
			build_tree(1);
			if(cnt<n);
			else if(judge())for(int i=1;i<=n;i++)ret[i]=ans[i];
		}
		for(int i=1;i<n;i++)printf("%d ",ret[i]);
		printf("%d\n",ret[n]);
		return 0;
	}
	return 0;
}
