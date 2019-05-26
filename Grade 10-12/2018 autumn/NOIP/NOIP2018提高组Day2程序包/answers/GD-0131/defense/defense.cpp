#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int maxn = 100000 + 10;
const int INF = 0x3f3f3f3f;

int n, m, val[maxn], h[maxn], cnt;
struct enode{
  int v, n;
  enode() {}
  enode(int _v, int _n):v(_v), n(_n) {}
}e[maxn << 1];
char type[10];

inline void addedge(int u, int v) { cnt ++; e[cnt] = enode(v,h[u]); h[u] = cnt; }

namespace work1{

int op[3][2], dp[maxn][2];

void dfs(int u, int fa) {
	dp[u][0] = 0;
	dp[u][1] = val[u];
  for(int i = h[u];~ i;i = e[i].n) {
    int v = e[i].v;
    if(v == fa) continue;
    dfs(v,u);
    dp[u][0] += dp[v][1];
    dp[u][1] += min(dp[v][0],dp[v][1]);
	}
	for(int i = 1;i <= 2;i ++) {
	  int v = op[i][0], kd = op[i][1];
	  if(v == u) dp[u][!kd] = INF;
	}
}

inline void work() {
  dfs(1,0);
  int Ans = min(dp[1][0],dp[1][1]);
  if(Ans >= INF / 2) puts("-1");
  else printf("%d\n", Ans);
}

inline void solve() {
  for(int i = 1;i <= m;i ++) {
    scanf("%d%d%d%d", &op[1][0], &op[1][1], &op[2][0], &op[2][1]);
    work();
	}
}

}

int main() {
  freopen("defense.in","r",stdin);
  freopen("defense.out","w",stdout);
  scanf("%d%d%s", &n, &m, &type);
  memset(h,-1,sizeof(h)); cnt = 0;
  for(int i = 1;i <= n;i ++) scanf("%d", &val[i]);
  for(int i = 1;i < n;i ++) {
    int u, v;
    scanf("%d%d", &u, &v);
    addedge(u,v);
    addedge(v,u);
  }
   work1::solve();
  return 0;
}
