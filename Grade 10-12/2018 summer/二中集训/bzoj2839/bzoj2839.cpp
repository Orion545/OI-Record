#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<cmath>
#define ll long long
#define MOD 1000000007
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
ll f[1000010],finv[1000010],ppow2[1000010],n,k;
ll qpow(ll a,ll b){
	ll re=1;
	while(b){
		if(b&1) re=re*a%MOD;
		a=a*a%MOD;b>>=1;
	}
	return re;
}
void init(){
	ll i;f[0]=f[1]=finv[0]=finv[1]=1;
	for(i=2;i<=n;i++) f[i]=f[i-1]*i%MOD;
	finv[n]=qpow(f[n],MOD-2);
	for(i=n;i>2;i--) finv[i-1]=finv[i]*i%MOD;
	ppow2[0]=2;
	for(i=1;i<=n;i++) ppow2[i]=ppow2[i-1]*ppow2[i-1]%MOD;
}
ll C(ll x,ll y){
//	cout<<x<<' '<<y<<' '<<f[x]<<' '<<finv[y]<<' '<<finv[x-y]<<'\n';
	return f[x]*finv[y]%MOD*finv[x-y]%MOD;
}
int main(){
	n=read();k=read();ll ans=0,ch=1,i;
	init();
	for(i=k;i<=n;i++){
		ans=(ans+ch*C(i,k)*C(n,i)%MOD*(ppow2[n-i]-1)%MOD+MOD)%MOD;
		ch=-ch;
	}
	printf("%lld\n",ans);
}

