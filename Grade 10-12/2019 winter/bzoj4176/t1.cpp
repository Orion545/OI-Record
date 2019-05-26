#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<unordered_map>
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
ll pri[1000010],cntp,mu[3000010],sum[3000010];bool vis[3000010];
void init(){
	ll i,j,k,len=2000000;
	mu[1]=1;
	for(i=2;i<=len;i++){
		if(!vis[i]) pri[++cntp]=i,mu[i]=-1;
		for(j=1;j<=cntp;j++){
			k=i*pri[j];if(k>len) break;
			vis[k]=1;
			if(i%pri[j]==0){mu[k]=0;break;}
			mu[k]=-mu[i];
		}
	}
	for(i=1;i<=len;i++) sum[i]=(sum[i-1]+mu[i]+MOD)%MOD;
}
unordered_map<ll,ll>mp;
ll c1(ll x){
	if(x<=2000000) return sum[x];
	if(mp[x]) return mp[x];
	ll i,j,re=1;
	for(i=2;i<=x;i=j+1){
		j=x/(x/i);
		re=(re-(j-i+1)*c1(x/i)%MOD+MOD)%MOD;
	}
	return mp[x]=re;
}
ll c2(ll x){
	ll re=0,i,j;
	for(i=1;i<=x;i=j+1){
		j=x/(x/i);
		re=(re+(j-i+1)*(x/i))%MOD;
	}
	return re*re%MOD;
}
int main(){
	init();
	ll n=read(),j,i,ans=0;
	for(i=1;i<=n;i=j+1){
		j=n/(n/i);
		ans=(ans+c2(n/i)*(c1(j)-c1(i-1))%MOD+MOD)%MOD;
	}
	cout<<ans<<'\n';
}
