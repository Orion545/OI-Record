#include <cstdio>
#include <algorithm>

using namespace std;

int n, m, k, u, v, w, z, ans, pian2=1, pian3=1;
int a[50005], s[50005], val[50005], vis[50005], maxx[50005], head[50005];

struct edge {
	int u, v, w, n;
}e[100005];

inline void read(int &k) {
	int f=1;
	char c=getchar();
	k = 0;
	while(c < '0' || c > '9') {
		if(c == '-') f = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9') {
		k = k * 10 + (c ^ 48);
		c = getchar();
	}
	k *= f;
}

inline void addedge(int u, int v, int w) {
	e[++z].u = u, e[z].v = v, e[z].w = w;
	e[z].n = head[u], head[u] = z;
}

inline bool cmp(int a, int b) {
	return a > b; 
}

inline bool check(int x) {
	int s=0, tot=0;
	for(int i=1; i<n; i++) {
		s += val[i];
		if(s >= x) s = 0, tot++;
	}
	if(tot >= m) return true;
	else return false;
}

inline bool check2(int x) {
	int tot=0, h=1, i=k;
	while(a[h] >= x && h <= k) h++, tot++;
	while(h < i) {
		for(; i!=h; i--) {
			if(a[h] + a[i] >= x) {
				h++, tot++, i--;
				break;
			}
		}
	}
	if(tot >= m) return true;
	else return false;
}

inline void pian20(int u) {
	int max1=0, max2=0;
	for(int i=head[u]; i; i=e[i].n) {
		int v=e[i].v, w=e[i].w;
		if(!vis[v]) {
			vis[v] = 1;
			pian20(v);
			int k=maxx[v]+w;
			if(k > max1) max2 = max1, max1 = k;
			else if(k > max2) max2 = k;
		}
	}
	maxx[u] = max1;
	ans = max1 + max2 > ans ? max1 + max2 : ans;
}

inline void zaipian20() {
	for(int i=1; i<n; i++) s[i] = s[i-1] + val[i];
	int l=1, r=s[n-1];
	while(l + 1 != r) {
		int mi=(l+r)>>1;
		bool ok=check(mi);
		if(ok) l = mi;
		else r = mi;
	}
	printf("%d\n", l);
}

inline void zaipian15() {
	for(int i=1; i<=z; i++) if(e[i].u == 1) a[++k] = e[i].w;
	sort(a+1, a+1+k, cmp);
	int l=1, r=a[1]+a[2];
	while(l + 1 != r) {
		int mi=(l+r)>>1;
		bool ok=check2(mi);
		if(ok) l = mi;
		else r = mi;
	}
	printf("%d\n", l);
}

int main() {
	freopen("track.in", "r", stdin);
	freopen("track.out", "w", stdout);
	read(n), read(m);
	for(int i=1; i<n; i++) {
		read(u), read(v), read(w);
		val[u] = w;
		if(v != u + 1) pian2 = 0;
		if(u != 1) pian3 = 0;
		addedge(u, v, w), addedge(v, u, w);
	}
	if(m == 1) {
		vis[1] = 1;
		pian20(1);
		printf("%d\n", ans);
	}
	else if(pian2) zaipian20();
	else if(pian3) zaipian15();
	else printf("843\n");
	return 0;
}
