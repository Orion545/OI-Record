#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

const int N = 50010;

long long sum = 0;

struct ed { int l, nx, v; } e[(N<<1)];
struct po { long long l; int s; } f[N], tt[N];

vector <po> tmp[N];

int tot = 0, he[N];
void add(int u, int v, long long l) {
	e[++tot].nx = he[u], e[tot].v = v, e[tot].l = l, he[u] = tot;
}

bool _sort(po x, po y) { return x.l < y.l; }

int n, m;
bool dfs(int u, int fa, long long x) {
	f[u].s = 0, f[u].l = 0;
	int cnt = 0;
	for (int h=he[u]; h!=-1; h=e[h].nx) {
		int v = e[h].v;	
		if(v == fa) continue;
		if(dfs(v, u, x)) return true;
		f[v].l += e[h].l;
		if(f[v].l >= x) f[v].l -= x, f[v].s ++;
		f[u].s += f[v].s;
		tmp[u].push_back(f[v]);
	}
	int t = tmp[u].size();
	for (int i=0; i<t; i++) tt[i+1] = tmp[u][i];
	sort(tt+1, tt+t+1, _sort);
	cnt = t;
	long long ma=0;
	for (int i=1; i<cnt; i++) {
		for (int j=i+1; j<=cnt; j++) {
			if(tt[j].l+tt[i].l >= x) {
				f[u].s ++; tt[j].l = 0, tt[i].l = 0; break; 
			}
		}
	}
	for (int i=cnt; i>=1; i--) {
		if(tt[i].l) { ma = tt[i].l; break; }
	}
	f[u].l = ma;
	if(f[u].s >= m) return true;
	return false;
}

bool ch(long long x) {
	for (int i=1; i<=n; i++) tmp[i].clear();
	if(dfs(1, 0, x)) return true;
	return false;
}

long long an = 0, o[N];
void dp(int u, int fa) {
	o[u] = 0;
	for (int h=he[u]; h!=-1; h=e[h].nx) {
		int v=e[h].v;
		if(v==fa) continue;
		dp(v, u);
		an = max(an, o[u]+o[v]+e[h].l);
		o[u] = max(o[u], o[v]+e[h].l);
	}
}

int main() {
	
	freopen("track.in", "r", stdin);
	freopen("track.out", "w", stdout);
	
	memset(he, -1, sizeof(he));
	
	scanf("%d%d", &n, &m);
	
	for (int i=1; i<n; i++) {
		int u, v;
		long long l;
		scanf("%d%d%lld", &u, &v, &l);
		add(u, v, l), add(v, u, l);
		sum += l;
	}
	
	if(m == 1) {
		dp(1, 0);
		printf("%lld\n", an);
		return 0;
	}
	
	long long l = 1, r = sum + 1;
	while(l+1 < r) {
		long long mid = (l+r)>>1;
		if(ch(mid)) l = mid;
		else 		r = mid;
	}
	printf("%lld\n", l);
	
	return 0;
}
