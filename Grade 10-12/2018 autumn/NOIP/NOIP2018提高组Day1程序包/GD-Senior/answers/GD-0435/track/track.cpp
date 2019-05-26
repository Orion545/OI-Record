#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>


using namespace std;


typedef long long LL;


const int N = 50010, M = 100010;


int n, m;


LL len[N];

LL dist[N];

bool typ, typ2;

bool del[N];


struct Data
{
	int x, y; LL dis;
	Data() { }
	Data(int a, int b, LL c) : x(a), y(b), dis(c) { }
	bool operator < (const Data & rhs) const { return dis < rhs.dis; }
} data[M];


struct edge
{
	int from, to; LL dis; int id;
	edge() { }
	edge(int a, int b, LL c, int d) : from(a), to(b), dis(c), id(d) { }
} edges[M];

int head[N], nxt[M], tot;

inline void init()
{
	memset(head, -1, sizeof(head));
	tot = 0;
}

inline void add_edge(int x, int y, LL z, int k)
{
	edges[tot] = edge(x, y, z, k);
	nxt[tot] = head[x];
	head[x] = tot++;
	edges[tot] = edge(y, x, z, k);
	nxt[tot] = head[y];
	head[y] = tot++;
}


LL maxdist;
int p;

void Find(int x, int fa, LL dist)
{
	if (maxdist < dist)
	{
		maxdist = dist;
		p = x;
	}
	for (int i = head[x]; ~i; i = nxt[i])
	{
		edge & e = edges[i];
		if (e.to != fa)
			Find(e.to, x, dist + e.dis);
	}
}


bool check(LL mid)
{
	memset(del, 0, sizeof(del));
	if (typ)
	{
		static set< pair<LL, int> > e;
		e.clear();
		for (int i = 2; i <= n; i++)
			e.insert( pair<int, int>(len[i], i) );
		int Ans = 0;
		for (int i = 2; i <= n; i++)
			if (len[i] >= mid)
			{
				Ans++;
				del[i] = 1;
				e.erase( pair<int, int>(len[i], i) );
			}
		for (int i = 2; i <= n; i++)
		{
			if (del[i]) continue;
			set< pair<LL, int> >::iterator it = e.find( pair<LL, int>(len[i], i) );
			e.erase(it);
			del[i] = 1;
			it = e.lower_bound( pair<LL, int>(mid - len[i], 0) );
			if (it == e.end())
			{
				del[i] = 0;
				e.insert( pair<int, int>(len[i], i) );
			}
			else
			{	
				del[it->second] = 1;
				e.erase(it);
				Ans++;
			}
		}
		return Ans >= m;
	}
	else if (typ2)
	{
		LL sum = 0;
		int Ans = 0;
		for (int i = 2; i <= n; i++)
		{
			sum += dist[i];
			if (sum >= mid)
			{
				sum = 0;
				Ans++;
			}
		}
		return Ans >= m;
	}
}


LL solve(LL l, LL r)
{
	LL Ans = l;
	while (l <= r)
	{
		LL mid = (l + r) >> 1LL;
		if (check(mid))
			Ans = mid, l = mid + 1;
		else
			r = mid - 1;
	}
	return Ans;
}


int main()
{
	freopen("track.in", "r", stdin);
	freopen("track.out", "w", stdout);
	
	scanf("%d %d", &n, &m);
	
	init();
	
	LL sum = 0;
	
	typ = 1;
	typ2 = 1;
	
	for (int i = 1; i < n; i++)
	{
		int x, y; LL z;
		scanf("%d %d %lld", &x, &y, &z);
		if (x != 1) typ = 0;
		else len[y] = z;
		
		if (y != x+1) typ2 = 0;
		else dist[y] = z;
		
		add_edge(x, y, z, i);
		sum += z;
	}
	
	if (m == 1)
	{
		maxdist = 0;
		p = 0;
		Find(1, 0, 0);
		maxdist = 0;
		Find(p, 0, 0);
		printf("%lld\n", maxdist);
		return 0;
	}
	
	printf("%lld\n", solve(0, sum));
	
	return 0;
}
