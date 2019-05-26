#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#define MOD 1000000007
#define ll long long
using namespace std;
inline ll read(){
	ll re=0,flag=1;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(isdigit(ch)) re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
ll n,m,f[100010],finv[100010];
ll qpow(ll a,ll b){
	ll re=1;
	while(b){
		if(b&1) re=re*a%MOD;
		a=a*a%MOD;b>>=1;
	}
	return re;
}
ll pri[100010],cntp,vis[100010],phi[100010],inv2;
void init(){
	ll i,j,k,len=100000;f[0]=f[1]=finv[0]=finv[1]=1;
	for(i=2;i<=len;i++) f[i]=f[i-1]*i%MOD;
	finv[len]=qpow(f[len],MOD-2);
	for(i=len;i>2;i--) finv[i-1]=finv[i]*i%MOD;
	phi[1]=1;vis[1]=0;
	for(i=2;i<=len;i++){
		if(!vis[i]) pri[++cntp]=i,phi[i]=i-1;
		for(j=1;j<=cntp;j++){
			k=i*pri[j];if(k>len) break;
			vis[k]=1;
			if(i%pri[j]==0){phi[k]=phi[i]*pri[j];break;}
			phi[k]=phi[i]*phi[pri[j]];
		}
	}
}
ll C(ll x,ll y){
	return f[x]*finv[y]%MOD*finv[x-y]%MOD;
}
ll sum(ll s,ll t,ll num){
//	cout<<"getsum "<<s<<' '<<t<<' '<<num<<' '<<((s+t)*num/2)%MOD<<'\n';
	return ((s+t)*num%MOD*inv2)%MOD;
}
int main(){
	inv2=qpow(2,MOD-2);
	init();
	n=read();m=read();ll i,j,ans=0;
	ans=(n*C(m,3)+m*C(n,3))%MOD;
//	cout<<ans<<'\n';
	if(n>m) swap(n,m);
	for(i=1;i<n;i++) ans=(ans+(2*phi[i]*sum(n-i,n-((n-1)/i)*i,(n-1)/i)%MOD*sum(m-i,m-((m-1)/i)*i,(m-1)/i)))%MOD;
//	cout<<ans<<'\n';
	ans=(ans-2*sum(n-1,1,n-1)%MOD*sum(m-1,1,m-1)%MOD+MOD)%MOD;
	cout<<ans<<'\n';
}
