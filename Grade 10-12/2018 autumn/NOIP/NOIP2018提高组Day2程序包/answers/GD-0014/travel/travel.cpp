#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int N = 5005;
int n, m, dfsq[2 * N], dfn[N], list[N], cnt = 0;
struct edge
{
	int from, to, next;
	void add(int x, int y) {
		from = x; to = y;
		next = list[x]; list[x] = cnt;
	}
} e[2 * N];

struct node {
	int num;
	bool operator < (const node &x) const {
		return num > x.num;
	}
};

typedef priority_queue<node> pq;
pq a[N];
bool v[N];

int ans[N], curr[N];

void minn() {
	bool flag = false;
	for(int i = 1; i <= n; i++) {
		if (flag) ans[i] = curr[i];
		else if (curr[i] < ans[i]) {
			flag = true;
			ans[i] = curr[i];
		} else if (curr[i] > ans[i]) {
			return;
		}
	}
}

void dfs(int x, int sum) {

}

void print(int x) {
	v[x] = 1;
	printf("%d ", x);
	while(! a[x].empty()) {
		node tmp = a[x].top();
		int y = tmp.num;
		a[x].pop();
		if (! v[y]) {
			print(y);
		}
	}
}

void print1() {
	for (int i = 1; i <= n; i++) {
		printf("%d ", ans[i]);
	}
}

int main () {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		node tmp;
		tmp.num = y;
		a[x].push(tmp);
		tmp.num = x;
		a[y].push(tmp);
		e[++cnt].add(x, y);
		e[++cnt].add(y, x);
	}
	if (m == n - 1) {
		print(1);	
	} else if (m == n) {
		dfs(1, 0);
		print1();
	}
	fclose(stdin); fclose(stdout);
	return 0;
}
