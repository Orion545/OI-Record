//#define DEBUG
#include <cstdio>
#define MAXN 50000

using namespace std;

int max(int a, int b) {
	return a>b ? a : b;
}

class Tree {
public:
	int m, ind[MAXN+1], next[2*MAXN-1], to[2*MAXN-1], len[2*MAXN-1], f[MAXN+1];

	void init() {
		this->m = 0;
	}

	void addSide(int x, int y, int l) {
		m++;
		next[m] = ind[x];
		to[m] = y;
		len[m] = l;
		ind[x] = m;
	}

	void makeF(int o, int fa) {
		f[o] = 0;
		for (int i=ind[o]; i; i=next[i]) {
			if (to[i]!=fa) {
				makeF(to[i], o);
				f[o] = max(f[o], f[to[i]]+len[i]);
			}
		}
	}

	int solve(int o, int fa) {
		int temp0, temp1, ret=f[o];
		for (int i=ind[o]; i; i=next[i]) {
			if (to[i]!=fa) {
				temp0 = f[o], f[o] = 0;
				for (int j=ind[o]; j; j=next[j]) {
					if (j!=i) {
						f[o] = max(f[to[j]]+len[j], f[o]);
					}
				}
				temp1 = f[to[i]], f[to[i]] = max(f[to[i]], f[o]+len[i]);
				ret = max(ret, solve(to[i], o));
				f[o] = temp0, f[to[i]] = temp1;
			}
		}
		return ret;
	}
};

bool check(int *a, int mid, int n, int m) {
	int sum=0;
	for (int i=1; i<=n; i++) {
		sum += a[i];
		if (sum>=mid) {
			m--;
			sum = 0;
		}
	}
	return !m;
}

int main() {
	freopen("track.in", "r", stdin);
	freopen("track.out", "w", stdout);

	int n, m;
	scanf("%d %d", &n, &m);
	if (m==1) {
		static Tree tree;
		tree.init();
		for (int i=1; i<n; i++) {
			int a, b, l;
			scanf("%d %d %d", &a, &b, &l);
			tree.addSide(a, b, l);
			tree.addSide(b, a, l);
		}
		tree.makeF(1, 0);
		printf("%d", tree.solve(1, 0));
	} else {
		static int a[MAXN+1];
		int sum=0;
		for (int i=1; i<n; i++) {
			int x, y;
			scanf("%d %d %d", &x, &y, a+i);
			sum += a[i];
		}
		int ans=0;
		for (int l=1, r=sum, mid; l<=r; ) {
			mid = (l+r)/2;
			if (check(a, mid, n-1, m)) {
				l = mid+1;
				ans = mid;
			} else {
				r = mid-1;
			}
		}
		printf("%d", ans);
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
