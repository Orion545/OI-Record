#include<cstdio>
#include<algorithm>
#include<string>
using namespace std;
struct Edge
{
	int u,to,nxt;
}e[200010];
int n,m,a,b,x,y,cnt,tot1,tot2;
int h[200010],w[100010],vis[100010],dep[100010];
int f[1<<20][30];
char ch[10];
void add(int u,int v)
{
	e[++cnt].u=u;e[cnt].to=v;e[cnt].nxt=h[u];h[u]=cnt;
}
void dfs(int u,int sd)
{
	if (sd) tot1+=w[u];
	else tot2+=w[u];
	vis[u]=1;
	for(int i=h[u],v=e[i].to;i;i=e[i].nxt,v=e[i].to)
	if (!vis[v]) dep[v]=dep[u]+1,f[v][0]=u,dfs(v,sd^1);
}
int lca(int x,int y)
{
	if (dep[x]<dep[y])
	{
		int t=x;x=y;y=t;
	}
	for(int i=20;i>=0;i--)
	if (dep[f[x][i]]>=dep[y]) x=f[x][i];
	if (x==y) return y;
	for(int i=20;i>=0;i--)
	if (f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
	return f[x][0];
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d%s",&n,&m,ch);dep[1]=1;
	for(int i=1;i<=n;i++) scanf("%d",&w[i]);
	for(int i=1;i<n;i++) scanf("%d%d",&x,&y),add(x,y),add(y,x);
	dfs(1,1);
	for(int i=1;i<=20;i++)
	for(int x=1;x<=n;x++) f[x][i]=f[f[x][i-1]][i-1];
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d%d",&a,&x,&b,&y);int tmp=lca(a,b);
		if ((dep[a]+dep[b]-2*dep[tmp])%2)
		{
			if (x!=y)
			{
				if (x)
				{
					if (dep[a]%2) printf("%d\n",tot1);
					else printf("%d\n",tot2);
				}
				else
				{
					if (dep[b]%2) printf("%d\n",tot2);
					else printf("%d\n",tot1);
				}
			}
			else printf("-1\n");
		}
		else
		{
			if (x==y)
			{
				if (x)
				{
					if (dep[a]%2) printf("%d\n",tot1);
					else printf("%d\n",tot2);					
				}
				else
				{
					if (dep[a]%2) printf("%d\n",tot2);
					else printf("%d\n",tot1);					
				}
			}
			else printf("-1\n");
		}
	}
	return 0;
}
