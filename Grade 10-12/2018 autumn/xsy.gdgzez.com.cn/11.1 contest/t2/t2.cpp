/*

宣告——
汝身听吾号令，托付吾之命运于汝之剑，
应圣杯之召，若汝遵从此意志此理，回应吧。
在此起誓，吾愿成就世间一切之善行，吾愿诛尽世间一切之恶行。
汝为身缠三大言灵之七天，从抑止之轮显现吧，天秤之守护者！

*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<cmath>
#include<vector>
#include<queue>
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
int n,m,q,curtop;
namespace G{
	int first[100010],cnte=-1;
	struct edge{
		int to,next;
	}a[200010];int in[200010],vis[100010];
	inline void add(int u,int v){
		a[++cnte]=(edge){v,first[u]};first[u]=cnte;
		a[++cnte]=(edge){u,first[v]};first[v]=cnte;
	}
	void dfs(int u){
		int i,v;vis[u]=1;
//		cout<<"G dfs "<<u<<'\n';
		for(i=first[u];~i;i=a[i].next){
			v=a[i].to;if(vis[v]) continue;
			in[i]=in[i^1]=1;dfs(v);
		}
	}
}
namespace seg{
	int a[400010];
	void add(int l,int r,int ql,int qr,int num){
		if(a[num]) return;
		if(l>=ql&&r<=qr){a[num]=1;return;}
		int mid=(l+r)>>1;
		if(mid>=ql) add(l,mid,ql,qr,num<<1);
		if(mid<qr) add(mid+1,r,ql,qr,num<<1|1);
	}
	int query(int l,int r,int ql,int qr,int num,int cur){
		cur|=a[num];
		if(l>=ql&&r<=qr) return cur;
		int mid=(l+r)>>1,re=0;
		if(mid>=ql) re|=query(l,mid,ql,qr,num<<1,cur);
		if(mid<qr) re|=query(mid+1,r,ql,qr,num<<1|1,cur);
		return re;
	}
}
namespace T{
	int first[100010],cnte=-1,belong[100010];
	struct edge{
		int to,next;
	}a[200010];
	inline void add(int u,int v){
		a[++cnte]=(edge){v,first[u]};first[u]=cnte;
		a[++cnte]=(edge){u,first[v]};first[v]=cnte;
	}
	int dep[100010],siz[100010],son[100010],top[100010],fa[100010],dfn[100010],clk;
	void dfs1(int u,int f){
		int i,v,maxn=0;
		dep[u]=dep[f]+1;
		siz[u]=1;fa[u]=f;son[u]=0;
		belong[u]=curtop;
//		cout<<"dfs1 "<<u<<' '<<f<<'\n';
		for(i=first[u];~i;i=a[i].next){
			v=a[i].to;if(v==f) continue;
			dfs1(v,u);
			siz[v]+=siz[u];
			if(siz[v]>maxn) son[u]=v;
		}
	}
	void dfs2(int u,int t){
		int i,v;
		dfn[u]=++clk;
		top[u]=t;
//		cout<<"dfs2 "<<u<<' '<<t<<' '<<son[u]<<' '<<first[u]<<'\n';
		if(son[u]) dfs2(son[u],t);
		for(i=first[u];~i;i=a[i].next){
			v=a[i].to;if(v==fa[u]||v==son[u]) continue;
			dfs2(v,u);
		}
	}
	void change(int u,int v){
		if(dep[top[u]]>dep[top[v]]) swap(u,v);
		if((dep[v]-dep[u])&1) return;
//		cout<<"change "<<u<<' '<<v<<'\n';
		while(top[u]!=top[v]){
			if(dep[top[u]]>dep[top[v]]) swap(u,v);
			seg::add(1,n,dfn[top[v]],dfn[v],1);v=fa[top[v]];
		}
		if(dep[u]>dep[v]) swap(u,v);
		seg::add(1,n,dfn[u],dfn[v],1);
	}
	int ask(int u,int v){
		if(u==v) return 0;
		if(dep[top[u]]>dep[top[v]]) swap(u,v);
		if((dep[v]-dep[u])&1) return 1;
//		cout<<"ask "<<u<<' '<<v<<'\n';
		if(belong[u]!=belong[v]) return 0;
		while(top[u]!=top[v]){
			if(dep[top[u]]>dep[top[v]]) swap(u,v);
			if(seg::query(1,n,dfn[top[v]],dfn[v],1,0)) return 1;
			v=fa[top[v]];
		}
		if(dep[u]>dep[v]) swap(u,v);
		return seg::query(1,n,dfn[u],dfn[v],1,0);
	}
}
void init(){
	memset(G::first,-1,sizeof(G::first));
	memset(T::first,-1,sizeof(T::first));
}
int main(){
//	freopen("graph.in","r",stdin);
//	freopen("my.out","w",stdout);
	init();int i,t1,t2;
	n=read();m=read();
	for(i=1;i<=m;i++){
		t1=read();t2=read();
		G::add(t1,t2);
	}
	for(i=1;i<=n;i++){
		if(!G::vis[i]) G::dfs(i);
	}
	for(i=0;i<=G::cnte;i+=2){
		if(G::in[i]) T::add(G::a[i].to,G::a[i^1].to);
	}
	for(i=1;i<=n;i++){
		if(!T::dep[i]){
			curtop=i;
			T::dfs1(i,0);
		}
	}
	for(i=1;i<=n;i++){
		if(!T::dfn[i]) T::dfs2(i,i);
	}
//	cout<<"**************finish build tree\n";
	for(i=0;i<=G::cnte;i+=2){
		if(!G::in[i]) T::change(G::a[i].to,G::a[i^1].to);
	}
//	cout<<"**************finish preproc\n";
	q=read();
	while(q--){
		t1=read();t2=read();
		if(T::ask(t1,t2)) puts("Yes");
		else puts("No");
	}
}
