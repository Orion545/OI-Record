#include <cstdio>
#include <queue>
using namespace std;
#define N 10050
struct edge {
	int v,nxt;
}e[2*N];
bool p,pp;
int n,m,t,mx,tot;
int d[N],dd[N],h[N],L[N],inq[N],vis[N];
queue<int> q;
int ins(int a,int b) {
	tot++;
	e[tot].v=b;
	e[tot].nxt=h[a];
	d[a]++; dd[a]++;
	h[a]=tot;
}
int dfs(int u,int fa) {
	int v,i,j,k,mn;
	L[++t]=u; vis[u]=1; dd[u]--; 
	if (!inq[u] && !p) p=1,mx=1<<30;
//	printf("%d %d:\n",u,mx);
	for (k=1;k<=n;k++) {
		mn=1<<30;
		for (i=h[u];i;i=e[i].nxt) 
			if (!vis[e[i].v] && e[i].v!=fa) mn=min(mn,e[i].v);
//		if (u==11) puts("PB");
		if (mn==1<<30) return 0;
//		if (u==11) puts("PB");
		if (p && !pp && mx<mn && dd[u]==1 && !inq[u]) {
			pp=1;
			return 0;
		}
//		if (u==11) puts("PB");
		dd[u]--;
		if (k==1 && p && dd[u]) {
			mx=1<<30;
			for (j=h[u];j;j=e[j].nxt) 
				if (e[j].v!=fa && e[j].v!=mn) 
					mx=min(mx,e[j].v);
//			printf("%d %d\n",mn,mx);
		}
		dfs(mn,u); 
	}
}
int main() {
	int i,a,b,u,v;
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
//	printf("%d %d\n",n,m);
	for (i=1;i<=m;i++) {
		scanf("%d%d",&a,&b);
		ins(a,b); ins(b,a);
	}
	for (i=1;i<=n;i++) if (d[i]==1) {
		inq[i]=1; q.push(i);
	}
	while (!q.empty()) {
		u=q.front(); q.pop(); inq[u]=1;
		for (i=h[u];i;i=e[i].nxt) {
			v=e[i].v;
			d[v]--;
			if (d[v]==1) q.push(v);
		}
	}
//	for (i=1;i<=n;i++) if (!inq[i]) printf("%d\n",i);
	dd[1]++; dfs(1,0);
	for (i=1;i<=t;i++) printf("%d ",L[i]);
//	printf("%d\n",inq[3]);
}
