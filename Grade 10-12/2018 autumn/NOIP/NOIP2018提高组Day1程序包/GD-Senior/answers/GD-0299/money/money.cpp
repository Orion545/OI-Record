#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
bool b[25010];
int T,n,a[110],mx,ans;
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		ans=n;
		mx=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			mx=max(mx,a[i]);
		}
		sort(a+1,a+n+1);
		memset(b,0,sizeof(b));
		b[0]=1;
		for(int i=1;i<=n;i++){
			if(b[a[i]])ans--;
			for(int j=0;j<=mx;j++){
				if(j+a[i]>mx)break;
				if(b[j])b[j+a[i]]=1;
			}
		}
//		for(int i=1;i<=mx;i++)if(b[i])printf("%d ",i);
//		printf("\n");
		printf("%d\n",ans);
	}
}
