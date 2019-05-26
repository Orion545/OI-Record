#include <bits/stdc++.h>
using namespace std;
const int maxn=100005;
const long long INF=0x1FFFFFFFFFFFFFFF;
struct edge { int obj,last; } e[maxn<<1];
int n,q,cnt,point[maxn],cost[maxn];
long long f[maxn],g[maxn];
bool must[maxn],ban[maxn];
char type1,type2;
void add(int x,int y)
{
	cnt++;
	e[cnt].obj=y;
	e[cnt].last=point[x];
	point[x]=cnt;
}
void dfs(int u,int last)
{
	f[u]=cost[u];
	g[u]=0;
	if (must[u]) g[u]=INF;
	if (ban[u]) f[u]=INF;
	for (int i=point[u],v;i;i=e[i].last)
	{
		v=e[i].obj;
		if (v==last) continue;
		dfs(v,u);
		if (!must[u]) g[u]+=f[v];
		if (!ban[u]) f[u]+=min(f[v],g[v]);
	}
	f[u]=min(f[u],INF);
	g[u]=min(g[u],INF);
}
void read(int &num)
{
	num=0;
	char ch=getchar();
	while (ch<48 || ch>57) ch=getchar();
	while (ch>=48 && ch<=57) num=(num<<3)+(num<<1)+(ch^48),ch=getchar();
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	read(n);
	read(q);
	scanf(" %c%c",&type1,&type2);
	for (int i=1;i<=n;i++) read(cost[i]);
	for (int i=1,x,y;i<n;i++)
	{
		read(x);
		read(y);
		add(x,y);
		add(y,x);
	}
	int A,B,C,D;
	while (q--)
	{
		read(A);
		read(B);
		read(C);
		read(D);
		if (B) must[A]=true; else ban[A]=true;
		if (D) must[C]=true; else ban[C]=true;
		dfs(1,0);
		if (f[1]==INF && g[1]==INF) printf("-1\n"); else printf("%lld\n",min(f[1],g[1]));
		if (B) must[A]=false; else ban[A]=false;
		if (D) must[C]=false; else ban[C]=false;
	}
	return 0;
}
