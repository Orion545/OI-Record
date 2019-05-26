#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define inf 0x7fffffff
#define ll long long
using namespace std;
int n,q,x[200200],lazy[1001000];
ll b[1000100],a[1000100];
int read(){
	int re=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9'){
		re=re*10+(int)(ch-'0');ch=getchar();
	}
	return re;
}
ll readd(){
	ll re=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9'){
		re=re*10+(ll)(ch-'0');ch=getchar();
	}
	return re;
}
void build(int l,int r,int num){
	if(l==r){
		a[num]=b[num]=x[l];lazy[num]=0;return;
	}
	ll mid=(l+r)>>1,son=num<<1;
	build(l,mid,son);build(mid+1,r,son+1);
	a[num]=min(a[son],a[son+1]);
	b[num]=b[son]+b[son+1];
	return;
}
void clear(int l,int r,int num){
	if(l==r||!lazy[num]) return;
	ll son=num<<1,mid=(l+r)>>1;
	a[son]+=lazy[num];b[son]+=(mid-l+1)*lazy[num];
	a[son+1]+=lazy[num];b[son+1]+=(r-mid)*lazy[num];
	lazy[son]+=lazy[num];lazy[son+1]+=lazy[num];
	lazy[num]=0;
}
void change(int l,int r,int ql,int qr,int num,ll sig){
	ll mid=(l+r)>>1,son=num<<1;
	clear(l,r,num);
	if(l>qr||r<ql) return;
	if(l>=ql&&r<=qr){
		a[num]+=sig;b[num]+=(r-l+1)*sig;lazy[num]+=sig;
		return;
	}
	if(mid>=ql) change(l,mid,ql,qr,son,sig);
	if(mid<qr) change(mid+1,r,ql,qr,son+1,sig);
	a[num]=min(a[son],a[son+1]);
	b[num]=b[son]+b[son+1];
}
ll qsum(int l,int r,int ql,int qr,int num){
	ll mid=(l+r)>>1,son=num<<1,re=0;
	clear(l,r,num);
	if(l>qr||r<ql) return 0;
	if(l>=ql&&r<=qr) return b[num];
	if(mid>=ql) re+=qsum(l,mid,ql,qr,son);
	if(mid<qr) re+=qsum(mid+1,r,ql,qr,son+1);
	return re;
}
ll qmin(int l,int r,int ql,int qr,int num){
	ll mid=(l+r)>>1,son=num<<1,re=inf;
	clear(l,r,num);
	if(l>qr||r<ql) return inf;
	if(l>=ql&&r<=qr) return a[num];
	if(mid>=ql) re=min(re,qmin(l,mid,ql,qr,son));
	if(mid<qr) re=min(re,qmin(mid+1,r,ql,qr,son+1));
	return re;
}
int main(){
	freopen("haybales.in","r",stdin);
	freopen("haybales.out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,t2,t3;ll t4;char t1;
	n=read();q=read();
	for(i=1;i<=n;i++) x[i]=read();
	build(1,n,1);
	for(i=1;i<=q;i++){
		t1=getchar();
		while(t1!='M'&&t1!='P'&&t1!='S') t1=getchar(); 
		if(t1=='M'){
			t2=read();t3=read();
			cout<<qmin(1,n,t2,t3,1)<<endl;
		}
		if(t1=='S'){
			t2=read();t3=read();
			cout<<qsum(1,n,t2,t3,1)<<endl;
		}
		if(t1=='P'){
			t2=read();t3=read();t4=readd();
			change(1,n,t2,t3,1,t4);
		}
	}
}
