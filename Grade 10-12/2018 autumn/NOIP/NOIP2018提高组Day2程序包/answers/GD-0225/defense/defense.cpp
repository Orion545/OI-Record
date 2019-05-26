#include <cstdio>
#include <vector>
#include <algorithm>
#define kN 100001
#define rep(i,x,y) for(int i=x;i<y;++i)
#define iter vector<int>::iterator
#define INF 10000000001
//          BA987654321
using std::vector;
using std::min;
typedef long long i64;
int n, m, a[kN], w[kN];
vector<int> adj[kN];
int qa, qx, qb, qy;
i64 dp[kN][2];
void dfs(int x, int fa=-1) {
	dp[x][0] = 0; dp[x][1] = w[x];
	//printf("<-- %d %d %lld %lld\n", x, fa, dp[x][0], dp[x][1]);
	for (iter i=adj[x].begin(); i!=adj[x].end(); ++i) {
		if (*i != fa) {
			dfs(*i, x);
			dp[x][0] += dp[*i][1];
			dp[x][1] += min(dp[*i][0], dp[*i][1]);
		}
			
	//	printf("zz %d %lld %lld\n", *i, dp[x][0], dp[x][1]);
	}
	//printf("- %d %lld %lld", x, dp[x][0], dp[x][1]);
	if (dp[x][0] > INF) dp[x][0] = INF;
	if (dp[x][1] > INF) dp[x][1] = INF;
	if (x == qa) {
		dp[x][qx^1] = INF;
	}
	else if (x == qb) {
		dp[x][qy^1] = INF;
	}
	//printf(" (%d %lld %lld)\n", x, dp[x][0], dp[x][1]);
}


int main() {
	freopen("defense.in", "r", stdin);
	freopen("defense.out", "w", stdout);
	char type_c; int type_i;
	scanf("%d %d %c%d", &n, &m, &type_c, &type_i);
	//printf("%d %d %c %d", n, m, type_c, type_i);
	rep(i, 1, n+1) {
		scanf("%d", w+i);
	}
	rep(i, 1, n) {
		int u, v;
		scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	rep(i, 1, n+1) {
		std::sort(adj[i].begin(), adj[i].end());
	}

	rep(i, 0, m) {
		scanf("%d%d%d%d", &qa, &qx, &qb, &qy);
		if (qx == 0 && qy == 0 &&
		    binary_search(adj[qa].begin(), adj[qa].end(), qb)) {
			puts("-1");
			continue;
		}
		int x=1;
		do {
			x = (x*23 % n) + 1;
		}while (x == qa || x == qb);
		//printf("--> %d\n", x);
		dfs(x);
		printf("%d\n", min(dp[x][0], dp[x][1]));
	}
	return 0;
}
