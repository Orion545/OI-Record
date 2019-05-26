#include <cstdio>
#define INF 0x7ffffff
#define MAXN 100000

using namespace std;

int min(int a, int b) {
	return a<b ? a : b;
}

int abs(int a) {
	return a>0 ? a : -a;
}

class Tree {
public:
	int n, m, ind[MAXN+1], to[MAXN*2], next[MAXN*2], fa[MAXN+1], f[MAXN+1][2], p[MAXN+1], dep[MAXN+1];

	void init(int n) {
		this->n = n;
		m=0;
	}

	void addSide(int u, int v) {
		m++;
		to[m] = v;
		next[m] = ind[u];
		ind[u] = m;
	}

	void build(int o, int root) {
		fa[o] = root;
		f[o][0]=0, f[o][1]=p[o], dep[o]=dep[root]+1;
		for (int i=ind[o]; i; i=next[i]) {
			if (to[i]!=root) {
				build(to[i], o);
				f[o][0] += f[to[i]][1];
				f[o][1] += min(f[to[i]][0], f[to[i]][1]);
			}
		}
	}

	int change(int a, int x, int b, int y) {
		static int q[MAXN+1][3];
		if ((fa[a]==b || fa[b]==a) && (x==0 && y==0)) {
			return -1;
		}
		q[1][0] = f[a][0], q[1][1] = f[a][1], q[1][2]=a;
		q[2][0] = f[b][0], q[2][1] = f[b][1], q[2][2]=b;
		f[a][abs(x-1)] = f[b][abs(y-1)] = INF;
		int head, tail;
		for (head=0, tail=2; head<tail; ) {
			head++;
			int x=fa[q[head][2]];
			tail++;
			q[tail][0] = f[x][0], q[tail][1] = f[x][1];
			f[x][0] = 0, f[x][1] = p[x];
			for (int i=ind[x]; i; i=next[i]) {
				if (to[i]!=fa[x]) {
					f[x][0] += f[to[i]][1];
					f[x][1] += min(f[to[i]][0], f[to[i]][1]);
				}
			}
			if (f[x][0]!=q[tail][0] || f[x][1]!=q[tail][1]) {
				q[tail][2] = x;
			} else {
				tail--;
			}
		}
		int ret=min(f[1][0], f[1][1]);
		for (int i=tail; i>0; i--) {
			f[q[i][2]][0] = q[i][0], f[q[i][2]][1] = q[i][1];
		}
		return ret;
	}
};

int main() {
	freopen("defense.in", "r", stdin);
	freopen("defense.out", "w", stdout);

	static Tree tree;
	int n, m;
	char type[3];
	scanf("%d %d %s", &n, &m, type);
	tree.init(n);
	for (int i=1; i<=n; i++) {
		scanf("%d", &tree.p[i]);
	}
	for (int i=1; i<n; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		tree.addSide(u, v);
		tree.addSide(v, u);
	}
	tree.build(1, 0);
	for (int i=1; i<=m; i++) {
		int a, b, x, y;
		scanf("%d %d %d %d", &a, &x, &b, &y);
		printf("%d\n", tree.change(a, x, b, y));
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
