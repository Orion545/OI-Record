#include <bits/stdc++.h>
#define inf (ll)1e12
#define end end2

using namespace std;

typedef long long ll;

struct Matrix {
  ll num[2][2];
  int n,m;
  Matrix() {}
  Matrix(int a,int b):n(a),m(b) {
  	for(int i=0;i<n;i++)
  	  for(int j=0;j<m;j++) num[i][j]=inf;
  }
};

Matrix operator * (Matrix a,Matrix b) {
  Matrix c(a.n,b.m);
  for(int i=0;i<c.n;i++)
    for(int j=0;j<c.m;j++)
      for(int k=0;k<a.m;k++) c.num[i][j]=min(c.num[i][j],a.num[i][k]+b.num[k][j]);
  return c;
}

struct Edge {
  int t,next;
  Edge() {}
  Edge(int a,int b):t(a),next(b) {}
};

Edge e[200005];
int head[100005],num[100005];

ll f[100005],g[100005];
ll s1[100005],s2[100005];

void dfs1(int x,int fa) {
  for(int i=head[x];i;i=e[i].next)
    if (e[i].t!=fa) {
    	int u=e[i].t;
    	dfs1(u,x);
    	s1[x]+=min(f[u],g[u]);
    	s2[x]+=g[u];
    }
  f[x]=s2[x];
  g[x]=s1[x]+num[x];
}

int dep[100005],fa[100005][20];
Matrix up[100005][20];
int dfn[100005],end[100005],tot;

void dfs2(int x) {
  dfn[x]=++tot;
  for(int i=head[x];i;i=e[i].next)
    if (e[i].t!=fa[x][0]) {
    	int u=e[i].t;
    	dep[u]=dep[x]+1;
		fa[u][0]=x;
		up[u][0].num[0][1]=s2[x]-g[u];
		up[u][0].num[1][0]=up[u][0].num[1][1]=s1[x]-min(f[u],g[u])+num[x];
		for(int j=1;j<20;j++) {
			fa[u][j]=fa[fa[u][j-1]][j-1];
			up[u][j]=up[fa[u][j-1]][j-1]*up[u][j-1];
		}
		dfs2(u);
    }
  end[x]=tot;
}

int lca(int x,int y) {
  if (dep[x]<dep[y]) swap(x,y);
  int d=dep[x]-dep[y];
  for(int i=0;i<20;i++)
    if (d&(1<<i)) x=fa[x][i];
  if (x==y) return x;
  for(int i=19;i>=0;i--)
    if (fa[x][i]!=fa[y][i]) {
    	x=fa[x][i];
    	y=fa[y][i];
    }
  return fa[x][0];
}

int jump(int x,int d) {
  for(int i=0;i<20;i++)
    if (d&(1<<i)) x=fa[x][i];
  return x;
}

void query(int x,int d,Matrix &a) {
  for(int i=0;i<20;i++)
    if (d&(1<<i)) {
    	a=up[x][i]*a;
    	x=fa[x][i];
    }
}

ll solve(int x,int y,bool t1,bool t2) {
  if (dfn[x]>dfn[y]) {
  	swap(x,y);
  	swap(t1,t2);
  }
  if (!t1&&!t2&&fa[y][0]==x) return -1;
  if (dfn[x]<=dfn[y]&&end[x]>=end[y]) {
  	Matrix fir(2,1);
  	if (!t2) fir.num[0][0]=f[y];
  	else fir.num[1][0]=g[y];
  	query(y,dep[y]-dep[x],fir);
  	if (!t1) fir.num[1][0]=inf;
  	else fir.num[0][0]=inf;
  	query(x,dep[x],fir);
  	return min(fir.num[0][0],fir.num[1][0]);
  }
  else {
  	int p=lca(x,y);
  	Matrix a(2,1),b(2,1);
  	if (!t1) a.num[0][0]=f[x];
  	else a.num[1][0]=g[x];
  	if (!t2) b.num[0][0]=f[y];
  	else b.num[1][0]=g[y];
  	query(x,dep[x]-dep[p]-1,a);
  	query(y,dep[y]-dep[p]-1,b);
  	x=jump(x,dep[x]-dep[p]-1);
  	y=jump(y,dep[y]-dep[p]-1);
  	Matrix c(2,1);
  	c.num[0][0]=min(c.num[0][0],s2[p]-g[x]-g[y]+a.num[1][0]+b.num[1][0]);
  	c.num[1][0]=min(c.num[1][0],s1[p]-min(f[x],g[x])-min(f[y],g[y])+min(a.num[0][0],a.num[1][0])+min(b.num[0][0],b.num[1][0])+num[p]);
  	query(p,dep[p],c);
  	return min(c.num[0][0],c.num[1][0]);
  }
}

int main() {
  freopen("defense.in","r",stdin);
  freopen("defense.out","w",stdout);
  int n,m;
  char str[5];
  scanf("%d%d%s",&n,&m,str);
  for(int i=0;i<=n;i++)
    for(int j=0;j<20;j++) up[i][j]=Matrix(2,2);
  for(int i=1;i<=n;i++) scanf("%d",&num[i]);
  for(int i=1;i<n;i++) {
  	int x,y;
  	scanf("%d%d",&x,&y);
  	e[2*i-1]=Edge(y,head[x]);
  	head[x]=2*i-1;
  	e[2*i]=Edge(x,head[y]);
  	head[y]=2*i;
  }
  dfs1(1,0);
  dfs2(1);
  for(int i=1;i<=m;i++) {
  	int a,b,c,d;
  	scanf("%d%d%d%d",&a,&b,&c,&d);
  	printf("%lld\n",solve(a,c,b,d));
  }
  return 0;
}
