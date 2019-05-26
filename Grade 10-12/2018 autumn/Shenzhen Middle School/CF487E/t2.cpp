#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<set>
using namespace std;
inline int read(){
	int re=0,flag=1;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(isdigit(ch)) re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
int n,m,q,w[100010],tot;
multiset<int>s[200010];
namespace t{
	int first[200010],cnte=1;
	struct edge{
		int to,next;
	}a[400010];
	inline void add(int u,int v){
		a[++cnte]=(edge){v,first[u]};first[u]=cnte;
		a[++cnte]=(edge){u,first[v]};first[v]=cnte;
	}
	int dep[200010],fa[200010],siz[200010],son[200010],dfn[200010],top[200010],back[200010],clk;
	void dfs1(int u,int f){
		int i,v,maxn=0;
		dep[u]=dep[f]+1;
		fa[u]=f;
		siz[u]=1;son[u]=0;
		if(u<=n){
			s[u].insert(w[u]);
			s[fa[u]].insert(w[u]);
		}
//		cout<<"dfs1 "<<u<<' '<<f<<'\n';
		for(i=first[u];~i;i=a[i].next){
			v=a[i].to;if(v==f) continue;
			dfs1(v,u);
			siz[u]+=siz[v];
			if(siz[v]>maxn) son[u]=v,maxn=siz[v];
		}
	}
	void dfs2(int u,int t){
		int i,v;
		dfn[u]=++clk;back[clk]=u;
		top[u]=t;
		if(son[u]) dfs2(son[u],t);
		for(i=first[u];~i;i=a[i].next){
			v=a[i].to;if(v==fa[u]||v==son[u]) continue;
			dfs2(v,v);
		}
	}
	int seg[800010];
	void build(int l,int r,int num){
		if(l==r){
//			cout<<"build end "<<l<<' '<<r<<' '<<back[l]<<' '<<*(s[back[l]].begin())<<'\n';
			seg[num]=*(s[back[l]].begin());
			return;
		}
		int mid=(l+r)>>1;
		build(l,mid,num<<1);build(mid+1,r,num<<1|1);
		seg[num]=min(seg[num<<1],seg[num<<1|1]);
//		cout<<"build "<<l<<' '<<r<<' '<<seg[num]<<'\n';
	}
	void change(int l,int r,int num,int pos){
		if(l==r){seg[num]=*(s[back[l]].begin());return;}
		int mid=(l+r)>>1;
		if(mid>=pos) change(l,mid,num<<1,pos);
		else change(mid+1,r,num<<1|1,pos);
		seg[num]=min(seg[num<<1],seg[num<<1|1]);
//		cout<<"change "<<l<<' '<<r<<' '<<pos<<' '<<seg[num]<<'\n';
	}
	int query(int l,int r,int ql,int qr,int num){
		if(l>=ql&&r<=qr) return seg[num];
		int mid=(l+r)>>1,re=1e9;
		if(mid>=ql) re=min(re,query(l,mid,ql,qr,num<<1));
		if(mid<qr) re=min(re,query(mid+1,r,ql,qr,num<<1|1));
		return re;
	}
	void mod(int u,int val){
		s[u].clear();
		s[fa[u]].erase(s[fa[u]].find(w[u]));
		w[u]=val;
		s[u].insert(val);
		s[fa[u]].insert(val);
		change(1,tot,1,dfn[u]);
		change(1,tot,1,dfn[fa[u]]);
	}
	int ask(int l,int r){
		int re=1e9;
		while(top[l]!=top[r]){
			if(dep[top[l]]>=dep[top[r]]) swap(l,r);
			re=min(re,query(1,tot,dfn[top[r]],dfn[r],1));
			r=fa[top[r]];
		}
		if(dep[l]>dep[r]) swap(l,r);
		re=min(re,query(1,tot,dfn[l],dfn[r],1));
		if(l>n) re=min(re,*(s[fa[l]].begin()));
		return re;
	}
}
namespace g{
	int first[100010],cnte=1,dfn[100010],low[100010],clk;
	struct edge{
		int to,next;
	}a[400010];
	inline void add(int u,int v){
		a[++cnte]=(edge){v,first[u]};first[u]=cnte;
		a[++cnte]=(edge){u,first[v]};first[v]=cnte;
	}
	int s[100010],top;
	void tarjan(int u){
		int i,v;
		s[++top]=u;
		dfn[u]=low[u]=++clk;
		for(i=first[u];~i;i=a[i].next){
			v=a[i].to;
			if(!dfn[v]){
				tarjan(v);
				low[u]=min(low[u],low[v]);
				if(low[v]>=dfn[u]){
					t::add(++tot,u);
					int tmp;
					do{
						tmp=s[top--];
						t::add(tot,tmp);
					}while(tmp!=v);
				}
			}
			else low[u]=min(low[u],dfn[v]);
		}
	}
}
int main(){
	memset(g::first,-1,sizeof(g::first));
	memset(t::first,-1,sizeof(t::first));
	n=read();m=read();q=read();int i,t1,t2;
	tot=n;
	for(i=1;i<=n;i++) w[i]=read();
	for(i=1;i<=m;i++){
		t1=read();t2=read();
		g::add(t1,t2);
	}
	g::tarjan(1);
	t::dfs1(1,0);t::dfs2(1,1);
	t::build(1,tot,1);
	char ss[10];
	while(q--){
		scanf("%s",ss);
		t1=read();t2=read();
		if(ss[0]=='C') t::mod(t1,t2);
		else printf("%d\n",t::ask(t1,t2));
	}
}
