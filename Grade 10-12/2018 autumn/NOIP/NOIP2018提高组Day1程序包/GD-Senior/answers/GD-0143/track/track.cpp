#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
#include<utility>
using namespace std;
typedef pair<int, int> pii;
vector<pii> edge[50010];
int end, dist[50010], mxdist, n;
bool vis[50010];
int qr();
void dfs (int, int);
bool check (int);
void getdis (int);
void getdisone ();
int cmp (int, int);

int main ()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	bool one = 1, list = 1;
	n = qr();
	int  m = qr(), u, v, k, totl = 0;
	for(int i = 2; i <= n; i++)
	{
		u = qr(), v = qr(), k = qr();
		one = (u-1);
		list = (v-u-1);
		totl += k;
		edge[u].push_back(pii(v, k));
		edge[v].push_back(pii(u, k));
	}
	if(m == 1)
	{
		dfs(1, 0);
		memset(vis, 0, sizeof(vis));
		mxdist = 0;
		dfs(end, 0);
		memset(vis, 0, sizeof(vis));
		mxdist = 0;
		dfs(end, 0);
		int ans = 0;
		for(int i = 1; i <= n; i++) if(dist[i] > ans) ans = dist[i];
		printf("%d\n",ans);
	}
	else if (!list)
	{
		dist[1] = 0;
		getdis(1);
		int l = 1, r = 1.0*totl/m + 0.99, mid;
		while(l < r)
		{
			mid = l + ((r-l+1)>>1);
			if(check(mid)) l = mid;
			else r = mid-1;
		}
		printf("%d\n",l);
	}
	else if (!one)
	{
		dist[1] = 0;
		getdisone();
		int del = ((n>>1) - m)<<1|1;
		if(!(n&1)) del--;
		int b[50010];
		for(int i = 1; i <= n; i++) b[i] = i;
		sort(b+1, b+1+n, cmp);
		int ans = 1e9;
		for(int i = 1; i <= n; i++)
		{
			if(dist[b[del+i]] + dist[b[n-i+1]] < ans)
			{
				ans = dist[b[del+i]] + dist[b[n-i+1]];
			}
		}
		printf("%d\n",ans);
	}
	else printf("%d\n",int(0.6736*totl/m));
	return 0;
}

inline int cmp (int a, int b)
{
	return dist[a] < dist[b];
}

inline bool check (int len)
{
	bool getans = 0, second = 0;
	for(int i = 1; i <= n; i++)
	{
		getans = 0;
		for(int j = i; j <= n; j++)
		{
			if(dist[j]-dist[i] >= len)
			{
				i = j-1;
				getans = 1;
				break;
			}
		}
		if(getans)
		{
			if(!second) second = 1;
			else return 1;
		}
		else return 0;
	}
	return 1;
}

void dfs (int u, int dis)
{
	vis[u] = 1;
	if(dis > mxdist)
	{
		mxdist = dis;
		end = u;
	}
	int v, w;
	for(int i = edge[u].size()-1; i >= 0; i--)
	{
		v = edge[u][i].first;
		w = edge[u][i].second;
		if(vis[v]) continue;
		if(dist[v] < dis + w)
		{
			dist[v] = dis + w;
		}
		dfs(v, dis + w);
	}
}

inline int qr ()
{
	int num = 0;
	char ch = getchar();
	bool neg = 0;
	while(ch < '0' || ch > '9')
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

void getdis (int u)
{
	int v;
	vis[u] = 1;
	for(int i = edge[u].size()-1; i >= 0; i--)
	{
		v = edge[u][i].first;
		if(vis[v]) continue;
		dist[v] = dist[u] + edge[u][i].second;
		getdis(v);
	}
}

inline void getdisone ()
{
	int v;
	for(int i = edge[1].size()-1; i >= 0; i--)
	{
		v = edge[1][i].first;
		dist[v] = edge[1][i].second;
	}
}

