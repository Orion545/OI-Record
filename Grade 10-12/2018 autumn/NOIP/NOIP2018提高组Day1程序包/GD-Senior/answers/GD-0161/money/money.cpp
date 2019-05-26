#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=110;
int T,n,ans,a[N],vis[25010];
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		memset(vis,0,sizeof(vis));
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",a+i);
		sort(a+1,a+n+1);
		n=unique(a+1,a+n+1)-(a+1);
		ans=n;
		if(a[1]==1){
			puts("1");
			continue;
		}
		for(int i=1;i<=n;i++){
			if(!vis[a[i]]){
				vis[a[i]]=1;
				for(int j=1;a[i]+j<=25000;j++){
					if(vis[j])
						vis[a[i]+j]=1;
				}
			}
			else ans--;
		}
		printf("%d\n",ans);
	}
	return 0;
}
