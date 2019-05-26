#define ICEY
#include <cstdio>

int n, a[100005], stk[100005], top;
long long ans;

int main () {
#ifdef ICEY
  freopen("road.in", "r", stdin);
  freopen("road.out", "w", stdout);  
#endif

  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    if (a[i] < stk[top]) ans += stk[top] - a[i];
    while (a[i] < stk[top]) top--;
    stk[++top] = a[i];
  }
  ans += stk[top];
  printf("%lld", ans);

	fclose(stdin), fclose(stdout);
	return 0;
}