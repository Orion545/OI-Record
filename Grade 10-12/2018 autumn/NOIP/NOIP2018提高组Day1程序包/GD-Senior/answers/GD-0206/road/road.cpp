#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const ll N=1e5+10;
ll a[N],n,m;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld",&n);
	ll ans=0;
	for(ll i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(i==1)continue;
		if(a[i]<a[i-1])ans+=a[i-1]-a[i];
	}
	ans+=a[n];
	printf("%lld",ans);
	return 0;
}
