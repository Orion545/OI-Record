#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<cmath>
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
//1019663265=3*5*6793*10007 
ll fac[5]={0,3,5,6793,10007};
ll n,m,T,MOD,ans[210],tans[5][210];
ll f[5][10010],finv[5][10010],ff[1000010],ffinv[1000010];
struct node{
	ll x,y;
}x[210];
inline bool cmp(node l,node r){
	if(l.x!=r.x) return l.x<r.x;
	return l.y<r.y;
}
ll exgcd(ll a,ll b,ll &x,ll &y){
	if(!b){x=1;y=0;return a;}
	ll re=exgcd(b,a%b,x,y),tmp=x;
	x=y;y=tmp-(a/b)*y;
	return re;
}
ll CRT(ll num){
	ll re=0,lcm=MOD,i,kl,x,y;
	for(i=1;i<=4;i++){
		kl=MOD/fac[i];
		exgcd(kl,fac[i],x,y);
		x=(x%fac[i]+fac[i])%fac[i];
		re=(re+tans[i][num]*x*kl)%lcm; 
	}
	return re;
}
ll qpow(ll a,ll b,ll mod){
	ll re=1;
	while(b){
//		cout<<"qpow "<<a<<' '<<b<<' '<<re<<'\n';
		if(b&1) re=re*a%mod;
//	cout<<"check\n";
		a=a*a%mod;b>>=1;
//	cout<<"check\n";
	}
	return re;
}
void init(){
//	cout<<"begin init\n";
	ll len=1000002,i,k;
	ff[0]=ff[1]=ffinv[0]=ffinv[1]=1;
	for(i=2;i<=len;i++) ff[i]=ff[i-1]*i%(len+1);
	ffinv[len]=qpow(ff[len],(len+1)-2,len+1);
	for(i=len;i>2;i--) ffinv[i-1]=ffinv[i]*i%(len+1);
//	cout<<"finish phase 1\n";
	for(k=1;k<=4;k++){
		len=fac[k]-1;
		f[k][0]=f[k][1]=finv[k][0]=finv[k][1]=1;
		for(i=2;i<=len;i++) f[k][i]=f[k][i-1]*i%fac[k];
		finv[k][len]=qpow(f[k][len],fac[k]-2,fac[k]);
		for(i=len;i>2;i--) finv[k][i-1]=finv[k][i]*i%fac[k];
	}
//	cout<<"finish init\n";
}
ll Lucas(ll x,ll y){
	if(y>x) return 0;
	if(x<MOD) return ff[x]*ffinv[y]%MOD*ffinv[x-y]%MOD;
	return Lucas(x/MOD,y/MOD)*Lucas(x%MOD,y%MOD)%MOD;
}
ll Lucas1(ll x,ll y,ll t){
	if(y>x) return 0;
	if(x<fac[t]) return f[t][x]*finv[t][y]%fac[t]*finv[t][x-y]%fac[t];
	return Lucas1(x/fac[t],y/fac[t],t)*Lucas1(x%fac[t],y%fac[t],t)%fac[t];
}
int main(){
	init();
	n=read();m=read();T=read();MOD=read();ll i,j,k;ll tx,ty;
	for(i=1;i<=T;i++) x[i].x=read(),x[i].y=read();
	sort(x+1,x+T+1,cmp);
	T++;x[T]=(node){n,m};
	if(MOD==1019663265){
		for(i=1;i<=T;i++){
			for(k=1;k<=4;k++){
				tans[k][i]=Lucas1(x[i].x+x[i].y,x[i].x,k);
				for(j=1;j<i;j++){
					tx=x[i].x-x[j].x;ty=x[i].y-x[j].y;
					if(tx>=0&&ty>=0){
						tans[k][i]=(tans[k][i]-tans[k][j]*Lucas1(tx+ty,tx,k)%fac[k]+fac[k])%fac[k];
					}
				}
			}
		}
		ans[T]=CRT(T);
	}
	else{
		for(i=1;i<=T;i++){
			ans[i]=Lucas(x[i].x+x[i].y,x[i].x);
			for(j=1;j<i;j++){
				tx=x[i].x-x[j].x;ty=x[i].y-x[j].y;
				if(tx>=0&&ty>=0){
					ans[i]=(ans[i]-ans[j]*Lucas(tx+ty,tx)%MOD+MOD)%MOD;
				}
			}
		}
	}
	printf("%lld\n",ans[T]);
}

