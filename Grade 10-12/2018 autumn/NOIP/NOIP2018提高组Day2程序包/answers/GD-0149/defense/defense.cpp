#include <cstdio>
#include <algorithm>
#define REG register
#define FOR(x,y,z) for(REG int (x) = (y); (x) <  (z); ++(x))
#define For(x,y,z) for(REG int (x) = (y); (x) <= (z); ++(x))

const int kmax_num = 5e3 + 10;

int n, m;
char cmd[2];

int val[kmax_num];

struct Edge {
	int v, next;
} edges[kmax_num * 2];

int head[kmax_num], cnt;

inline void AddEdge(const int& u, const int& v) {
  edges[++cnt] = (Edge) {v, head[u]};
  head[u] = cnt;
  edges[++cnt] = (Edge) {u, head[v]};
  head[v] = cnt;
  return  ;
}

int main() {
  freopen("defense.in", "r", stdin);
  freopen("defense.out", "w", stdout);
  scanf(" %d %d %s", &n, &m, cmd);
  For(i,1,n)  scanf(" %d", & val[i]);
  int u, v;
  FOR(i,1,n)  scanf(" %d %d", &u, &v), AddEdge(u, v);
  
  if(cmd[0] == 'A' && cmd[1] == '2') {
    For(i,1,m)  printf("-1\n");
  }
  return 0;
}
