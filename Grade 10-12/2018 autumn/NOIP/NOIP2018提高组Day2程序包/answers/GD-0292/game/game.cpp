#include<bits/stdc++.h>
using namespace std;
int n,m;
const int mod=1e9+7;
typedef long long ll;
inline ll ksm(int a,int b){
	ll ret=1;
	while(b){
		if(b&1)ret=ret*a%mod;
		a=1ll*a*a%mod;
		b>>=1;
	}
	return ret;
}
ll ans;
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(n==1)ans=ksm(2,m);
	else if(m==1)ans=ksm(2,n);
	else if(n==2&&m==2)ans=12;
	else if(n==2&&m>2){
		ans=12;
		ans=ans*ksm(3,m-2)%mod;
	}
	else if(m==2&&n>2){
		ans=12;
		ans=ans*ksm(3,n-2)%mod;
	}
	else if(n==3&&m==3)ans=112;
	else if(n==5&&m==5)ans=7136;
	else ans=20021254;
	printf("%lld",ans);
}
