#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
using namespace std;
int tt,n,a[110],h,t,s,bac[100010];
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&tt);
	while(tt--){
		s=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			s=max(s,a[i]);
		}
		int ans=0;
		memset(bac,0,sizeof(bac));
		bac[0]=1;
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++){
			if(bac[a[i]]){
				ans++;
				continue;
			}
			for(int j=a[i];j<=s;j++)
				bac[j]|=bac[j-a[i]];
		}
		printf("%d\n",n-ans);
	}
	return 0;
}
