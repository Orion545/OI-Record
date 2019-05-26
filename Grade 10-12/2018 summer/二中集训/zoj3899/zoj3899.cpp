#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<cmath>
#define ll long long
#define MOD 880803841 
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
struct segtree{
	ll a[400010],lazy[400010];
	void push(ll l,ll r,ll num){
		if(l==r||!lazy[num]) return;
		ll mid=(l+r)>>1;
		a[num<<1]=(mid-l+1)-a[num<<1];
		a[num<<1|1]=(r-mid)-a[num<<1|1];
		lazy[num<<1]^=1;lazy[num<<1|1]^=1;
		lazy[num]=0;
	}
	void update(ll num){
		a[num]=a[num<<1]+a[num<<1|1];
	}
	void change(ll l,ll r,ll ql,ll qr,ll num){
//		cout<<"change "<<l<<' '<<r<<' '<<ql<<' '<<qr<<' '<<num<<' '<<a[num]<<' '<<lazy[num]<<'\n';
		push(l,r,num);
		if(l>=ql&&r<=qr){a[num]=(r-l+1)-a[num];lazy[num]^=1;return;}
		ll mid=(l+r)>>1;
		if(mid>=ql) change(l,mid,ql,qr,num<<1);
		if(mid<qr) change(mid+1,r,ql,qr,num<<1|1);
		update(num);
//		cout<<"return change "<<l<<' '<<r<<' '<<a[num]<<'\n';
	}
	ll query(){
		return a[1];
	}
}Tr; 
ll f[100010],finv[100010];
ll qpow(ll a,ll b){
	ll re=1;
	while(b){
		if(b&1) re=re*a%MOD;
		a=a*a%MOD;b>>=1;
	}
	return re;
}
ll N,K;
void init(){
	ll i;f[0]=f[1]=finv[0]=finv[1]=1;
	for(i=2;i<=N;i++) f[i]=f[i-1]*i%MOD;
	finv[N]=qpow(f[N],MOD-2);
	for(i=N;i>2;i--) finv[i-1]=finv[i]*i%MOD;
}
ll F[100010];
struct NTT{
	ll g=26,ginv;
	ll A[400010],B[400010],r[400010],lim,cnt;
	ll add(ll x,ll y){
		x+=y;
		return (x>=MOD)?x-MOD:x;
	}
	ll dec(ll x,ll y){
		x-=y;
		return (x<0)?x+MOD:x;
	}
	void ntt(ll *a,ll type){
		ll i,j,k;ll x,y,w,wn,inv,mid;
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
	void solve(){
		ll i,ch=1;init();ginv=qpow(g,MOD-2);
		for(i=0;i<=K;i++) A[i]=(ch*finv[i]+MOD)%MOD,ch=-ch;
		for(i=0;i<=K;i++) B[i]=qpow(i,N)*finv[i]%MOD;
		lim=1;cnt=0;
		while(lim<=(K<<1)) lim<<=1,cnt++;
		for(i=0;i<lim;i++) r[i]=((r[i>>1]>>1)|((i&1)<<(cnt-1)));
		ntt(A,1);ntt(B,1);
		for(i=0;i<lim;i++) A[i]=A[i]*B[i]%MOD;
		ntt(A,-1);
		for(i=0;i<=K;i++) F[i]=A[i];
	}
}S;
void initial(){
	memset(f,0,sizeof(f));memset(finv,0,sizeof(finv));
	memset(Tr.a,0,sizeof(Tr.a));memset(Tr.lazy,0,sizeof(Tr.lazy));memset(F,0,sizeof(F));
	memset(S.A,0,sizeof(S.A));memset(S.B,0,sizeof(S.B));memset(S.r,0,sizeof(S.r));
}
int main(){
	ll T=read(),t1,t2,Q;
	while(T--){
		N=read();K=read();Q=read();
		initial();
		S.solve();Tr.change(1,K,1,K,1);
		while(Q--){
			t1=read();t2=read();
			Tr.change(1,K,t1,t2,1);
			printf("%lld\n",F[Tr.query()]);
//			cout<<"query "<<Tr.query()<<'\n';
		}
	}
}

