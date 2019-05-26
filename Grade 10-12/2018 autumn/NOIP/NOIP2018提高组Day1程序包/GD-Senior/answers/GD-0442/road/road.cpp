#include<cstdio>
#include<algorithm>

#define ll long long
const ll maxn = 100005;
const ll INF = 0x3f3f3f3f3f3f3f3f;
ll a[maxn], n;

ll solve(ll l, ll r)
{
	if(l > r) return 0;
	ll ans = 0, minv = INF;
	for(ll i = l; i <= r; i++)
	{
		if(a[i] == 0) return solve(l, i - 1) + solve(i + 1, r);
		minv = std::min(minv, a[i]);
	}
	for(ll i = l; i <= r; i++) a[i] -= minv;
	ans = minv;
	ll pos = l;
	while(a[pos] != 0) pos++;
	ans = ans + solve(l, pos - 1) + solve(pos + 1, r);
	return ans;
}
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%lld", &n);
	for(ll i = 1; i <= n; i++)
	{
		scanf("%lld", &a[i]);
	}
	ll ans = solve(1, n);
	printf("%lld\n", ans);
	return 0;
}
