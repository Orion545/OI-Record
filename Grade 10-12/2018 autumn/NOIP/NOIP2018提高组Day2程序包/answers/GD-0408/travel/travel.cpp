#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#define REP(i, a, b) for(register int i = (a); i < (b); i++)
#define _for(i, a, b) for(register int i = (a); i <= (b); i++)
using namespace std;

const int N = 5e3 + 10;
struct Edge{ int to, next; } e[N << 1];
int head[N], tot;

int n, m, vis[N];
vector<int> ans;

void AddEdge(int from, int to)
{
	e[tot] = Edge{to, head[from]};
	head[from] = tot++;
}

void dfs(int i, int u, int fa)
{
	if(i > n) return;
	vector<int> t;
	ans.push_back(u);
	for(int i = head[u]; ~i; i = e[i].next)
	{
		int v = e[i].to;
		if(v == fa) continue;
		t.push_back(v);
	}
	sort(t.begin(), t.end());
	REP(i, 0, t.size()) dfs(i + 1, t[i], u);
}

priority_queue<int, vector<int>, greater<int> > q;
void solve()
{
	q.push(1); vis[1] = 1;
	_for(k, 1, n)
	{
		int u = q.top(); q.pop();
		ans.push_back(u);
		for(int i = head[u]; ~i; i = e[i].next)
		{
			int v = e[i].to;
			if(!vis[v]) vis[v] = 1, q.push(v);
		}
	}
}

int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	memset(head, -1, sizeof(head)); tot = 0;
	scanf("%d%d", &n, &m);
	_for(i, 1, m)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		AddEdge(u, v); AddEdge(v, u);
	}
	
	if(n == m) solve();
	else dfs(1, 1, -1);
	
	printf("%d", ans[0]);
	REP(i, 1, ans.size()) printf(" %d", ans[i]);
	puts("");
	
	return 0;
}
