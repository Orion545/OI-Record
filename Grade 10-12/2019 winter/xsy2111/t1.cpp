#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<cmath>
#define ll unsigned long long
using namespace std;
inline ll read(){
	ll re=0,flag=1;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(isdigit(ch)) re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
ll n,m,a[100010],ql[100010],qr[100010],belong[100010],blk,tot,sum[410][100010],add[100010],ans[410];
namespace BIT{
	ll a[100010];
	inline void add(ll x,ll val){
		if(!x) return;
		for(;x<=n;x+=(x&(-x))) a[x]+=val;
	}
	inline ll sum(ll x){
		ll re=0;if(!x) return 0;
		for(;x;x^=(x&(-x))) re+=a[x];
		return re;
	}
}
int main(){
	n=read();ll i,j,t1,t2,t3,re=0;
	blk=sqrt(n);tot=(n/blk)+(n%blk!=0);
	for(i=1;i<=n;i++) a[i]=read(),BIT::add(i,a[i]);
	for(i=1;i<=n;i++){
		ql[i]=read();qr[i]=read();
		belong[i]=(i/blk)+(i%blk!=0);
	}
	for(i=1;i<=tot;i++){
		memset(add,0,sizeof(add));
		for(j=(i-1)*blk+1;j<=min(i*blk,n);j++){
//			if(belong[j]!=i) cout<<"do "<<i<<' '<<j<<' '<<belong[j]<<'\n',fflush(stdout);
//			assert(belong[j]==i);
			add[ql[j]]++;add[qr[j]+1]--;
			ans[i]+=BIT::sum(qr[j])-BIT::sum(ql[j]-1);
		}
		for(j=1;j<=n;j++){
			add[j]+=add[j-1];
			sum[i][j]=add[j];
		}
	}
	m=read();
	while(m--){
		t1=read();t2=read();t3=read();
		if(t1==1){
			BIT::add(t2,-a[t2]);
			BIT::add(t2,t3);
			for(i=1;i<=tot;i++) ans[i]+=sum[i][t2]*(t3-a[t2]);
			a[t2]=t3;
		}
		else{
			re=0;
			if(belong[t2]==belong[t3]){
				for(i=t2;i<=t3;i++) re+=BIT::sum(qr[i])-BIT::sum(ql[i]-1);
			}
			else{
				for(i=belong[t2]+1;i<belong[t3];i++) re+=ans[i];
				for(i=t2;i<=belong[t2]*blk;i++) re+=BIT::sum(qr[i])-BIT::sum(ql[i]-1);
				for(i=(belong[t3]-1)*blk+1;i<=t3;i++) re+=BIT::sum(qr[i])-BIT::sum(ql[i]-1);
			}
			printf("%lld\n",re);
		}
	}
}
