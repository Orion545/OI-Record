#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#define ll long long
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
int n,q,first[500010],val[500010],cnte=-1;
namespace BIT{
	int a[500010];
	inline void add(int x,int va){
		for(;x<=n;x+=(x&(-x))) a[x]^=va;
	}
	inline int sum(int x){
		int re=0;
		for(;x;x^=(x&(-x))) re^=a[x];
		return re;
	}
	inline int query(int l,int r){
		return sum(r)^(sum(l-1));
	}
}
struct edge{
	int to,next;
}a[1000010];
inline void add(int u,int v){
	a[++cnte]=(edge){v,first[u]};first[u]=cnte;
	a[++cnte]=(edge){u,first[v]};first[v]=cnte;
}
int dep[500010],fa[500010],siz[500010],son[500010],top[500010],pos[500010],back[500010],clk;
void dfs1(int u,int f){
	int i,v;
	fa[u]=f;
	siz[u]=1;son[u]=0;
	dep[u]=dep[f]+1;
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(v==f) continue;
		dfs1(v,u);
		siz[u]+=siz[v];
		if(siz[son[u]]<siz[v]) son[u]=v;
	}
}
void dfs2(int u,int t){
	int i,v;
	top[u]=t;
	pos[u]=++clk;back[clk]=u;
	if(son[u]) dfs2(son[u],t);
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(v==fa[u]||v==son[u]) continue;
		dfs2(v,v);
	}
}
int query(int u,int v){
	int re=0;
	while(top[u]!=top[v]){
		if(dep[top[u]]>=dep[top[v]]) swap(u,v);
		re^=BIT::query(pos[top[v]],pos[v]);
		v=fa[top[v]];
	}
	if(dep[u]>=dep[v]) swap(u,v);
	re^=BIT::query(pos[u],pos[v]);
	return re;
}
int main(){
	memset(first,-1,sizeof(first));
	n=read();int i,t1,t2;char s[10];
	for(i=1;i<=n;i++) val[i]=read();
	for(i=1;i<n;i++){
		t1=read();t2=read();
		add(t1,t2);
	}
	dfs1(1,0);
	dfs2(1,1);
	for(i=1;i<=n;i++) BIT::add(i,val[back[i]]);
	q=read();
	while(q--){
		scanf("%s",s);
		t1=read();t2=read();
		if(s[0]=='Q') puts((query(t1,t2)!=0)?"Yes":"No");
		else BIT::add(pos[t1],val[t1]^t2),val[t1]=t2;
	}
}
