#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 110, E = 25100;
int T,n,a[N],f[E],ans;

int main() {
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	cin>>T;
	while (T--) {
		cin>>n;
		for (int i = 1; i <= n; i++) {
			scanf("%d",&a[i]);
		}
		sort(a+1,a+1+n);
		memset(f,0,sizeof f);
		f[0] = 1;
		ans = 0;
		for (int i = 1; i <= n; i++) if (!f[a[i]]) {
			ans++;
			for (int j = 1; j<E; j++) {
				if (j-a[i]>=0)
					f[j] |= f[j - a[i]];
			}
		}
		printf("%d\n",ans);
	}
}
