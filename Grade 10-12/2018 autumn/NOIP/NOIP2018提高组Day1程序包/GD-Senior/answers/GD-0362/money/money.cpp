#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;
const int N=105;
bool cmp(int a,int b) { return a<b; }
int a[N];
bool v[N],f[25010];
int main() {
	freopen("money.in","r",stdin); freopen("money.out","w",stdout);
	int T; scanf("%d",&T);
	while(T--) {
		int n; scanf("%d",&n); int mx=0;
		for(int i=1;i<=n;i++) { scanf("%d",&a[i]); mx=max(mx,a[i]); }
		sort(a+1,a+1+n,cmp); int ans=n;
		memset(f,false,sizeof(f)); f[0]=true;
		for(int i=1;i<=n;i++) {
			if(f[a[i]]==true) {
				ans--; continue;
			}
			for(int j=a[i];j<=mx;j++) if(f[j-a[i]]==true) f[j]=true;
		}
		printf("%d\n",ans);
	}
	return 0;
}
