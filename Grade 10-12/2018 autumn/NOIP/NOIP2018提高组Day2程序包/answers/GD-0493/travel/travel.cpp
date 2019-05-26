#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define _FOR(i,a,b) for (int i = (a); i<=(b); i++)
using namespace std;
const int maxn = 5001, maxm = 10001;
int N, M, path[maxn], Pn = 0, 
	rot,
	En = 0, head[maxn], dgr[maxn];
bool vis[maxn], son[maxn];
struct edge
{
	int v, nxt;
} E[maxm];
void addE(int u, int v)
{
	++En;
	E[En].v = v;
	E[En].nxt = head[u];
	head[u] = En;
}
void dfs(int u)
{
	vis[u] = 1;
	if (dgr[u]==1)
	{
		for (int i = head[u]; i; i = E[i].nxt)
		{
			int v = E[i].v;
			if (vis[v]) continue;
			path[++Pn] = v;
			dfs(v);
		}
	}
	else if (dgr[u]==2)
	{
		int son[2], Vn = 0;
		for (int i = head[u]; i; i = E[i].nxt)
		{
			int v = E[i].v;
			if (vis[v]) continue;
			son[Vn++] = v;
		}
		if (Vn==2||son[0]>son[1])
		{
			int t = son[0];
			son[0] = son[1];
			son[1] = t;
		}
		_FOR(i,0,Vn-1)
		{
			path[++Pn] = son[i];
			dfs(son[i]);
		}
	}
	else 
	{
		memset(son, 0, sizeof(son));
		for (int i = head[u]; i; i = E[i].nxt)
		{
			int v = E[i].v;
			if (vis[v]) continue;
			son[v] = 1;
		}
		_FOR(i,1,N)
		{
			if (!son[i]) continue;
			path[++Pn] = i;
			dfs(i);
		}
	}
	return;
}
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	scanf("%d%d", &N, &M);
	_FOR(i,1,M)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		addE(u,v);
		addE(v,u);
		dgr[v]++; dgr[u]++;
	}
	if (M==N-1)
	{
		_FOR(i,1,N)
		{
			_FOR(j,0,N) vis[j] = 0;
			Pn = 0;
			rot = i;
			path[++Pn] = rot;
			dfs(rot);
			if (Pn == N) break;
		}
	}
	_FOR(i,1,Pn)
	{
		printf("%d ", path[i]);
	}
	puts("");
	return 0;
}
