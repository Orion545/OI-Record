#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

int T,a[10000];

int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&T);
	for (int lll=1;lll<=T;lll++) {
		int n;
		scanf("%d",&n);
		bool bo[70000];
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		int maxn=a[n];	int ans=1;
		for (int i=1;i<=maxn;i++) bo[i]=true;
		for (int i=1;i<=maxn;i++) if (i%a[1]==0) bo[i]=false;
		for (int i=1;i<=n;i++) if (bo[a[i]]) {
			ans++;
			bo[a[i]]=false;
			for (int j=1;j<=maxn;j++) if (bo[j]==false) bo[j+a[i]]=false;
		}
		printf("%d\n",ans);
	}
	fclose(stdin); fclose(stdout);
	return 0;
}
