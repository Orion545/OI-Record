#include <bits/stdc++.h>
using namespace std;
int T,n,ans,Maxx;
int a[200];
bool val[25010];
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		memset(val,0,sizeof(val));
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		sort(a+1,a+1+n); ans=n; Maxx=a[n];
		val[0]=1;
		for(int i=1;i<=n;i++){
			if(val[a[i]]){ans--;continue;}
			for(int j=0;j+a[i]<=Maxx;j++){
				if(val[j]) val[j+a[i]]=1;
			}
		} 
		printf("%d\n",ans);
	}
	return 0;
}
