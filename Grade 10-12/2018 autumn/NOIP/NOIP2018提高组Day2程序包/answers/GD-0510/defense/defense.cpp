#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

typedef long long LL;

const int N=100005;
const LL inf=(LL)1e15;

int n,m,cnt,last[N],p[N],ty[N];
char str[5];
LL f[N],g[N];
struct edge{int to,next;}e[N*2];

void addedge(int u,int v)
{
	e[++cnt].to=v;e[cnt].next=last[u];last[u]=cnt;
	e[++cnt].to=u;e[cnt].next=last[v];last[v]=cnt;
}

void dp(int x,int fa)
{
	f[x]=p[x];g[x]=0;
	for (int i=last[x];i;i=e[i].next)
	{
		if (e[i].to==fa) continue;
		dp(e[i].to,x);
		f[x]+=std::min(f[e[i].to],g[e[i].to]);
		g[x]+=f[e[i].to];
	}
	if (ty[x]==1) f[x]=inf;
	if (ty[x]==2) g[x]=inf;
}

int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d%s",&n,&m,str);
	for (int i=1;i<=n;i++) scanf("%d",&p[i]);
	for (int i=1;i<n;i++)
	{
		int x,y;scanf("%d%d",&x,&y);
		addedge(x,y);
	}
	while (m--)
	{
		int a,x,b,y;scanf("%d%d%d%d",&a,&x,&b,&y);
		ty[a]=x+1;ty[b]=y+1;
		dp(1,0);
		if (std::min(f[1],g[1])<inf) printf("%lld\n",std::min(f[1],g[1]));
		else puts("-1");
		ty[a]=ty[b]=0;
	}
	return 0;
}
