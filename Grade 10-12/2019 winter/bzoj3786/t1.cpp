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
ll n,m,root,ori[200010];
namespace g{
	ll first[200010],cnte=-1;
	void init(){memset(first,-1,sizeof(first));}
	struct edge{
		ll to,next;
	}a[400010];
	inline void add(ll u,ll v){
		a[++cnte]=(edge){v,first[u]};first[u]=cnte;
	}
	ll in[200010],clk,out[200010],lis[200010];
	void dfs(ll u){
		ll i;in[u]=++clk;lis[clk]=u;
		for(i=first[u];~i;i=a[i].next) dfs(a[i].to);
		out[u]=++clk;lis[clk]=-u;
	}
}
namespace t{
	ll ch[400010][2],fa[400010],siz[400010],sum[400010],suf[400010],tag[400010],flag[400010],w[400010];
	//suf refers to "sum of flag"
	inline void update(ll cur){
		siz[cur]=siz[ch[cur][0]]+siz[ch[cur][1]]+1;
		suf[cur]=suf[ch[cur][0]]+suf[ch[cur][1]]+flag[cur];
		sum[cur]=sum[ch[cur][0]]+sum[ch[cur][1]]+flag[cur]*w[cur];
	}
	inline void push(ll cur){
		if(!tag[cur]) return;
		tag[ch[cur][0]]+=tag[cur];
		tag[ch[cur][1]]+=tag[cur];
		w[ch[cur][0]]+=tag[cur];
		w[ch[cur][1]]+=tag[cur];
		sum[ch[cur][0]]+=suf[ch[cur][0]]*tag[cur];
		sum[ch[cur][1]]+=suf[ch[cur][1]]*tag[cur];
		tag[cur]=0;
	}
	inline bool get(ll cur){return ch[fa[cur]][1]==cur;}
	inline void rotate(ll cur){
		ll f=fa[cur],ff=fa[f],son=get(cur);
//		cout<<"	rotate "<<cur<<' '<<f<<' '<<ff<<'\n';
		push(f);push(cur);
		ch[f][son]=ch[cur][son^1];
		if(ch[f][son]) fa[ch[f][son]]=f;
		fa[f]=cur;ch[cur][son^1]=f;
		fa[cur]=ff;
		if(ff) ch[ff][ch[ff][1]==f]=cur;
		else root=cur;
		update(f);update(cur);
	}
	inline void splay(ll cur,ll to){
//		cout<<"SPLAY "<<cur<<' '<<to<<' '<<root<<'\n';
		for(ll f;(f=fa[cur])&&(f!=to);rotate(cur)){
			if(fa[f]!=to)
				rotate((get(cur)==get(f))?f:cur);
			if(fa[cur]==to) break;
		}
		update(cur);
		if(!to) root=cur;
	}
	void build(ll &cur,ll f,ll l,ll r){
		if(l>r){cur=0;return;}
		ll mid=(l+r)>>1;
		if(mid==0||mid==n*2+1){
			cur=n*2+1+(mid==n*2+1);
			fa[cur]=f;tag[cur]=0;siz[cur]=1;
			flag[cur]=w[cur]=0;
		}
		else{
			cur=abs(g::lis[mid])+(g::lis[mid]<0)*n;
			fa[cur]=f;tag[cur]=0;siz[cur]=1;
			flag[cur]=(g::lis[mid]>0)?1:-1;
			w[cur]=ori[abs(g::lis[mid])];
		}
//		cout<<"build "<<l<<' '<<r<<' '<<cur<<' '<<mid<<' '<<g::lis[mid]<<' '<<f<<' '<<w[cur]<<' '<<flag[cur]<<'\n';

		build(ch[cur][0],cur,l,mid-1);
		build(ch[cur][1],cur,mid+1,r);
		update(cur);
//		cout<<"finish build "<<cur<<' '<<siz[cur]<<' '<<sum[cur]<<' '<<suf[cur]<<'\n';
	}
	ll getrank(ll cur){
		ll re;
		push(cur);
//		cout<<"begin getrank "<<cur<<'\n';
		if(cur==root) return siz[ch[cur][0]]+1;
		if(get(cur)) re=getrank(fa[cur])+siz[ch[cur][0]]+1;
		else re=getrank(fa[cur])-siz[ch[cur][1]]-1;
//		cout<<"getrank "<<cur<<' '<<root<<' '<<re<<'\n';
		return re;
	}
	ll findrank(ll cur,ll lim){
//		cout<<"findrank "<<cur<<' '<<lim<<'\n';
//		assert(cur);
		if(siz[ch[cur][0]]+1==lim) return cur;
		if(siz[ch[cur][0]]>=lim) return findrank(ch[cur][0],lim);
		else return findrank(ch[cur][1],lim-siz[ch[cur][0]]-1);
	}
	void link(ll x,ll y){
		splay(findrank(root,getrank(x)-1),0);
		splay(findrank(root,getrank(x+n)+1),root);
		ll tmp=ch[ch[root][1]][0];
		ch[ch[root][1]][0]=0;
		update(ch[root][1]);update(root);
		splay(findrank(root,getrank(y+n)-1),0);
		splay(findrank(root,getrank(y+n)),root);
		fa[tmp]=ch[root][1];ch[ch[root][1]][0]=tmp;
		update(ch[root][1]);update(root);
	}
	ll query(ll x){
		getrank(x);
		splay(x,0);
		return sum[ch[root][0]]+w[root]*flag[root];
	}
	void change(ll x,ll val){
		splay(findrank(root,getrank(x)-1),0);
		splay(findrank(root,getrank(x+n)+1),root);
		ll tmp=ch[ch[root][1]][0];
		tag[tmp]+=val;
		w[tmp]+=val;
		sum[tmp]+=suf[tmp]*val;
	}
}
int main(){
	n=read();ll i,t1,t2;char s[20];
	g::init();
	for(i=2;i<=n;i++) g::add(read(),i);
	for(i=1;i<=n;i++) ori[i]=read();
	g::dfs(1);
	t::build(root,0,0,n*2+1);
	m=read();
	while(m--){
		scanf("%s",s);
		if(s[0]=='Q') printf("%lld\n",t::query(read()));
		if(s[0]=='F'){
			t1=read();t2=read();
			t::change(t1,t2);
		}
		if(s[0]=='C'){
			t1=read();t2=read();
			t::link(t1,t2);
		}
	}
}
