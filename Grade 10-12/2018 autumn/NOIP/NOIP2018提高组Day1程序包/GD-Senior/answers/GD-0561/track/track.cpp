#include <cstdio>
#define N 100005
#include <string>
#include <cstring>
#define ll long long
using namespace std;

struct arr
{
	int nxt,to;
	ll w;
}a[N];
int n,m,l,ls[N],pos;
ll sum[N],ans,mx;

bool check(ll x)
{
	ll ss = 0;
	int k = 0;
	for (int i = 1; i <= n; i++)
	{
		if (ss + sum[i] < x) ss += sum[i];
			else k++, ss = 0;
	}
	return k >= m;
}

int read()
{
	int x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9') {if (ch == '-') f = -1; ch = getchar();}
	while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
	return x * f;
}

void add(int x, int y, ll w)
{
	a[++l].to = y;
	a[l].nxt = ls[x];
	a[l].w = w;
	ls[x] = l;
}

void dfs(int x, int fa, ll s)
{
	if (s > mx)
	{
		mx = s;
		pos = x;
	}
	for (int i = ls[x]; i; i = a[i].nxt)
		if (a[i].to != fa)
			dfs(a[i].to, x, s + a[i].w);
}

int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d", &n, &m);
	int mn = 1e9;
	bool flag = false;
	sum[1] = 0;
	for (int i = 1; i < n; i++)
	{
		int x, y;
		ll w;
		x = read(), y = read();
		if (y != x + 1) flag = true;
		scanf("%lld", &w);
		sum[i + 1] = sum[i] + w;
		add(x, y, w);
		add(y, x, w);
	}
	if (flag)
	{
		dfs(1, 0, 0);
		mx = 0;
		dfs(pos, 0, 0);
		if (m != 1) mx = a[1].w + a[n].w;
		printf("%lld", mx);
	}
	else
	{
		ll l = 0, r = 1e15;
		ans = 0;
		while (l <= r)
		{
			ll mid = (l + r) / 2;
			if (check(mid)) ans = mid, l = mid + 1;
				else r = mid - 1;
		}
		printf("%lld", ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
