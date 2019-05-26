#include<cstdio>
using namespace std;
struct e{
	int t,nxt,v;
}ed[100100];
int cnt=0,n,m;
int h[50100],dep[50100]={0},dist[50100]={0},mxtr[50100]={0},f[50100]={0};
void addedge(int f,int t,int v)
{
	ed[++cnt].t=t;
	ed[cnt].nxt=h[f];
	ed[cnt].v=v;
	h[f]=cnt;
}
/*void dfs(int now,int fa)
{
	dep[now]=dep[fa]+1;
	f[now][0]=fa;
	for (int i=0;i<=20;i++)
		f[now][i]=f[f[now][i-1]][i-1];
	for (int i=h[now];i;i=ed[i].nxt)
	{
		if (ed[i].t!=fa)
		{
			dist[ed[i].t]=dist[now]+ed[i].v;
			dfs(ed[i].t,now);
		}
	}
}*/
/*int lca(int x,int y)
{
	if (dep[x]<dep[y]) {
		int t=x;x=y;y=t;
	}
	int dept=dep[x]-dep[y];
	for (int i=0;i<=20;i++)
		if (dept&(1<<i)) x=f[x][i];
	if (x==y) return x;
	for (int i=20;i>=0;i--)
	{
		if (f[x][i]!=f[y][i])
		{
			x=f[x][i];
			y=f[y][i];
		}
	}
	return f[x][0];
}*/
void dfs1(int now,int fa)
{
	mxtr[now]=dist[now];
	f[now]=fa;
	for (int i=h[now];i;i=ed[i].nxt)
	{
		if (ed[i].t!=fa)
		{
			dist[ed[i].t]=dist[now]+ed[i].v;
			dfs1(ed[i].t,now);
			if (mxtr[ed[i].t]>mxtr[now]) mxtr[now]=mxtr[ed[i].t];
		}
	}
}
int p[50100]={0};
void pth(int now,int fa)
{
	int fm=0,sm=0;
	for (int i=h[now];i;i=ed[i].nxt)
	{
		if (ed[i].t!=fa)
		{
			pth(ed[i].t,now);
			if (mxtr[ed[i].t]>fm)
			{
				sm=fm;
				fm=mxtr[ed[i].t];
			}
			else if (mxtr[ed[i].t]>sm)
			{
				sm=mxtr[ed[i].t];
			}
			if (p[ed[i].t]>p[now]) p[now]=p[ed[i].t];
		} 
	}
	if (fm+sm-2*dist[now]>p[now]) p[now]=fm+sm-2*dist[now];
}
int sum[50100]={0};
bool check(int k)
{
	int st=0,w=0;
	for (int i=1;i<=n;i++)
	{
		int now=sum[i]-sum[st];
		if (now>=k)
		{
			st=i;
			w++;
		}
	}
	if (w>=m) return true;
	return false;
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	if (m==1)
	{
		//最长链
		for (int i=1;i<n;i++)
		{
			int f,t,v;
			scanf("%d%d%d",&f,&t,&v);
			addedge(f,t,v);
			addedge(t,f,v);
		}
		dfs1(1,0);
		pth(1,0);
		printf("%d",p[1]);
	}
	else
	{
		//树的退化 
		int d[50100]={0},r=0;
		for (int i=1;i<n;i++)
		{
			int f,t,v;
			scanf("%d%d%d",&f,&t,&v);
			if (f>t) {
				int tem=f;f=t;t=tem;
			}
			d[t]=v;
			r+=v;
		}
		for (int i=2;i<=n;i++)
			sum[i]=sum[i-1]+d[i];
		int l=1,ans=0;
		while (l<=r)
		{
			int mid=(l+r)/2;
			if (check(mid)) 
			{
				l=mid+1;
				ans=mid;
			}
			else r=mid-1;
		}
		printf("%d",ans);
	}
	return 0;
}
