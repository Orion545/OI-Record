#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

const int N=200010,M=2010,T=262222;

typedef long long LL;

const LL INF=1e16;

int n,tot,m,bz[N],h[N],e[N],nxt[N],P[N];

LL f[N][2],ans;

bool g[M][M];

char S[3];

struct Data
{
	LL a,b,c,d;
}t[T],tmp,p,q,r;

Data operator + (Data a,Data b)
{
	tmp.a=min(min(a.a+b.c,a.b+b.a),a.b+b.c);
	tmp.b=min(min(a.a+b.d,a.b+b.b),a.b+b.d);
	tmp.c=min(min(a.c+b.c,a.d+b.a),a.d+b.c);
	tmp.d=min(min(a.c+b.d,a.d+b.b),a.d+b.d);
	return tmp;
}

char c;

int read()
{
	int x=0,sig=1;
	for (c=getchar();c<'0' || c>'9';c=getchar()) if (c=='-') sig=-sig;
	for (;c>='0' && c<='9';c=getchar()) x=x*10+c-48;
	return x*sig;
}

void Add(int x,int y)
{
	e[++tot]=y; nxt[tot]=h[x]; h[x]=tot;
}

void dfs(int x,int y)
{
	f[x][0]=0; f[x][1]=P[x];
	for (int i=h[x];i;i=nxt[i]) if (e[i]!=y)
	{
		dfs(e[i],x);
		f[x][0]+=f[e[i]][1];
		f[x][1]+=min(f[e[i]][0],f[e[i]][1]);
	}
	if (bz[x]==1) f[x][1]=INF;else if (bz[x]==2) f[x][0]=INF;
}

void Init(int l,int r,int x)
{
	if (l==r)
	{
		t[x].a=0; t[x].d=P[l]; t[x].b=t[x].c=INF; return;
	}
	int mid=l+r>>1;
	Init(l,mid,x<<1); Init(mid+1,r,x<<1|1);
	t[x]=t[x<<1]+t[x<<1|1];
}

Data Ask(int l,int r,int a,int b,int x)
{
	if (l==a && r==b) return t[x];
	int mid=l+r>>1;
	if (b<=mid) return Ask(l,mid,a,b,x<<1);
	if (a>mid) return Ask(mid+1,r,a,b,x<<1|1);
	return Ask(l,mid,a,mid,x<<1)+Ask(mid+1,r,mid+1,b,x<<1|1);
}

int main()
{
	freopen("defense.in","r",stdin); freopen("defense.out","w",stdout);
	scanf("%d%d%s",&n,&m,S);
	for (int i=1;i<=n;i++) P[i]=read();
	for (int i=1,x,y;i<n;i++)
	{
		x=read(); y=read();
		Add(x,y); Add(y,x);
		if (n<=2000 && m<=2000) g[x][y]=g[y][x]=1;
	}
	if (n<=2000 && m<=2000)
	{
		for (int a,x,b,y;m--;)
		{
			a=read(); x=read(); b=read(); y=read();
			if (g[a][b] && !x && !y)
			{
				printf("-1\n"); continue;
			}
			bz[a]=x+1; bz[b]=y+1;
			
			dfs(1,0);
			printf("%lld\n",min(f[1][0],f[1][1]));
			
			bz[a]=bz[b]=0;
		}
		return 0;
	}
	Init(1,n,1);
	for (int a,x,b,y;m--;)
	{
		a=read(); x=read(); b=read(); y=read();
		if (a>b) swap(a,b),swap(x,y);
		if (a==b-1 && x==y && !x)
		{
			printf("-1\n"); continue;
		}
		if (a>1) p=Ask(1,n,1,a-1,1);else
		{
			p.a=p.b=p.c=INF; p.d=0;
		}
		if (b<n) r=Ask(1,n,b+1,n,1);else
		{
			r.a=r.b=r.c=INF; r.d=0;
		}
		if (a<b-1) q=Ask(1,n,a+1,b-1,1);else
		{
			q.a=q.b=q.c=INF; q.d=0;
		}
		if (!x)
		{
			if (!y)
			{
				ans=min(p.b,p.d)+q.d+min(r.c,r.d);
			}else
			{
				ans=min(p.b,p.d)+min(q.c,q.d)+P[b]+min(min(r.a,r.b),min(r.c,r.d));
			}
		}else
		{
			if (!y)
			{
				ans=min(min(p.a,p.b),min(p.c,p.d))+P[a]+min(q.b,q.d)+min(r.c,r.d);
			}else
			{
				ans=min(min(p.a,p.b),min(p.c,p.d))+P[a]+min(min(q.a,q.b),min(q.c,q.d))+P[b]+min(min(r.a,r.b),min(r.c,r.d));
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
