#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<ctime>
#define MOD 1000000007
#define ll long long
using namespace std;
ll f[1000010],finv[1000010];
ll qpow(ll a,ll b){
	ll re=1;
	while(b){
		if(b&1) re=re*a%MOD;
		a=a*a%MOD;b>>=1;
	}
	return re;
}
void init(){
	int i,len=1000000;
	f[0]=f[1]=finv[0]=finv[1]=1;
	for(i=2;i<=len;i++) f[i]=f[i-1]*i%MOD;
	finv[len]=qpow(f[len],MOD-2);
	for(i=len;i>2;i--) finv[i-1]=finv[i]*i%MOD;
}
ll C(ll x,ll y){
	if(y>x) return 0;
	return f[x]*finv[y]%MOD*finv[x-y]%MOD;
}
int main(){
	int T;scanf("%d",&T);
	init();
	while(T--){
		ll n,m,k;int x;ll ans=0;
		scanf("%lld%lld%lld",&n,&m,&k);
		for(x=0;x<=m;x++){
			(ans+=C(m,x)*C(n-m+2*x,k)%MOD)%=MOD;
		}
		printf("%lld\n",ans);
	}
}
