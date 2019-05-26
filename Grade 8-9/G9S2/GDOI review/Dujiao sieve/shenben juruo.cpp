#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
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
ll MOD=1000000007,inv6=166666668;
ll phi[1000010],pri[100010],cnt,vis[1000010];
void init(){
	ll i,j,k,siz=1000000;phi[1]=1;
	for(i=2;i<=siz;i++){
		if(!vis[i]){pri[++cnt]=i;phi[i]=i-1;}
		for(j=1;j<=cnt;j++){
			k=i*pri[j];if(k>siz) break;
			vis[k]=1;
			if(i%pri[j]) phi[k]=phi[i]*phi[pri[j]]%MOD;
			else{phi[k]=phi[i]*pri[j]%MOD;break;}
		}
	}
	for(i=2;i<=siz;i++) phi[i]=phi[i-1]+phi[i]*i%MOD;
}
map<ll,ll>m;
ll S1(ll x){return x*(x+1)/2%MOD;}
ll S2(ll x){return x*(x+1)%MOD*(2ll*x+1)%MOD*inv6%MOD;}
ll S(ll x){
	if(x<=1000000) return phi[x];
	if(m[x]) return m[x];
	ll i,j,re=S2(x),tmp;
	for(i=2;i<=x;i=j+1){
		j=x/(x/i);
		tmp=S1(j)-S1(i-1);tmp=(tmp+MOD)%MOD;
		re-=tmp*S(x/i)%MOD;re=(re+MOD)%MOD; 
	} 
	return m[x]=(re+MOD)%MOD;
}
ll n;
int main(){
	n=read();init();
	printf("%lld\n%lld",1ll,S(n));
}
