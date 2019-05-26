#include <cstdio>
int ans,T,n,f[25005],g[25005];

int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&T);
	f[0]=1;
	while (T--){
		ans=0;
		for (int i=1; i<=25000; i++) f[i]=g[i]=0;
		scanf("%d",&n);
		for (int i=1,j; i<=n; i++) scanf("%d",&j),g[j]=1;
		for (int i=1; i<=25000; i++) if (!f[i] && g[i]){
			ans++;
			for (int j=i; j<=25000; j++) f[j]|=f[j-i];
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*
f[i]:	能否达到面值 i 
g[i]:	是否有面值 i 
*/
