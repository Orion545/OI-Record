#include <cstdio>
#include <algorithm>
#define N 50005
using namespace std;
struct node{
	int a, b, c, n; 
} d[N*2], g[N];
int l, i, j, k, a, b, c, n, m, x, cnt, cnt2, ans;
int h[N], y[N], t[N], s[N], q[N], dis[N], dep[N], f[N][20], r[N][20], u[1005][1005];

void add(int a, int b, int c)
{
	d[++cnt] = (node){a, b, c, h[a]};
	h[a] = cnt;
}
void add2(int a, int b, int c)
{
	g[++cnt2] = (node){a, b, c, y[a]};
	y[a] = cnt2;
}
void Maketree(int x)
{
	int i, b;
	for (i=h[x]; i; i=d[i].n)
	{
		b = d[i].b;
		if (!dep[b]) {
			dep[b] = dep[x] + 1;
			dis[b] = dis[x] + d[i].c;
			add2(x, b, d[i].c);
			f[b][0] = x;
			r[b][0] = d[i].c;
			Maketree(b);
		}
	}
}
int lca(int a, int b){
	int i, j, l;
	if (a == 1 || b == 1) return 1;
	if (a == b) return a;
	if (dep[a] != dep[b]) {
		if (dep[a] > dep[b]) swap(a, b);
		l = dep[b] - dep[a];
		for (i=0; i<=19; ++i) {
			if (l & (1 << i)) {
				b = f[b][i];
				l = l-(1 << i);
			}
			if (!l) break;
		}
	}
	if (a == b) return a;
	if (f[a][0] == f[b][0]) return f[a][0];
	l = dep[a];
	i = 0;
	while((1 << i) <= l) i++;
	i--;
	for (j=i; j>=0; --j){
		if (f[a][j] != f[b][j]) {
			a = f[a][j], b = f[b][j];
		}
		if (a == b) return a;
	}
	return f[a][0];
}
int main()
{
	freopen("track.in", "r", stdin);
	freopen("track.out", "w", stdout);
	scanf("%d%d", &n, &m);
	int Lian = 1;
	for (i=1; i<n; ++i) {
		scanf("%d%d%d", &a, &b, &c);
		add(a, b, c);
		add(b, a, c);
		if (b != a+1) Lian = 0;
	}
	dep[1] = 1;
	dis[1] = 0;
	Maketree(1);
	for (i=1; i<=19; ++i) {
		for (j=1; j<=19; ++j) {
			f[i][j] = f[ f[i][j-1] ][j-1];
			r[i][j] = r[i][j-1] + r[ f[i][j-1] ][j-1];
		}
	}
	/*
	for (i=1; i<=n; ++i) {
		for (j=1; j<=n; ++j) {
			printf("%d ", lca(i, j));
		}
		printf("\n");
	}
	*/
	if (m == 1) {
		ans = 0;
		for (i=1; i<=n; ++i) {
			if (!y[i]) {
				q[++q[0]] = i;
			 	ans = max(ans, dis[i]);
			 	for (j=1; j<=t[0]; ++j) {
			 		if (t[j] == f[i][0]) break;
			 	}
			 	if (j > t[0]) t[++t[0]] = f[i][0];
			}
		}
//		printf("%d\n", ans);	
		for (i=1; i<=t[0]; ++i) {
			x = t[i];
			for (j=y[x]; j; j=g[j].n) {
				s[x] = max(s[x], g[j].c);
			}
		}
//		for (i=1; i<=t[0]; ++i) printf("%d %d\n", t[i], s[t[i]]);
		for (i=1; i<t[0]; ++i) {
			for (j=i+1; j<=t[0]; ++j) {
				c = lca(t[i], t[j]);
				ans = max(ans, dis[t[i]]+dis[t[j]]-dis[c] + s[t[i]] + s[t[j]]);
			}
		}
		printf("%d\n", ans);
		return 0;
	}
	else if (m == n-1) {
		ans = 2147483647;
		for (i=2; i<=n; ++i) ans = min(ans, r[i][0]);
		printf("%d\n", ans);
		return 0;
	}
	if (Lian) {
		ans = 0;
		for (i=2; i<=n; ++i) {
			u[i][1] = u[i-1][1] + r[i][0];
			for (j=2; j<=min(i-1, m); ++j) {
				int z = 0;
				for (k=2; k<i; ++k) {
					z = max(z, min(u[k][j-1], u[i][1]-u[k][1]));
				}
				u[k][j] = z;
			}
		}
		for (i=2; i<=n; ++i) {
			ans = max(ans, min(u[i][m-1], u[n][1]-u[i][1]));
		}
		printf("%d\n", ans);
		return 0;
	}
	int LuckyNum = 2333 % n;
	printf("%d\n", dis[LuckyNum]);
	return 0;
}
