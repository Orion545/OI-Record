#include <cstdio>
#include <algorithm>
using namespace std;
int d[200050],ans;
int dfs(int l,int r) {
	int mx=20000,i,ll=l;
	if (l==r) {
		ans+=d[l]; return 0;
	}
	for (i=l;i<=r;i++) mx=min(mx,d[i]);
	for (i=l;i<=r;i++) d[i]-=mx;
	ans+=mx;
	
	for (i=l;i<=r;i++) if (d[i]==0) {
//		printf("%d %d %d %d %d %d\n",ll,i,l,r,mx,ans);
		if (ll<=i-1) dfs(ll,i-1);
		ll=i+1;
	}
	if (ll<=r) dfs(ll,r);
	return 0;
}
int main() {
	int n,i;
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for (i=1;i<=n;i++) scanf("%d",&d[i]);
	dfs(1,n);
	printf("%d\n",ans);
}
