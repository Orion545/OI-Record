#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
const int N=1e5+10;
const ll Inf=1ll<<52;
struct Edge {
	int u,v,nx;
}g[N];
int cnt,list[N];
ll w[N],f[N][2];
int h[N];
int n,m;
char c[20];

void Add(int u,int v) {
	g[++cnt]=(Edge){u,v,list[u]};list[u]=cnt;
}

void DFS(int u,int fa) {
	bool canempty=1,canup=1;
	f[u][0]=f[u][1]=0;
	for (int i=list[u];i;i=g[i].nx)
		if (g[i].v!=fa) {
			DFS(g[i].v,u);
			if (f[g[i].v][1]==Inf) canempty=0;
			if (min(f[g[i].v][0],f[g[i].v][1])==Inf) canup=0;
			f[u][0]+=f[g[i].v][1];
			f[u][1]+=min(f[g[i].v][0],f[g[i].v][1]);
		}
	if ((!h[u]||h[u]==1)&&canup) f[u][1]+=w[u];
		else f[u][1]=Inf;
	if (h[u]==1||!canempty) f[u][0]=Inf;
}

int main() {
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d%s",&n,&m,c);
	for (int i=1;i<=n;i++) scanf("%d",&w[i]);
	for (int i=1,u,v;i<n;i++) scanf("%d%d",&u,&v),Add(u,v),Add(v,u);
	for (int i=1;i<=m;i++) {
		int a,x,b,y;
		scanf("%d%d%d%d",&a,&x,&b,&y);
		h[a]=x?1:2;h[b]=y?1:2;
		DFS(1,0);
		h[a]=h[b]=0;
		printf("%d\n",min(f[1][1],f[1][0])==Inf?-1:min(f[1][1],f[1][0]));
	}
	fclose(stdin);fclose(stdout);
}
