# include<cstdio>
# include<cstring>
# include<algorithm>
using namespace std;
const int N = 1e5 + 5;
int st[N],to[N << 1],nx[N << 1];
int f[N][2],is[N],p[N],g[N][2];
int n,m,tot;
inline void add(int u,int v)
{
	to[++tot] = v,nx[tot] = st[u],st[u] = tot;
	to[++tot] = u,nx[tot] = st[v],st[v] = tot;
}
inline void dfs(int x,int fa)
{
	f[x][0] = 0,f[x][1] = p[x];
	if (is[x] == 1) f[x][0] = 0x3f3f3f3f;
	else if (is[x] == 0) f[x][1] = 0x3f3f3f3f;
	for (int i = st[x] ; i ; i = nx[i])
	if (to[i] != fa)
	{
		dfs(to[i],x);
		f[x][0] += f[to[i]][1];
		f[x][1] += min(f[to[i]][1],f[to[i]][0]);
	}
}
inline void dfs1(int x,int fa)
{
	f[x][0] = 0,f[x][1] = p[x];
	g[x][0] = g[fa][1],g[x][1] = min(g[fa][1],g[fa][0]) + p[x];
	for (int i = st[x] ; i ; i = nx[i])
	if (to[i] != fa)
	{
		dfs1(to[i],x);
		f[x][0] += f[to[i]][1];
		f[x][1] += min(f[to[i]][1],f[to[i]][0]);
	}
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	char s[10];
	scanf("%d%d%s",&n,&m,s + 1);
	for (int i = 1 ; i <= n ; ++i) scanf("%d",&p[i]),is[i] = 2;
	for (int i = 1 ; i < n ; ++i)
	{
		int u,v; scanf("%d%d",&u,&v);
		add(u,v);
	}
	if (n <= 2000 && m <= 2000)
	{
		while (m--)
		{
			int a,b,x,y; scanf("%d%d%d%d",&a,&x,&b,&y);
			is[a] = x,is[b] = y;
			dfs(1,0);
			printf("%d\n",min(f[1][0],f[1][1]) >= 0x3f3f3f3f ? -1 : min(f[1][0],f[1][1]));
			is[a] = is[b] = 2;
		}
	}else
	{
		dfs1(1,0);
		while (m--)
		{
			int a,b,x,y; scanf("%d%d%d%d",&a,&x,&b,&y);
			if (a > b) swap(a,b),swap(x,y);
			if (!x && !y) { puts("-1"); continue; }
			printf("%d\n",g[a][x] + f[b][y] >= 0x3f3f3f3f ? -1 : g[a][x] + f[b][y]);
		}			
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
