#include<cstdio>
#include<cstring>
#include<queue>
#include <algorithm>
using namespace std;
const int N = 3005;
int n, m, list[N], cnt = 0;
struct edge {
	int from, to, len, next;
	void add(int x, int y, int z) {
		from = x; to = y; len = z;
		next = list[x]; list[x] = cnt;
	}
} e[2 * N], er[2 * N], ef[2 * N];
int read() {
	int x = 0, f = 1; char ch = getchar();
	while(ch > '9' || ch < '0') {if (ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}
long long sum[N], f[N][N];
long long work1() {
	for (int i = list[1]; i; i = e[i].next) {
		sum[e[i].to] = sum[e[i].from] + e[i].len;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			f[i][j] = 0;
			for (int k = 1; k < i; i++) {
				f[i][j] = max(f[i][j], min(f[k][j - 1], sum[i] - sum[k - 1]));
			}
		}
	}
	return f[n][m];
}
struct node {
	int num;
	long long dis;
	bool operator < (const node &n0) const {
		dis < n0.dis;
	}
};
//long long d[N];
//priority_queue<node> q;
bool visited[N];
int longest(int x) {
//	memset(d, 0, sizeof(d));
	visited[x] = 1;
	while(x) {
		int maxe = 0, maxn = 0;
		bool f = 1;
		for (int i = list[x]; i; i = e[i].next) {
			if (!visited[e[i].to] && e[i].len > maxe) {
				visited[e[i].to] = 1;
				maxe = e[i].len;
				maxn = e[i].to;
				f = 0;
			}
		}
		if (f) break;
		x = maxn;
	}
	memset(visited, 0, sizeof(visited));
	int maxl = 0;
	visited[x] = 1;
	while(x) {
		int maxe = 0, maxn = 0;
		bool f = 1;
		for (int i = list[x]; i; i = e[i].next) {
			if (!visited[e[i].to] && e[i].len > maxe) {
				visited[e[i].to] = 1;
				maxe = e[i].len;
				maxn = e[i].to;
				f = 0;
			}
		}
		if (f) break;
		maxl += maxe;
		x = maxn;
	}
	return maxl;
}
long long work0() {
	return longest(1);
}
bool cmp0(const edge &x, const edge &y) {
	return x.len < y.len;
}
bool cmp1(const edge &x, const edge &y) {
	return x.len > y.len;
}
long long work2() {
	for (int i = 1; i <= cnt; i++) {
		er[i] = e[i];
		ef[i] = e[i];
	}
	long long re = 0;
	sort(er + 1, er + 1 + cnt, cmp0);
	sort(ef + 1, ef + 1 + cnt, cmp1);
	for (int i = 1; i <= m; i++) {
		re = min (re, (long long)(er[i].len + ef[cnt - i + 1].len));
	}
	return re;
}
int main() {
	freopen("track.in", "r", stdin);
	freopen("track.out", "w", stdout);
	bool flag0 = false, flag1 = true, flag2 = true;
	n = read(); m = read();
	if (m == 1) flag0 = true;
	bool b = 1;	for (int i = 1; i < n; i++) {
		int x = read(), y = read(), z = read();
		e[++cnt].add(x, y, z);
		e[++cnt].add(y, x, z);
		if (y != x + 1) flag1 = false;
		if (x != 1) flag2 = false;
	}
	long long ans = 0;
	if (flag1) ans = work1();
	else if (flag0) ans = work0();
	else if (flag2) ans = work2();
	printf("%d", ans);
	fclose(stdin); fclose(stdout);
}
