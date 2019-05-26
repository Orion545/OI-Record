#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int T, n, a[105], ans, lim;
bool f[25001];

void solve() {
	memset(f, 0, sizeof(f));
	scanf("%d", &n);
	for (register int i=1; i<=n; ++i) scanf("%d", &a[i]);
	sort(a+1, a+1+n);
	lim=a[n];
	ans=n;
	f[0]=1;
	for (register int i=1; i<=n; ++i) {
		if (f[a[i]]) { ans--; continue; }
		for (register int j=a[i]; j<=lim; ++j) f[j]|=f[j-a[i]];
	}
	printf("%d\n", ans);
	return;
}

int main() {
	freopen("money.in", "r", stdin);
	freopen("money.out", "w", stdout);
	scanf("%d", &T);
	while (T--) solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}

