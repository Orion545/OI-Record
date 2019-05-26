#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cmath>
#include<cstring>
#define N 1000005
#define INF (1<<29)
using namespace std;
struct edge{
	int v, nxt;
}e[N];
int p[N], eid;
void init(){
	memset(p, -1, sizeof p);
	eid = 0;
}
void insert(int u, int v){
	e[eid].v =v ;
	e[eid].nxt = p[u];
	p[u] = eid ++;
}
int F = 0, f[N][2], n, m, A[N], vis[N], B[N][2];
void dfs(int x){
	vis[x] = 1;
	f[x][1] = A[x]; f[x][0] = 0;
	if(B[x][1]) f[x][1] = INF; if(B[x][0]) f[x][0] = INF;
	for(int i = p[x]; i + 1; i = e[i].nxt){
		int v = e[i].v;
		if(vis[v]) continue;
		dfs(v);
		f[x][1] += min(f[v][0], f[v][1]);
		f[x][0] += f[v][1];
	//	if(f[x][0] >= INF && !B[x][0]) F = 1, printf("***%d***", x);
	}
	vis[x] = 0;
}
void work1(){
	for(int i = 1; i <= m; i ++){
		int a, x, b, y;
		F = 0;
		scanf("%d%d%d%d", &a, &x, &b, &y);
		B[a][!x] = 1;
		B[b][!y] = 1; 
		dfs(1);
		//for(int j = 1; j <= n; j ++) printf("%d*%d\n", f[j][0], f[j][1]);
		if(min(f[1][1], f[1][0]) >= INF) printf("-1\n");
		else printf("%d\n", min(f[1][1], f[1][0]));
		B[a][!x] = 0;
		B[b][!y] = 0; 
	}
}
char c1;
int c2;
long long L[N][2], R[N][2]; 
void work2(){
	for(int i = 1; i <= n; i ++) L[i][1] = A[i] + min(L[i-1][1], L[i-1][0]), L[i][0] = L[i-1][1];
	for(int i = n; i >= 1; i --) R[i][1] = A[i] + min(R[i+1][1], R[i+1][0]), R[i][0] = R[i+1][1];
/*	for(int i = 1; i <= n; i ++) printf("%d ", L[i][0]); printf("\n");
	for(int i = 1; i <= n; i ++) printf("%d ", L[i][1]); printf("\n");
	for(int i = 1; i <= n; i ++) printf("%d ", R[i][0]); printf("\n");
	for(int i = 1; i <= n; i ++) printf("%d ", R[i][1]); printf("\n");*/
	for(int i = 1; i <= m; i ++){
		int a, x, b, y;
		scanf("%d%d%d%d", &a, &x, &b, &y);
		if(a > b) swap(a, b), swap(x, y);
		if(!x && !y) printf("-1\n");
		else{
			long long ans = 0;
			if(!x) ans += L[a-1][1]; else ans += L[a][1];
			if(!y) ans += R[b+1][1]; else ans += R[b][1];
			printf("%lld\n", ans);
		}
	}
}
void work3(){
	for(int i = 1; i <= n; i ++){
		L[i][1] = A[i] + min(L[i-1][1], L[i-1][0]), L[i][0] = L[i-1][1];
		if(i == 1) L[i][0] = INF;
	}
	for(int i = n; i >= 1; i --){
		R[i][1] = A[i] + min(R[i+1][1], R[i+1][0]), R[i][0] = R[i+1][1];
		if(i == 1) R[i][0] = INF;
	}
/*	for(int i = 1; i <= n; i ++) printf("%d ", L[i][0]); printf("\n");
	for(int i = 1; i <= n; i ++) printf("%d ", L[i][1]); printf("\n");
	for(int i = 1; i <= n; i ++) printf("%d ", R[i][0]); printf("\n");
	for(int i = 1; i <= n; i ++) printf("%d ", R[i][1]); printf("\n");*/
	for(int i = 1; i <= m; i ++){
		int a, x, b, y;
		scanf("%d%d%d%d", &a, &x, &b, &y);
		if(a > b) swap(a, b), swap(x, y);
		if(!x && !y) printf("-1\n");
		else{
			long long ans = 0;
		//	if(!x) ans += L[a-1][1]; else ans += L[a][1];
			if(!y) ans += R[b+1][1] + L[b][0]; else ans += R[b][1] + L[b][1] - A[b];
			printf("%lld\n", ans);
		}
	}
}
int FF;
int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	
	init();
	scanf("%d%d %c %d", &n, &m, &c1, &c2);
	for(int i = 1; i <= n; i ++) scanf("%d", &A[i]);
	for(int i = 1; i < n; i ++){
		int u, v;
		scanf("%d%d", &u, &v);
		if(u > v) swap(u, v);
		if(u + 1 != v) FF = 1;
		insert(u, v);
		insert(v, u);
	}
//	dfs(1);
	if(c1 == 'A' && c2 == 2) work2();
	else if(c1 == 'A' && c2 == 1) work3();
	else work1();
	

	return 0;
}
