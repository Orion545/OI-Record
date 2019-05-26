#include <bits/stdc++.h>
#define N 10010
using namespace std;

int n, m, sz, ans[N], now[N], S, T, a[N], b[N];
vector<int> G[N];
bool vis[N];

void dfs(int u) {
	now[++sz] = u;
	vis[u] = 1;
	for (int i=0;i<G[u].size();i++)
		if (!vis[G[u][i]] && (u != S || G[u][i] != T) && (u != T || G[u][i] != S)) dfs(G[u][i]);
}

int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=0;i<m;i++) {
		scanf("%d%d",a+i,b+i);
		G[a[i]].push_back(b[i]);
		G[b[i]].push_back(a[i]);
	}
	for (int i=1;i<=n;i++) if (G[i].size()) sort(G[i].begin(),G[i].end());
	
	ans[1] = 2;
	
	if (m == n-1) {
		dfs(1);
		for (int i=1;i<=n;i++) ans[i] = now[i];
	} else {
		for (int i=0;i<m;i++) {
			S = a[i], T = b[i];
			sz = 0;
			for (int j=1;j<=n;j++) vis[j] = 0;
			dfs(1);
			bool cmp = 0;
			if (sz == n) for (int j=1;j<=n;j++) if (ans[j] < now[j]) break;
			else if (ans[j] > now[j]) {cmp = 1;  break;}
			
			if (cmp) for (int j=1;j<=n;j++) ans[j] = now[j];
		}
	}
	for (int i=1;i<=n;i++) printf("%d ",ans[i]);
}
