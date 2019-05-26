#include <stdio.h>
#include <string.h>
#include <algorithm>
#define rep(i,st,ed) for (int i=st;i<=ed;++i)

typedef long long LL;
const LL INF=1e11;
const int N=20005;

struct edge {int x,y,next;} e[N*2];

int ls[N],v[N],edCnt;
int lim[N];

LL f[N],g[N];

void add_edge(int x,int y) {
	e[++edCnt]=(edge) {x,y,ls[x]}; ls[x]=edCnt;
	e[++edCnt]=(edge) {y,x,ls[y]}; ls[y]=edCnt;
}

void dfs(int now,int fa) {
	f[now]=g[now]=0;
	bool flag=false;
	for (int i=ls[now];i;i=e[i].next) {
		if (e[i].y==fa) continue;
		flag=true;
		dfs(e[i].y,now);
	}
	if (!flag) {
		f[now]=v[now];
		g[now]=0;
		if (lim[now]==0) f[now]=INF;
		if (lim[now]==1) g[now]=INF;
		return ;
	}
	f[now]=v[now];
	for (int i=ls[now];i;i=e[i].next) {
		if (e[i].y==fa) continue;
		g[now]+=f[e[i].y];
		f[now]+=std:: min(g[e[i].y],f[e[i].y]);
		f[now]=std:: min(f[now],INF);
		g[now]=std:: min(g[now],INF);
	}
	if (lim[now]==0) f[now]=INF;
	if (lim[now]==1) g[now]=INF;
}

int main(void) {
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	int n,m; LL sum=0; scanf("%d%d %*c%*d",&n,&m);
	rep(i,1,n) {
		scanf("%d",&v[i]);
		sum+=v[i];
	}
	rep(i,2,n) {
		int x,y; scanf("%d%d",&x,&y);
		add_edge(x,y);
	}
	rep(i,1,n) lim[i]=-1;
	for (;m--;) {
		int x; scanf("%d",&x);
		scanf("%d",&lim[x]);
		int y; scanf("%d",&y);
		scanf("%d",&lim[y]);
		dfs(x,0); LL ans;
		if (lim[x]==1) ans=f[x];
		else if (lim[x]==0) ans=g[x];
		if (ans>sum) ans=-1;
		printf("%lld\n", ans);
		lim[x]=lim[y]=-1;
	}
	return 0;
}
