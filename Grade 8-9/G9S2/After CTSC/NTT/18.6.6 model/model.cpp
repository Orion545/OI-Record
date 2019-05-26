#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
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
ll MOD=1004535809,g=3;
struct NTT{
	ll n,m,limit,cur,r[5000010],a[5000010],b[5000010],c[5000010],inv,ginv;
	ll qpow(ll a,ll b){
		ll re=1;
		while(b){
			if(b&1) re=re*a%MOD;
			a=a*a%MOD;b>>=1;
		}
		return re;
	}
	void init(){
		ginv=qpow(g,MOD-2);
		limit=1;cur=0;
		while(limit<=(n+m)) limit<<=1,cur++;
		for(int i=0;i<=limit;i++) r[i]=((r[i>>1]>>1)|((i&1)<<(cur-1)));
		inv=qpow(limit,MOD-2);
	}
	void ntt(ll *a,ll type){
		ll i,j,k,mid;ll y,w,wn;
		for(i=0;i<limit;i++) cout<<"begin "<<i<<' '<<a[i]<<'\n'; 
		for(i=0;i<limit;i++) if(i<r[i]) swap(a[i],a[r[i]]);
		for(mid=1;mid<limit;mid<<=1){
			wn=qpow((type==1)?g:ginv,(MOD-1)/(mid<<1));
			cout<<"	do "<<mid<<' '<<wn<<'\n';
			for(j=0;j<limit;j+=(mid<<1)){
				w=1;
				for(k=0;k<mid;k++,w=(w*wn)%MOD){
					y=a[j+k+mid]*w%MOD;
					a[j+k+mid]=(a[j+k]-y+MOD)%MOD;
					a[j+k]=(a[j+k]+y)%MOD;
				}
			}
		}
		for(i=0;i<limit;i++) cout<<i<<' '<<a[i]<<'\n';
		if(type==-1) for(i=0;i<limit;i++) a[i]=a[i]*inv%MOD,cout<<"finish "<<i<<' '<<a[i]<<'\n';;
	}
	void mul(){
		init();
		ntt(a,1);ntt(b,1);
		for(int i=0;i<limit;i++) c[i]=a[i]*b[i]%MOD;
		ntt(c,-1);
	}
}T;
int main(){
//	freopen("ntt.in","r",stdin);
//	freopen("my.out","w",stdout);
	T.n=read();T.m=read();ll i;
	for(i=0;i<=T.n;i++) T.a[i]=(read()+MOD)%MOD;
	for(i=0;i<=T.m;i++) T.b[i]=(read()+MOD)%MOD;
	T.mul();
	for(i=0;i<=T.n+T.m;i++) printf("%lld ",T.c[i]%MOD); 
}
