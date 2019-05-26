#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cassert>
#define ll long long
#define MOD 998244353
using namespace std;
inline int read(){
	int re=0,flag=1;char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
double x[210],y[210];
int n;
ll qpow(ll a,ll b){
	if(b<0) return 0;
	ll re=1;
	while(b){
		if(b&1) re=re*a%MOD;
		a=a*a%MOD;b>>=1;
	}
	return re;
}
double getk(int l,int r){
	if(x[r]==x[l]) return 19260817;
	return (y[r]-y[l])/(x[r]-x[l]);
}
int main(){
	n=read();
	ll ans=qpow(2,n);int i,j,k,flag,tmp=0;
	for(i=1;i<=n;i++) x[i]=read(),y[i]=read();
	for(i=1;i<n;i++){
		for(j=i+1;j<n;j++){
//			cout<<i<<' '<<j<<' '<<flag<<'\n';
			tmp=0;
			for(k=j+1;k<=n;k++)	if(fabs(getk(i,j)-getk(j,k))<1e-6) tmp++;
//			cout<<"passed "<<i<<' '<<j<<' '<<tmp<<'\n';
			ans=(ans-qpow(2,tmp)+1+MOD)%MOD;
		}
	}
	printf("%lld\n",(ans-(n-1)*n/2-n-1+MOD)%MOD);
}
