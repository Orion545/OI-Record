#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
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
const ll MOD=1e9+7;
ll f[20010],finv[20010],n,K,d;
ll qpow(ll a,ll b){
	ll re=1;
	while(b){
		if(b&1) re=re*a%MOD;
		a=a*a%MOD;b>>=1;
	}
	return re;
}
void init(){
	ll i;f[1]=f[0]=1;
	for(i=2;i<=n;i++) f[i]=f[i-1]*i%MOD;
	finv[n]=qpow(f[n],MOD-2);
	for(i=n-1;i>=0;i--) finv[i]=finv[i+1]*(i+1)%MOD;
}
ll C(ll y,ll x){
//	cout<<"C "<<y<<' '<<x<<' '<<f[x]*finv[y]%MOD*finv[x-y]%MOD<<'\n';
	return f[x]*finv[y]%MOD*finv[x-y]%MOD;
}
ll dp[20][20010];
int main(){
	n=read();K=read();d=read();
	init();K>>=1;
	ll i,j,k;
	dp[0][0]=1;
	for(i=0;i<15;i++){
		for(j=0;j<=n-(K<<1);j++){
			for(k=0;k*(d+1)<=K&&(j+k*(d+1)*(1<<i))<=n-(K<<1);k++){
//				cout<<"dp "<<i<<' '<<j<<' '<<k<<'\n';
				dp[i+1][j+k*(d+1)*(1<<i)]+=dp[i][j]*C(k*(d+1),K)%MOD;
				dp[i+1][j+k*(d+1)*(1<<i)]%=MOD; 
			}
		}
	}
	ll ans=0;
	for(i=0;i<=n-(K<<1);i++){
		ans=(ans+dp[15][i]*C(K,n-i-K))%MOD;
	} 
	cout<<(C(K*2,n)-ans+MOD)%MOD<<'\n';
}
