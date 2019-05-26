#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define LL long long
#define inf 400000000000ll
#define N 100010
int read()
{
	int x = 0; char ch = getchar();
	for(;ch<'0'||ch>'9';ch = getchar());
	for(;ch>='0'&&ch<='9';ch = getchar()) x = (x<<3)+(x<<1)+(ch^48);
	return x;
}
int n,m;
int x,x_opt,y,y_opt,fa[N];
char opt[10];
int ver[N<<1],ne[N<<1],head[N],tot;
void add(int x,int y)
{
	ver[++tot] = y; ne[tot] = head[x]; head[x] = tot;
	ver[++tot] = x; ne[tot] = head[y]; head[y] = tot;
}
LL p[N],f[N][2],g[N][2];
void dfs1(int u,int pre)
{
	f[u][0] = f[u][1] = 0;
	for(int i=head[u],v;i;i=ne[i])
	if((v = ver[i]) != pre)
	{
		dfs1(v,u);
		f[u][0] += f[v][1];
		f[u][1] += min(f[v][0],f[v][1]);
		f[u][0] = min(f[u][0],inf);
		f[u][1] = min(f[u][1],inf);
	}
	f[u][1] += p[u]; f[u][1] = min(f[u][1],inf);
	if(u==x) f[u][x_opt] = inf;
	if(u==y) f[u][y_opt] = inf;
}
void dfs2(int u,int pre)
{
	fa[u] = pre;
	for(int i=head[u],v;i;i=ne[i])
	if((v = ver[i]) != pre)
	{
		dfs2(v,u);
		g[u][0] += g[v][1];
		g[u][1] += min(g[v][0],g[v][1]);
	}
	g[u][1] += p[u];
}
struct node{
	LL x,y;
};
node pushup(int u,node now)
{
	node nf;
	if(now.y == inf) nf.x = inf;
	else nf.x = g[fa[u]][0] - g[u][1] + now.y;
	
	if(now.x == inf && now.y == inf) nf.y = inf;
	else nf.y = g[fa[u]][1] - min(g[u][0],g[u][1]) + min(now.x,now.y);
	return nf;
}

int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	n = read(); m = read(); scanf("%s",opt);
	for(int i=1;i<=n;i++) p[i] = read();
	for(int i=1;i<n;i++) add(read(),read());
	if(n>2000) dfs2(1,0);
	node now;
	for(;m--;)
	{
		x = read(); x_opt = 1-read();
		y = read(); y_opt = 1-read();
		if(n<=2000)
		{
			dfs1(1,0);
			if(f[1][1]==inf && f[1][0]==inf)
				printf("-1\n");
			else
				printf("%lld\n",min(f[1][1],f[1][0]));
		}
		else
		{
			now.x = inf; now.y = inf;
			if(y_opt == 0) now.y = g[y][1];
			else now.x = g[y][0];
			for(int u=y;fa[u];u=fa[u])
				now = pushup(u,now);
			if(now.y == inf)
				printf("-1\n");
			else
				printf("%lld\n",now.y);
		}
	}
	return 0;
}
