#include <bits/stdc++.h>
using namespace std;

int T, n, a[1000], ans;
bool b[50050];

int main() {
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&T);
	while (T--) {
		memset(b,0,sizeof(b));
		ans = 0;
		scanf("%d",&n);
		for (int i=1;i<=n;i++) scanf("%d",a+i);
		sort(a+1,a+n+1);
		b[0] = 1;
		for (int i=1;i<=n;i++) if (!b[a[i]]) {
			for (int j=0;j<=a[n]-a[i];j++) if (b[j]) b[j+a[i]] = 1;
			++ans;
		}
		printf("%d\n",ans);
	}
}
