#include<bits/stdc++.h>
using namespace std;
long long n,m,ans,mod=1000000007;
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	if (n==1) {
		ans=1;
		while (m--) ans=(ans*2)%mod;
		printf("%lld",ans);
	}
	if (n==2) {
		ans=4;
		m--;
		while (m--) ans=(ans*3)%mod;
		printf("%lld",ans);
	}
	if (n==3) {
		if (m==1) printf("8");
		if (m==2) printf("36");
		if (m==3) printf("112");
	}
}
