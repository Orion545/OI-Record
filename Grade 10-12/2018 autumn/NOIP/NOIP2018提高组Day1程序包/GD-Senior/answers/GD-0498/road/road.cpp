#include <algorithm>
#include <cstdio>
using std::sort;
using std::max;

const int MAXN = 100010;
int n, d[MAXN], o[MAXN], p[MAXN][2];
long long ans = 0;

bool RoadSort(const int lhs, const int rhs) {
	return d[lhs] > d[rhs];
}

int main() {
	freopen("road.in" , "r", stdin );
	freopen("road.out", "w", stdout);

	scanf("%d", &n);
	for (int i=1; i<=n; i++) {
		scanf("%d", &d[i]);
		o[i] = i;
		p[i][0] = i - 1;
		p[i][1] = i + 1;
	}
	sort(o+1, o+n+1, RoadSort);

	for (int i=1, now, dt; i<=n; i++) {
		now = o[i];
		dt = d[now] - max(d[p[now][0]], d[p[now][1]]);
		ans += dt;

		p[p[now][0]][1] = p[now][1];
		p[p[now][1]][0] = p[now][0];

		// printf("Up %d with %d (%d %d %d)\n", now, dt, d[now], d[p[now][0]], d[p[now][1]]);
	}

	printf("%lld\n", ans);

	return 0;
}
