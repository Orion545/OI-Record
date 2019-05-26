#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define N 100003
#define inf 2147483647
using namespace std;
struct node{
	int a, b, c, n;
	bool operator < (const node & A) const{
		return c < A.c;
	}
}d[N * 2], e[N];
int h[N], dis[N], dep[N], fa[N], son[N], v[N], siz[N], top[N], vis[N], cnt, n, p, maxn, m, ret, minn = inf;
void cr(int a, int b, int c){
	d[++cnt].a = a; d[cnt].b = b; d[cnt].c = c; d[cnt].n = h[a]; h[a] = cnt;
}
void dfs1(int a, int f){
	int i, b, c;
	siz[a] = 1;
	for(i = h[a]; i; i = d[i].n){
		b = d[i].b;
		c = d[i].c;
		if(b == f) continue;
		dis[b] = dis[a] + c;
		minn = min(minn, c);
		dep[b] = dep[a] + 1;
		fa[b] = a;
		if(maxn < dis[b]) maxn = dis[b], p = b;
		dfs1(b, a);
		siz[a] += siz[b];
		if(siz[son[a]] <= siz[b]) son[a] = b;
	}
}
void dfs2(int a, int f){
	int i, b;
	top[a] = f;
	if(son[a]) dfs2(son[a], f);
	for(i = h[a]; i; i = d[i].n){
		b = d[i].b;
		if(b != fa[a] && b != son[a]) dfs2(b, b);
	}
}
int lca(int a, int b){
	int f1 = top[a], f2 = top[b];
	while(f1 != f2){
		if(dep[f1] < dep[f2]) swap(f1, f2), swap(a, b);
		a = fa[f1], f1 = top[a];
	}
	return dep[a] < dep[b] ? a : b;
}

int moni(int i){
	int a = e[i].a, b = e[i].b, c = e[i].n;
	while(a != c){
		if(v[a] == 1) return 0;
		a = fa[a];
	}
	while(b != c){
		if(v[b] == 1) return 0;
		b = fa[b];
	}
	a = e[i].a, b = e[i].b;
	while(a != c){
		v[a] = 1, a = fa[a];
	}
	while(b != c){
		v[b] = 1, b = fa[b];
	}
	return 1;
}
int bac(int i){
	int a = e[i].a, b = e[i].b, c = e[i].n;
	while(a != c){
		v[a] = 0;
		a = fa[a];
	}
	while(b != c){
		v[b] = 0;
		b = fa[b];
	}
}
int dfs(int pos, int s){
	int i;
	if(pos == ret + 1) return 0;
	if(s == m) return 1;
	for(i = pos; i <= ret; i++){
		if(!vis[i] && moni(i)){
			vis[i] = 1;
			if(dfs(pos + 1, s + 1)) return 1;
			bac(i);
			vis[i] = 0;
		}
	}
	return 0;
}
int work(int x){
	int i, j, s = 0;
	for(j = 1; j <= ret; j++) if(e[j].c >= x) break;
	/*printf("%d ---", x);
	for(i = j; i <= ret; i++) printf("%d %d %d\n", e[i].a, e[i].b, e[i].c);
	printf("ok =======:\n")*/;
	if(n <= 50){
		return dfs(j, 0);
	}
	else{
		for(i = j; i <= ret; i++){
			if(moni(i)){
				//printf("%d %d %d\n", e[i].a, e[i].b, e[i].c);
				s++;
			}
		}
		//printf("\n\n");
		return s >= m;
	}
}
int check(int x){
	int i, j, s = 0;
	j = 0;
	for(i = 1; i <= n; i++){
		if(dis[i] - dis[j] >= x){
			j = i;
			s++;
		}
	}
	return s >= m;
}
int main(){
	freopen("track.in", "r", stdin);
	freopen("track.out", "w", stdout);
	int i, j, a, b, c, l, r, mid;
	scanf("%d%d", &n, &m);
	for(i = 1; i < n; i++){
		scanf("%d%d%d", &a, &b, &c);
		cr(a, b, c); cr(b, a, c);
	}
	dfs1(1, 1);
	if(m == 1){
		maxn = 0;
		memset(dis, 0, sizeof(dis));
		memset(fa, 0, sizeof(fa));
		dfs1(p, p);
		printf("%d", maxn);
	}
	else if(n <= 200){
		dfs2(1, 1);
		for(i = 1; i <= n; i++){
			for(j = i + 1; j <= n; j++){
				e[++ret].a = i; e[ret].b = j; 
				c = lca(i, j);
				e[ret].n = c;
				e[ret].c = dis[i] + dis[j] - 2 * dis[c];
				//printf("====%d %d %d\n", i, j, e[ret].c);
			}
		}
		sort(e + 1, e + ret + 1);
		l = e[1].c; r = e[ret].c;
		while(l < r){
			memset(vis, 0, sizeof(vis));
			mid = l + r + 1 >> 1;
			if(work(mid)) l = mid;
			else r = mid - 1;
		}
		printf("%d", l);
	}
	else{
		l = minn, r = maxn;
		while(l < r){
			mid = l + r >> 1;
			if(check(mid)) l = mid;
			else r = mid - 1;
		}
		printf("%d", l);
	}
	return 0;
}
