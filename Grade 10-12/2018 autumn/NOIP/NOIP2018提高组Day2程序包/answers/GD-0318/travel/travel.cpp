# include<cstdio>
# include<cstring>
# include<algorithm>
using namespace std;
const int N = 5e3 + 5;
int st[N],to[N << 1],nx[N << 1];
int ans[N],vis[N],sta[N][N],col[N];
int n,m,tot,flag;
inline void add(int u,int v)
{
	to[++tot] = v,nx[tot] = st[u],st[u] = tot;
	to[++tot] = u,nx[tot] = st[v],st[v] = tot;
}
inline void dfs(int x)
{
	vis[x] = 1,ans[++n] = x;
	int top = 0;
	for (int i = st[x] ; i ; i = nx[i])
	if (!vis[to[i]]) sta[x][++top] = to[i];
	sort(sta[x] + 1,sta[x] + top + 1);
	for (int i = 1 ; i <= top ; ++i) dfs(sta[x][i]);
}
inline bool find(int x,int f,int g)
{
	vis[x] = col[x] = 1;
	for (int i = st[x] ; i ; i = nx[i])
	if (to[i] != f)
	{
		if (to[i] == g) return 1;
		if (!vis[to[i]] && find(to[i],x,g)) return 1;
	}
	col[x] = 0;
	return 0;
}
inline void solve(int x,int las)
{
	if (col[x] < 2) ans[++n] = x;
	vis[x] = 1;
	int top = 0;
	for (int i = st[x] ; i ; i = nx[i])
	if (!vis[to[i]]) sta[x][++top] = to[i];
	if (!top) return;
	sort(sta[x] + 1,sta[x] + top + 1);
	if (las < sta[x][1] && col[x] && !flag) { col[x] = 2,vis[x] = 0,flag = 1; return; }
	sta[x][top + 1] = las;
	for (int i = 1 ; i <= top ; ++i)
	if (col[sta[x][i]]) solve(sta[x][i],sta[x][i + 1]);
	else solve(sta[x][i],N);
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i = 1 ; i <= m ; ++i)
	{
		int u,v; scanf("%d%d",&u,&v);
		add(u,v);
	}
	if (m == n - 1) { n = 0,dfs(1); }
	else
	{
		for (int i = 1 ; i <= n ; ++i)
		if (find(i,0,i)) break;
		else memset(vis,0,sizeof(vis));
		memset(vis,0,sizeof(vis));
		n = 0,solve(1,N);
	}
	for (int i = 1 ; i < n ; ++i) printf("%d ",ans[i]);
	printf("%d",ans[n]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
