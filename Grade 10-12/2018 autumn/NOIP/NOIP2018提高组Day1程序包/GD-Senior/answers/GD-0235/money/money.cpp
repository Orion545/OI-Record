#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int t,n,s,ma,a[200],bz[60010],f[60010],ans;
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		memset(bz,0,sizeof(bz));
		memset(f,0,sizeof(f));
		ma=ans=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			bz[a[i]]=1;
			if(ma<a[i]) ma=a[i];
		}
		for(int i=1;i<=ma;i++){
			if(bz[i]){
				for(int j=1;j<=n;j++){
					bz[i+a[j]]=f[i+a[j]]=1;
				}
			}
		}
		for(int i=1;i<=n;i++){
			if(!f[a[i]]) ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
