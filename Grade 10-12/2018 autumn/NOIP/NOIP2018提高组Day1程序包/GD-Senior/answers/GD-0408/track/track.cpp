#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#define REP(i, a, b) for(register int i = (a); i < (b); i++)
#define _for(i, a, b) for(register int i = (a); i <= (b); i++)
using namespace std;

const int N = 5e4 + 10;
struct Edge{ int to, next, w; } e[N << 1];
int head[N], tot, n, m;
int d[N], dp[N];

void AddEdge(int from, int to, int w)
{
	e[tot] = Edge{to, head[from], w};
	head[from] = tot++;
}

int dfs(int u, int fa, int ans)
{
	vector<int> t;
	t.push_back(0);
	for(int i = head[u]; ~i; i = e[i].next)
	{
		int v = e[i].to;
		if(v == fa) continue;
		dfs(v, u, ans);
		dp[u] += dp[v];
		t.push_back(d[v] + e[i].w);
	}
	
	sort(t.begin(), t.end());
	int l = 0, r = t.size() - 1;
	int maxt = 0;
	
	while(l < r)
	{
		if(t[l] + t[r] >= ans) 
		{
			dp[u]++, r--;
			if(t[l] != 0) l++;
		}
		else maxt = t[l++];
	}
	if(l == r) maxt = t[l];
	d[u] = maxt;
}

bool check(int ans)
{
	memset(dp, 0, sizeof(dp));
	memset(d, 0, sizeof(d));
	dfs(1, -1, ans);
	return dp[1] >= m;
}


int main()
{
	freopen("track.in", "r", stdin);
	freopen("track.out", "w", stdout);
	
	memset(head, -1, sizeof(head)); tot = 0;
	scanf("%d%d", &n, &m);
	
	int r = 0;
	REP(i, 1, n)
	{
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		AddEdge(u, v, w); AddEdge(v, u, w);
		r += w;
	}
	
	r++;
	int l = 1;
	while(l + 1 < r)
	{
		int m = (l + r) >> 1;
		if(check(m)) l = m;
		else r = m;
	}
	printf("%d\n", l);
	
	return 0;
}
