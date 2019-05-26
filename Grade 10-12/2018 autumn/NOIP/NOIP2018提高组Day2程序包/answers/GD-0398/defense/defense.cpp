#include <cstdio>
#include <algorithm>
#include <cstring>
#define N 100005
using namespace std;
struct node{
	int a, b, n;
} q[200005], d[100005];
int h[N], g[N], cnt, cnt2;
int i, j, k, n, m, a, b, c, ans, ta, tb, dep[N], v[N], f[N], p[N];
char s[10];

void add(int a, int b)
{
	q[++cnt2] = (node){a, b, g[a]};
	g[a] = cnt2;
}
void add2(int a, int b)
{
	d[++cnt] = (node){a, b, h[a]};
	h[a] = cnt;
}
void Maketree(int x)
{
	for (i=g[x]; i; i=q[i].n)
	{
		b = q[i].b;
		if (!v[b]) {
			add2(x, b);
			v[b] = 1;
			f[b] = x;
			dep[b] = dep[x] + 1;
			Maketree(b);
		}
	}
	if (dep[x] > dep[k]) k = x;
}
int run(int l, int r)
{
	int a, b, x, i;
	if (dep[l] >= dep[r]) {
		return 0;
	}
	x = r;
	a = 0, b = 0;
	i = 0;
	while (f[x] == f[l]) {
		if (i) a += p[x];
		else b += p[x];
		i = (i ^ 1);
		x = f[x];
	}
	return min(a, b);
}
int main()
{
	freopen("defense.in", "r", stdin);
	freopen("defense.out", "w", stdout);
	scanf("%d%d%s", &n, &m, s);
	for (i=1; i<=n; ++i) scanf("%d", &p[i]);
	for (i=1; i<n; ++i) {
		scanf("%d%d", &a, &b);
		add(a, b);
		add(b, a);
	}
//	printf("%s\n", s);
	v[1] = 1;
	dep[1] = 1;
	k = 1;
	Maketree(1);
	while (m--) {
		ans = 0;
		scanf("%d%d%d%d", &a, &ta, &b, &tb);
//		printf("%d\n", ans);
		if (dep[a] > dep[b]) swap(a, b), swap(ta, tb);
		if (!ta && !tb) {
			if (a == f[b] || b == f[a]) {
				printf("-1\n");
				continue;
			}
			else {
				if (dep[b] == dep[a] + 2) {
					ans += p[f[b]];
					ans += p[f[a]];
					ans += run(1, f[f[a]]);
					c = d[h[b]].b;
					ans += run(c, k);
				}
				else {
					c = d[h[a]].b;
					ans += p[c];
					ans += run(d[h[c]].b, f[f[b]]);
					ans += p[f[b]];
					ans += p[f[a]];
					ans += run(1, f[f[a]]);
					c = d[h[b]].b;
					ans += run(c, k);
				}
			}
			printf("%d\n", ans);
		}
		else {
			if (ta && tb) {
				ans += p[a]+p[b];
				ans += run(1, f[a]);
				ans += run(d[h[a]].b, f[b]);
				ans += run(d[h[b]].b, k);
			}
			else {
				if (!ta) {
					ans += p[f[a]];
					ans += run(1, f[f[a]]);
					c = d[h[a]].b;
					ans += p[c];
					ans += run(d[h[c]].b, f[b]);
					ans += p[b];
					ans += run(d[h[b]].b, k);
				}
				else {
					ans += p[f[b]];
					ans += run(1, f[f[b]]);
					c = d[h[b]].b;
					ans += p[c];
					ans += run(d[h[c]].b, f[a]);
					ans += p[a];
					ans += run(d[h[a]].b, k);
				}
				printf("%d\n", ans);
			}
		}
	}
	return 0;
}
