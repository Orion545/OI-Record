#define ICEY
#include <cstdio>

int t, n, a[105], ans;

bool Dfs(int pos, int x, int y) {
  if (pos == n) return y == a[x];
  if (pos == x) return Dfs(pos + 1, x, y);
  
  for (int i = 0; y + i * a[pos] <= a[x]; i++) {
    if (Dfs(pos + 1, x, y + i * a[pos])) return true;
  }
  return false;
}

int main () {
#ifdef ICEY
  freopen("money.in", "r", stdin);
  freopen("money.out", "w", stdout);  
#endif

  for (scanf("%d", &t); t--; ans = 0) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)  scanf("%d", a + i);
    
    for (int i = 1; i <= n; i++)
      if (Dfs(1, i, 0)) ans++;
    printf("%d\n", n - ans);
  }
  
	fclose(stdin), fclose(stdout);
	return 0;
}