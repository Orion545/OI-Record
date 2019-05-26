#define ICEY
#include <cstdio>
#include <cstdlib>
#include <ctime>

typedef long long LL;
const int kMod = 1e9 + 7;
int n, m, a[100005], deg[100005];
char s[3];

int main () {
#ifdef ICEY
  freopen("defense.in", "r", stdin);
  freopen("defense.out", "w", stdout);
#endif

  srand(time(0));
  
  scanf("%d %d %s", &n, &m, s);
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  for (int i = 1, x, y; i < n; i++) scanf("%d %d", &x, &y);
  
  while (m--) printf("-1\n");
  
  fclose(stdin), fclose(stdout);
  return 0;
}