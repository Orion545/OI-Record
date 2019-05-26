#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cmath>
#include<cstring>
#include<vector>
#define N 50005
using namespace std;
vector<int> a[N];
int n, m, vis[N];
void dfs(int x, int o){
//	if(vis[x]) return;
	vis[x] = 1; if(o) printf("%d ", x);
	int len = a[x].size();
	sort(a[x].begin(), a[x].end());
	for(int i = 0; i < len; i ++) if(!vis[a[x][i]]) dfs(a[x][i], o);
}
void work1(){
	dfs(1, 1);
}
int f = 0, r[N], sz, ring[N];
void findring(int x, int fa){
	if(vis[x]) {f = x; r[++ sz] = x; return;}
	vis[x] = 1;
	for(int i = 0; i < a[x].size(); i ++){
		if(fa != a[x][i]) findring(a[x][i], x);
		if(f) break;
	}
	if(f == x) {f = 0;return;}
	if(f) r[++ sz] = x;
}
struct A{
	int b[5005];
}st[5005];
int t, oo;
void dfss(int x, int u, int v, int id){
//	if(vis[x]) return;
	vis[x] = 1;
	int len = a[x].size(); st[id].b[++ oo] = x;
	sort(a[x].begin(), a[x].end());
	for(int i = 0; i < len; i ++){
		if((x == u && a[x][i] == v) || (x == v && a[x][i] == u)) continue;
		if(!vis[a[x][i]]) dfss(a[x][i], u, v, id);
	}
}
int cmp(A x, A y){
	for(int i = 1; i <= 5000; i ++) if(x.b[i] < y.b[i]) {return 1;} else if(x.b[i] > y.b[i]) {return 0;}
	
	return 0;
}
void work2(){
	findring(1, 0);
//	printf("%d %d\n", f, sz);
	
	for(int i = 0; i <= n; i ++) vis[i] = 0;
	int mi_id = 0;/*
	for(int i = 1; i <= sz; i ++) vis[r[i]] = 1;
	for(int i = 1; i <= sz; i ++) printf("%d ", r[i]);
	for(int i = 1; i <= sz; i ++){
		dfs(r[i], 0);
		if(vis[1]) {mi_id = i; printf("%d %d", mi_id, r[i]); break;}
	}
	
	for(int i = 0; i <= n; i ++) vis[i] = 0;
	
	r[0] = r[sz], r[sz + 1] = r[1];
	int F = r[mi_id - 1] < r[mi_id + 1];
	if(F){
		for(int i = 1; i <=  sz/2; i ++) swap(r[i], r[sz - i + 1]);	
		mi_id = sz - mi_id + 1;
	}
	printf("*%d\n", mi_id);
	for(int i = 1; i <= sz; i ++) r[i + sz] = r[i];
	for(int i = mi_id; i <= mi_id + sz - 1; i ++) ring[i - mi_id + 1] = r[i];
	
	for(int i = 1; i <= sz; i ++) printf("%d ", ring[i]); printf("\n");
	*/
	//for(int i = 1; i <= sz; i ++) vis[ring[i]] = 1;
	for(int i = 1; i <= sz; i ++) r[i + sz] = r[i];
	for(int i = 1; i <= sz; i ++){
		for(int j = 0; j <= n; j ++) vis[j] = 0;
		oo = 0;
		dfss(1, r[i], r[i + 1], ++ t);
	}
	
	sort(st + 1, st + 1 + t, cmp);
	for(int j = 1; j <= n; j ++) printf("%d ", st[1].b[j]);
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i ++){
		int u, v;
		scanf("%d%d", &u, &v);
		a[u].push_back(v);
		a[v].push_back(u);
	}
	if(m == n-1) work1();
	else work2();
	return 0;
}
