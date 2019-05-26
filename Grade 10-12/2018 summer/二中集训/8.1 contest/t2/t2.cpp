#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<map>
#include<cmath>
#define MOD 1000000007
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
ll pri[1000010],cntp,vis[1000010],mu[1000010];
void init(){
	ll i,j,k;vis[1]=mu[1]=1;
	for(i=2;i<=1000000;i++){
		if(!vis[i]) pri[++cntp]=i,mu[i]=-1;
		for(j=1;j<=cntp;j++){
			k=i*pri[j];if(k>1000000) break;
			vis[k]=1;
			if(i%pri[j]==0){mu[k]=0;break;}
			mu[k]=-mu[i];
		}
	}
	for(i=1;i<=1000000;i++) mu[i]+=mu[i-1];
} 
map<ll,ll>mp;
ll S(ll n){
	ll i,j;ll re=1;
	if(n<=1000000) return mu[n];
	if(mp[n]) return mp[n];
	for(i=2;i<=n;i=j+1){
		j=n/(n/i);
		re=(re-(ll)(j-i+1)*S(n/i)%MOD+MOD)%MOD;
	}
	return mp[n]=re;
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
	init();
	ll n=read(),k=read(),l=read(),r=read(),i,j;ll re=0;
	l=(l-1)/k;r=r/k;
	for(i=1;i<=r;i=j+1){
		j=r/(r/i);
		if(i<=l) j=min(j,l/(l/i));
		re+=(S(j)-S(i-1)+MOD)%MOD*qpow(r/i-l/i,n)%MOD;re%=MOD;
	}
	printf("%lld\n",re);
}

