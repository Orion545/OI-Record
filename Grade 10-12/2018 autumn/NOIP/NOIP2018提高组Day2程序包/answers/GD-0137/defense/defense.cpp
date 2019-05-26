#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#define N 105
#define inf 2147483647
using namespace std;
struct node{
	int a, b, c, n;
}d[N * 2];
int h[N], cnt, v[N], t[N], ans = inf, sum;
char o[N];
void cr(int a, int b){
	d[++cnt].a = a; d[cnt].b = b; d[cnt].n = h[a]; h[a] = cnt;
}
/*void dfs(int a, int f, int pre, int sum){
	if(ans <= sum) return;
	int i, b, fl = 0;
	for(i = h[a]; i; i = d[i].n){
		b = d[i].b;
		if(b == f) continue;
		fl = 1;
		if(t[b]){
			dfs(b, a, 1, sum);
		}
		else if(!pre){
			t[b] = 1;
			dfs(b, a, 1, sum + v[b]);
		}
		else if(pre){
			dfs(b, a, 1, sum + v[b]);
			dfs(b, a, 0, sum);
		}
	}
	if(!fl) ans = min(ans, sum);
}*/
int check(int a, int f){
	int i, b;
	for(i = h[a]; i; i = d[i].n){
		b = d[i].b;
		if(b == f) continue;
		if(!(t[a] | t[b])) return 0;
		if(!check(b, a)) return 0;
	}
	return 1;
}
int main(){
	freopen("defense.in", "r", stdin);
	freopen("defense.out", "w", stdout);
	int i, j, n, m, a, b, c, k, x, y, tot = 0;
	scanf("%d%d%s", &n, &m, o);
	for(i = 1; i <= n; i++) scanf("%d", &v[i]);
	for(i = 1; i < n; i++){
		scanf("%d%d", &a, &b);
		cr(a , b); cr(b , a);
	}
	for(i = 1; i <= m; i++){
		ans = inf;
		sum = tot = 0;
		scanf("%d%d%d%d", &a , &x, &b, &y);
		t[a] = x;
		if(x) sum += v[a];
		t[b] = y;
		if(y) sum += v[b];
		for(j = 0; j < (1 << n); j++){
			tot = 0;
			for(k = 0; k < n; k++){
				if((1 << k & j) && (k + 1 != a) && (k + 1 != b)){
					t[k + 1] = 1;
					tot += v[k + 1];
				}
			}
			if(check(1, 1)) ans = min(ans, sum + tot);
			memset(t, 0, sizeof(t));
		}
		t[a] = t[b] = 0;
		if(ans == inf) printf("-1\n");
		else printf("%d\n", ans);
	}
	return 0;
}
