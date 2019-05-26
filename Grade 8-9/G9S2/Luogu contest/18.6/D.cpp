#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define ll long long
#include<cassert>
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
ll n,K;
ll MOD=998244353;
ll ans=0,anss=1;
ll fac[50],times[50],cnt;
ll tmp[50];
ll f[1010],inv[1010],finv[1010];
ll f1[1010];
ll qpow(ll a,ll b){
	ll re=1;
	while(b){
		if(b&1) re=re*a%MOD;
		a=a*a%MOD;b>>=1;
	}
	return re;
}
void getf(){
	f[1]=inv[1]=finv[1]=1;f[0]=finv[0]=1;
	
	ll i;
	for(i=2;i<=1000;i++){
		inv[i]=(MOD-MOD/i)*inv[MOD%i]%MOD;
	}
	for(i=2;i<=1000;i++) f[i]=f[i-1]*i%MOD,finv[i]=finv[i-1]*inv[i]%MOD,assert(f[i]*finv[i]%MOD==1);
	
	f1[0]=1;
	for(i=1;i<=1000;i++) f1[i]=(K+i)%MOD*f1[i-1]%MOD;
}
void dfs(ll now,ll sum){
	if(now>cnt){
//		cout<<"dfs end "<<sum<<"\n";
		ll re=1;
		for(ll i=1;i<=cnt;i++){
			ll c=times[i]-tmp[i];
//			cout<<i<<' '<<c<<'\n';
//			re=(re*(f[c+K]*finv[c]%MOD)%MOD*finv[K]%MOD);
			re=(re*(f1[c]*finv[c]%MOD)%MOD);
//			cout<<re<<'\n';
		}
//		cout<<re<<'\n';
		ans=(ans+re)%MOD;
		return;
	}
	for(ll i=0;i<=times[now];i++){
		tmp[now]=i;
		dfs(now+1,sum*qpow(fac[now],i)%MOD);
	}
}
int main(){
	n=read();K=read();ll i,x=n,j;
	i=2;getf();bool flag=0;
//	ll tmp=sqrt(x);
//	if(tmp*tmp==x) flag=1,x=tmp;
//	cout<<x<<' '<<sqrt(x)<<'\n';
	while(i*i<=x){
		if(x%i){
			i++;continue;
		}
		fac[++cnt]=i;
		while(x%i==0) times[cnt]++,x/=i;
//		cout<<i<<' '<<times[cnt]<<'\n';
		i++;
	}
	if(x!=1) fac[++cnt]=x,times[cnt]=1;
//	if(flag){
//		for(i=1;i<=cnt;i++) times[cnt]*=2;
//	}
//	dfs(1,1);
//	for(i=1;i<=cnt;i++) cout<<i<<' '<<fac[i]<<' '<<times[i]<<'\n';
	for(i=1;i<=cnt;i++){
		x=0;
		for(j=0;j<=times[i];j++) x=(x+f1[j]*finv[j]%MOD)%MOD;
		anss=anss*x%MOD;
	}
	
//	cout<<ans;
	cout<<anss;
}
