#include<cstdio>
#include<algorithm>
using namespace std;
struct node{int v,fr;}e[200010];
int n,m,tail[100010],p[100010],f[100010][2],cnt=0;
int fa[100010][18],dep[100010];
char s[11];

void add(int u,int v) {e[++cnt]=(node){v,tail[u]}; tail[u]=cnt;}

void dfs(int x,int fat)
{
	f[x][0]=0,f[x][1]=p[x];dep[x]=dep[fat]+1;
	for (int i=0;fa[fa[x][i]][i];i++)
		fa[x][i+1]=fa[fa[x][i]][i];
	for (int p=tail[x];p;p=e[p].fr)
		if (e[p].v!=fat)
		{
			fa[e[p].v][0]=x,dfs(e[p].v,x);
			f[x][0]+=f[e[p].v][1],f[x][1]+=min(f[e[p].v][0],f[e[p].v][1]);
		}
}

int LCA(int x,int y)
{
	if (dep[x]<dep[y]) swap(x,y);
	for (int i=16;i>=0;i--)
		if (dep[x]-dep[y]>=(1<<i)) x=fa[x][i];
	if (x==y) return x;
	for (int i=16;i>=0;i--)
		if (fa[x][i]!=fa[y][i]) x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}

int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d %d %s",&n,&m,s+1);
	for (int i=1;i<=n;i++) scanf("%d",&p[i]);
	for (int i=1,u,v;i<n;i++)
		scanf("%d%d",&u,&v),add(u,v),add(v,u);
	dfs(1,0);
	while (m--)
	{
		int a,x,b,y,lca;
		scanf("%d%d%d%d",&a,&x,&b,&y);
		if ((fa[a][0]==b || fa[b][0]==a) && x==0 && y==0) {printf("-1\n"); continue;}
		lca=LCA(a,b);
		if (lca==a)
		{
			if (y==1) printf("%d\n",f[b][y]+f[a][x]-min(f[b][0],f[b][1]));
			else printf("%d\n",f[b][y]+f[a][x]-f[b][1]);
		}
		else if (lca==b)
		{
			if (x==1) printf("%d\n",f[a][x]+f[b][y]-min(f[a][0],f[a][1]));
			else printf("%d\n",f[a][x]+f[b][y]-f[a][1]);
		}
		else
		{
			int ans=f[a][x]+f[b][y]+min(f[lca][0],f[lca][1])-f[a][x^1]+f[b][y^1];
			printf("%d\n",ans);
		}
	}
	return 0;
}
