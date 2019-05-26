#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define F(i, a, b) for (int i = a; i <= b; i ++)
#define G(i, a, b) for (int i = a; i >= b; i --)
#define mem(a, b) memset(a, b, sizeof a)
#define mec(a, b) memcpy(a, b, sizeof a)
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define mx(a, b) ((a) = max(a, b))
#define mn(a, b) ((a) = min(a, b))
#define lowbit(x) ((x) & (- x))
#define get getchar()

const int N = 1e5 + 10;

void Re(int &x) {
	char c = get; x = 0; int t = 1;
	for (; !isdigit(c); c = get) t = (c == '-' ? -1 : t);
	for (; isdigit(c); x = (x << 3) + (x << 1) + c - '0', c = get); x *= t;
}
void Wr(int x) {
	if (x < 0) { putchar('-'); x = - x; }
	if (x > 9) Wr(x / 10); putchar(x % 10 + '0');
}

int n, m, u[N], v[N], Ans[N], now[N], L;
int tov[N], nex[N], las[N], tot; bool vis[N];
vector <int> Q[N];
void ins(int x, int y) {
	tov[++ tot] = y, nex[tot] = las[x], las[x] = tot;
}

void Dfs(int k, int La, int p) {
	Ans[++ L] = k, vis[k] = 1;
	F(i, 0, Q[k].size() - 1)
		if (!vis[Q[k][i]]) {
			if ((u[p] == k && v[p] == Q[k][i]) || (u[p] == Q[k][i]) && (v[p] == k))
				continue;
			Dfs(Q[k][i], k, p);
		}
}

bool OK() {
	F(i, 1, L)
		if (Ans[i] < now[i]) return 1;
			else
		if (Ans[i] > now[i]) return 0;
	return 0;
}

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);

	Re(n), Re(m);
	F(i, 1, m) Re(u[i]), Re(v[i]), Q[u[i]].push_back(v[i]), Q[v[i]].push_back(u[i]), ins(u[i], v[i]), ins(v[i], u[i]);
	F(i, 1, n) sort(Q[i].begin(), Q[i].end());

	if (m == n - 1) {
		Dfs(1, 0, 0);
		F(i, 1, L)
			Wr(Ans[i]), putchar(' ');
		return 0;
	}

	mem(now, 7);
	F(i, 1, m) {
		L = 0, mem(vis, 0);
		Dfs(1, 0, i);
		if (L < n) continue;
		if (OK())
			mec(now, Ans);
	}
	F(i, 1, n)
		printf("%d ", now[i]);
	return 0;
}
