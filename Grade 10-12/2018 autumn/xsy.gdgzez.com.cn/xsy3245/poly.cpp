#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MOD 1004535809
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
ll add(ll a,ll b){
	a+=b;
	return ((a>=MOD)?a-MOD:a);
}
ll dec(ll a,ll b){
	a-=b;
	return ((a<0)?a+MOD:a);
}
ll g=3,ginv;
namespace NTT{
	int lim,cnt,r[400010];
	ll A[400010],B[400010];
	void ntt(ll *a,ll type){
		int i,j,k,mid;ll x,y,w,wn,inv;
		for(i=0;i<lim;i++) if(i<r[i]) swap(a[i],a[r[i]]);
		for(mid=1;mid<lim;mid<<=1){
			wn=qpow(((~type)?g:ginv),(MOD-1)/(mid<<1));
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
	void init(int n){
		int i;
		lim=1;cnt=0;
		while(lim<=n) lim<<=1,cnt++;
		for(i=0;i<lim;i++) r[i]=((r[i>>1]>>1)|((i&1)<<(cnt-1))),A[i]=B[i]=0;
	}
}
void mul(){
	using namespace NTT;
	ntt(A,1);ntt(B,1);int i;
	for(i=0;i<lim;i++) A[i]=A[i]*B[i]%MOD;
	ntt(A,-1);
}
ll c[100010];
int n,k;ll v[100010],f[100010];
void solve(int l,int r){
	if(l==r){
		c[l]=MOD-v[l];
		return;
	}
	int mid=(l+r)>>1,i;
	solve(l,mid);solve(mid+1,r);
	using namespace NTT;
	init(r-l+1);
	for(i=0;i<=mid-l;i++) A[i]=c[i+l];
	for(i=0;i<r-mid;i++) B[i]=c[i+mid+1];
	A[mid-l+1]=B[r-mid]=1;
	mul();
	for(i=0;i<=r-l;i++) c[l+i]=A[i];
}
int main(){
	n=read();k=read();int i,j;
//	cout<<"input check "<<n<<' '<<k<<'\n';
	g=3;ginv=qpow(3,MOD-2);
	for(i=1;i<=k;i++) v[i]=read();
	for(i=1;i<=k;i++) f[i]=read();
	solve(1,k);
	for(i=0;i<k;i++) c[i]=c[i+1];
	c[k]=1;
//	for(i=0;i<=k;i++) cout<<i<<' '<<c[i]<<'\n';
	for(i=0;i<=k;i++) if(c[i]) c[i]=MOD-c[i];
	for(i=0;i<=k/2;i++) swap(c[i],c[k-i]);
	for(i=k+1;i<=n;i++){
		ll w=0;
		for(j=1;j<=k;j++) w+=c[j]*f[i-j]%MOD;
		f[i]=w%MOD;
	}
	printf("%lld\n",f[n]);
}
