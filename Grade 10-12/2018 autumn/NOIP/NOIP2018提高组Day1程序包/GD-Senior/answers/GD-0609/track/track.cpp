#include <cstdio>
#include <cstring>
#include <cstdlib>

const int N = 50007;
inline int read()
{
	int x = 0, f = 0;
	char c = getchar();
	for (; c < '0' || c > '9'; c = getchar()) if (c == '-') f = 1;
	for (; c >= '0' && c <= '9'; c = getchar()) x = (x << 1) + (x << 3) + (c ^ '0');
	return f ? -x : x;
}

int n, m, a[N], b[N], c[N];

int tot, st[N], to[N << 1], nx[N << 1], len[N << 1];
void add(int u, int v, int w) { to[++tot] = v, nx[tot] = st[u], len[tot] = w, st[u] = tot; }

int x, head, tail, que[N], dis[N];
void solve1()
{
	memset(dis, 0, sizeof(dis));
	head = 1, que[tail = 1] = 1, dis[1] = 1;
	while (head <= tail)
	{
		int u = que[head++];
		for (int i = st[u]; i; i = nx[i]) if (!dis[to[i]]) dis[to[i]] = dis[u] + len[i], que[++tail] = to[i];
	}
	int mxdis = 0;
	for (int i = 1; i <= n; i++) if (dis[i] > mxdis) mxdis = dis[i], x = i;
	memset(dis, 0, sizeof(dis));
	head = 1, que[tail = 1] = x, dis[x] = 1;
	while (head <= tail)
	{
		int u = que[head++];
		for (int i = st[u]; i; i = nx[i]) if (!dis[to[i]]) dis[to[i]] = dis[u] + len[i], que[++tail] = to[i];
	}
	mxdis = 0;
	for (int i = 1; i <= n; i++) if (dis[i] > mxdis) mxdis = dis[i] - 1;
	printf("%d\n", mxdis);
}

int check(int k)
{
	int cnt = 0;
	for (int i = 1; i < n; i++) if (c[i] >= k) cnt++;
	if (cnt < m - 1) return 0;
	if (cnt >= m) return 1;
	int max1 = 0, max2 = 0;
	for (int i = 1; i < n; i++)
		if (c[i] < k)
		{
			if (c[i] >= max1) max2 = max1, max1 = c[i];
			else if (c[i] >= max2) max2 = c[i];
		}
	if (max1 + max2 >= k) return 1;
	return 0;
}
void solve2()
{
	int l = 0, r = 500000000, mid, ans;
	while (l <= r)
	{
		mid = l + r >> 1;
		if (check(mid)) l = mid + 1, ans = mid;
		else r = mid - 1;
	}
	printf("%d\n", ans);
}
int ok(int k)
{
	int sum = 0, cnt = 0;
	for (int i = 1; i < n; i++)
	{
		if (sum + c[i] >= k) sum = 0, cnt++;
		else sum += c[i];
	}
	if (sum >= k) cnt++;
	return cnt >= m;
}
void solve3()
{
	int l = 0, r = 500000000, mid, ans;
	while (l <= r)
	{
		mid = l + r >> 1;
		if (ok(mid)) l = mid + 1, ans = mid;
		else r = mid - 1;
	}
	printf("%d\n", ans);
}

int main()
{
	freopen("track.in", "r", stdin);
	freopen("track.out", "w", stdout);
	
	n = read(), m = read();
	int flag1 = 1, flag2 = 1;
	for (int i = 1; i < n; i++)
	{
		a[i] = read(), b[i] = read(), c[i] = read(), add(a[i], b[i], c[i]), add(b[i], a[i], c[i]);
		if (a[i] != 1) flag1 = 0;
		if (b[i] != a[i] + 1) flag2 = 0;
	}
	if (m == 1) solve1();
	else if (flag1) solve2();
	else if (flag2) solve3();

	fclose(stdin);
	fclose(stdout);
	return 0;
}

