#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#define MOD 10007
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
ll f[100010],finv[100010];
void init(){
	int i,len=MOD-1;
	f[0]=f[1]=finv[0]=finv[1]=1;
	for(i=2;i<=len;i++) f[i]=f[i-1]*i%MOD;
	finv[len]=qpow(f[len],MOD-2);
	for(i=len;i>2;i--) finv[i-1]=finv[i]*i%MOD;
//	cout<<f[2]<<' '<<finv[2]<<' '<<f[3]<<' '<<finv[3]<<' '<<finv[len]<<' '<<f[len]<<'\n';
}
ll C(ll x,ll y){
	if(x<y) return 0;
	return f[x]*finv[y]%MOD*finv[x-y]%MOD;
}
ll Lucas(ll x,ll y){
//	cout<<"Lucas "<<x<<' '<<y<<'\n';
	if(x<y) return 0;
	if(x<MOD) return C(x,y);
	return Lucas(x/MOD,y/MOD)*C(x%MOD,y%MOD)%MOD;
}
int main(){
	init();int T=read(),n,m;
	while(T--){
		n=read();m=read();
		cout<<Lucas(n,m)<<'\n';
	}
}
