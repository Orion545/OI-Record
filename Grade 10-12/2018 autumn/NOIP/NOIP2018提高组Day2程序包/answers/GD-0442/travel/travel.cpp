#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>

const int maxn = 5005;
struct Edges
{
	int next, to, no;
} e[maxn << 1];
int head[maxn], tot;
std::vector<int> vec;
std::vector<int> answer;
int fa[maxn];
int n, m;
int cnt[maxn];
int no1, no2;
bool vis[maxn];
int pre[maxn];
int count;
void link(int u, int v)
{
	e[++tot] = (Edges){head[u], v, 0};
	head[u] = tot;
}
void dfs(int u, int f)
{
	printf("%d ", u);
	//vec.push_back(u);
	fa[u] = f;
	std::vector<int> temp;
	for(int i = head[u]; i; i = e[i].next)
	{
		int v = e[i].to;
		if(v == f) continue;
		if(u == no1 && v == no2) continue;
		if(u == no2 && v == no1) continue;
		temp.push_back(v);
	}
	std::sort(temp.begin(), temp.end());
	int siz = temp.size();
	for(int i = 0; i < siz; i++)
	{
		dfs(temp[i], u);
	}
}
void bfs(int s)
{
	std::queue<int> q;
	q.push(1); cnt[1]++;
	while(!q.empty())
	{
		int u = q.front(); q.pop();
		for(int i = head[u]; i; i = e[i].next)
		{
			int v = e[i].to;
			if(v == fa[u]) continue;
			if(no1 && no2 && u == no2 && v == no1) continue;
			if(fa[v] == 0)
			{
				fa[v] = u;
				q.push(v);
				cnt[v]++;
			}
			else
			{
				int temp1 = fa[v], temp2 = u;
				no1 = std::min(temp1, temp2); no2 = v;
				fa[v] = std::max(temp1, temp2);
			}
		}
	}
}
void solve()
{
	if(answer.size() == 0) answer = vec;
	else
	{
		for(int i = 0; i < n; i++)
		{
			if(vec[i] < answer[i])
			{
				answer = vec;
				return;
			}
			else if(answer[i] < vec[i])
			{
				return;
			}
		}
	}
}
void dfss(int u, int f)
{
	if(u == 0) return;
	if(vis[u])
	{
		for(int i = head[u]; i; i = e[i].next)
		{
			int v = e[i].to;
			if(v == f) continue;
			if(!vis[v])
			{
				dfss(v, u);
			}
		}
		dfss(pre[u], u);
	}
	else
	{
		vis[u] = true;
		vec.push_back(u);
		pre[u] = f;
		count++;
		if(count == n)
		{
			solve();
		}
		for(int i = head[u]; i; i = e[i].next)
		{
			int v = e[i].to;
			if(v == f) continue;
			if(!vis[v])
			{
				dfss(v, u);
			}
		}
		dfss(pre[u], u);
		count--;
		vis[u] = false;
		vec.resize(vec.size() - 1);
	}
	
}
void print()
{
	for(std::vector<int>::iterator it = answer.begin(); it != answer.end(); ++it)
	{
		printf("%d ", *it);
	}
	printf("\n");
}
void baoli()
{
	dfss(1, 0);
	print();
}
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++)
	{
		int u, v; scanf("%d%d", &u, &v);
		link(u, v); link(v, u);
	}
	if(m == n - 1)
	{
		dfs(1, 0);
		/*
		for(std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
		{
			printf("%d ", *it);
		}
		*/
		printf("\n");
	}
	else if(m == n)
	{
		if(m <= 10)
		{
			baoli();
		}
		else
		{
			bfs(1);
			memset(vis, false, sizeof vis);
			dfs(1, 0);
			/*
			for(std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
			{
				printf("%d ", *it);
			}
			*/
			printf("\n");
		}
	}
	return 0;
}
