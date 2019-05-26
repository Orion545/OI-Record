#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int, int> pii;
vector<int> edge[5010];
//priority_queue<pii, vector<pii>, greater<pii> > que;
bool vis[5010], bacl[5010];
int tu, tv;

int qr ();
int cmp (int, int);

void search (int u)
{
	vis[u] = 1;
	int v;
	printf("%d ",u);
	sort(edge[u].begin(), edge[u].end(), cmp);
	for(int i = edge[u].size()-1; i >= 0; i--)
	{
		v = edge[u][i];
		if(vis[v]) continue;
		if((tu == u && tv == v) || (tu == v && tv == u)) continue;
		//que.push(pii(v,u));
		search(v);
	}
	/*
	que.push(1);
	while(!que.empty())
	{
		int top = que.top(), v;
		que.pop();
		if(vis[top]) continue;
		printf("%d ",top);
		vis[top] = 1;
		for(int i = edge[top].size()-1; i >= 0; i--)
		{
			v = edge[top][i];
			if(vis[v]) continue;
			que.push(v);
		}
	}
	*/
}

int stack[5010], stop, dfn[5010], low[5010], cnt;
bool inst[5010], get;

void find (int u, int f)
{
	inst[u] = dfn[u] = low[u] = ++cnt;
	stack[++stop] = u;
	int v;
	for(int i = edge[u].size()-1; i >= 0; i--)
	{
		v = edge[u][i];
		if(v == f) continue;
		if(!dfn[v])
		{
			find(v,u);
			low[u] = min(low[u], low[v]);
		}
		else if (inst[v]) low[u] = min(dfn[v], low[u]);
	}
	if(dfn[u] == low[u])
	{
		int diff = 0;
		inst[u] = 0;
		while(stack[stop] != u)
		{
			int d = stack[stop] - stack[stop-1];
			if(d < 0) d = -d;
			if(diff < d && min(stack[stop], stack[stop-1]) > min(tu, tv) && min(stack[stop], stack[stop-1]) != 1)
			{
				tu = stack[stop];
				tv = stack[stop-1];
				diff = d;
			}
			inst[stack[stop--]] = 0;
		}
		stop--;
	}
}

int main ()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n = qr(), m = qr(), u, v;
	for(int i = 1; i <= m; i++)
	{
		u = qr(), v = qr();
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	if(m == n)
	{
		find(1, 0);
	}
	search(1);
	return 0;
}

inline int qr ()
{
	int num = 0;
	char ch = getchar();
	bool neg  = 0;
	while(ch < '0' && ch > '9')
	{
		if(ch == '-') neg = 1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9')
	{
		num = (num<<1) + (num<<3) + ch - '0';
		ch = getchar();
	}
	return neg ? -num : num;
}

inline int cmp (int a, int b)
{
	return a > b;
}
