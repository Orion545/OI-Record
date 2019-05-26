#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define maxn 105
#define maxm 25010
using namespace std;

int T,n,i,j,k,a[maxn],f[maxm],bz[maxm],M,ans;

int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		memset(f,0,sizeof(f));
		memset(bz,0,sizeof(bz));
		sort(a+1,a+1+n);
		ans=n,M=0;
		for(i=1;i<=n;i++) M=max(M,a[i]),bz[a[i]]++;
		for(i=0;i<=M;i++){
			for(j=1;j<=n;j++) if (a[j]<i) f[i]|=f[i-a[j]]; else break;
			if (bz[i]){
				if (f[i]) ans-=bz[i];
				else f[i]=1;
			}
		}
		printf("%d\n",ans);
	}
}
