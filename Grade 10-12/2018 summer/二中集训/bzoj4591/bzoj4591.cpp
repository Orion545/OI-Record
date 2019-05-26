#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<cmath>
#define ll long long
#define MOD 2333
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
ll f[3010],finv[3010],dp[2500][2500];
ll qpow(ll a,ll b){
	ll re=1;
	while(b){
		if(b&1) re=re*a%MOD;
		a=a*a%MOD;b>>=1;
	}
	return re;
}
ll C(ll x,ll y){
	if(y>x) return 0;
	return f[x]*finv[y]%MOD*finv[x-y]%MOD;
}
ll Lucas(ll x,ll y){
	if(y>x) return 0;
	if(y==0) return 1;
	return Lucas(x/MOD,y/MOD)*C(x%MOD,y%MOD)%MOD;
} 
void init(){
	ll i,j;
	f[1]=f[0]=finv[1]=finv[0]=1;
	for(i=2;i<MOD;i++) f[i]=f[i-1]*i%MOD;
	finv[MOD-1]=qpow(f[MOD-1],MOD-2);
	for(i=MOD-1;i>2;i--) finv[i-1]=finv[i]*i%MOD;
	for(i=0;i<MOD;i++){
		dp[i][0]=1;
		for(j=1;j<MOD;j++){
			dp[i][j]=(dp[i][j-1]+C(i,j))%MOD;
		}
	}
}
ll getans(ll x,ll y){
	if(y<0) return 0;
	if(x<MOD&&y<MOD) return dp[x][y];
	else return ((getans(x/MOD,y/MOD-1)*getans(x%MOD,MOD-1))%MOD+Lucas(x/MOD,y/MOD)*getans(x%MOD,y%MOD))%MOD;
}
int main(){
	init();
	ll T=read(),n,m;
	while(T--){
		n=read();m=read();
		printf("%lld\n",getans(n,m));
	}
}
