#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const long long MaxN = 1E5;
const long long Maxint = 1E11;

struct node
{
	long long v, nxt;
	node(long long _v = 0, long long _nxt = 0) {v = _v, nxt = _nxt;}
};

long long n, m;
long long p[MaxN + 5];
node d[MaxN * 2 + 5];
long long final[MaxN + 5], cnt;
long long a, x, b, y;
bool bj[MaxN + 5];
long long f[MaxN + 5][2];

void Link(long long u, long long v)
{
	d[++cnt] = node(v, final[u]), final[u] = cnt;
	d[++cnt] = node(u, final[v]), final[v] = cnt;
}

void Get() {for (long long c = getchar(); c != '\n'; c = getchar());}

void Dfs(long long u)
{
	bj[u] = true, f[u][0] = 0, f[u][1] = p[u];
	
	for (long long i = final[u]; i; i = d[i].nxt)
	{
		long long v = d[i].v;
		
		if (bj[v])
			continue;
			
		Dfs(v);
		f[u][0] += f[v][1], f[u][1] += min(f[v][0], f[v][1]);
		f[u][0] = min(f[u][0], Maxint), f[u][1] = min(f[u][1], Maxint);
	}
	
	if (u == a)
		f[u][1 - x] = Maxint;
	
	if (u == b)
		f[u][1 - y] = Maxint;
}

int main()
{
	freopen("defense.in", "r", stdin);
	freopen("defense.out", "w", stdout);
	
	scanf("%lld%lld", &n, &m), Get();
	
	for (long long i = 1; i <= n; i++)
		scanf("%lld", &p[i]);
	
	for (long long i = 1; i < n; i++)
	{
		long long u, v;
		scanf("%lld%lld", &u, &v);
		Link(u, v);
	}
	
	for (long long i = 1; i <= m; i++)
	{
		scanf("%lld%lld%lld%lld", &a, &x, &b, &y);
		memset(bj, false, sizeof(bj));
		Dfs(1);
		long long ans = min(f[1][0], f[1][1]);
		
		if (ans >= Maxint)
			printf("-1\n");
		else
			printf("%lld\n", ans);
	}
	
	return 0;
}

