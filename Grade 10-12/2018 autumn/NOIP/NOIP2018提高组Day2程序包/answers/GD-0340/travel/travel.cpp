#include <cstdio>
#include <vector>
#include <algorithm>
#include <string.h>
#define R register
#define In inline
#define re(i, x, y) for (R int i = x; i <= y; ++ i)
#define de(i, x, y) for (R int i = x; i >= y; -- i)
using namespace std;

int n, m, ans[5005], now[5005], q = 1, used[5005];
struct node{
	int s[5005], cnt;
}a[5005];

In void find(int x) {
	if (q==n) {
		bool w = false;
		re(i, 1, n) {
		    if (ans[i]<now[i]) break;
		    if (ans[i]>now[i]) { w = true; break; }
		}
		if (w) re(i, 1, n) ans[i] = now[i];
		return;
	}
	re(i, 1, a[x].cnt) if (a[x].s[i]) {
		int f = a[x].s[i]; 
		if (!used[f]) now[++q] = f; used[f]++;
		a[x].s[i] = 0;
		find(f);
		a[x].s[i] = f; used[f]--; 
		if (!used[f]) { now[q] = 0; q--; }
	}
	return;
}

In void findd(int x) {
	if (q==n) {
        re(i, 1, n) ans[i] = now[i]; return;
	} 
	re(i, 1, a[x].cnt) if (!used[a[x].s[i]]){ 
 		now[++q] = a[x].s[i]; used[a[x].s[i]] = 1;
		findd(a[x].s[i]);
	}
	return;
}

In bool cmp(int x, int y) { return x<y; }

int main() {
	freopen("travel.in", "r", stdin); freopen("travel.out", "w", stdout);
	scanf("%d%d", &n, &m);
	int u, v;
	re(i, 1, m) {
		scanf("%d%d", &u, &v);
		a[u].s[++a[u].cnt] = v; a[v].s[++a[v].cnt] = u;
	}
	memset(used, 0, sizeof(used));
	re(i, 1, n) sort(a[i].s+1, a[i].s+a[i].cnt+1, cmp);
	re(i, 1, n) ans[i] = n-i+1; now[q] = 1; used[1] = 1;
	if (m==n) find(1);
	else findd(1);
	re(i, 1, n) printf("%d ", ans[i]);
	return 0;
}
