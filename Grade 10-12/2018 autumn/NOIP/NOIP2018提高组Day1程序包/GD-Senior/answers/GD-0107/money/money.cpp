#include <cstdio>
#include <algorithm>
using namespace std;
int a[200],f[30000];
#define M 25000
int main() {
	int T,i,j,n,ans;
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout); 
	scanf("%d",&T);
	while (T--) {
		scanf("%d",&n); 
		for (i=1;i<=n;i++) scanf("%d",&a[i]); a[n+1]=0;
		sort(a+1,a+n+1);
		for (i=1,j=0;i<=n;i++) if (a[i]<a[i+1]) a[++j]=a[i];
		a[++j]=a[n]; n=j; ans=n;
		for (i=0;i<=M;i++) f[i]=0;
		for (i=1;i<=n;i++) 
		for (j=i;j<=n;j++) f[a[i]+a[j]]=1;
		for (i=0;i<=M;i++) for (j=1;j<=n;j++) if (i-a[j]>=0) 
			f[i]=f[i]|f[i-a[j]];
		for (i=1;i<=n;i++) if (f[a[i]]) ans--;
		printf("%d\n",ans);
	}
}
