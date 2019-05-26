#include<bits/stdc++.h>
using namespace std;
const int maxn=210;
int a[maxn];
bool b[25010],re[maxn];
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		memset(b,0,sizeof(b));
		memset(re,0,sizeof(re));
		int n,ans;
		scanf("%d",&n);
		ans=n;
		for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
		sort(a+1,a+1+n);
		b[0]=1;
		for(int i=1;i<=n;++i){
			if(!re[i]){
				for(int j=a[i];j<=a[n];++j){
					b[j]=(b[j]||b[j-a[i]]);					
				}
				for(int j=i+1;j<=n;++j){
					if(!re[j]&&b[a[j]]){
						re[j]=1;
						--ans;
					}
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
