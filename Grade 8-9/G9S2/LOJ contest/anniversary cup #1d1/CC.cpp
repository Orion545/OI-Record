#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
inline ll read(){
	ll re=0,flag=1;char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
ll MOD=998244353;
ll n,m,Q,p[3010],k[3010],q[3010],invp[3010];
ll gcd(ll x,ll y){
	if(y==0) return x;
	else return gcd(y,x%y);
}
ll lcm(ll x,ll y){
	return x/gcd(x,y)*y;
}
ll qpow(ll a,ll b){
	ll re=1;
	while(b){
		if(b&1) re=re*a%MOD;
		a=a*a%MOD;b>>=1;
	}
	return re;
}
int main(){
//	freopen("in.in","r",stdin);
//	freopen("my.out","w",stdout); 
	n=read();m=read();Q=read();ll i,j;
	ll inv6=qpow(6,MOD-2);
	for(i=1;i<=m;i++) p[i]=read(),k[i]=read(),invp[i]=qpow(p[i],MOD-2);
	for(i=1;i<=Q;i++){
//		cout<<i<<'\n';
		q[i]=read();ll ans=0,invq=qpow(q[i],MOD-2);
		for(j=1;j<=m;j++){
			ll tmp=lcm(q[i],p[j]);
//			cout<<i<<' '<<j<<' '<<tmp<<'\n';
			ll lim=n/tmp,tans=(tmp*tmp%MOD*k[j]%MOD*invq%MOD*invp[j]%MOD);
			ans=(ans+(tans*(lim*(lim+1)%MOD*(lim*2+1)%MOD*inv6%MOD)%MOD))%MOD;
		}
		printf("%lld\n",ans);
	}
}
