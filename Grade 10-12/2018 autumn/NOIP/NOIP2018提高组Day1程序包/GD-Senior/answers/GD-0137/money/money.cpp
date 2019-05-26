#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#define N 103
using namespace std;
int m, a[N], b[N], f[25005], v[25005], vis[N], ans = N, n, maxn;
int o[N];
int cmp(int x, int y){
	return x > y;
}
void dfs(int pos, int cnt){
	int i, j;
	if(ans <= cnt - 1) return;
	if(pos == n + 1){
		m = 0;
		for(i = 1; i <= n; i++) if(o[i]) b[++m] = a[i];
		for(i = 0; i <= maxn; i++) f[i] = 0;
		f[0] = 1;
		for(i = 1; i <= m; i++){
			for(j = b[i]; j <= maxn; j++) f[j] += f[j - b[i]];
		}
		for(i = 1; i <= n; i++) if(!f[a[i]]) return;
		ans = min(ans, m);
		return;
	}
	o[pos] = 1; dfs(pos + 1, cnt + 1);
	o[pos] = 0; dfs(pos + 1, cnt);
}
int main(){
	freopen("money.in", "r", stdin);
	freopen("money.out", "w", stdout);
	int i, j, T, l;
	scanf("%d", &T);
	while(T--){
		memset(f, 0, sizeof(f));
		memset(v, 0, sizeof(v));
		n = maxn = 0;
		scanf("%d", &l);
		ans = N;
		for(i = 1; i <= l; i++) scanf("%d", &a[i]), maxn = max(maxn, a[i]);
		sort(a + 1, a + 1 + l);
		for(i = 1; i <= l; i++){
			if(!v[a[i]]) v[a[i]] = 1, a[++n] = a[i];
		}
		dfs(1, 1);
		printf("%d\n", ans);
	}
	return 0;
}
