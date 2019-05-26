#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <utility>
#include <map>
#define LL long long
using namespace std;
const LL Maxn = 100010;
const LL inf = 1ll<<50; //
LL f[Maxn][2];
LL n, m, w[Maxn];
char s[10];
vector <LL> vec[Maxn];
LL xz[Maxn];
map <pair<LL, LL>, LL> mp;
LL _min(LL x, LL y) { return x < y ? x : y; }
void dfs(LL x, LL fa) {
	f[x][0] = f[x][1] = 0;
	for(LL i = 0; i < vec[x].size(); i++){
		LL y = vec[x][i];
		if(y == fa) continue;
		dfs(y, x);
		f[x][0] += f[y][1];
		f[x][1] += _min(f[y][0], f[y][1]);
	}
	f[x][1] += w[x];
	if(xz[x] == 1) f[x][0] = inf;
	if(xz[x] == 0) f[x][1] = inf;
}
int main() {
	freopen("defense.in", "r", stdin);
	freopen("defense.out", "w", stdout);
	LL i, j, k;
	scanf("%lld%lld", &n, &m);
	scanf("%s", s+1);
	for(i = 1; i <= n; i++) scanf("%lld", &w[i]);
	for(i = 1; i < n; i++){
		LL x, y;
		scanf("%lld%lld", &x, &y);
		vec[x].push_back(y);
		vec[y].push_back(x);
		mp[make_pair(x,y)] = mp[make_pair(y,x)] = 1;
	}
	for(i = 1; i <= n; i++) xz[i] = -1;
	for(i = 1; i <= m; i++){
		LL A, X, B, Y;
		scanf("%lld%lld%lld%lld", &A, &X, &B, &Y);
		if(A == B && X != Y){ printf("-1\n"); continue; }
		if(X == 0 && Y == 0 && mp.count(make_pair(A, B))){ printf("-1\n"); continue; }
		xz[A] = X; xz[B] = Y;
		dfs(1, 0);
		printf("%lld\n", _min(f[1][0], f[1][1]));
		xz[A] = -1; xz[B] = -1;
	}
	return 0;
}

