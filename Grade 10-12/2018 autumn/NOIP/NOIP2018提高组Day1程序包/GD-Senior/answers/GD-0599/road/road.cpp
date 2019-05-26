#include<cstdio>
#include<algorithm>
#define ll long long

using namespace std;

ll d[100100],n,ans;

int main(){
	freopen("road.in","r",stdin); 
	freopen("road.out","w",stdout);
	scanf("%lld",&n);
	for (ll i=1;i<=n;i++) scanf("%lld",&d[i]);
	ll i=1;
	while (d[i]!=0) {
		ll j=i,minn=d[i]; 
		while (d[j]!=0) minn=min(minn,d[j]),j++;
		j--;
		for (ll k=i;k<=j;k++) d[k]-=minn;
		ans+=minn;
		bool bo=true;
		for (ll k=i;k<=n&&bo;k++) {
			if (d[k]!=0) i=k,bo=false;
		}
	}
	printf("%lld\n",ans);
	fclose(stdin); fclose(stdout);
	return 0;
}
