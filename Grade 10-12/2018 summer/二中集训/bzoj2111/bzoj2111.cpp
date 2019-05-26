#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<cmath>
#define ll long long
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
ll n,MOD,f[1000010],finv[1000010],inv[1000010];
void init(){
	int len=min(n,MOD-1),i;
	f[1]=finv[1]=finv[0]=f[0]=inv[1]=inv[0]=1;
	for(i=2;i<=len;i++) f[i]=f[i-1]*i%MOD;
	for(i=2;i<=len;i++) inv[i]=(MOD-MOD/i)*inv[MOD%i]%MOD;
	for(i=2;i<=len;i++) finv[i]=finv[i-1]*inv[i]%MOD;
}
ll C(ll x,ll y){
	if(y>x) return 0ll;
//	cout<<"C "<<x<<' '<<y<<' '<<f[x]<<' '<<finv[y]<<' '<<finv[x-y]<<' '<<f[x]*finv[y]%MOD*finv[x-y]%MOD<<'\n';
	return f[x]*finv[y]%MOD*finv[x-y]%MOD;
}
ll Lucas(ll x,ll y){
	if(y>x) return 0ll;
	if(x<MOD) return C(x,y);
	return Lucas(x/MOD,y/MOD)*Lucas(x%MOD,y%MOD)%MOD;
}
ll dp[1000010],siz[3000010];
int main(){
	n=read();MOD=read();int l,r,i;
	init();
	for(i=n;i>=1;i--){
		l=i<<1;r=(i<<1)+1;
		siz[i]=siz[l]+siz[r]+1;
		if(l>n) dp[i]=1;
		else if(r>n) dp[i]=dp[l];
		else dp[i]=dp[l]*dp[r]%MOD*Lucas(siz[i]-1,siz[l])%MOD;
//		cout<<i<<' '<<dp[i]<<' '<<siz[i]<<'\n';
	}
	printf("%lld\n",dp[1]);
}

