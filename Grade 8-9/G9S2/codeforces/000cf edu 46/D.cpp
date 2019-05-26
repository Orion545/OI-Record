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
ll n,dp[1010],f[1010],finv[1010],a[1010]; 
ll qpow(ll a,ll b){
	ll re=1;
	while(b){
		if(b&1) re=re*a%MOD;
		a=a*a%MOD;b>>=1;
	}
	return re;
}
void init(){
	ll i;f[1]=f[0]=finv[0]=1;
	for(i=2;i<=n;i++) f[i]=f[i-1]*i%MOD;
	finv[n]=qpow(f[n],MOD-2);
	for(i=n-1;i>=1;i--) finv[i]=finv[i+1]*(i+1)%MOD;
}
ll C(ll r,ll l){
//	cout<<"C "<<l<<' '<<r<<' '<<f[r]*finv[l]%MOD*finv[r-l]%MOD<<'\n';
	return f[r]*finv[l]%MOD*finv[r-l]%MOD;
}
int main(){
	n=read();ll i,j,ans=0;init();
	for(i=1;i<=n;i++) a[i]=read();
	dp[n+1]=1;
	for(i=n;i>=1;i--){
		dp[i]=0;
		if(a[i]<=0||a[i]>=(n-i+1)) continue;
//		cout<<i<<' '<<a[i]<<' '<<i+a[i]+1<<'\n';
		for(j=i+a[i]+1;j<=n+1;j++){
			dp[i]=(dp[i]+dp[j]*C(j-i-1,a[i])%MOD)%MOD;
		}
		ans+=dp[i];ans%=MOD;
	}
	cout<<ans;
}
