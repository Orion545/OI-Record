#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

int head[5005], ver[10005], nxt[10005], tot=1;
int n, m, tot2, ans[5005], v[5005];
int keyp, flag;

inline void add(int x, int y) {
	ver[++tot]=y, nxt[tot]=head[x],
	head[x]=tot;
}

void dfs(int x) {
	priority_queue<int, vector<int>, greater<int> > q;
	ans[++tot2]=x;
	for (register int i=head[x]; i; i=nxt[i]) {
		int y=ver[i];
		if (v[y]) continue;
		if (y == keyp && !flag) {
			flag=1;
			continue;
		}
		v[y]=1;
		q.push(y);
	}
	while (!q.empty()) {
		int y=q.top(); q.pop();
		dfs(y);
	}
}

int findcir(int x, int fa) {
	for (register int i=head[x]; i; i=nxt[i]) {
		int y=ver[i];
		if (y == fa) continue;
		if (v[y]) {
			keyp=x;
			return y;
		}
		v[y]=1;
		int res=findcir(y, x);
		//printf("%d -> %d : %d\n", x, y, res);
		if (res == -1) return -1;
		if (!res) continue;
		keyp=keyp < x ? x : keyp;
		if (res == x) return -1;
		return res;
	}
	return 0;
}

void prework() {
	memset(v, 0, sizeof(v));
	v[1]=1; findcir(1, 0);
	memset(v, 0, sizeof(v));
}

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (register int i=1; i<=m; ++i) {
		int x, y; scanf("%d%d", &x, &y);
		add(x, y); add(y, x);
	}
	if (m == n) prework();
	v[1]=1; dfs(1);
	for (register int i=1; i<tot2; ++i)
		printf("%d ", ans[i]);
	printf("%d\n", ans[tot2]);
	return 0;
}

