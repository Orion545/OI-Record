#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<ctime>
#define LL long long
#define N  100005
#define INF 0x3f3f3f3f
#define rep(i,a,b) for (int i = a; i <= b; ++i)
#define drep(i,a,b) for (int i = a; i >= b; -- i)
using namespace std;
int n,a[N],tot = 0;
LL d[N];
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	d[0] = 0;
	rep(i,1,n) {
		scanf("%lld",&d[i]);
		if (d[i] > d[i-1])
			a[++tot] = i;
	}
	LL ans = 0;
	rep(i,1,tot) ans += d[a[i]] - d[a[i]-1];
	printf("%lld\n",ans);
	return 0;
}
