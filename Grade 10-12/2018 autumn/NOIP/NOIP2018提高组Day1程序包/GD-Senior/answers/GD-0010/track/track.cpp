#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int N=1e5+10,INF=1e9;
int ne[N*2],he[N],t[N*2],cc[N],e[N],ee[N],d[N],tot=0,n,m,fa[N],dfn[N],g[N],sz[N],nd=0;
long long ans,sum[N],dis[N],f[2000][2000];
void link(int x,int y,int z)
{
	tot++;
	ne[tot]=he[x];
	he[x]=tot;
	t[tot]=y;
	cc[tot]=z;
}
void flow(int x,int y)
{
	fa[x]=y;
	for (int i=he[x];i;i=ne[i]) if (t[i]!=y)
	{
		dis[t[i]]=dis[x]+cc[i];
		flow(t[i],x);
	}
}
void pre(int x,int y,int d)
{
	for (int i=he[x];i;i=ne[i]) if (t[i]!=y)
	{
		e[d]=cc[i];
		pre(t[i],x,d+1);
	}
}
void solve1()
{
	flow(1,0);
	int s=1;
	for (int i=1;i<=n;i++) if (dis[i]>dis[s]) s=i;
	dis[s]=0;
	flow(s,0);
	for (int i=1;i<=n;i++) ans=max(dis[i],ans);
}
void solve2()
{
	int s=0;
	for (int i=1;i<=n;i++) if (d[i]==1) s=i;
	pre(s,0,1);
	for (int i=1;i<n;i++) sum[i]=sum[i-1]+e[i];
	long long l=1,r=sum[n-1];
	while (l<=r)
	{
		long long mid=l+r>>1;
		long long last=0;
		int tmp=0;
		for (int i=1;i<n;i++) 
		{
			if (sum[i]-last>=mid) 
			{
				last=sum[i];
				tmp++;
			}
		}
		if (tmp>=m)
		{
			ans=mid;
			l=mid+1;
		}else r=mid-1;
	}
}
void solve3()
{
	sort(ee+1,ee+n);
	long long ss=0;
	for (int i=1;i<n;i++) ss=ss+ee[i];
	long long l=1,r=ss;
	while (l<=r)
	{
		long long mid=l+r>>1;
		int tmp=0;
		int j;
		for (int i=n-1;i>=1;i--) 
		{
			if (ee[i]>=mid)
			{
				tmp++;
				j=i;
			}else break;
		}
		j--;
		for (int i=1;i<=j;i++)
		{
			if (i>=j) break;
			if (ee[i]+ee[j]>=mid)
			{
				tmp++;
				j--;
			}
		}
		if (tmp>=m)
		{
			ans=mid;
			l=mid+1;
		}else r=mid-1;
	}
}
void dfs(int x)
{
	nd++;
	g[nd]=x;
	dfn[x]=nd;
	for (int i=he[x];i;i=ne[i]) if (t[i]!=fa[x]) 
	{
		dfs(t[i]);
		sz[x]=sz[x]+t[i];
	}
	sz[x]++;
}
void get(long long &x,long long y)
{
	if (x==INF) x=y;else if (y==INF) return;else x=max(x,y);
}
void dp(int x)
{
	for (int i=he[x];i;i=ne[i]) if (t[i]!=fa[x]) dp(t[i]);
	int cc=0,dd[3];
	for (int i=he[x];i;i=ne[i]) if (t[i]!=fa[x]) 
	{
		cc++;
		dd[cc]=t[i];
	}
	if (!cc) return;
	if (cc==1)
	{
		for (int j=1;j<=m;j++) for (int i=dfn[dd[1]];i<dfn[dd[1]]+sz[dd[1]];i++) get(f[x][j],f[g[i]][j]);
		for (int j=1;j<=m;j++) for (int i=dfn[dd[1]];i<dfn[dd[1]]+sz[dd[1]];i++) get(f[x][j],min(f[g[i]][j-1],dis[g[i]]-dis[x]));
	}
	if (cc==2)
	{
		for (int j=1;j<=m;j++)
		{
			for (int i=dfn[dd[1]];i<dfn[dd[1]]+sz[dd[1]];i++) get(f[x][j],f[g[i]][j]);
			for (int i=dfn[dd[2]];i<dfn[dd[2]]+sz[dd[2]];i++) get(f[x][j],f[g[i]][j]);
		}
		for (int j=1;j<=m;j++)
		{
			for (int i=dfn[dd[1]];i<dfn[dd[1]]+sz[dd[1]];i++) get(f[x][j],min(f[g[i]][j-1],dis[g[i]]-dis[x]));
			for (int i=dfn[dd[2]];i<dfn[dd[2]]+sz[dd[2]];i++) get(f[x][j],min(f[g[i]][j-1],dis[g[i]]-dis[x]));
		}
		for (int j=1;j<=m;j++) 
		{
			for (int i=dfn[dd[1]];i<dfn[dd[1]]+sz[dd[1]];i++) for (int k=dfn[dd[2]];k<dfn[dd[2]]+sz[dd[2]];k++)
			for (int l=1;l<=j;l++) get(f[x][j],min(f[g[i]][j-l],min(f[g[k]][l-1],dis[g[i]]+dis[g[k]]-2*dis[x])));
		}
	}
}
void solve4()
{
	int s=0;
	for (int i=1;i<=n;i++) if (d[i]<3) s=i;
	flow(s,0);
	dfs(s);
	for (int i=1;i<=n;i++) for (int j=0;j<=m;j++) f[i][j]=INF;
	dp(s);
	ans=f[s][m];
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	int fl=0;
	ans=0;
	scanf("%d%d",&n,&m);
	for (int i=1;i<n;i++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		d[x]++;
		d[y]++;
		link(x,y,z);
		link(y,x,z);
		if (d[x]>2||d[y]>2) fl=1;
		ee[i]=z;
	}
	if (m==1) solve1();else
	if (fl==0) solve2();else
	if (d[1]==n-1) solve3();
	else solve4();
	printf("%lld\n",ans);
}
