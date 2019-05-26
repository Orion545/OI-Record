#include <algorithm>
#include <cstdio>
using std::sort;
using std::swap;
using std::max;

const int MAXN = 50010;
struct EDGE { int v, w; EDGE *n; } edge[MAXN*2], *head[MAXN];
int n, m, ce, sum_weight;

void AddEdge(const int u, const int v, const int w) {
	edge[ce].v = v;
	edge[ce].w = w;
	edge[ce].n = head[u];
	head[u] = edge + ce;
	ce ++;
}

namespace Part_Chain {

bool check(const int k) {
	int cnt, p = 1;
	for (int i=1; i<=m; i++) {
		cnt = 0;
		while (cnt < k) {
			if (p >= n)
				return false;
			cnt += head[p]->v == p + 1 ? head[p]->w : head[p]->n->w;
			p ++;
		}
	}
	return true;
}

bool check_chain() {
	for (int i=1; i<n; i++)
		if (head[i]->v != i + 1 && (head[i]->n && head[i]->n->v != i + 1))
			return false;
	return true;
}

int work() {
	int l = 0, r = sum_weight, mid;
	while (l + 1 < r) {
		mid = (l + r) >> 1;
		if (check(mid)) l = mid;
		else            r = mid;
	}
	return l;
}

}

namespace M_Equal_1 {

int maxl[MAXN];

int dfs(const int u, const int f) {
	int ans = 0, ma[3] = {0, 0, 0};
	for (EDGE *e=head[u]; e; e=e->n) {
		if (e->v == f)
			continue;
		ans = max(ans, dfs(e->v, u));
		ma[2] = maxl[e->v] + e->w;
		for (int i=2; i; i--)
			if (ma[i] > ma[i - 1])
				swap(ma[i], ma[i - 1]);
	}
	ans = max(ans, ma[0] + ma[1]);
	maxl[u] = ma[0];
	return ans;
}

int work() { return dfs(1, 1); }

}

namespace A_Equal_1 {

int maxl[MAXN], tmp[MAXN];

int dfs(const int u, const int f, const int k) {
	int cnt = 0, p = 0;
	for (EDGE *e=head[u]; e; e=e->n) {
		if (e->v == f)
			continue;
		cnt += dfs(e->v, u, k);
	}
	// printf("[%d] %d: ", u, cnt);
	for (EDGE *e=head[u]; e; e=e->n) {
		if (e->v == f)
			continue;
		if (maxl[e->v] + e->w >= k)
			cnt ++;
		else
			tmp[++ p] = maxl[e->v] + e->w;
		// printf("%d ", tmp[p]);
	}
	sort(tmp+1, tmp+p+1);
	for (int l=1, r=p; l<r; r--) {
		while (tmp[l] + tmp[r] < k && l < r)
			l ++;
		if (l < r) {
			cnt ++;
			tmp[l] = tmp[r] = 0;
		}
	}
	// printf("=> %d\n", cnt);
	maxl[u] = 0;
	for (int i=p; i; i--)
		if (tmp[i]) {
			maxl[u] = tmp[i];
			break;
		}

	return cnt;
}

int work() {
	int l = 0, r = sum_weight, mid;
	while (l + 1 < r) {
		mid = (l + r) >> 1;
		// printf("Check %d\n", mid);
		if (dfs(1, 1, mid) >= m) l = mid;
		else                     r = mid;
	}
	return l;
}

bool check_a() {
	for (int i=1; i<=n; i++)
		for (EDGE *e=head[i]; e; e=e->n)
			if (e->w != 1)
				return false;
	return true;
}

}

namespace BF {

int maxl[MAXN], q[MAXN], pair[MAXN];

int dfs(const int u, const int f, const int k) {
	int cnt = 0, qt = 0, max_match = 0;
	for (EDGE *e=head[u]; e; e=e->n) {
		if (e->v == f)
			continue;
		cnt += dfs(e->v, u, k);
	}
	// printf("[%d] %d: ", u, cnt);
	for (EDGE *e=head[u]; e; e=e->n) {
		if (e->v == f)
			continue;
		if (maxl[e->v] + e->w >= k)
			cnt ++;
		else {
			q[++ qt] = maxl[e->v] + e->w;
			pair[qt] = 0;
		}
	}
	sort(q+1, q+qt+1);
	for (int l=1, r=qt; l<r; l++, r--) {
		while (q[l] + q[r] < k && l < r)
			l ++;
		if (l < r) {
			max_match ++;
			pair[l] = r;
			pair[r] = l;
		}
	}

	int p = 1;
	while (p <= qt && (!pair[p] || pair[p] > p))
		p ++;
	if (pair[p - 1])
		p = n + 1;
	for (int i=1; p<=qt && i<=max_match && q[pair[p]] + q[p - 1] >= k; i++, p++) {
		pair[p - 1] = pair[p];
		pair[p] = 0;
		// printf("Fu*k %d\n", p);
	}

	// printf("=> %d\n", cnt + max_match);
	maxl[u] = 0;
	for (int i=qt; i; i--)
		if (!pair[i]) {
			maxl[u] = q[i];
			break;
		}

	return cnt + max_match;
}

int work() {
	int l = 0, r = sum_weight + 1, mid;
	while (l + 1 < r) {
		mid = (l + r) >> 1;
		// printf("Check %d\n", mid);
		if (dfs(1, 1, mid) >= m) l = mid;
		else                     r = mid;
	}
	return l;
}

}

int main() {
	freopen("track.in" , "r", stdin );
	freopen("track.out", "w", stdout);

	scanf("%d %d", &n, &m);
	for (int i=1, u, v, w; i<n; i++) {
		scanf("%d %d %d", &u, &v, &w);
		AddEdge(u, v, w);
		AddEdge(v, u, w);
		sum_weight += w;
	}

	if (m == 1)
		printf("%d\n", M_Equal_1::work());
	else if (Part_Chain::check_chain())
		printf("%d\n", Part_Chain::work());
	else if (A_Equal_1::check_a())
		printf("%d\n", A_Equal_1::work());
	else
		printf("%d\n", BF::work());

	return 0;
}
