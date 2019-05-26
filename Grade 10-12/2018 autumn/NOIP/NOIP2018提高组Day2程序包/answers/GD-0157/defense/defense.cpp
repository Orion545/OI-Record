#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
		
char str[2];
int n, m;
int a, f1, b, f2;
long long p[100005], f[100005][2];

int head[100005], ver[200005], nxt[200005], tot=1;

inline void add(int x, int y) {
	ver[++tot]=y, nxt[tot]=head[x],
	head[x]=tot;
}

long long min(long long a, long long b) {
	return a < b ? a : b;
}

void dp(int x, int fa) {
	f[x][0]=0; f[x][1]=p[x];
	if ((x == a && f1) || (x == b && f2)) f[x][0]=1e18;
	if ((x == a && !f1) || (x == b && !f2)) f[x][1]=1e18;
	for (register int i=head[x]; i; i=nxt[i]) {
		int y=ver[i];
		if (y == fa) continue;
		dp(y, x);
		if ((x != a && x != b)||(x == a && !f1)||(x == b && !f2)) f[x][0]+=f[y][1];
		if ((x != a && x != b)||(x == a && f1)||(x == b && f2)) f[x][1]+=min(f[y][1], f[y][0]);
	}
}

int main() {
	freopen("defense.in", "r", stdin);
	freopen("defense.out", "w", stdout);
	scanf("%d%d%s", &n, &m, str);
	for (register int i=1; i<=n; ++i) scanf("%lld", &p[i]);
	for (register int i=1; i<n; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		add(x, y); add(y, x);
	}
	for (register int i=1; i<=m; ++i) {
		scanf("%d%d%d%d", &a, &f1, &b, &f2);
		dp(1, 0);
		long long ans;
		if (f[1][1] >= 1e18 && f[1][0] >= 1e18) ans=-1;
		else ans=min(f[1][1], f[1][0]);
		printf("%lld\n", ans);
	}
	return 0;
}

