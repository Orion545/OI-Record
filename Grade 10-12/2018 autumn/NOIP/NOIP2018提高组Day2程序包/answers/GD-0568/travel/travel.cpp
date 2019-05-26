#include <cstdio>
#define MAXN 5000
#define MAXM 5000

using namespace std;

class Graph {
public:
	int n, m, ind[MAXN+1], next[2*MAXM+1], from[2*MAXM+1], to[2*MAXM+1], num[2*MAXM+1], circle[MAXM+1], ans[MAXN+1];

	void qsort(int a[][3], int l, int r, int o) {
		int i=l, j=r, mid=a[(l+r)/2][o], temp;
		for (; i<=j; ) {
			for (; a[j][o]>mid; j--);
			for (; a[i][o]<mid; i++);
			if (i<=j) {
				for (int k=0; k<3; k++) {
					temp = a[i][k], a[i][k] = a[j][k], a[j][k] = temp;
				}
				i++, j--;
			}
		}
		if (i<r) {
			qsort(a, i, r, o);
		}
		if (j>l) {
			qsort(a, l, j, o);
		}
	}

	void init(int n, int m, int arr[][3]) {
		this->n = n;
		this->m = 0;
		for (int i=1; i<=n; i++) {
			ans[i] = n+1;
		}
		qsort(arr, 1, 2*m, 1);
		for (int i=2*m; i>0; i--) {
			addSide(arr[i][0], arr[i][1], arr[i][2]);
		}
	}

	void addSide(int x, int y, int no) {
		m++;
		next[m] = ind[x];
		from[m] = x;
		to[m] = y;
		num[m] = no;
		ind[x] = m;
	}

	void buildTree(int o, int fa) {
		static int stack[MAXN+1];
		static bool book[MAXM+1];
		book[o] = true;
		stack[0]++;
		for (int i=ind[o]; i; i=next[i]) {
			if (to[i]!=fa) {
				stack[stack[0]] = i;
				if (book[to[i]]) {
					circle[0] = 0;
					for (int j=stack[0]; from[stack[j]]!=to[i]; j--) {
						circle[++circle[0]] = num[stack[j]];
					}
				} else {
					buildTree(to[i], o);
				}
			}
		}
		book[o] = false;
		stack[0]--;
	}

	void getAns(int o, int &pos, int fa, int ban, int *ans) {
		ans[++pos] = o;
		for (int i=ind[o]; i; i=next[i]) {
			if (to[i]!=fa && num[i]!=ban) {
				getAns(to[i], pos, o, ban, ans);
			}
		}
	}

	void solve() {
		static int temp[MAXN+1];
		buildTree(1, 0);
		int pos;
		if (circle[0]>0) {
			for (int i=1; i<=circle[0]; i++) {
				pos=0;
				getAns(1, pos, 0, circle[i], temp);
				int flag=0;
				for (int j=1; j<=n && !flag; j++) {
					flag = temp[j]==ans[j] ? 0 : (temp[j]<ans[j] ? 1 : -1);
				}
				if (flag>0) {
					for (int j=1; j<=n; j++) {
						ans[j] = temp[j];
					}
				}
			}
		} else {
			pos=0;
			getAns(1, pos, 0, 0, ans);
		}
	}
};

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);

	static int a[2*MAXM+1][3];
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i=1; i<=m; i++) {
		scanf("%d %d", a[i*2-1], a[i*2-1]+1);
		a[i*2][0] = a[i*2-1][1], a[i*2][1] = a[i*2-1][0];
		a[i*2-1][2] = a[i*2][2] = i;
	}
	static Graph g;
	g.init(n, m, a);
	g.solve();
	for (int i=1; i<=n; i++) {
		printf("%d ", g.ans[i]);
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
