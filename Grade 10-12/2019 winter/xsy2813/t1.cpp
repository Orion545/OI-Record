#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#define MOD 998244353
#define g 3
#define ll long long
using namespace std;
inline int read(){
	int re=0,flag=1;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(isdigit(ch)) re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
ll qpow(ll a,ll b){
	ll re=1;
	while(b){
		if(b&1) re=re*a%MOD;
		a=a*a%MOD;b>>=1;
	}
	return re;
}
ll fac[10000010],finv[10000010],a[10000010];
int main(){
	ll n=read(),ans=0,i,f,inv4=qpow(4,MOD-2);
	ll w=qpow(3,(MOD-1)/4);
	ll w0=0,w1=(1-w+MOD)%MOD,w2=(1-w*w%MOD+MOD)%MOD,w3=(1-w*w%MOD*w%MOD+MOD)%MOD;
	ll v0=w0,v1=w1,v2=w2,v3=w3;
	w0=w1=w2=w3=1;
	fac[0]=fac[1]=finv[0]=finv[1]=1;a[1]=4;a[0]=2;
	for(i=2;i<=n;i++) fac[i]=fac[i-1]*i%MOD,a[i]=a[i-1]*a[i-1]%MOD;
	finv[n]=qpow(fac[n],MOD-2);
	for(i=n;i>2;i--) finv[i-1]=finv[i]*i%MOD;
	for(i=0;i<=n;i++){
		f=inv4*(w0+w1+w2+w3)%MOD*((i&1)?-1:1);
		f=(f+MOD)%MOD;
//		cout<<i<<' '<<f<<' '<<a<<' '<<inv4<<' '<<(w0+w1+w2+w3)<<' '<<inv4*(w0+w1+w2+w3)<<'\n';
		ans=(ans+f*(a[n-i]-1)%MOD*fac[n]%MOD*finv[i]%MOD*finv[n-i]%MOD)%MOD;
//		cout<<"tmpans "<<ans<<'\n';
		w0=w0*v0%MOD;
		w1=w1*v1%MOD;
		w2=w2*v2%MOD;
		w3=w3*v3%MOD;
//		cout<<w0<<' '<<w1<<' '<<w2<<' '<<w3<<'\n';
	}
//	cout<<"w "<<w<<'\n';
	cout<<ans%MOD+1<<'\n';
}
