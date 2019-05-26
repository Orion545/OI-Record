#include<bits/stdc++.h>
using namespace std;
int t,n,a[200],i,j,ans;
bool f[60000];
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&t);
	while (t--) {
		memset(f,false,sizeof(f));
		f[0]=true;
		scanf("%d",&n);
		for (i=1;i<=n;i++) scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		ans=n;
		for (i=1;i<=n;i++) {
			if (f[a[i]]==true) ans--;
			else for (j=0;j<=a[n];j++) if (f[j]==true) f[j+a[i]]=true;
		}
		printf("%d\n",ans);
	}
}
