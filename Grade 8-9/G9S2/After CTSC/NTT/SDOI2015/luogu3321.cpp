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
ll MOD=1004535809,G=3,invg;
ll n,m,x,tot,g,s[10010],f[100010],re[100010],ind[10010];
ll qpow(ll a,ll b,ll mod){
//	cout<<"qpow "<<a<<' '<<b<<' '<<mod<<'\n';
	ll re=1;
	while(b){
		if(b&1) re=re*a%mod;
		a=a*a%mod;b>>=1;
	}
//	cout<<"ret "<<re<<'\n';
	return re;
}
struct getg{
	ll pri[10010],cnt;bool vis[10010];
	ll fac[10010],cntfac;
	void init(){
//		cout<<"init\n";
		vis[1]=1;ll i,j,k,len=10000;cnt=0;
		for(i=2;i<=len;i++){
			if(!vis[i]) pri[++cnt]=i;
			for(j=1;j<=cnt;j++){
				k=i*pri[j];
				if(k>len) break;
				vis[k]=1;
				if(i%pri[j]==0) break;
			}
		}
	}
	void dec(ll x){
//		cout<<"dec "<<x<<'\n';
		ll i;cntfac=0;
		for(i=1;i<=cnt;i++){
			if(x%pri[i]==0){
				fac[++cntfac]=pri[i];
//				cout<<"	find "<<pri[i]<<'\n';
				while(x%pri[i]==0) x/=pri[i];
			}
		}
	}
	ll solve(ll x){
		init();dec(x-1);
		ll i,j,flag;
//		cout<<"finish init "<<x<<'\n';
		for(j=2;j<x;j++){
			flag=1;
			for(i=1;i<=cntfac;i++){
				if(qpow(j,(x-1)/fac[i],x)==1){
					flag=0;break;
				}
			}
			if(flag) return j;
//			system("pause");
		}
		return 0;
	}
}test;
int limit,cnt,r[100010];
void ntt(ll *a,ll type){
	int i,j,k,mid,len,inv=qpow(limit,MOD-2,MOD);ll y,w,wn;
	for(i=0;i<limit;i++) if(i<r[i]) swap(a[i],a[r[i]]);
	for(mid=1;mid<limit;mid<<=1){
		len=mid<<1;
		wn=qpow((type==1)?G:invg,(MOD-1)/len,MOD);
		for(j=0;j<limit;j+=len){
			w=1;
			for(k=0;k<mid;k++,w=w*wn%MOD){
				y=a[j+k+mid]*w%MOD;
				a[j+k+mid]=(a[j+k]-y+MOD)%MOD;
				a[j+k]=(a[j+k]+y)%MOD;
			}
		}
	}
	if(type==-1) for(i=0;i<limit;i++) a[i]=(a[i]*inv)%MOD;
}
void init(int siz){
	limit=1;cnt=0;memset(r,0,sizeof(r));
	while(limit<=(siz<<1)) limit<<=1,cnt++;
	for(int i=0;i<limit;i++) r[i]=((r[i>>1]>>1)|((i&1)<<(cnt-1)));
}
void fpow(int siz){
	int i;
	while(siz){
		if(siz&1){
			init(m);
			ntt(f,1);ntt(re,1);
			for(i=0;i<limit;i++) re[i]=re[i]*f[i]%MOD;
			ntt(f,-1);ntt(re,-1);
			for(i=m-1;i<((m-1)<<1);i++) re[i-m+1]=(re[i-m+1]+re[i])%MOD,re[i]=0;
		}
		init(m);
		ntt(f,1);
		for(i=0;i<limit;i++) f[i]=f[i]*f[i]%MOD;
		ntt(f,-1);
		for(i=m-1;i<((m-1)<<1);i++) f[i-m+1]=(f[i-m+1]+f[i])%MOD,f[i]=0;
//		for(i=0;i<m;i++) cout<<f[i]<<' ';cout<<'\n';
		siz>>=1;
	}
}
int main(){
	n=read();m=read();x=read();tot=read();g=test.solve(m);
//	cout<<"g="<<g<<'\n';
	int i;invg=qpow(G,MOD-2,MOD);
	for(i=0;i<m-1;i++) ind[qpow(g,i,m)]=i;
//	for(i=1;i<m;i++) cout<<ind[i]<<' ';cout<<'\n';
	for(i=1;i<=tot;i++){
		s[i]=read();
		if(s[i]) f[ind[s[i]]]=1;
	}
//	for(i=0;i<m;i++) cout<<f[i]<<' ';cout<<'\n';
//	init(m);ntt(f,1);ntt(f,-1);
//	for(i=0;i<m;i++) cout<<f[i]<<' ';cout<<'\n';
	re[0]=1;
	fpow(n);
	printf("%lld\n",re[ind[x]]);
}
