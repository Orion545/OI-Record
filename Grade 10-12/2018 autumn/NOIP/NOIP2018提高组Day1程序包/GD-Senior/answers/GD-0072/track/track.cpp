/*
	problem:赛道修建
	骗分 
	分割成m棵树，最小的直径最大 
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cstring>
#include <math.h>
#include <cmath>
#include <queue>
#include <map>

using namespace std;

long long n, m;
struct data {
	long long u;
	long long v;
	long long w;
	long long nxt;
}edge[100100];
long long cnt;
long long head[50100];
long long walk[50100];
long long ans;
long long f1[50100];
long long f2[50100];

long long dd(long long x) {
	long long i, j, k;
	walk[x] = 1;
	f1[x] = 0;
	f2[x] = 0;
	long long get = 0;
	i = head[x];
	while (i) {
		long long y = edge[i].v;
		if (walk[y]) {
			i = edge[i].nxt;
			continue;
		}
		get = max(get, dd(y));
		long long longedge = f1[y] + edge[i].w;
		if (longedge >= f1[x]) {
			f2[x] = f1[x]; f1[x] = longedge;
		}
		else if (longedge >= f2[x]) {
			f2[x] = longedge;
		}
		i = edge[i].nxt;
	}
	return max(get, f1[x] + f2[x]);
}

void m1() {
	long long i, j, k;
	memset(f1, 0, sizeof(f1));
	memset(f2, 0, sizeof(f2));
	memset(walk, 0, sizeof(walk));
	long long d = dd(1);
	printf("%lld\n", d);
}
/*
void juhua() {
	long long i, j, k;
	long long a[100100];
	long long b[2500000001];
	i = head[1];
	j = 0;
	while (i) {
		a[++ j] = edge[i].w;
		i = edge[i].nxt;
	}
	k = 0;
	for (i = 1; i <= n - 2; ++ i) {
		for (j = i + 1; j <= n - 1; ++ j) {
			b[++ k] = - a[i] - a[j];
		}
	}
	sort(b + 1, b + n - 1 + 1);
//	sort(a + 1, a + n - 1 + 1);
	long long ans = - b[m]; 
	printf("%lld/n", ans);

	i = n - 1;
	j = i - 1;
	long long cnt = m;
	long long d, ans;
	while (cnt --) {
		d = a[i] - a[i - 1];
		ans = a[i] + a[j];
		-- j;
		if (!j || a[j] < d) {
			-- i;
			j = i - 1;
		}
	}
}
*/
long long a[50100];

long long check(long long x) {
	long long i, j, k;
	i = 1;
	long long get = 0;
	while (i <= n - 1) {
		long long summ = 0;
		j = i;
		while (summ < x && j <= n - 1) {
			summ += a[j ++];
		}
		if (summ >= x) {
			++ get;
			i = j - 1;
			if (get == m) return 1;
		}
		++ i;
	}
	return 0;
}
long long devide(long long l, long long r) {
	long long i, j, k;
	if (l == r || l + 1 == r) {
		if (check(r)) {
			return r;
		}
		else {
			return l;
		}
	}
	long long mid = (l + r) / 2;
	if (check(mid)) {
		return devide(mid, r);
	}
	else {
		return devide(l, mid - 1);
	}
}

void lian() {
	long long i, j, k;
	
	long long sum = 0, minn = 10100;
	for (i = 1; i <= n - 1; ++ i) {
		j = head[i];
		while (j) {
			long long y = edge[j].v;
			if (y == i + 1) {
				a[i] = edge[j].w;
			}
			j = edge[j].nxt;
		}
		sum += a[i];
		minn = min(minn, a[i]);
	}
	for (i = 1; i <= n - 1; ++ i) cout << a[i] << ' '; cout << endl;
	long long ans = devide(minn, sum);
	printf("%lld\n", ans);
}

int main () {
	
	freopen("track.in", "r", stdin);
	freopen("track.out", "w", stdout);
	
	long long i, j, k;
	scanf("%lld%lld", &n, &m);
	cnt = 0;
	memset(head, 0, sizeof(head));
	long long jh = 1, ln = 1;
	for (i = 1; i <= n - 1; ++ i) {
		long long x, y, z;
		scanf("%lld%lld%lld", &x, &y, &z);
		if (x != 1) jh = 0;
		if (y != x + 1) ln = 0;
		++ cnt;
		edge[cnt].u = x;
		edge[cnt].v = y;
		edge[cnt].w = z;
		edge[cnt].nxt = head[x];
		head[x] = cnt;
		++ cnt;
		edge[cnt].u = y;
		edge[cnt].v = x;
		edge[cnt].w = z;
		edge[cnt].nxt = head[y];
		head[y] = cnt;
	}
	if (m == 1) {
		m1();
		return 0;
	}
	if (ln) {
		lian();
		return 0;
	}
		
	return 0;
}
/*
9 3
1 2 6
2 3
3 4 5
4 5 10
6 2 4
7 2 9
8 4 7
9
*/
