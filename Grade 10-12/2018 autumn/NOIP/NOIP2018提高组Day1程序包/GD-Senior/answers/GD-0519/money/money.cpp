#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<ctime>
#include<queue>
#include<map>
#include<vector>
#define LL long long
#define N  105
#define A 25005
#define INF 0x3f3f3f3f
#define rep(i,a,b) for (int i = a; i <= b; ++i)
#define drep(i,a,b) for (int i = a; i >= b; -- i)
using namespace std;
int t,n,a[N],vis[A];
int main() {
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&t);
	while (t--) {
		int ans = 0;
		scanf("%d",&n);
		memset(vis,0,sizeof(vis));
		rep(i,1,n) {
			scanf("%d",&a[i]);
			vis[a[i]] = 2;
		}
		sort(a+1,a+n+1);
		rep(i,1,n) {
			if (vis[a[i]] == 1) continue;
			rep(j,1,a[n])
				rep(k,1,n) {
					if (a[k] > j)
						break;
					if (vis[j-a[k]]) {
						vis[j] = 1;
						break;
					}
				}
		}
		rep(i,1,n)
			if (vis[a[i]] != 1) ++ans;
		printf("%d\n",ans);
	}
	return 0;
}
/*
1
7
10 14 12 5 11 13 15
*/
