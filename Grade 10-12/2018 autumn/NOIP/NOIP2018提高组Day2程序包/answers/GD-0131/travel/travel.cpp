#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
using namespace std;
const int maxn = 5000 + 10;
const int INF = 0x3f3f3f3f;

int n, m, sfa[maxn], ku, kv;
vector<int> g[maxn];

inline void addedge(int u, int v) { g[u].push_back(v); }

int findfa(int u) { return (sfa[u] == u) ? (u) : (sfa[u] = findfa(sfa[u])); }

namespace work1{

int pre[20][maxn], dep[maxn], bl[maxn], vis[maxn];
void dfs1(int u, int fa) {
  sort(g[u].begin(),g[u].end());
  pre[0][u] = fa; dep[u] = dep[fa] + 1;
  for(int i = 1;i <= 13;i ++) pre[i][u] = pre[i - 1][pre[i - 1][u]];
  int Sz = g[u].size();
  for(int i = 0;i < Sz;i ++) {
    int v = g[u][i];
    if(v == fa || vis[v]) continue;
    if(kv == v && ku == u) continue;
    if(kv == u && ku == v) continue;
    vis[v] = 1;
    dfs1(v,u);
  }
}

inline int LCA(int u, int v) {
  if(dep[u] < dep[v]) swap(u,v);
  int d = dep[u] - dep[v];
  for(int i = 0;i <= 13;i ++) if(d & (1 << i)) u = pre[i][u];
  if(u == v) return u;
  for(int i = 13;i >= 0;i --) if(pre[i][u] != pre[i][v]) {
    u = pre[i][u];
    v = pre[i][v];
  }
  return pre[0][u];
}

int tot, Ans[maxn], flag;
void dfs(int u, int fa, int lst, int bo) {
  if(vis[u] == 1) Ans[++ tot] = u;
  int tmp = INF, Sz = g[u].size();
  int Fr, Se;
  Fr = Se = INF;
  for(int i = 0;i < Sz;i ++) {
    int v = g[u][i];
    if(v == fa) continue;
    tmp = min(tmp,v);
    if(v <= Fr) Se = Fr, Fr = v;
    else if(v <= Se) Se = v;
  }
  if(bo && !flag) {
    if(lst < tmp) {
      flag = 1;
      vis[u] = 2;
      return;
	}
  }
  for(int i = 0;i < Sz;i ++) {
    int v = g[u][i];
    if(v == fa) continue;
    if(vis[v] == 1) continue;
    int tmp, now;
    if(bl[u] && bl[v]) tmp = 1;
    else tmp = 0;
    if(v == Fr) now = Se;
    else now = Fr;
    if(!vis[v]) vis[v] = 1;
    dfs(v,u,now,tmp);
  }
}

inline void solve() {
  vis[1] = 1;
  dfs1(1,0);
  int lca = LCA(ku,kv);
  memset(bl,0,sizeof(bl));
  while(ku != lca) {
    bl[ku] = 1;
    ku = pre[0][ku];
  }
  while(kv != lca) {
    bl[kv] = 1;
    kv = pre[0][kv];
  }
  bl[lca] = 1;
  tot = flag = 0;
  memset(vis,0,sizeof(vis));
  vis[1] = 1;
  dfs(1,0,INF,0);
  for(int i = 1;i < tot;i ++) printf("%d ", Ans[i]);
  printf("%d\n", Ans[tot]);
}

}

namespace work2{

int tot, Ans[maxn];

void dfs(int u, int fa) {
  Ans[++ tot] = u;
  sort(g[u].begin(),g[u].end());
  int Sz = g[u].size();
  for(int i = 0;i < Sz;i ++) {
    int v = g[u][i];
    if(v == fa) continue;
    dfs(v,u);
  }
}

inline void solve() {
  tot = 0;
  dfs(1,0);
  for(int i = 1;i < tot;i ++) printf("%d ", Ans[i]);
  printf("%d\n", Ans[tot]);
}

}

int main() {
  freopen("travel.in","r",stdin);
  freopen("travel.out","w",stdout);
  scanf("%d%d", &n, &m); ku = kv = -1;
  for(int i = 1;i <= n;i ++) {
  	sfa[i] = i;
  	g[i].clear();
  }
  for(int i = 1;i <= m;i ++) {
    int u, v;
    scanf("%d%d", &u, &v);
    int f1 = findfa(u);
    int f2 = findfa(v);
    if(f1 == f2) {
      ku = u, kv = v;
      addedge(u,v);
      addedge(v,u);
	}
    else {
      sfa[f1] = f2;
      addedge(u,v);
      addedge(v,u);
	}
  }
  if(n == m) work1::solve();
  else work2::solve();
  return 0;
}
