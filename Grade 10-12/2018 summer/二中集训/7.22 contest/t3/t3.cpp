#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<queue>
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
ll n,K,flag;
struct node{
	ll x,y,minx,miny,maxx,maxy,lc,rc;
}x[100010],a[100010];
inline bool operator <(node l,node r){
	if(flag) return l.x<r.x;
	else return l.y<r.y;
}
void update(ll pos){
	a[pos].maxx=a[pos].minx=a[pos].x;
	if(a[pos].lc) a[pos].maxx=max(a[pos].maxx,a[a[pos].lc].maxx);
	if(a[pos].rc) a[pos].maxx=max(a[pos].maxx,a[a[pos].rc].maxx);
	if(a[pos].lc) a[pos].minx=min(a[pos].minx,a[a[pos].lc].minx);
	if(a[pos].rc) a[pos].minx=min(a[pos].minx,a[a[pos].rc].minx);
	a[pos].maxy=a[pos].miny=a[pos].y;
	if(a[pos].lc) a[pos].maxy=max(a[pos].maxy,a[a[pos].lc].maxy);
	if(a[pos].rc) a[pos].maxy=max(a[pos].maxy,a[a[pos].rc].maxy);
	if(a[pos].lc) a[pos].miny=min(a[pos].miny,a[a[pos].lc].miny);
	if(a[pos].rc) a[pos].miny=min(a[pos].miny,a[a[pos].rc].miny);
}
ll build(ll l,ll r,ll f){
	ll mid=(l+r)>>1;flag=f;
	nth_element(x+l,x+mid,x+r+1);
	a[mid]=x[mid];
	if(mid>l) a[mid].lc=build(l,mid-1,f^1);
	if(mid<r) a[mid].rc=build(mid+1,r,f^1);
	update(mid);
//	cout<<"build "<<l<<' '<<r<<' '<<a[mid].x<<' '<<a[mid].maxx<<' '<<a[mid].minx<<' '<<a[mid].y<<' '<<a[mid].maxy<<' '<<a[mid].miny<<'\n'; 
	return mid;
}
priority_queue<ll,vector<ll>,greater<ll> >q;int cntq=0;
ll sqr(ll x){
	return x*x;
}
ll getdis(ll pos,ll qx,ll qy){
	ll re=0;
	re+=max(sqr(qx-a[pos].minx),sqr(a[pos].maxx-qx));
	re+=max(sqr(qy-a[pos].miny),sqr(a[pos].maxy-qy));
//	cout<<"getdis "<<pos<<' '<<qx<<' '<<qy<<' '<<re<<'\n';
	return re;
}
void query(ll pos,ll qx,ll qy){
	ll dl=-1,dr=-1,d=sqr(a[pos].x-qx)+sqr(a[pos].y-qy);
	if(cntq<K) ++cntq,q.push(d);
	else if(d>q.top()) q.pop(),q.push(d);
	if(a[pos].lc) dl=getdis(a[pos].lc,qx,qy);
	if(a[pos].rc) dr=getdis(a[pos].rc,qx,qy);
	if(dl>dr){
		if(a[pos].lc&&(cntq<K||dl>q.top())) query(a[pos].lc,qx,qy);
		if(a[pos].rc&&(cntq<K||dr>q.top())) query(a[pos].rc,qx,qy);
	}
	else{ 
		if(a[pos].rc&&(cntq<K||dr>q.top())) query(a[pos].rc,qx,qy);
		if(a[pos].lc&&(cntq<K||dl>q.top())) query(a[pos].lc,qx,qy);
	}
}
int main(){
	n=read();K=read();ll i;K<<=1;
	for(i=1;i<=n;i++) x[i].x=read(),x[i].y=read();
	ll root=build(1,n,1);
	for(i=1;i<=n;i++) query(root,a[i].x,a[i].y);
	printf("%lld\n",q.top());
}
