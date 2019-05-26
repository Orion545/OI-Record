# include <bits/stdc++.h>
using namespace std;
# define Rep(i, s, t) for (int i = (s), _ = (t); i <= _; i ++)
# define Fore(x) for (vector<int>::iterator it = gr[x].begin(); it != gr[x].end(); it ++)
const int N = 5005;
int n, m, px[N], py[N];
vector<int> gr[N];
int v[N], r[N], l[N], tot;
void Run(int x, int X, int Y) {
	v[x] = 1, l[++ tot] = x;
	Fore(x)
		if (! v[* it] && (x != X || * it != Y) && (x != Y || * it != X))
			Run(* it, X, Y);
	v[x] = 0;
}
int Judge() {
	if (tot != n)
		return 0;
	Rep (i, 1, n)
		if (l[i] != r[i])
			return l[i] < r[i];
}
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	scanf("%d %d", & n, & m);
	Rep (i, 1, m) {
		int x, y;
		scanf("%d %d", & x, & y);
		px[i] = x, py[i] = y;
		gr[x].push_back(y);
		gr[y].push_back(x);
	}
	Rep (i, 1, n)
		sort(gr[i].begin(), gr[i].end());
	r[1] = n + 1;
	if (m == n - 1) {
		tot = 0, Run(1, 0, 0);
		if (Judge())
			memcpy(r, l, sizeof l);
	}
	else {
		Rep (i, 1, m) {
			tot = 0, Run(1, px[i], py[i]);
			if (Judge())
				memcpy(r, l, sizeof l);
		}
	}
	Rep (i, 1, n)
		printf("%d%c", r[i], i < n ? ' ' : '\n');
	return 0;
}
