#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

#define F(i, a, b) for (int i = a; i <= b; i ++)
#define mem(a, b) memset(a, b, sizeof a)

const int N = 5e5 + 10, M = 2 * N;

using namespace std;

int n, m, pos, x, y, l, r, md, Mx, Ans, tot;
int a[N], b[N], L[N], dis[N]; bool bz, flag, BZ[N], vis[N];
int tov[M], nex[M], las[N], len[M], fa[N], dep[N], D[N];
struct node { int x, y, l; } d[N];

bool cmp(node x, node y) {
	return x.l > y.l;
}

void ins(int x, int y, int l) {
	tov[++ tot] = y, nex[tot] = las[x], las[x] = tot, len[tot] = l;
}

void DFS(int k, int La) {
	for (int x = las[k] ; x; x = nex[x])
		if (tov[x] ^ La)
			dis[tov[x]] = dis[k] + len[x], DFS(tov[x], k);
}

bool OK(int dis) {
	int ToT = 0, en = n;
	F(i, 1, n - 1) {
		while (en > i + 1 && d[i].l + d[en].l < dis)
			en --;
		if (en <= i || d[i].l + d[en].l < dis)
			break;
		ToT ++;
		if (d[i].l < dis)
			en --;
	}
	return ToT >= m;
}

bool PD(int d) {
	int ToT = 0;
	for (int i = n, st = n; i > 1; i = st - 1) {
		while (st > 1 && dis[i] - dis[st - 1] < d)
			st --;
		if (st < 1 || dis[i] - dis[st - 1] < d)
			break;
		ToT ++;
	}
	return ToT >= m;
}

void dfs(int k) {
	for (int x = las[k] ; x ; x = nex[x])
		if (dep[tov[x]] == 0)
			D[tov[x]] = len[x], fa[tov[x]] = k, dep[tov[x]] = dep[k] + 1, dfs(tov[x]);
}

void DFS(int k, int t, int now) {
	if (now <= Ans)
		return;
	if (k > n) {
		if (t >= m)
			Ans = now;
		return;
	}

	DFS(k + 1, t, now);
	
	BZ[k] = 1;
	F(i, k + 1, n)
		if (!BZ[i]) {
			bool f = 0; int sum = 0;
			for (x = i, y = k; x ^ y; ) {
				if (dep[x] > dep[y]) {
					if (vis[x]) f = 1;
					sum += D[x], x = fa[x];
				}
				else
				{
					if (vis[y]) f = 1;
					sum += D[y], y = fa[y];
				}
			}
			
			if (f) continue;
			
			for (x = i, y = k; x ^ y; )
				if (dep[x] > dep[y])
					vis[x] = 1, x = fa[x]; else vis[y] = 1, y = fa[y];

			BZ[i] = 1;
			DFS(k + 1, t + 1, min(now, sum));
			BZ[i] = 0;
			for (x = i, y = k; x ^ y; )
				if (dep[x] > dep[y])
					vis[x] = 0, x = fa[x]; else vis[y] = 0, y = fa[y];
		}
	BZ[k] = 0;
}

int main() {
	freopen("track.in", "r", stdin);
	freopen("track.out", "w", stdout);

	scanf("%d%d", &n, &m), bz = flag = 1;
	F(i, 1, n - 1)
		scanf("%d%d%d", &a[i], &b[i], &L[i]), ins(a[i], b[i], L[i]), ins(b[i], a[i], L[i]), r += L[i],
		bz = a[i] > 1 ? 0 : bz, flag = (a[i] + 1 != b[i]) ? 0 : flag;

	if (m == 1) {
		DFS(1, 0);
		F(i, 1, n)
			if (dis[i] > Mx)
				Mx = dis[i], pos = i;
		mem(dis, 0), Mx = 0, DFS(pos, 0);
		F(i, 1, n)
			if (dis[i] > Mx)
				Mx = dis[i];
		printf("%d\n", Mx);
		return 0;
	}

	if (bz) {
		F(i, 1, n - 1)
			d[i] = {a[i], b[i], L[i]};
		sort(d + 1, d + n, cmp);
		while (l <= r) {
			md = l + r >> 1;
			if (OK(md))
				Ans = md, l = md + 1;
			else
				r = md - 1;
		}
		printf("%d\n", Ans);
		return 0;
	}

	if (flag) {
		DFS(1, 0);
		while (l <= r) {
			md = l + r >> 1;
			if (PD(md))
				Ans = md, l = md + 1;
			else
				r = md - 1;
		}
		printf("%d\n", Ans);
		return 0;
	}
	
	dep[1] = 1, dfs(1), Ans = 0;
	DFS(1, 0, 1e9);
	printf("%d\n", Ans);

	return 0;
}
