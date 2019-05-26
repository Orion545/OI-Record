#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 5e4 + 5;

struct Edge
{
	int to,next,val;
}edge[N << 1];

struct Edge1
{
	int x,y,z;
}f[N << 1];

int n,m,u,v,w,lian = 1,juhua = 1,zhijing = 1,fir,k,sec,l,r,ans,tot;
int st[N],vis[N];

void link(int u,int v,int w)
{
	edge[++tot].to = v;
	edge[tot].next = st[u];
	edge[tot].val = w;
	st[u] = tot;
}

void dfs(int x,int dis)
{
	if (dis > k) k = dis,fir = x;
	vis[x] = 1;
	for (int l = st[x] ; l ; l = edge[l].next)
	{
		int v = edge[l].to;
		if (!vis[v]) dfs(v,dis + edge[l].val);
	}
}

int check(int mid)
{
	int sum = 0,ti = 0;
	for (int i = 1 ; i < n ; i++)
	{
		sum += f[i].z;
		if (sum >= mid) sum = 0,ti++;
		if (ti >= m) return 1;
	}
	return 0;
}

int cmp(Edge1 x,Edge1 y)
{
	return x.z < y.z;
}

int find(int x)
{
	int l_ = 1,r_ = n - 1,ans_ = 0;
	while (l_ <= r_)
	{
		int mid_ = l_ + r_ >> 1;
		(f[mid_].z >= x) ? ans_ = mid_,r_ = mid_ - 1 : l_ = mid_ + 1;
	}
	return ans_;
}

int check1(int mid)
{
	memset(vis,0,sizeof(vis));
	int ti = 0;
	for (int i = 1 ; i < n ; i++)
	{
		if (vis[i]) continue;
		int tmp = mid - f[i].z;
		if (tmp <= 0) { ti++; continue; }
		int pos = find(tmp);
		if (!pos) continue;
		while (vis[pos] || pos == i) pos++;
		if (pos >= n) continue;
		vis[pos] = vis[i] = 1,ti++;
	}
	return ti >= m;
}

int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	if (m != 1) zhijing = 0;
	for (int i = 1 ; i < n ; i++) 
	{
		scanf("%d%d%d",&u,&v,&w),link(u,v,w),link(v,u,w);
		f[i].x = u,f[i].y = v,f[i].z = w;
		r += w;
		if (u != 1) juhua = 0;
		if (v != u + 1) lian = 0;
	}
	if (zhijing)
	{
		dfs(1,0);
		k = 0;
		sec = fir;
		memset(vis,0,sizeof(vis));
		dfs(sec,0);
		printf("%d\n",k);
		return 0;
	}
	if (lian)
	{
		while (l <= r)
		{
			int mid = l + r >> 1;
			check(mid) ? ans = mid,l = mid + 1 : r = mid - 1;
		}
		printf("%d\n",ans);
		return 0;
	}
	if (juhua)
	{
		sort(f + 1,f + n,cmp);
		while (l <= r)
		{
			int mid = l + r >> 1;
			check1(mid) ? ans = mid,l = mid + 1 : r = mid - 1;
		}
		printf("%d\n",ans);
		return 0;
	}
	return 0;
}

