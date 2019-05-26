#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;
const int N=1e5+100;
const int mod=1e9+7;
#define pr(p) printf("%lld\n",p)
inline void sc (int &x)
{
	x=0; static int p; p=1; static char c; c=getchar();
	while (!isdigit(c)) { if (c=='-') p=-1;  c=getchar(); }
	while ( isdigit(c)) { x=(x<<3)+(x<<1)+(c-48);  c=getchar(); }
	x*=p;
}
struct EDGE { int v,nx; }lb[N<<1]; int tot=1,top[N];
void add (int u,int v) { lb[++tot].v=v,lb[tot].nx=top[u]; top[u]=tot; }
int w[N];
int a,x,b,y;
long long f[N][2];
void tree (int u,int fa)
{
	f[u][1]=w[u];
	bool fg=0;
	for (int kb=top[u]; kb!=-1; kb=lb[kb].nx)
	{
		int v=lb[kb].v;
		if (v==fa) continue;
		fg=1; tree (v,u);
		f[u][1]+=min (f[v][0],f[v][1]);
		f[u][0]+=f[v][1];
	}
	if (!fg) f[u][0]=0;
	if (u==a&&x==1||u==b&&y==1) f[u][0]=30000000000;
	if (u==a&&x==0||u==b&&y==0) f[u][1]=30000000000;
}
int main()
{
	freopen ("defense.in","r",stdin);
	freopen ("defense.out","w",stdout);
	memset (top,-1,sizeof (top));
	int n,m; char op[5];
	sc(n),sc(m),scanf ("%s",op+1);
	for (int i=1; i<=n; i++)
		sc(w[i]);
	for (int i=1; i< n; i++)
	{
		int u,v; sc(u),sc(v);
		add (u,v),add (v,u);
	}
	while (m--)
	{
		sc(a),sc(x),sc(b),sc(y);
		memset (f,0,sizeof (f));
		tree (1,0);
		if (f[1][0]>=30000000000) f[1][0]=-1;
		if (f[1][1]>=30000000000) f[1][1]=-1;
		if (a==1) pr(f[1][x]);
		else if (b==1) pr(f[1][y]);
		else
		{
			if (f[1][0]==-1) pr(f[1][1]);
			else if (f[1][1]==-1) pr(f[1][0]);
			else pr(min (f[1][0],f[1][1]));
		}
	}
	return 0;
}

