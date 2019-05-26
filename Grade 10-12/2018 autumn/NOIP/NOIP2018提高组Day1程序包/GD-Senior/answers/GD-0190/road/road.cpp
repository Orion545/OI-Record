#include <stdio.h>
#define N 100005
int x=1e9;
int n,m,i,j,k,a[N],f[1005][1005],h[1005][1005],v[1005][1005];
long long ans;
void dfs(int l,int r,int p,int q){
	v[l][r]=1;
	ans+=(f[l][r]-f[p][q]);//printf("hh %d %d %d %d %d\n",l,r,p,q,ans);
	if(l<=h[l][r]-1&&!v[l][h[l][r]-1])dfs(l,h[l][r]-1,l,r);
	if(h[l][r]+1<=r&&!v[h[l][r]+1][r])dfs(h[l][r]+1,r,l,r);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d", &n);
	if(n<=1000){
		for(i=1;i<=n;i++){
			scanf("%d", &a[i]);
			f[i][i]=a[i];
			h[i][i]=i;
			if(x>a[i])x=a[i],k=i;
		}
		for(i=1;i<=n;i++){
			for(j=i+1;j<=n;j++){
				if(f[i][j-1]>a[j]){
					f[i][j]=a[j];
					h[i][j]=j;
				}
				else f[i][j]=f[i][j-1],h[i][j]=h[i][j-1];
			}
		}
		dfs(1,n,0,0);
		printf("%lld",ans);
	}
	return 0;
}
