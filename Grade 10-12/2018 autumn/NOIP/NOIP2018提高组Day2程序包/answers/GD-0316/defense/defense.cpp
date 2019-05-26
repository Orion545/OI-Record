#include<cstdio>
#include<algorithm>
#include<cstring>
#define INF 500000000
using namespace std;

const int N=100000+5;

int n, m, p[N], a, x, b, y;
char s[10];

int cnt, to[N<<1], next[N<<1], first[N];
void add(int u, int v) {
	to[++cnt]=v; next[cnt]=first[u]; first[u]=cnt;
	to[++cnt]=u; next[cnt]=first[v]; first[v]=cnt;
}

int dp[N][2];
void dfs(int now, int from) {
	dp[now][0]=0; dp[now][1]=p[now];
	if(now==a) {
		if(x==0) dp[now][1]=INF;
		else dp[now][0]=INF;
	}
	if(now==b) {
		if(y==0) dp[now][1]=INF;
		else dp[now][0]=INF;
	}
	for(int i=first[now]; i; i=next[i]) if(to[i]!=from) {
		dfs(to[i], now);
		dp[now][0]=min(dp[now][0]+dp[to[i]][1], INF);
		dp[now][1]=min(min(dp[to[i]][0], dp[to[i]][1])+dp[now][1], INF);
	}
	return;
}

int main() {
	freopen("defense.in", "r", stdin);
	freopen("defense.out", "w", stdout);

	scanf("%d%d%s", &n, &m, &s);
	for(int i=1; i<=n; i++) scanf("%d", &p[i]);
	for(int i=1, u, v; i<n; i++) {
		scanf("%d%d", &u, &v);
		add(u, v);
	}
	if(s[0]=='A') {
		int sum[2];
		sum[0]=sum[1]=0;
		for(int i=1; i<=n; i++) sum[i&1]+=p[i];
		for(int i=1; i<=m; i++) {
			scanf("%d%d%d%d", &a, &x, &b, &y);
			if(((a&1)==(b&1))&&(x!=y)) printf("-1\n");
			else if(((a&1)!=(b&1))&&(x==y)) printf("-1\n");
			else {
				if(x==0) printf("%d\n", sum[(a&1)^1]);
				else printf("%d\n", sum[a&1]);
			}
		}
	}
	else {
		for(int i=1, ans; i<=m; i++) {
			scanf("%d%d%d%d", &a, &x, &b, &y);
			for(int i=1; i<=n; i++) dp[i][0]=dp[i][1]=INF;
			dfs(1, 0);
			ans=min(dp[1][0], dp[1][1]);
			printf("%d\n", ans==INF?-1:ans);
		}
	}

	fclose(stdin); fclose(stdout);
	return 0;
}

