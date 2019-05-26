#include<cstdio>
#define INF 0x3f3f3f3f
#define min(a, b) (a > b ? b : a)
long long d[100010];
long long ans = 0;
void dfs(int l, int r, long long nowdep){
	if(l > r) return;
	if(l == r){
		ans += d[l] - nowdep;
		return;
	}
	long long minn = INF;
	for(int i = l; i <= r; i++)	minn = min(d[i], minn);
	ans += minn - nowdep;
	int lft = l;
	for(int i = l; i <= r; i++){
		if(minn == d[i]){
			dfs(lft, i - 1, minn);
			while(d[++i] == minn && i <= r);
			lft = i;
		}
	}
	if(lft <= r) dfs(lft, r, minn);
}
int n;
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &d[i]);
	}
	dfs(1, n, 0);
	printf("%lld", ans);
	fclose(stdin);
	fclose(stdout);
}
