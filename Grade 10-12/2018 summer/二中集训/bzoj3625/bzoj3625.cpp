#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<cmath>
#include<ctime>
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
int n,m,K;
ll A[600010],B[600010],C[600010],x[600010],y[600010];
int g=3,ginv,inv2,r[600010],lim,cnt;
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
		wn=qpow((type==1)?g:ginv,(MOD-1)/(mid<<1));
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
void getinv(ll *a,ll *b,int len,int lena){
//	cout<<"getinv "<<len<<' '<<lena<<'\n';
	if(len==1){b[0]=qpow(a[0],MOD-2);return;}
	assert(len==((len>>1)<<1));
	int i,mid=len>>1;
	getinv(a,b,mid,lena);
	lim=1;cnt=0;r[0]=0;
	while(lim<=(len<<1)) lim<<=1,cnt++;
	for(i=0;i<len;i++) x[i]=a[i];
	for(i=len;i<lim;i++) x[i]=0;
	for(i=0;i<mid;i++) y[i]=b[i];
	for(i=len;i<lim;i++) y[i]=0;
	for(i=0;i<lim;i++) r[i]=((r[i>>1]>>1)|((i&1)<<(cnt-1)));
	ntt(x,1);ntt(y,1);
	for(i=0;i<lim;i++) x[i]=y[i]*(2ll-y[i]*x[i]%MOD+MOD)%MOD;
	ntt(x,-1);
	for(i=0;i<len;i++) b[i]=x[i];
}
void getrt(ll *a,ll *b,int len){
//	cout<<"getrt "<<len<<'\n';
	if(len==1){b[0]=1;return;}
	int i,mid=len>>1;
	
	getrt(a,b,mid);
//	for(i=0;i<len;i++) cout<<i<<' '<<a[i]<<' '<<b[i]<<'\n';
	memset(C,0,sizeof(C));getinv(b,C,len,len);
	
	lim=1;cnt=0;r[0]=0;
	while(lim<=(len<<1)) lim<<=1,cnt++;
	for(i=0;i<lim;i++) r[i]=((r[i>>1]>>1)|((i&1)<<(cnt-1))),x[i]=a[i];
	for(i=len;i<lim;i++) x[i]=C[i]=b[i]=0;
//	for(i=0;i<len;i++) cout<<i<<' '<<a[i]<<' '<<b[i]<<' '<<C[i]<<'\n';
	
	ntt(x,1);ntt(C,1);
	for(i=0;i<lim;i++) x[i]=x[i]*C[i]%MOD;
	ntt(x,-1);
	
	for(i=0;i<len;i++) b[i]=add(b[i],x[i])*inv2%MOD;
//	for(i=0;i<len;i++) cout<<i<<' '<<a[i]<<' '<<x[i]<<' '<<b[i]<<'\n';
//	cout<<"end of getrt "<<len<<'\n';
}
void init(){
	ginv=qpow(g,MOD-2);
	inv2=qpow(2,MOD-2);
}
int main(){
//	freopen("7.in","r",stdin);
//	freopen("my.out","w",stdout); 
	init();
	n=read();m=read();int i,t1;A[0]=K=1;
//	ll c1=clock(),c2,c3,c4;
	for(i=1;i<=n;i++) t1=read(),A[t1]=dec(A[t1],4);
	while(K<=m) K<<=1;
//	c2=clock();
	getrt(A,B,K);
	B[0]=add(B[0],1);
//	c3=clock();
	memset(C,0,sizeof(C));
	getinv(B,C,K,K);
//	c4=clock();
//	cout<<c2-c1<<' '<<c3-c2<<' '<<c4-c3<<' '<<K<<'\n';
	for(i=1;i<=m;i++) printf("%lld\n",(2*C[i]+MOD)%MOD);
}

