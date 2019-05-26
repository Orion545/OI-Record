#include <cstdio>
#include <cstring>
#include <cctype>
#include <set>
#include <algorithm>
#define REG register
#define FOR(x,y,z) for(REG int (x) = (y); (x) <  (z); ++x)
#define For(x,y,z) for(REG int (x) = (y); (x) <= (z); ++x)

const int kmax_num = 5e4 + 10;

int n, m;

struct Edge {
  int u, v, w, next;
} edges[kmax_num * 2];

int head[kmax_num],
    cnt;

inline void AddEdge(const int& u, const int& v, const int& w) {
  edges[++cnt] = (Edge) {u, v, w, head[u]};
  head[u] = cnt;
  edges[++cnt] = (Edge) {v, u, w, head[v]};
  head[v] = cnt;
  return ; 
}

int weight[kmax_num];
long long dis[kmax_num];

void DFS(const int& u, const int& v) {
  for(REG int i = head[v]; i; i = edges[i].next)  {
    if(edges[i].v == u) continue;
    dis[edges[i].v] = dis[v] + edges[i].w;
    DFS(v, edges[i].v);
  }
  return ;
}

inline void SubTask1() {
  memset(dis, 0, sizeof(dis));
  int beg, maxn = 0;
  DFS(-1, 1);
  For(i,1,n)  if(dis[i] > maxn) maxn = dis[i], beg = i;
  
  memset(dis, 0, sizeof(dis));
  maxn = 0;
  DFS(-1, beg);
  For(i,1,n)  if(dis[i] > maxn) maxn = dis[i];
  
  printf("%d\n", maxn);
  return ;
}

inline bool SubTask2Judge() {
  For(i,1,cnt)  if(edges[i].u != 1 && edges[i].v != 1)  return false;
  return true;
}

std::set<int> set, t;

inline bool SubTask2Check(const int& x) {
  int tim = 0;
  t = set;
  while(tim != m) {
    REG int l1 = *t.rbegin();
    t.erase(--t.end());
    if(l1 >= x) {
      ++tim;
    }
    else  {
      if(t.size() == 0 || *t.rbegin() + l1 < x) break;
      else  {
        t.erase(t.lower_bound(x - l1));
        ++tim;
      }
    }
  }
  return tim == m;
}

inline void SubTask2() {
  FOR(i,1,n)  set.insert(weight[i]);
  
  int l = 0, r = 1e9, ans = 0;

  while(l <= r) {
    int mid = (l + r) / 2;
    if(SubTask2Check(mid))  l = (ans = mid) + 1;
    else  r = mid - 1;
  }
  printf("%d\n", ans);
  return ;
}

inline bool SubTask3Judge() {
  For(i,1,cnt)  if(std::abs(edges[i].u - edges[i].v) != 1)  return false;
  return true;
}

int s3[kmax_num];

inline bool SubTask3Check(const long long& x) {
  long long cur = 0;
  int tim = 0;
  FOR(i,1,n)  {
    cur += s3[i];
    if(cur >= x) cur = 0, ++tim;
  }
  return tim >= m;
}

inline void SubTask3() {
  long long l = 0, r = 1e18, ans = 0;
  while(l <= r) {
    long long mid = (l + r) / 2;
    if(SubTask3Check(mid))  l = (ans = mid) + 1;
    else  r = mid - 1;
  }
  printf("%lld\n", ans);
  return ;
}

int tp;
long long v;
void Get(const int& u, const int& v, long long& val, const long long& x) {
  if(val >= x)  ++tp, val = 0;
  for(REG int i = head[v]; i; i = edges[i].next)  {
    if(edges[i].v == u) continue;
    val += edges[i].v;
    Get(v, edges[i].v, val, x);
    val -= edges[i].v;
  }
  return ;
}

inline bool SubTask4Check(const long long& x) {
  For(i,1,n)  {
    tp = v = 0;
    Get(-1, i, v, x);
    if(tp >= m) return true;
  }
  return false;
}

inline void SubTask4() {
  long long l = 0, r = 1e18, ans = 0;
  while(l <= r) {
    long long mid = (l + r) / 2;
    if(SubTask4Check(mid))  l = (ans = mid) + 1;
    else  r = mid - 1;
  }
  printf("%lld\n", ans);
  return ;
}

int main() {
  freopen("track.in", "r", stdin);
  freopen("track.out", "w", stdout);
  scanf(" %d %d", &n, &m);
  int u, v, w;
  FOR(i,1,n)  scanf(" %d %d %d", &u, &v, &w), AddEdge(u, v, w), weight[i] = w, s3[std::min(u, v)] = w;
  
  if(m == 1)  SubTask1();
  else  if(SubTask2Judge()) SubTask2();
  else  if(SubTask3Judge()) SubTask3();
  else  SubTask4();
  return 0;
}   
