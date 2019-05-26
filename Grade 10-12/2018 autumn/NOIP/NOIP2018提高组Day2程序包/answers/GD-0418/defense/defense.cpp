#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#define ll long long
using namespace std;
const int maxn=500010, inf=1e9;
struct edge{int too, pre;}e[maxn<<1];
int n, Q, x, y, tot;
int last[maxn], w[maxn], v[maxn], f[maxn][2], fa[maxn], g[maxn][2];
char s[233];

template<typename T>
inline void read(T &k)
{
	int f=1; k=0; char c=getchar();
	while(c<'0' || c>'9') c=='-' && (f=-1), c=getchar();
	while(c<='9' && c>='0') k=k*10+c-'0', c=getchar();
	k*=f;
}

void dfs(int x)
{
	f[x][0]=f[x][1]=0;
	for(int i=last[x], too;i;i=e[i].pre)
	if((too=e[i].too)!=fa[x])
	{
		fa[too]=x;
		dfs(too);
		f[x][0]+=f[too][1];
		f[x][1]+=min(f[too][1], f[too][0]);
	}
	f[x][1]+=w[x];
	if(!v[x]) f[x][1]=inf;
	if(v[x]==1) f[x][0]=inf;
//	printf("x:%d f[x][0]:%d f[x][1]:%d \n", x, f[x][0], f[x][1]);
}

inline void add(int x, int y) {e[++tot]=(edge){y, last[x]}; last[x]=tot;}

void getans(int x, int y)
{
	if(!y) g[x][0]=f[x][0], g[x][1]=inf;
	else g[x][0]=inf, g[x][1]=f[x][1];
	while(x!=1)
	{
		g[fa[x]][0]=f[fa[x]][0]-f[x][1]+g[x][1];
		g[fa[x]][1]=f[fa[x]][1]-min(f[x][1], f[x][0])+min(g[x][0], g[x][1]);
		x=fa[x];
	}
}

inline void solve1()
{
//	puts("OWO");
	dfs(1);
	while(Q--)
	{
		read(x); read(x); 
		read(x); read(y);
		getans(x, y);
		if(g[1][1]>=inf) puts("-1");
		else printf("%d\n", g[1][1]);
	}
}

int main()
{
	freopen("defense.in", "r", stdin);
	freopen("defense.out", "w", stdout);
	read(n); read(Q); scanf("%s", s+1);
	for(int i=1;i<=n;i++) read(w[i]);
	for(int i=1;i<n;i++)
	{
		read(x); read(y);
		add(x, y); add(y, x);
	}
	memset(v, -1, sizeof(v));
	if(s[1]=='B') return solve1(), 0;
	while(Q--)
	{
		read(x); read(v[x]);
		read(y); read(v[y]);
		dfs(1);
		int ans=min(f[1][0], f[1][1]);
		if(ans>=inf) puts("-1");
		else printf("%d\n", ans);
		v[x]=v[y]=-1;
	}
	return 0;
}
