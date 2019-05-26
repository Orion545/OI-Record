#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<cmath>
#define ll long long
#define MOD 1004535809
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
ll F[600010],G[600010],GINV[600010],H[600010],tmp[600010],x[600010],y[600010],r[600010],g=3,ginv;
int lim,cnt,n;
ll qpow(ll a,ll b){
	ll re=1;
	while(b){
		if(b&1) re=re*a%MOD;
		a=a*a%MOD;b>>=1; 
	}
	return re;
}
ll add(ll a,ll b){
	a+=b;
	return (a>=MOD)?a-MOD:a;
}
ll dec(ll a,ll b){
	a-=b;
	return (a<0)?a+MOD:a;
}
void ntt(ll *a,ll type){
	int i,j,k;ll x,y,w,wn,inv,mid;
	for(i=0;i<lim;i++) if(i<r[i]) swap(a[i],a[r[i]]);
	for(mid=1;mid<lim;mid<<=1){
		wn=qpow(((type==1)?g:ginv),(MOD-1)/(mid<<1));
		for(j=0;j<lim;j+=(mid<<1)){
			w=1;
			for(k=0;k<mid;k++,w=w*wn%MOD){
				x=a[j+k];y=a[j+k+mid]*w%MOD;
				a[j+k]=add(x,y);
				a[j+k+mid]=dec(x,y);
			}
		}
	}
	if(~type) return;
	inv=qpow(lim,MOD-2);
	for(i=0;i<lim;i++) a[i]=a[i]*inv%MOD;
}
void Solve(ll *a,ll *b,int len){
//	cout<<"Solve "<<len<<'\n';
	if(len==1){b[0]=qpow(a[0],MOD-2);return;}
	int i,mid=(len+1)>>1;
	Solve(a,b,mid);
	lim=1;cnt=0;memset(r,0,sizeof(r));
	while(lim<=(n+mid*2)) lim<<=1,cnt++;
	for(i=0;i<lim;i++) r[i]=((r[i>>1]>>1)|((i&1)<<(cnt-1))),x[i]=a[i],y[i]=b[i];
	ntt(x,1);ntt(y,1);
	for(i=0;i<lim;i++) x[i]=y[i]*y[i]%MOD*x[i]%MOD;
	ntt(x,-1);
	for(i=0;i<len;i++) b[i]=dec((b[i]<<1)%MOD,x[i]);
}
ll fac[130010],finv[130010];
void initf(){
	int i;fac[0]=fac[1]=finv[0]=finv[1]=1;
	for(i=2;i<=130000;i++) fac[i]=fac[i-1]*i%MOD;
	finv[130000]=qpow(fac[130000],MOD-2);
	for(i=130000;i>2;i--) finv[i-1]=finv[i]*i%MOD;
}
int main(){
	n=read();ll i,tmp;
	initf();ginv=qpow(g,MOD-2);
	G[0]=1;
	for(i=1;i<=n;i++){
		tmp=qpow(2,(i*(i-1)>>1)%(MOD-1));
		G[i]=tmp*finv[i]%MOD;H[i]=tmp*finv[i-1]%MOD;
	}
	Solve(G,GINV,n+1);
//	for(i=0;i<=n;i++) cout<<i<<' '<<G[i]<<' '<<H[i]<<' '<<GINV[i]<<'\n';
	lim=1;cnt=0;
	while(lim<=((n+1)<<1)) lim<<=1,cnt++;
	for(i=0;i<lim;i++) r[i]=((r[i>>1]>>1)|((i&1)<<(cnt-1)));
	ntt(GINV,1);ntt(H,1);
	for(i=0;i<lim;i++) F[i]=GINV[i]*H[i]%MOD;
	ntt(F,-1);
	printf("%lld\n",F[n]*fac[n-1]%MOD);
}

