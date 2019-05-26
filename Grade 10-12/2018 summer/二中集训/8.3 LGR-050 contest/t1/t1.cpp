#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<cmath>
#define ll long long
#define MOD 998244353
using namespace std;
inline int read(){
	int re=0,flag=1;char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
int n,Q;ll a[2000010],f[10010],finv[10010];
ll qpow(ll a,ll b){
	ll re=1;
	while(b){
		if(b&1) re=re*a%MOD;
		a=a*a%MOD;b>>=1;
	}
	return re;
}
void init(){
	ll i;
	f[1]=f[0]=finv[1]=finv[0]=1;
	for(i=2;i<=10000;i++) f[i]=f[i-1]*i%MOD;
	finv[10000]=qpow(f[10000],MOD-2);
	for(i=10000;i>2;i--) finv[i-1]=finv[i]*i%MOD;
}
ll C(int x,int y){
	return f[x]*finv[y]%MOD*finv[x-y]%MOD;
}
int main(){
	init();int i,t1,t2;
	n=read();
	for(i=1;i<=n;i++) a[i]=read(),a[i+n]=a[i];
	Q=read();
	while(Q--){
		t1=read();t2=read();ll ans=0;
		for(i=t2;i<=t1+t2;i++){
			ans+=C(t1,i-t2)*a[i]%MOD;ans%=MOD;
		}
		printf("%lld\n",ans);
	}
}

