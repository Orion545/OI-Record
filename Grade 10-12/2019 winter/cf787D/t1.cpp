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
	while(!isdigit(ch)){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(isdigit(ch)) re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
ll n,m,s,tot;
namespace g{
	ll first[1000010],cnte=-1,dis[1000010];
	struct edge{
		ll to,next,w;
	}a[3000010];
	void init(){memset(first,-1,sizeof(first));}
	inline void add(ll u,ll v,ll w){
//		cout<<"add "<<u<<' '<<v<<' '<<w<<'\n';
		a[++cnte]=(edge){v,first[u],w};first[u]=cnte;
	}
	struct node{
		ll pos,dis;
		inline bool operator <(const node &b)const{
			return dis>b.dis;
		}
	};
	priority_queue<node>q;
	void dij(){
		ll i,u,v,d;node tmp;
		for(i=1;i<=tot;i++) dis[i]=1e18;
		dis[s]=0;q.push((node){s,0});
		while(!q.empty()){
			tmp=q.top();q.pop();
			u=tmp.pos;d=tmp.dis;
//			cout<<"dij "<<u<<' '<<d<<'\n';
			assert(u);
			if(d!=dis[u]) continue;
			for(i=first[u];~i;i=a[i].next){
				v=a[i].to;if(dis[v]<=d+a[i].w) continue;
				dis[v]=d+a[i].w;
				q.push((node){v,dis[v]});
			}
		}
		for(i=1;i<=n;i++){
			if(dis[i]!=1e18) printf("%lld ",dis[i]);
			else printf("-1 ");
		}
	}
}
namespace seg1{
	ll seg[400010];
	void build(ll l,ll r,ll num){
		if(l==r){seg[num]=l;return;}
		ll mid=(l+r)>>1;seg[num]=++tot;
//		cout<<"build1 "<<l<<' '<<r<<' '<<seg[num]<<'\n';
		build(l,mid,num<<1);
		build(mid+1,r,num<<1|1);
		g::add(seg[num],seg[num<<1],0);
		g::add(seg[num],seg[num<<1|1],0);
	}
	void add1(ll l,ll r,ll ql,ll qr,ll num,ll from,ll val){
		if(l>=ql&&r<=qr){g::add(from,seg[num],val);return;}
		ll mid=(l+r)>>1;
		if(mid>=ql) add1(l,mid,ql,qr,num<<1,from,val);
		if(mid<qr) add1(mid+1,r,ql,qr,num<<1|1,from,val);
	}
}
namespace seg2{
	ll seg[400010];
	void build(ll l,ll r,ll num){
		if(l==r){seg[num]=l;return;}
		ll mid=(l+r)>>1;seg[num]=++tot;
//		cout<<"build2 "<<l<<' '<<r<<' '<<seg[num]<<'\n';
		build(l,mid,num<<1);
		build(mid+1,r,num<<1|1);
		g::add(seg[num<<1],seg[num],0);
		g::add(seg[num<<1|1],seg[num],0);
	}
	void add2(ll l,ll r,ll ql,ll qr,ll num,ll from,ll val){
		if(l>=ql&&r<=qr){g::add(seg[num],from,val);return;}
		ll mid=(l+r)>>1;
		if(mid>=ql) add2(l,mid,ql,qr,num<<1,from,val);
		if(mid<qr) add2(mid+1,r,ql,qr,num<<1|1,from,val);
	}
}
int main(){
	n=read();m=read();s=read();ll i,t5,t1,t2,t3,t4;tot=n;
	g::init();
	seg1::build(1,n,1);
	seg2::build(1,n,1);
	for(i=1;i<=m;i++){
		t5=read();
		t1=read();t2=read();t3=read();
		if(t5!=1) t4=read();
		if(t5==1) g::add(t1,t2,t3);
		if(t5==2) seg1::add1(1,n,t2,t3,1,t1,t4);
		if(t5==3) seg2::add2(1,n,t2,t3,1,t1,t4);
	}
	g::dij();
}
