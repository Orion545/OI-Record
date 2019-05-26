#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cassert>
#define ll long long
#define MOD 1000000007
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
ll qpow(ll a,ll b){
	ll re=1;
	while(b){
		if(b&1) re=re*a%MOD;
		a=a*a%MOD;b>>=1;
	}
	return re;
}
ll f[3000010],finv[3000010];
void init(){
	int i,len=3000000;f[0]=f[1]=finv[0]=finv[1]=1;
	for(i=2;i<=len;i++) f[i]=f[i-1]*i%MOD;
	finv[len]=qpow(f[len],MOD-2);
	for(i=len;i>2;i--) finv[i-1]=finv[i]*i%MOD;
}
ll C(ll x,ll y){
	if(x<abs(y)) return 0;
	y=((x-abs(y))>>1);
	if(x<y) return 0;
//	cout<<"C "<<x<<' '<<y<<' '<<f[x]*finv[y]%MOD*finv[x-y]%MOD<<'\n';
	return f[x]*finv[y]%MOD*finv[x-y]%MOD;
}
ll add(ll x,ll y){
	x+=y;
	return ((x>=MOD)?x-MOD:x);
}
int main(){
	int n=read(),m=read();
	init();
	int x=(n*2+m+1),y0,y1,y2;
	ll ans=C(x,m+1);
	for(y0=m+1,y1=-1,y2=m+2;x>=abs(y0);){
		y0=2*y1-y0;y2=2*y1-y2;
		ans=add(ans,MOD-C(x,y0));
		y0=2*y2-y0;y1=2*y2-y1;
		ans=add(ans,C(x,y0));
	}
	for(y0=m+1,y1=m+2,y2=-1;x>=abs(y0);){
		y0=2*y1-y0;y2=2*y1-y2;
		ans=add(ans,MOD-C(x,y0));
		y0=2*y2-y0;y1=2*y2-y1;
		ans=add(ans,C(x,y0));
	}
	printf("%lld\n",ans);
}
