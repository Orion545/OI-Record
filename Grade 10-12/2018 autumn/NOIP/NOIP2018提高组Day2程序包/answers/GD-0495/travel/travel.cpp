#define ICEY
#include <algorithm>
#include <cstdio>

const int kN = 5005;
int n, m, a[kN][kN], cnt[kN], col[kN];
bool vis[kN];

inline int Abs(const int &x) { return x < 0 ? -x : x; }
inline void Swap(int &x, int &y) { if (x != y) x ^= y, y ^= x, x ^= y; }

int px = 0, py = 0;
int Col(const int &x, const int &fa) {
  vis[x] = 1;
  for (int i = 1; i <= cnt[x]; i++) {
    if (!vis[a[x][i]]) {
      int val = Col(a[x][i], x);
      if (val != 0) {
        if (Abs(x - a[x][i]) > Abs(px - py)) px = x, py = a[x][i];
        return (val == x ? 0 : val);
      }
    }
    if (vis[ a[x][i] ] && a[x][i] != fa && fa != 0) {
      px = x, py = a[x][i];
      return a[x][i];
    }
  }
  return 0;
}

void Dfs(const int &x) {
  printf("%d ", x);
  vis[x] = 1;
  for (int i = 1; i <= cnt[x]; i++)
    if (!vis[a[x][i]]) Dfs(a[x][i]);
}

int main () {
#ifdef ICEY
  freopen("travel.in", "r", stdin);
  freopen("travel.out", "w", stdout);
#endif
  
  scanf("%d %d", &n, &m);
  for (int i = 1, x, y; i <= m; i++) {
    scanf("%d %d", &x, &y);
    a[x][++cnt[x]] = y;
    a[y][++cnt[y]] = x;
  }
  
  if (n == m) {
    Col(1, 0);

    for (int i = 1; i <= cnt[px]; i++) {
      if (py == a[px][i]) Swap(a[px][i], a[px][cnt[px]]);
      cnt[px]--;
      break;
    }
    
    for (int i = 1; i <= cnt[py]; i++) {
      if (px == a[py][i]) Swap(a[py][i], a[py][cnt[py]]);
      cnt[py]--;
      break;
    }
  }
  
  for (int i = 1; i <= n; i++) vis[i] = 0;
  
  for (int i = 1; i <= n; i++) std::sort(a[i] + 1, a[i] + 1 + cnt[i]);
  Dfs(1);
  
  fclose(stdin), fclose(stdout);
  return 0;
}
