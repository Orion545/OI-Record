#include <bits/stdc++.h>
#define N 100100
#define inf 1000000000000ll
using namespace std;
typedef long long ll;

int n, m, p[N], fa[N], a, b, x, y;
ll dp[N][2];
char s[10];

vector<int> G[N];

inline void upd(int u) {
	int lim = -1;
	if (u == a) lim = x;  else if (u == b) lim = y;
	
	dp[u][0] = 0;
	dp[u][1] = p[u];
	if (lim == 0) dp[u][1] = inf;
	if (lim == 1) dp[u][0] = inf;
	for (int i=0;i<G[u].size();i++) if (G[u][i] != fa[u]) {
		if (lim != 0) dp[u][1] += min(dp[G[u][i]][0],dp[G[u][i]][1]);
		if (lim != 1) dp[u][0] += dp[G[u][i]][1];
	}
}

void dfs(int u,int from) {
	fa[u] = from;
	for (int i=0;i<G[u].size();i++) if (G[u][i] != from) dfs(G[u][i],u);
	upd(u);
}

int main() {
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d%s",&n,&m,s);
	for (int i=1;i<=n;i++) scanf("%d",p+i);
	for (int i=0,u,v;i<n-1;i++) {
		scanf("%d%d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1,0);
	for (;m--;) {
		scanf("%d%d%d%d",&a,&x,&b,&y);
		if ((fa[a] == b || fa[b] == a) && x+y == 0) {puts("-1");  continue;}
		
		for (int p=a;p;p=fa[p]) upd(p);
		for (int p=b;p;p=fa[p]) upd(p);
		
		ll ans = min(dp[1][0],dp[1][1]);
		
		x = -1, y = -1;
		for (int p=a;p;p=fa[p]) upd(p);
		for (int p=b;p;p=fa[p]) upd(p);
		printf("%lld\n",ans >= inf ? -1 : ans);
	}
}
