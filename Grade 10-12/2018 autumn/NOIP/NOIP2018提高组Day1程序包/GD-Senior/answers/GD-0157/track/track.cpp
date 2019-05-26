#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

inline int read() {
	register int num=0, f=1;
	register char c=getchar();
	while (c < '0' || '9' < c) {
		if (c == '-') f=-1;
		c=getchar();
	}
	while ('0' <= c && c <= '9')
		num=(num<<3)+(num<<1)+(c&15), c=getchar();
	return num*f;
}

int head[50005], ver[100005], edge[100005], nxt[100005], tot=1;
int n, m;
long long ans, lim;
long long f[50005], g[50005];
vector<long long> tmp[50005];
vector<int> vis;

inline void add(int x, int y, int z) {
	ver[++tot]=y, edge[tot]=z;
	nxt[tot]=head[x], head[x]=tot;
}

void work(int x, int fa) {
	f[x]=g[x]=0;
	for (register int i=head[x]; i; i=nxt[i]) {
		int y=ver[i], z=edge[i];
		if (y == fa) continue;
		work(y, x);
		g[x]+=g[y];
		if (f[y]+z >= lim) ++g[x];
		else tmp[x].push_back(f[y]+z);
	}
	sort(tmp[x].begin(), tmp[x].end());
	int tt=tmp[x].size();
	vis.resize(tt);
	for (register int i=0; i<tt; ++i) {
		if (vis[i]) continue;
		for (register int j=i+1; j<tt; ++j) { 
			if (vis[j]) continue;
			if (tmp[x][i]+tmp[x][j] >= lim) {
				++g[x], vis[i]=vis[j]=1;
				break;
			}
		}
	}
	for (register int i=tt-1; i>=0; --i) 
		if (!vis[i]) {
			f[x]=tmp[x][i];
			break;
		}
	tmp[x].clear(); vis.clear();
}

bool check(long long x) {
	lim=x;
	work(1, 0);
	return g[1] >= m;
}

int main() {
	freopen("track.in", "r", stdin);
	freopen("track.out", "w", stdout);
	n=read(); m=read();
	long long l=0,  r=0;
	for (register int i=1; i<n; ++i) {
		int x=read(), y=read(), z=read();
		add(x, y, z);
		add(y, x, z); r+=z;
	}
	while (l <= r) {
		long long mid=(l+r)>>1;
		if (check(mid)) ans=mid, l=mid+1;
		else r=mid-1;
	}
	printf("%lld\n", ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

