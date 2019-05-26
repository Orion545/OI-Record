#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#define LONG_INF 0x7fffffff

long n, m, node_st[10000], node_ed[10000];
bool vis[5001], flag, visible[5001];

typedef struct side {
	long x, y;	
};

side a[10000];

inline bool cmp(side a, side b) {
	if (a.x < b.x) {
		return true;
	} else {
		if (a.x == b.x) {
			return a.y < b.y;
		} else {
			return false;
		}
	}
}

inline void qsort(long l, long r) {
	long i = l, j = r;
	side mid = a[(l + r) / 2];
	do {
		while (cmp(a[i], mid))
			i++;
		while (cmp(mid, a[j]))
			j--;
		if (i <= j) {
			side temp;
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			i++;
			j--;
		}
	} while (i <= j);
	if (l < j)
		qsort(l, j);
	if (i < r)
		qsort(i, r);
}

inline void dfs(long node) {
	std::cout << node << ' ';
	for (long i = node_st[node]; i <= node_ed[node]; i++) {
		side temp = a[i];
		//long next;
		//next = a[i+1].y;
		//if (i == node_ed[node]) next = LONG_INF;
		if (!vis[temp.y]) { // (flag || (temp.y < father_next))
			vis[temp.y] = true;
			dfs(temp.y); // next
		}
	}
	return;
}

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	std::cin >> n >> m;
	for (long i = 0; i < m; i++) {
		std::cin >> a[i].x >> a[i].y;
		a[m+i].x = a[i].y;
		a[m+i].y = a[i].x;
	}	
	qsort(0, m*2-1);
	memset(node_st, -1, sizeof(node_st));
	memset(node_ed, -1, sizeof(node_ed));
	memset(vis, 0, sizeof(vis));

	long last = a[0].x;
	node_st[last] = 0;

	for (long i = 1; i < m*2; i++) {
		if (a[i].x != last) {
			node_ed[last] = i-1;
			last = a[i]. x;
			node_st[last] = i;
		}
	}
	node_ed[last] = m*2-1;
	if (n-1 == m) {
		vis[a[0].x] = 1;
		dfs(a[0].x);
	} else {
		visible[a[0].x] = 1;
		for (long i = 0; i < n; i++) {
			long j;
			for (j = 1; j <= n; j++) {
				if (visible[j]) break;
			}
			std::cout << j << ' ';
			vis[j] = true;
			visible[j] = false;
			for (long k = node_st[j]; k <= node_ed[j]; k++) {
				if (vis[a[k].y]) continue;
				visible[a[k].y] = true;
			}
		}
	}	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
