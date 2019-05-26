#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#define MOD 998244353
#define ll long long
using namespace std;
inline int read(){
	int re=0,flag=1;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(isdigit(ch)) re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
ll n,m,f[1000010],finv[1000010];
ll qpow(ll a,ll b){
	ll re=1;
	while(b){
		if(b&1) re=re*a%MOD;
		a=a*a%MOD;b>>=1;
	}
	return re;
}
void init(){
	ll i,len=n+m;
	f[0]=f[1]=finv[0]=finv[1]=1;
	for(i=2;i<=len;i++) f[i]=f[i-1]*i%MOD;
	finv[len]=qpow(f[len],MOD-2);
	for(i=len;i>2;i--) finv[i-1]=finv[i]*i%MOD;
}
ll C(ll y,ll x){
//	cout<<"C "<<x<<' '<<y<<' '<<f[x]<<' '<<finv[y]<<' '<<finv[x-y]<<'\n'; 
	return f[x]*finv[y]%MOD*finv[x-y]%MOD;
}
int main(){
	n=read();m=read();int i;ll ans=0;
	if(n<m) swap(n,m);
	init();
	for(i=1;i<=m;i++) (ans+=C(i,2*i)*C(n-i,n+m-2*i)%MOD)%=MOD;
	ans=ans*qpow(2*C(n,n+m)%MOD,MOD-2)%MOD;
//	cout<<ans<<'\n';
	ans=(ans+n+MOD)%MOD;
	cout<<ans;
}

