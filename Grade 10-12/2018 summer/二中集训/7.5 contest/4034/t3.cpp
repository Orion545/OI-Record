#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cassert>
#define ll long long
#define inf 1e15
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
ll n,Q,cnt,first[100010];
ll dep[100010],siz[100010],son[100010],pos[100010],fa[100010],top[100010],re[100010],clk;
ll x[100010],back[100010];
struct edge{
	ll to,next;
}a[200010];
inline void add(ll u,ll v){
	a[++cnt]=(edge){v,first[u]};first[u]=cnt;
	a[++cnt]=(edge){u,first[v]};first[v]=cnt;
}
void dfs1(ll u,ll f){
//	cout<<"dfs1 "<<u<<' '<<f<<'\n';
	ll i,v,maxn=0;son[u]=0;
	dep[u]=dep[f]+1;siz[u]=1;fa[u]=f;
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;
		if(v==f) continue;
		dfs1(v,u);
		siz[u]+=siz[v];
		if(maxn<siz[v]) maxn=siz[v],son[u]=v;
	}
}
void dfs2(ll u,ll t){
	ll i,v;
	pos[u]=++clk;top[u]=t;re[clk]=u;
	if(son[u]) dfs2(son[u],t);
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;
		if(v==fa[u]||v==son[u]) continue;
		dfs2(v,v);
	}
	back[u]=clk;
}
struct segtree{
	ll a[400010],lazy[400010];
	void push(ll l,ll r,ll num){
		if(!lazy[num]||l==r) return;
		ll son=num<<1,mid=(l+r)>>1;
		a[son]+=(mid-l+1)*lazy[num];lazy[son]+=lazy[num];
		a[son+1]+=(r-mid)*lazy[num];lazy[son+1]+=lazy[num];
		lazy[num]=0;
	}
	void build(ll l,ll r,ll num){
		if(l==r){
			a[num]=x[re[l]];return;
		}
		ll son=num<<1,mid=(l+r)>>1;
		build(l,mid,son);build(mid+1,r,son+1);
		a[num]=a[son]+a[son+1];
		return;
	}
	void add(ll l,ll r,ll ql,ll qr,ll num,ll t){
//		cout<<"add "<<l<<' '<<r<<' '<<ql<<' '<<qr<<' '<<num<<' '<<t<<'\n';
		push(l,r,num);
		if(l>=ql&&r<=qr){
			a[num]+=t*(r-l+1);lazy[num]+=t;
			return;
		}
		ll mid=(l+r)>>1,son=num<<1;
		if(mid>=ql) add(l,mid,ql,qr,son,t);
		if(mid<qr) add(mid+1,r,ql,qr,son+1,t);
		a[num]=(a[son]+a[son+1]);
	}
	ll query(ll l,ll r,ll ql,ll qr,ll num){
//		cout<<"query "<<l<<' '<<r<<' '<<ql<<' '<<qr<<' '<<num<<'\n';
		push(l,r,num);
		if(l>=ql&&r<=qr) return a[num];
		ll mid=(l+r)>>1,son=num<<1,re=0;
		if(mid>=ql) re+=query(l,mid,ql,qr,son);
		if(mid<qr) re+=query(mid+1,r,ql,qr,son+1);
//		cout<<"ret "<<l<<' '<<r<<' '<<re<<'\n';
		return re;
	}
}T;
ll ask(ll x){
	ll re=0;
	while(x){
		re+=T.query(1,n,pos[top[x]],pos[x],1);
		x=fa[top[x]];
	}
	return re;
}
int main(){
//	freopen("1.in","r",stdin);
//	freopen("my.out","w",stdout);
	memset(first,-1,sizeof(first));
	n=read();Q=read();ll i,t1,t2,t3;
	for(i=1;i<=n;i++) x[i]=read();
	for(i=1;i<n;i++){
		t1=read();t2=read();add(t1,t2);
	}
	dfs1(1,0);dfs2(1,1);
	T.build(1,n,1);
	while(Q--){
		t1=read();
		if(t1==1){
			t2=read();t3=read();
			T.add(1,n,pos[t2],pos[t2],1,t3);
		}
		if(t1==2){
			t2=read();t3=read();
			T.add(1,n,pos[t2],back[t2],1,t3);
		}
		if(t1==3){
			t2=read();
			printf("%lld\n",ask(t2));
		}
	}
}
