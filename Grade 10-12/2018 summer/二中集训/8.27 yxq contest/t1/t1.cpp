#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cassert>
#define ll __int128
#define MOD 999999999999999989
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
ll b,d,n;
ll qpow(ll a,ll b){
	ll re=1;
//	cout<<"qpow "<<a<<' '<<b<<'\n';
	while(b){
		if(b&1) re=re*a%MOD;
		a=a*a%MOD;b>>=1;
	}
//	cout<<"qpow "<<re<<'\n';
	return re;
}
ll f[1000010],finv[1000010];
void init(){
	int i,len=1000000;f[0]=f[1]=finv[0]=finv[1]=1;
	for(i=2;i<=len;i++) f[i]=f[i-1]*i%MOD;
	finv[len]=qpow(f[len],MOD-2);
	for(i=len;i>2;i--) finv[i-1]=finv[i]*i%MOD; 
}
ll C(ll x,ll y){
	return f[x]*finv[y]%MOD*finv[x-y]%MOD;
}
void print(ll x){
	if(!x) return;
	print(x/10);
	putchar(x%10+'0');
}
int main(){
	b=read();d=read();n=read();init();
	if(n==0){
		puts("1");return 0;
	}
	ll ans;
	ans=qpow(qpow(2,n-1),MOD-2);
	ll tmp=0;
	for(ll i=0;i<=n;i+=2){
		(tmp+=(qpow(b,n-i)*qpow(d,i>>1)%MOD*C(n,i)%MOD))%=MOD;
	}
	print(tmp*ans%MOD);
}
