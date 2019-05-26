#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
const long long INF=1e13;
const int N=3e5+10;
int ne[N*2],he[N],t[N*2],a[N],tot=0,p[N];
long long f[N],g[N];
char tp[10];
void link(int x,int y)
{
	tot++;
	ne[tot]=he[x];
	he[x]=tot;
	t[tot]=y;
}
void dp(int x,int y)
{
	for (int i=he[x];i;i=ne[i]) if (t[i]!=y) dp(t[i],x);
	f[x]=0;
	g[x]=a[x];
	for (int i=he[x];i;i=ne[i]) if (t[i]!=y) f[x]=f[x]+g[t[i]],g[x]=g[x]+min(g[t[i]],f[t[i]]);
	f[x]=min(f[x],INF);
	g[x]=min(g[x],INF);
	if (p[x]==2) f[x]=INF;
	if (p[x]==1) g[x]=INF;
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	scanf("%s",tp+1);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		link(x,y);
		link(y,x);
	}
	if (n<=2000&&m<=2000)
	{
		for (int i=1;i<=m;i++)
		{
			int x,x1,y,y1;
			scanf("%d%d%d%d",&x,&x1,&y,&y1);
			p[x]=x1+1;
			p[y]=y1+1;
			dp(1,0);
			if (f[1]==INF&&g[1]==INF) printf("-1\n");else printf("%lld\n",min(f[1],g[1]));
			p[x]=0;
			p[y]=0;
		}
	}
}
