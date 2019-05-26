#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define kN 50000
using std::vector;
#define rep(i,x,y) for(int i=x;i<y;++i)
int dist[kN];
struct node {
	int v, w;
	node(int v=0, int w=0):
		v(v), w(w) {}
	bool operator < (const node &a) const {
		return w > a.w;
	}
};
vector<node> adj[kN];

int n, m;
void src(int o, int d = 0, int fa = -1) {
	dist[o] = d;
	for (vector<node>::iterator
	j = adj[o].begin(); j != adj[o].end(); ++j) {
		if (j->v != fa)
			src(j->v, d + j->w, o);
	}
}

void work1() { //Ê÷ÉÏ×î³¤Á´ 
	src(0);
	int chain_head = 0;
	for (int i = 1; i < n; ++i) {
		if (dist[i] > dist[chain_head])
			chain_head = i;
	}
	src(chain_head);
	int ans = dist[0];
	for (int i = 1; i < n; ++i) {
		if (dist[i] > ans)
			ans = dist[i];
	}
	printf("%d\n", ans);
}

int n__;
int a[kN];

bool check(int k) {
	int l = 0, r = n__ - 1, cnt = 0;
	while (r >= 0 && cnt < m && a[r] >= k) --r, ++cnt;
	if (cnt == m) {
	//	putchar('\n');
		return true;	
	}
	//printf("%d\n", r);
	for (int i = cnt + 1; i <= m; ++i) {
		while (l < r && a[l] + a[r] < k) {
			++l;
		}
		if (l == r) return false;
		//printf("%d, [%d]  %d, [%d]\n", l, a[l], r, a[r]);
		++l, --r;
	}
	return true;
}

void work2() {
	n__ = n - 1;
	rep(i, 0, n__) a[i] = adj[0][i].w;
	std::sort(a, a + n__);
	//rep(i,0,n__) printf("%d ", a[i]);
	//putchar('\n');
	int l = 1, r = a[n__ - 1] << 2;
	while (l < r) {
		int mid = (l + r + 1) >> 1;
		//printf("mid = %d: \n", mid);
		if (check(mid)) {
			l = mid;
		//	puts("true");
		} else {
			r = mid - 1;
		//	puts("false");
		}
		//putchar('\n');
		//printf("--> %d %d\n\n", l, r);
	}
	printf("%d\n", l);
}

int main() {
	freopen("track.in", "r", stdin);
	freopen("track.out", "w", stdout);
	int maxu = 0;
	scanf("%d%d", &n, &m);
	rep(i,0,n) adj[i].reserve(6);
	rep(i,1,n) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		--u; --v;
		if (u > maxu) maxu = u;
		adj[u].push_back(node(v, w));
		adj[v].push_back(node(u, w));
	}
	if (m == 1) {
		work1();
		return 0;
	}
	if (maxu == 0) {
		work2();
		return 0;
	}
	return 0;
}
