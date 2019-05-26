#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define LL long long
using namespace std;
const LL Maxn = 1000020;
const LL Mod = 1e9+7;
LL ans;
LL n, m;
LL f[Maxn], g[Maxn];
LL _max(LL x, LL y) { return x > y ? x : y; }
LL _min(LL x, LL y) { return x < y ? x : y; }
int main() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	LL i, j, k;
	scanf("%lld%lld", &n, &m);
	if(n > m) swap(n, m);
	for(i = 2; i <= n+m; i++){
		f[i] = 0; g[i] = 2;
		for(j = _max(1, i-m); j < _min(n, i-1); j++){
			if(j == 1 || i-j == 2) g[i]++;
			else if(j == 2 || i-j == 3) f[i]++;
		}
	}
	LL ret = 1;
	for(i = n+m-1; i >= 3; i--){
		LL p = g[i-1];
		if(p != i-1) p++;
		ans = (ans+ret*f[i]%Mod*p)%Mod;
		ret = ret*g[i]%Mod;
	}
	ans = (ans+ret)*4%Mod;
	printf("%lld\n", ans);
	return 0;
}
