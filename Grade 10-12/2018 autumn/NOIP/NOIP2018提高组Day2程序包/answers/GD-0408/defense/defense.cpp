#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<cctype>
#define REP(i, a, b) for(register int i = (a); i < (b); i++)
#define _for(i, a, b) for(register int i = (a); i <= (b); i++)
using namespace std;

typedef long long ll;
const int N = 1e5 + 10;
struct Edge{ int to, next; } e[N << 1];
int head[N], tot;

int n, m, p[N], vis[N];
char s[100];
ll dp[N][2];

void read(int& x)
{
	int f = 1; x = 0; char ch = getchar();
	while(!isdigit(ch)) { if(ch == '-') f = -1; ch = getchar(); }
	while(isdigit(ch)) { x = x * 10 + ch - '0'; ch = getchar(); }
	x *= f;
}

void AddEdge(int from, int to)
{
	e[tot] = Edge{to, head[from]};
	head[from] = tot++;
}

void dfs(int u, int fa)
{
	dp[u][0] = 0; dp[u][1] = p[u];
	for(int i = head[u]; ~i; i = e[i].next)
	{
		int v = e[i].to;
		if(v == fa) continue;
		dfs(v, u);
		dp[u][0] += dp[v][1];
		dp[u][1] += min(dp[v][1], dp[v][0]);
	}
	if(vis[u] == 1) dp[u][1] = dp[u][0];
	if(vis[u] == 2) dp[u][0] = dp[u][1];
}

bool check(int u, int b)
{
	for(int i = head[u]; ~i; i = e[i].next)
	{
		int v = e[i].to;
		if(v == b) return true;
	}
	return false;
}

int main()
{
	freopen("defense.in", "r", stdin);
	freopen("defense.out", "w", stdout);
	
	memset(head, -1, sizeof(head)); tot = 0;
	scanf("%d%d%s", &n, &m, s + 1);
	_for(i, 1, n) read(p[i]);
	
	REP(i, 1, n)
	{
		int u, v;
		read(u); read(v);
		AddEdge(u, v); AddEdge(v, u);
	}
	
	_for(k, 1, m)
	{
		int a, b, x, y;
		read(a); read(x); read(b); read(y);
		
		if(check(a, b) && !x && !y) puts("-1");
		else
		{
			memset(vis, 0, sizeof(vis));
			vis[a] = x + 1; vis[b] = y + 1;
			dfs(1, -1);
			printf("%lld\n", min(dp[1][0], dp[1][1]));
		}
	}
	
	return 0;
}
