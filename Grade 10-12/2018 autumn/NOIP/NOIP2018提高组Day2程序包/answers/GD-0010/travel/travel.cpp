#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=5e3+10;
int ne[N*2],he[N],t[N*2],tot=0,c[N],d[N][N],vis[N],fa[N],dep[N],u[N],v[N],n,fl=0,f[N][N],dd[N],p1[N],p2[N],ans[N],z=0;
void link(int x,int y)
{
	tot++;
	ne[tot]=he[x];
	he[x]=tot;
	t[tot]=y;
}
void dfs(int x)
{
	vis[x]=1;
	dep[x]=dep[fa[x]]+1;
	for (int i=he[x];i;i=ne[i]) if (!vis[t[i]])
	{
		fa[t[i]]=x;
		dfs(t[i]);
	}
}
void flow(int x,int y)
{
	printf("%d ",x);
	for (int i=1;i<=c[x];i++) if (d[x][i]!=y) flow(d[x][i],x);
}
void flow1(int x,int y)
{
	z++;
	dd[z]=x;
	for (int i=1;i<=c[x];i++) if (d[x][i]!=y&&!f[x][d[x][i]]) flow1(d[x][i],x);
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int m;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d",&u[i],&v[i]);
		link(u[i],v[i]);
		link(v[i],u[i]);
		c[u[i]]++;
		c[v[i]]++;
		d[u[i]][c[u[i]]]=v[i];
		d[v[i]][c[v[i]]]=u[i];
	}
	for (int i=1;i<=n;i++) sort(d[i]+1,d[i]+c[i]+1);
	if (m==n-1) 
	{
		flow(1,0);
		return 0;
	}
	else 
	{
		int cnt=0;
		dfs(1);
		for (int i=1;i<=m;i++)
		{
			if (fa[u[i]]==v[i]||fa[v[i]]==u[i]) fl=0;else
			{
				int x=u[i],y=v[i];
				cnt++;
				p1[cnt]=x;
				p2[cnt]=y;
				if (dep[x]<dep[y]) swap(x,y);
				while (dep[x]>dep[y])
				{
					cnt++;
					p1[cnt]=x;
					p2[cnt]=fa[x];
					x=fa[x];
				}
				if (x==y) continue;
				while (x!=y)
				{
					cnt++;
					p1[cnt]=x;
					p2[cnt]=fa[x];
					cnt++;
					p1[cnt]=y;
					p2[cnt]=fa[y];
					x=fa[x];
					y=fa[y];
				}
			}
		}
		for (int i=1;i<=n;i++) ans[i]=n;
		for (int i=1;i<=cnt;i++)
		{
			f[p1[i-1]][p2[i-1]]=0;
			f[p2[i-1]][p1[i-1]]=0;
			f[p1[i]][p2[i]]=1;
			f[p2[i]][p1[i]]=1;
			z=0;
			flow1(1,0);
			for (int i=1;i<=n;i++) 
			{
				if (dd[i]>ans[i]) break;
				if (dd[i]<ans[i])
				{
					for (int j=1;j<=n;j++) ans[j]=dd[j];
					break;
				}
			}
		}
		for (int i=1;i<=n;i++) printf("%d ",ans[i]);
	}
}
