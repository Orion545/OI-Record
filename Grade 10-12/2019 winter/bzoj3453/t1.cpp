#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#define MOD 1234567891
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
ll n,k,a,d,gy[210],fy[210];
inline ll qpow(ll a,ll b){
	ll re=1;
	while(b){
		if(b&1) re=re*a%MOD;
		a=a*a%MOD;b>>=1;
	}
	return re;
}
inline void add(ll &a,ll b){
	a+=b;
	if(a>=MOD) a-=MOD;
}
ll lag(ll val){
//	cout<<"lag "<<val<<'\n';
	ll i,j,re=0,tmp,inv[210]={0};
	for(i=1;i<=k+3;i++){
		inv[i]=1;
		for(j=1;j<=k+3;j++) if(i!=j) inv[i]=(inv[i]*(i-j)%MOD+MOD)%MOD;
		inv[i]=qpow(inv[i],MOD-2);
		tmp=inv[i]*gy[i]%MOD;
		for(j=1;j<=k+3;j++) if(i!=j) tmp=(tmp*(val-j)%MOD+MOD)%MOD;
		add(re,tmp);
	}
	return re;
}
ll lagf(ll val){
	ll i,j,re=0,tmp,inv[210]={0};
	for(i=1;i<=k+5;i++){
		inv[i]=1;
		for(j=1;j<=k+5;j++) if(i!=j) inv[i]=(inv[i]*(i-j)%MOD+MOD)%MOD;
		inv[i]=qpow(inv[i],MOD-2);
		tmp=inv[i]*fy[i]%MOD;
		for(j=1;j<=k+5;j++) if(i!=j) tmp=(tmp*(val-j)%MOD+MOD)%MOD;
		add(re,tmp);
	}
	return re;
}
int main(){
	ll T=read(),i,j;
	while(T--){
		k=read();a=read();n=read();d=read();
		memset(gy,0,sizeof(gy));
		memset(fy,0,sizeof(fy));
		for(i=1;i<=k+3;i++){
			gy[i]=0;
			for(j=1;j<=i;j++) add(gy[i],(i-j+1)*qpow(j,k)%MOD);
//			cout<<"get "<<i<<' '<<gy[i]<<'\n';
		}
		fy[0]=lag(a);
		for(i=1;i<=k+5;i++) fy[i]=(fy[i-1]+lag((a+i*d%MOD)%MOD))%MOD;
		cout<<lagf(n)<<'\n';
	}
}
