#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define fo(i,a,b) for (i=a; i<=b; i++)
#define foo(i,a,b) for (i=a; i>=b; i--)
using namespace std;

const int N=5e3+5, M=N*2;
int n, m, i, j, x, y, t, root, t0, tot;
struct line {int x, y;} a[M];
int lst[N], e[M][2];
int d[N], g[N], ans[N];
bool bz[N], bz0[N], flag;

bool cmp(line a,line b) {return a.y>b.y;}
void link(int x,int y) {e[i][0]=lst[x], e[i][1]=y, lst[x]=i;}
void dg(int x)
{
	int i=lst[x]; bz[ans[++tot]=x]=1;
	while (i)
	{
		int y=e[i][1]; i=e[i][0];
		if (!bz[y] && !bz0[y]) dg(y);
	}
}
void build(int x,int fx)
{
	int i=lst[x]; bz[ans[++tot]=x]=1;
	while (i)
	{
		int y=e[i][1]; i=e[i][0];
		if (fx!=y)
		{
			if (!bz[y]) build(y,x); else
			{
				flag=bz0[root=y]=1, t=0;
				while (ans[tot]!=y) d[++t]=ans[tot--], bz[d[t]]=0, bz0[d[t]]=1;
			}
			if (flag) return;
		}
	}
	bz[x]=0, ans[tot--]=0;
}
void dg2(int x,int k)
{
	int i=lst[x]; bz[ans[++tot]=x]=1;
	while (i)
	{
		int y=e[i][1]; i=e[i][0];
		if (!bz[y] && !bz0[y])
			if (y<k) dg2(y,n+1); else {t0=y; return;}
	}
}
void work()
{
	bool flag=0; int i, j=0;
	if (d[1]<d[t]) {fo(i,1,t>>1) swap(d[i],d[t-i+1]);}
	
	int lx=d[1];
	if (d[t]<g[root]) lx=min(lx,g[root]);
	else {int p=tot, q=ans[tot--]; dg(root), ans[p]=q, flag=1;}

	foo(i,t,1)
	{
		int x=d[i];
		if (x>lx) {j=i; break;}
		t0=n+1, dg2(x,i>1?d[i-1]:n+1), lx=t0>n?lx:t0;
	}
	fo(i,j+1,t)
	{
		int x=d[i];
		int p=tot, q=ans[tot--]; dg(x), ans[p]=q;
	}
	
	if (d[1]>g[root] && !flag) {int p=tot, q=ans[tot--]; dg(root), ans[p]=q, flag=1;}
	fo(i,1,j) {int x=d[i]; dg2(x,d[i+1]);}
	foo(i,j,1)
	{
		int x=d[i];
		int p=tot, q=ans[tot--]; dg(x), ans[p]=q;
	}
	if (!flag) {int p=tot, q=ans[tot--]; dg(root), ans[p]=q;}
}

int main()
{
	freopen("travel.in","r",stdin), freopen("travel.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	if (m==n-1)
	{
		fo(i,1,m) scanf("%d%d",&x,&y), a[i+m].x=a[i].y=x, a[i+m].y=a[i].x=y;
		m<<=1, sort(a+1,a+m+1,cmp); fo(i,1,m) link(a[i].x,a[i].y);
		dg(1);
		fo(i,1,n) printf("%d ",ans[i]);
		return 0;
	}
	
	fo(i,1,m) scanf("%d%d",&x,&y), a[i+m].x=a[i].y=x, a[i+m].y=a[i].x=y;
	m<<=1, sort(a+1,a+m+1,cmp); fo(i,1,m) link(a[i].x,a[i].y);
	build(1,0);
	x=root, i=lst[x], g[x]=n+1;
	while (i)
	{
		y=e[i][1], i=e[i][0];
		if (!bz[y] && !bz0[y]) {g[x]=y; break;}
	}
	work();
	int p=tot, q=ans[tot--]; dg(1), ans[p]=q;
	fo(i,1,n) printf("%d ",ans[i]);
}
