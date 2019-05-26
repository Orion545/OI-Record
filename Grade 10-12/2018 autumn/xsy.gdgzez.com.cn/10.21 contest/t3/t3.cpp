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
	while(!isdigit(ch)){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(isdigit(ch)) re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
ll n,Q,q[200010],dp;
ll seg[1000010],up[1000010],down[1000010],lazy[1000010];
void add(ll cur,ll val){
	if(seg[cur]==1e15) return;
	seg[cur]+=val;up[cur]+=val;down[cur]+=val;lazy[cur]+=val;
}
void update(ll cur){
	seg[cur]=min(seg[cur<<1],seg[cur<<1|1]);
	up[cur]=min(up[cur<<1],up[cur<<1|1]);
	down[cur]=min(down[cur<<1],down[cur<<1|1]);
}
void push(ll l,ll r,ll cur){
	if(l==r||!lazy[cur]) return;
	add(cur<<1,lazy[cur]);
	add(cur<<1|1,lazy[cur]);
	lazy[cur]=0;
	return;
}
void build(ll l,ll r,ll cur){
	if(l==r){seg[cur]=up[cur]=down[cur]=1e15;lazy[cur]=0;return;}
	ll mid=(l+r)>>1;
	build(l,mid,cur<<1);build(mid+1,r,cur<<1|1);
	update(cur);
}
void change(ll l,ll r,ll cur,ll pos,ll val){
	if(l==r){
		if(val<seg[cur]){seg[cur]=val;up[cur]=val+r;down[cur]=val-r;}
		return;
	}
	push(l,r,cur);
	ll mid=(l+r)>>1;
	if(mid>=pos) change(l,mid,cur<<1,pos,val);
	else change(mid+1,r,cur<<1|1,pos,val);
	update(cur);
}
ll query(ll l,ll r,ll ql,ll qr,ll cur,ll tp){
	if(ql>qr) return 1e15;
//	cout<<"query "<<l<<' '<<r<<' '<<ql<<' '<<qr<<' '<<cur<<' '<<tp<<' '<<seg[cur]<<' '<<up[cur]<<' '<<down[cur]<<'\n';
	if(l>=ql&&r<=qr) return (tp?up[cur]:down[cur]);
	push(l,r,cur);
	ll mid=(l+r)>>1,re=1e15;
	if(mid>=ql) re=min(re,query(l,mid,ql,qr,cur<<1,tp));
	if(mid<qr) re=min(re,query(mid+1,r,ql,qr,cur<<1|1,tp));
	return re;
}
int main(){
	n=read();Q=read();ll i,op1,op2;
	op1=read();op2=read();
	for(i=1;i<=Q;i++) q[i]=read();
	build(1,n,1);
	change(1,n,1,op1,abs(q[1]-op2));
	change(1,n,1,op2,abs(q[1]-op1));
	for(i=2;i<=Q;i++){
		dp=min(query(1,n,1,q[i],1,0)+q[i],query(1,n,q[i]+1,n,1,1)-q[i]);
		add(1,abs(q[i]-q[i-1]));change(1,n,1,q[i-1],dp);
//		cout<<"check seg1 "<<i<<' '<<seg[1]<<'\n';
	}
	printf("%lld\n",seg[1]);
}
