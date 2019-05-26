using namespace std;
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 100
#define MAXA 25000
int n;
int a[N+1],maxa;
int f[MAXA+1];
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int T;
	scanf("%d",&T);
	for (int bz=1;bz<=T;++bz){
		scanf("%d",&n);
		for (int i=1;i<=n;++i)
			scanf("%d",&a[i]);			
		sort(a+1,a+n+1);
		maxa=a[n];
		f[0]=bz;
		int ans=0;
		for (int i=1;i<=n;++i){
			if (f[a[i]]==bz)
				continue;
			ans++;
			for (int j=a[i];j<=maxa;++j)
				if (f[j-a[i]]==bz)
					f[j]=bz;
		}
		printf("%d\n",ans);
	}
	return 0;
}
