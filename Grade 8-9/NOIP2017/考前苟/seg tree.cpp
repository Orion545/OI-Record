#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
ll n,m,MOD,x[100010],a[400010],lazy1[400010],lazy2[400010]; 
inline ll read(){
	ll re=0,flag=1;char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') re=re*10+ch-'0',ch=getchar();
	return re;
}
void build(ll l,ll r,ll num){
	lazy1[num]=0;lazy2[num]=1;
	if(l==r){
		a[num]=x[l];return;
	}
	ll mid=(l+r)>>1,son=num<<1;
	build(l,mid,son);build(mid+1,r,son+1);
	a[num]=(a[son]+a[son+1])%MOD;
	return;
}
void clear(ll l,ll r,ll num){
	if(!lazy1[num]&&lazy2[num]==1) return;
	if(l==r){
		lazy1[num]=0;lazy2[num]=1;return;
	}
//	cout<<"clear "<<l<<ends<<r<<ends<<a[num]<<ends<<lazy1[num]<<ends<<lazy2[num]<<endl;
	ll mid=(l+r)>>1,son=num<<1;
	a[son]*=lazy2[num];
	a[son]%=MOD;
	a[son]+=lazy1[num]*(mid-l+1);
	a[son]%=MOD;
	a[son+1]*=lazy2[num];
	a[son+1]%=MOD;
	a[son+1]+=lazy1[num]*(r-mid);
	a[son+1]%=MOD;
	lazy2[son]*=lazy2[num];
	lazy2[son]%=MOD;
	lazy1[son]*=lazy2[num];
	lazy1[son]%=MOD;
	lazy1[son]+=lazy1[num];
	lazy1[son]%=MOD;
	lazy2[son+1]*=lazy2[num];
	lazy2[son+1]%=MOD;
	lazy1[son+1]*=lazy2[num];
	lazy1[son+1]%=MOD;
	lazy1[son+1]+=lazy1[num];
	lazy1[son+1]%=MOD;
	lazy1[num]=0;lazy2[num]=1;
	return;
}
ll query(ll l,ll r,ll ql,ll qr,ll num){
	clear(l,r,num);
//	cout<<"q "<<l<<ends<<r<<ends<<ql<<ends<<qr<<ends<<a[num]<<endl;
	if(l>=ql&&r<=qr) return a[num]%MOD;
	ll mid=(l+r)>>1,son=num<<1,re=0;
	if(mid>=ql) re+=query(l,mid,ql,qr,son);
	if(mid<qr) re+=query(mid+1,r,ql,qr,son+1);
	return re%MOD;
}
void change1(ll l,ll r,ll ql,ll qr,ll num,ll w){
	clear(l,r,num);
//	cout<<"c1 "<<l<<ends<<r<<ends<<ql<<ends<<qr<<ends<<a[num]<<ends<<w<<endl;
	if(l>=ql&&r<=qr){
		a[num]+=(r-l+1)*w;lazy1[num]+=w;return;
	}
	ll mid=(l+r)>>1,son=num<<1;
//	cout<<"do "<<mid<<endl;
	if(mid>=ql) change1(l,mid,ql,qr,son,w);
	if(mid<qr) change1(mid+1,r,ql,qr,son+1,w);
	a[num]=(a[son]+a[son+1])%MOD;
	return ;
}
void change2(ll l,ll r,ll ql,ll qr,ll num,ll w){
	clear(l,r,num);
//	cout<<"c2 "<<l<<ends<<r<<ends<<ql<<ends<<qr<<ends<<a[num]<<ends<<w<<ends<<lazy1[num]<<ends<<lazy2[num]<<endl;
	if(l>=ql&&r<=qr){
		a[num]*=w;a[num]%=MOD;
		lazy1[num]*=w;
		lazy2[num]*=w;
		return;
	}
	ll mid=(l+r)>>1,son=num<<1;
//	cout<<"do "<<mid<<endl;
	if(mid>=ql) change2(l,mid,ql,qr,son,w);
	if(mid<qr) change2(mid+1,r,ql,qr,son+1,w);
	a[num]=(a[son]+a[son+1])%MOD;
	return ;
}
int main(){
	ll i,t1,t2,t3,t4;
	n=read();m=read();MOD=read();
	for(i=1;i<=n;i++) x[i]=read();
	build(1,n,1);
	for(i=1;i<=m;i++){
		t1=read();
		if(t1==1){
			t2=read();t3=read();t4=read();
			change2(1,n,t2,t3,1,t4);
		}
		if(t1==2){
			t2=read();t3=read();t4=read();
			change1(1,n,t2,t3,1,t4);
		}
		if(t1==3){
			t2=read();t3=read();
			printf("%lld\n",query(1,n,t2,t3,1));
		}
	}
}
