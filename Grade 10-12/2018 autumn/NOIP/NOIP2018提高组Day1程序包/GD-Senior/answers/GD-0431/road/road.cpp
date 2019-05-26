#include <stdio.h>
#include <string.h>
#define rep(i,st,ed) for (int i=st;i<=ed;++i)

const int N=200005;

int a[N],ans;

int main(void) {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n; scanf("%d",&n);
	rep(i,1,n) scanf("%d",&a[i]);
	rep(i,1,n) {
		if (a[i]>a[i-1]) ans+=a[i]-a[i-1];
	}
	printf("%d\n", ans);
	return 0;
}