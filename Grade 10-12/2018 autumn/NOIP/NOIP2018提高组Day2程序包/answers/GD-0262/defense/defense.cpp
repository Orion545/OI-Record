#include <iostream>
#include <cstdio>
#include <cmath>
#define LL long long

const LL inf=1e13;
const int maxn=1e5+7;

using namespace std;

int n,m,x,y,opx,opy,cnt;
int a[maxn],ls[maxn];
LL f[maxn][2];
char s[20];

struct edge{
	int y,next;
}g[maxn*2];

void add(int x,int y)
{
	g[++cnt]=(edge){y,ls[x]};
	ls[x]=cnt;
}

void dfs(int x,int fa)
{
	for (int i=ls[x];i>0;i=g[i].next)
	{
		int y=g[i].y;
		if (y==fa) continue;
		dfs(y,x);
		f[x][0]+=f[y][1];
		f[x][1]+=min(f[y][0],f[y][1]);
	}
	f[x][1]+=(LL)a[x];
}

int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d%s",&n,&m,s);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d%d%d",&x,&opx,&y,&opy);		
		for (int j=1;j<=n;j++) f[j][0]=f[j][1]=0;
		if (opx==1) f[x][0]=inf;
		       else f[x][1]=inf;
		if (opy==1) f[y][0]=inf;
		       else f[y][1]=inf;
		dfs(1,0);
		LL ans=min(f[1][0],f[1][1]);
		if (ans>=inf) printf("-1\n");
		         else printf("%lld\n",ans);
	}
}
