#define ICEY
#include <cstdio>

const int kN = 50005, kM = 100005;
int ver[kM], edge[kM], nxt[kM], head[kN], deg[kN], tot = 1;
int n, m, p, q, fa[kN];
long long d[kN], pa, pb, qa, qb, ans;
bool vis[kN];


inline void Insert(const int &x, const int &y, const int &z) {
  ver[++tot] = y, edge[tot] = z, nxt[tot] = head[x], head[x] = tot;
  deg[x]++;
}

void Dfs(const int &x, int &max_pos) {
  vis[x] = 1;
  if (d[x] > d[max_pos]) max_pos = x;
  for (int i = head[x], y; i != 0; i = nxt[i])
    if (!vis[y = ver[i]]) {
      fa[y] = x;
      d[y] = d[x] + edge[i];
      Dfs(y, max_pos);
  }
}

long long ZhiJing() {
  Dfs(1, p);
  
  for (int i = 1; i <= n; i++) vis[i]= 0;
  d[p] = fa[p] = 0;
  
  Dfs(p, q);
  
  for (int i = 1; i <= n; i++) vis[i]= 0;
  for (int x = q; x != p; x = fa[x]) 
    vis[x] = 1;
  vis[p] = 1; 
  
  return d[q];
}


void FindMin(const int &p) {
  for (int i = head[p]; i != 0; i = nxt[i])
    if (!vis[ver[i]]) {
      if (edge[i] < pa) pb = pa, pa = edge[i];
      else if (edge[i] < pb) pb = edge[i];
    }
    
  pa += pb;
  if (ans > pa) ans = pa;
}

int main () {
#ifdef ICEY
  freopen("track.in", "r", stdin);
  freopen("track.out", "w", stdout);  
#endif

  scanf("%d %d", &n, &m);
  for (int i = 1, x, y, z; i < n; i++) {
    scanf("%d %d %d", &x, &y, &z);
    Insert(x, y, z), Insert(y, x, z);
  }
  long long zhi_jing = ZhiJing();
  

  ans = zhi_jing - edge[head[p]] - edge[head[q]];
  vis[p] = vis[q] = 0;
  
  printf("%d %d\n", deg[p], deg[q]);
  
  p = ver[head[p]], q = ver[head[q]];
  
  printf("%d %d\n", deg[p], deg[q]);
  
  if (deg[p] <= 3 && deg[q] <= 3) {
    printf("%lld", zhi_jing);
	  fclose(stdin), fclose(stdout);
    return 0;
  }
  
  
  
  int pp = 0, qq = 0;
  pa = pb = qa = qb = 1LL << 60;
  
  for (int i = head[p]; i != 0; i = nxt[i])
    if (!vis[ver[i]] && edge[i] < pa) pa = edge[i], pp = i;
  
  for (int i = head[q]; i != 0; i = nxt[i])
    if (!vis[ver[i]] && edge[i] < qa) qa = edge[i], qq = i;
  
  vis[ver[pp]] = vis[ver[qq]] = 1;
  
  ans = zhi_jing + pa + qa;
  pa = qa = 1LL << 60;
  
  
  for (int i = head[p]; i != 0; i = nxt[i])
    if (!vis[ver[i]]) {
      if (edge[i] < pa) pb = pa, pa = edge[i];
      else if (edge[i] < pb) pb = edge[i];
    }
  
  for (int i = head[q]; i != 0; i = nxt[i])
    if (!vis[ver[i]]) {
      if (edge[i] < qa) qb = qa, qa = edge[i];
      else if (edge[i] < qb) qb = edge[i];
    }
    
  pa += pb, qa += qb;
  if (ans > pa) ans = pa;
  if (ans > qa) ans = qa;
  
  printf("%lld", ans);
    
  
	fclose(stdin), fclose(stdout);
	return 0;
}