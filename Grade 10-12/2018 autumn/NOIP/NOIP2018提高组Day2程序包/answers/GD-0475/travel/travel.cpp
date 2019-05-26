#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

const int N=10010,M=5005;

typedef long long LL;

int n,m,tot,h[N],e[N],Id[N],nxt[N],len,Loop[N],Now[N],Ans[N],Top,st[N][2];

int E[M][M],d[M];

bool bz[N],vis[N];

char c;

int read()
{
	int x=0,sig=1;
	for (c=getchar();c<'0' || c>'9';c=getchar()) if (c=='-') sig=-sig;
	for (;c>='0' && c<='9';c=getchar()) x=x*10+c-48;
	return x*sig;
}

bool cmp(int x,int y)
{
	return e[x]<e[y];
}

void Add(int x,int y)
{
	e[++tot]=y; nxt[tot]=h[x]; h[x]=tot; E[x][d[x]++]=tot; //E[x].push_back(tot);
}

bool Get(int x,int y)
{
	st[++Top][0]=x; st[Top][1]=y; vis[x]=1;
	for (int i=0;i<d[x];i++)
	{
		if (!vis[e[E[x][i]]])
		{
			if (Get(e[E[x][i]],E[x][i]^1)) return 1;
		}else if (E[x][i]!=y)
		{
			for (Loop[len++]=E[x][i];st[Top][0]!=e[E[x][i]];Loop[len++]=st[Top--][1]);
			return 1;
		}
	}
	return 0;
}

void dfs(int x)
{
	vis[x]=1;
	Now[++tot]=x;
	for (int i=0;i<d[x];i++) if (!vis[e[E[x][i]]] && !bz[E[x][i]]) dfs(e[E[x][i]]);
}

int main()
{
	freopen("travel.in","r",stdin); freopen("travel.out","w",stdout);
	n=read(); m=read(); tot=1;
	for (int i=0,x,y;i<m;i++)
	{
		x=read(); y=read();
		Add(x,y); Add(y,x);
	}
	tot=0;
	for (int i=1;i<=n;i++)
	{
		sort(E[i],E[i]+d[i],cmp);
	}
	if (m==n-1)
	{
		tot=0;
		dfs(1);
		for (int i=1;i<=n;i++) printf("%d%c",Now[i],(i<n)?' ':'\n');
		return 0;
	}
	Get(1,0);
	Ans[1]=n+1;
	for (int i=0;i<len;i++)
	{
		bz[Loop[i]]=bz[Loop[i]^1]=1;
		for (int j=1;j<=n;j++) vis[j]=0; tot=0;
		dfs(1);
		bool Ok=0;
		for (int j=1;j<=n;j++) if (Ans[j]!=Now[j])
		{
			if (Ans[j]>Now[j]) Ok=1;
			break;
		}
		if (Ok)
		{
			for (int j=1;j<=n;j++) Ans[j]=Now[j];
		}
		bz[Loop[i]]=bz[Loop[i]^1]=0;
	}
	for (int i=1;i<=n;i++) printf("%d%c",Ans[i],(i<n)?' ':'\n');
	return 0;
}
