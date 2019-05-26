#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#define N 600006
using namespace std;
struct edge{
	int v, c, nxt;
}e[N];
int p[N], eid;
void init(){
	memset(p, -1, sizeof p);
	eid = 0;
}
void insert(int u, int v, int c){
	e[eid].v = v;
	e[eid].c = c;
	e[eid].nxt = p[u];
	p[u] = eid ++;
}
int dis[N], vis[N], n, m;
priority_queue<pair<int, int >, vector<pair<int, int> >, greater<pair<int, int> > > q;
int dij(int S){
	memset(dis, 0x3f, sizeof dis);
	memset(vis, 0, sizeof dis);
	dis[S] = 0;
	q.push(make_pair(0, S));
	while(q.size()){
		int u = q.top().second; q.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		for(int i = p[u]; i + 1; i = e[i].nxt){
			int v = e[i].v;
			int c = e[i].c;
			if(dis[u] + c < dis[v]) dis[v] = dis[u] + c, q.push(make_pair(dis[v], v));
		}
	}
	int ma = 0, ma_id = 0;
	for(int i = 1; i <= n; i ++) if(dis[i] > ma) ma = dis[i], ma_id = i;
	return ma_id;
}
void work1(){

		int x = dij(1);
		x = dij(x);
		printf("%d", dis[x]);
}
int a[N];
int check(int x){
	int s = 0, ss = 0;
	for(int i = 1; i < n; i ++){
		if(s + a[i] < x) s += a[i];
		else ss ++, s = 0;
	}
	return (ss >= m);
}
void work2(){
	int l = 1, r = 1;
	for(int i = 1; i < n; i ++) r += a[i];
	while(l + 1 < r){ 
		int mid = (l + r) >> 1;//printf("%d %d %d\n", l, r, mid);
		if(check(mid)) l = mid;
		else r = mid;
	}
	printf("%d", l);
}
int b[N];
void work3(){
	sort(b + 1, b + n);
	int ans = (1<<30);
	for(int i = 1; i < n; i ++) ans = min(ans, b[i] + b[n - i]);
	printf("%d", ans);
}
int F;
int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	init();
	scanf("%d%d", &n, &m);
	for(int i = 1; i < n; i ++){
		int u, v, c;
		scanf("%d%d%d", &u, &v, &c);
		if(u > v) swap(u, v);
		if(u > 1) F = 1;
		insert(u, v, c);
		insert(v, u, c);
		a[u] = c;
		if(!F) b[i] = c; 
	}
	if(m == 1){
		work1();
	}else 
	if(!F){
		work3();	
	}
	else {
		work2();
	}
	return 0;
}
