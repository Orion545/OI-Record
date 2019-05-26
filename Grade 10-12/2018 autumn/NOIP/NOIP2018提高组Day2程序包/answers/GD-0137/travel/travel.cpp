#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#define N 5005
using namespace std;
struct node{
	int a, b, c, n, i;
	bool operator < (const node & A) const{
		return b > A.b;
	}
}d[N * 2], e[N * 2];
int h[N * 2], v[N], p[N * 2], cc[N], cnt;
void cr(int i, int a, int b){
	e[i].a = a; e[i].b = b; e[i].n = p[a]; p[a] = i;
}
void cr1(int a, int b){
	d[++cnt].a = a; d[cnt].b = b; d[cnt].n = h[a]; h[a] = cnt;
}
void dfs(int a){
	int i, b;
	v[a] = 1;
	printf("%d ", a);
	for(i = h[a]; i; i = d[i].n){
		b = d[i].b;
		if(!v[b]) dfs(b);
	}
}
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int i, j, n, m, a, b;
	scanf("%d%d", &n, &m);
	if(m == n - 1){
		for(i = 1; i <= m; i++){
			scanf("%d%d", &a, &b);
			cr(i, a, b); cr(i + m, b, a);
		}
		for(i = 1; i <= n; i++){
			for(j = p[i]; j; j = e[j].n){
				a = i; b = e[j].b;
				cr1(a, b);
			}
			sort(d + h[i-1] + 1, d + h[i] + 1);
			//for(j = h[i-1] + 1; j <= h[i]; j++) printf("==%d %d\n", d[j].a, d[j].b);
		}
		m = cnt;
		cnt = 0;
		memset(h, 0, sizeof(h));
		for(i = 1; i <= m; i++){
			a = d[i].a; b = d[i].b;
			cr1(a, b);
		}
		dfs(1);
	}
	else{
		for(i = 1; i <= n; i++) printf("%d ", i);
	}
	return 0;
}
