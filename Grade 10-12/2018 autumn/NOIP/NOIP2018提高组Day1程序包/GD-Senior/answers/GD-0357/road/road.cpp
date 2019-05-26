#include <iostream>
#include <cstdio>
#include <algorithm>
#define ll long long
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ll n;
	scanf("%lld",&n);
	ll ans=0,lst=0;
	for (register int i=0;i<n;++i){
		ll t;
		scanf("%lld",&t);
		if (lst<t) ans+=(t-lst);
		lst=t;
	}
	printf("%lld\n",ans);
	return 0;
}
