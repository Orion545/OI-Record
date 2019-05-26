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
ll dep[100010],siz[100010],son[100010],pos[100010],fa[100010],top[100010],clk;
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
	pos[u]=++clk;top[u]=t;
	if(son[u]) dfs2(son[u],t);
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;
		if(v==fa[u]||v==son[u]) continue;
		dfs2(v,v);
	}
}
struct segtree{
	ll a[200010],lazy[200010];
	void push(ll l,ll r,ll num){
		if(!lazy[num]||l==r) return;
		ll son=num<<1,mid=(l+r)>>1;
		a[son]+=(mid-l+1)*lazy[num]%201314;lazy[son]+=lazy[num];
		a[son+1]+=(r-mid)*lazy[num]%201314;lazy[son+1]+=lazy[num];
		lazy[num]=0;
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
		a[num]=(a[son]+a[son+1])%201314;
	}
	ll query(ll l,ll r,ll ql,ll qr,ll num){
//		cout<<"query "<<l<<' '<<r<<' '<<ql<<' '<<qr<<' '<<num<<'\n';
		push(l,r,num);
		if(l>=ql&&r<=qr) return a[num]%201314;
		ll mid=(l+r)>>1,son=num<<1,re=0;
		if(mid>=ql) re+=query(l,mid,ql,qr,son);
		if(mid<qr) re+=query(mid+1,r,ql,qr,son+1);
//		cout<<"ret "<<l<<' '<<r<<' '<<re<<'\n';
		return re%201314;
	}
}T;
struct query{
	ll pos,ans,num,type,rk;
}q[200010];
bool cmp(query l,query r){
	return l.num<r.num;
}
bool cmp2(query l,query r){
	if(l.rk!=r.rk) return l.rk<r.rk;
	else return l.type<r.type;
}
void change(ll x){
//	cout<<"change "<<x<<'\n';
	ll f=top[x];
	while(x) T.add(1,n,pos[f],pos[x],1,1),x=fa[f],f=top[x];
}
ll ask(ll x){
//	cout<<"ask "<<x<<'\n';
	ll f=top[x],re=0;
	while(x) re+=T.query(1,n,pos[f],pos[x],1),re%=201314,x=fa[f],f=top[x];
//	cout<<"ret "<<re<<'\n';
	return re;
}
int main(){
	freopen("data.in","r",stdin);
	memset(first,-1,sizeof(first));
	n=read();Q=read();ll i,t1,t2,t3,j=1;
	for(i=1;i<n;i++){
		t1=read();
		add(i+1,t1+1);
	}
//	cout<<"finish in edge\n";
	dfs1(1,0);
//	cout<<"finish dfs \n";
	dfs2(1,1);
//	cout<<"finish dfs \n";
	for(i=1;i<=Q;i++){
		t1=read();t2=read();t3=read();
		q[i]=(query){t3+1,0,t1,-1,i};
		q[i+Q]=(query){t3+1,0,t2+1,1,i};
	}
	sort(q+1,q+Q+Q+1,cmp);
	while(q[j].num==0) j++;
	for(i=1;i<=n;i++){
		change(i);
//		cout<<i<<' '<<j<<' '<<q[j].num<<'\n';
		while(q[j].num==i) q[j].ans=ask(q[j].pos),j++;
	}
	sort(q+1,q+Q+Q+1,cmp2);
	for(i=1;i<=Q*2;i+=2){
//		cout<<q[i].ans<<' '<<q[i+1].ans<<'\n';
//		assert(q[i].ans>=0&&q[i+1].ans>=0);
//		assert(q[i].ans<=q[i+1].ans);
//		assert(q[i].rk==q[i+1].rk);
		printf("%lld\n",(q[i].ans*q[i].type+q[i+1].ans*q[i+1].type+201314)%201314);
	}
}
