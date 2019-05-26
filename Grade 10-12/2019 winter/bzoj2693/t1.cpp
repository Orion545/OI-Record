#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<cmath>
#define MOD 100000009
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
inline ll add(ll a,ll b){
	a+=b;
	if(a>=MOD) a-=MOD;
	return a;
}
ll pri[1000010],cntp,f[10000010],sum[10000010];bool vis[10000010];
void init(){
	ll i,j,k,len=10000000;
	f[1]=1;
	for(i=2;i<=len;i++){
		if(!vis[i]) pri[++cntp]=i,f[i]=(i*(1-i)%MOD+MOD)%MOD;
		for(j=1;j<=cntp;j++){
			k=i*pri[j];if(k>len) break;
			vis[k]=1;
			if(i%pri[j]==0){f[k]=f[i]*pri[j]%MOD;break;}
			else f[k]=f[i]*f[pri[j]]%MOD;
		}
	}
	for(i=1;i<=len;i++) sum[i]=add(sum[i-1],f[i]);
}
ll s(ll x){return (x*(x+1)/2)%MOD;}
int main(){
	ll T=read(),n,m,i,j,ans;
	init();
	while(T--){
		n=read();m=read();ans=0;
		if(n>m) swap(n,m);
		for(i=1;i<=n;i=j+1){
			j=min(n/(n/i),m/(m/i));
			ans=add(ans,s(n/i)*s(m/i)%MOD*(sum[j]-sum[i-1]+MOD)%MOD);
		}
		printf("%lld\n",ans);
	}
}
