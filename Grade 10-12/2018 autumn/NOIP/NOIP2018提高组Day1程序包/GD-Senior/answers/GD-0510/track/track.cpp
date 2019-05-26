#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

const int N=50005;

int n,m,cnt,last[N],mid,a[N],f[N],g[N],val[N],fa[N],nx[N];
bool vis[N];
struct edge{int to,next,w;}e[N*2];

int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

void addedge(int u,int v,int w)
{
	e[++cnt].to=v;e[cnt].w=w;e[cnt].next=last[u];last[u]=cnt;
	e[++cnt].to=u;e[cnt].w=w;e[cnt].next=last[v];last[v]=cnt;
}

void pre(int x)
{
	for (int i=last[x];i;i=e[i].next)
	{
		if (e[i].to==fa[x]) continue;
		fa[e[i].to]=x;
		val[e[i].to]=e[i].w;
		pre(e[i].to);
	}
}

int fnd(int x)
{
	if (nx[x]==x) return x;
	else return nx[x]=fnd(nx[x]);
}

void dfs(int x)
{
	f[x]=g[x]=0;
	for (int i=last[x];i;i=e[i].next)
		if (e[i].to!=fa[x]) dfs(e[i].to);
	int tot=0;
	for (int i=last[x];i;i=e[i].next)
		if (e[i].to!=fa[x]) f[x]+=f[e[i].to],a[++tot]=g[e[i].to];
	std::sort(a+1,a+tot+1);
	for (int i=1;i<=tot+1;i++) vis[i]=0,nx[i]=i;
	int p=tot+1;
	for (int i=1;i<tot;i++)
	{
		if (vis[i]) continue;
		while (p>1&&a[p-1]+a[i]>=mid) p--;
		int y=fnd(std::max(p,i+1));
		if (y>tot) continue;
		vis[i]=vis[y]=1;
		nx[y]=y+1;nx[i]=i+1;
		f[x]++;
	}
	int mx=0;
	for (int i=tot;i>=1;i--)
		if (!vis[i]) {mx=a[i];break;}
	if (mx+val[x]>=mid) f[x]++;
	else g[x]=mx+val[x];
}

int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	n=read();m=read();
	for (int i=1;i<n;i++)
	{
		int x=read(),y=read(),z=read();
		addedge(x,y,z);
	}
	pre(1);
	int l=1,r=1e9;
	while (l<=r)
	{
		mid=(l+r)/2;
		dfs(1);
		if (f[1]>=m) l=mid+1;
		else r=mid-1;
	}
	printf("%d\n",l-1);
	return 0;
}
