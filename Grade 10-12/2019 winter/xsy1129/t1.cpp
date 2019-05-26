#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<queue>
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
int n,v[100010],k[100010],p[100010];
namespace g{
	int first[100010],cnte=-1;
	void init(){memset(first,-1,sizeof(first));cnte=-1;}
	struct edge{
		int to,next,w;
	}a[6000010];
	inline void add(int u,int v,int w){
//		cout<<"g add "<<u<<' '<<v<<' '<<w<<'\n';
		a[++cnte]=(edge){v,first[u],w};first[u]=cnte;
		a[++cnte]=(edge){u,first[v],0};first[v]=cnte;
	}
	queue<int>q;int dep[100010],cur[100010];
	bool bfs(int s,int t){
		int i,u,v;
		for(i=s;i<=t;i++) dep[i]=-1,cur[i]=first[i];
		q.push(s);dep[s]=0;
		while(!q.empty()){
			u=q.front();q.pop();
			for(i=first[u];~i;i=a[i].next){
				v=a[i].to;if(!a[i].w||~dep[v]) continue;
				dep[v]=dep[u]+1;q.push(v);
			}
		}
		return ~dep[t];
	}
	int dfs(int u,int t,int lim){
		if(u==t||!lim) return lim;
		int i,v,f,flow=0;
		for(i=cur[u];~i;i=a[i].next){
			v=a[i].to;cur[u]=i;
			if(dep[v]==dep[u]+1&&(f=dfs(v,t,min(lim,a[i].w)))){
				a[i].w-=f;a[i^1].w+=f;
				flow+=f;lim-=f;
				if(!lim) return flow;
			}
		}
		return flow;
	}
	int dinic(int s,int t){
		int re=0;
		while(bfs(s,t)) re+=dfs(s,t,1e9);
		return re;
	}
}
int fa[1000010],dep[100010],siz[100010],son[100010],back[100010],dfn[100010],top[100010],clk;
namespace t{
	int first[100010],cnte=-1;
	void init(){memset(first,-1,sizeof(first));}
	struct edge{
		int to,next;
	}a[200010];
	inline void add(int u,int v){
//		cout<<"t add "<<u<<' '<<v<<'\n';
		a[++cnte]=(edge){v,first[u]};first[u]=cnte;
		a[++cnte]=(edge){u,first[v]};first[v]=cnte;
	}
	void dfs1(int u,int f){
		int i,v;
		dep[u]=dep[f]+1;
		siz[u]=1;son[u]=0;
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
		dfn[u]=++clk;back[clk]=u;
//		cout<<"dfs2 "<<u<<' '<<t<<' '<<dfn[u]<<' '<<siz[u]<<' '<<son[u]<<'\n';
		if(son[u]) dfs2(son[u],t);
		for(i=first[u];~i;i=a[i].next){
			v=a[i].to;if(v==fa[u]||v==son[u]) continue;
			dfs2(v,v);
		}
	}
}
namespace seg{
	int seg[100010],cnt;
	void init(){cnt=n;}
	void build(int l,int r,int num){
		if(l==r){seg[num]=back[l];return;}
		int mid=(l+r)>>1;
		seg[num]=++cnt;
		build(l,mid,num<<1);g::add(seg[num],seg[num<<1],1e9);
		build(mid+1,r,num<<1|1);g::add(seg[num],seg[num<<1|1],1e9);
//		cout<<"finish seg build "<<l<<' '<<r<<' '<<seg[num]<<' '<<seg[num<<1]<<' '<<seg[num<<1|1]<<'\n';
	}
	void add(int l,int r,int ql,int qr,int num,int from){
//		cout<<"seg add "<<l<<' '<<r<<' '<<ql<<' '<<qr<<' '<<from<<'\n';
		assert(ql);
		if(l>=ql&&r<=qr){g::add(from,seg[num],1e9);return;}
		int mid=(l+r)>>1;
		if(mid>=ql) add(l,mid,ql,qr,num<<1,from);
		if(mid<qr) add(mid+1,r,ql,qr,num<<1|1,from);
	}
}
void link(int u,int tot){
	if(!tot) return;
	int from=u+seg::cnt;
	u=fa[u];
	while(tot){
//		cout<<"*******link while "<<tot<<' '<<u<<'\n';
		if(tot>=dep[u]-dep[top[u]]+1){
			seg::add(1,n,dfn[top[u]],dfn[u],1,from);
			tot-=dep[u]-dep[top[u]]+1;
			u=fa[top[u]];
		}
		else{
			seg::add(1,n,dfn[u]-tot+1,dfn[u],1,from);
			break;
		}
	}
}
int main(){
	n=read();int i,S,T,ans=0;
	t::init();
	for(i=1;i<=n;i++){
		fa[i]=read();v[i]=read();k[i]=read();p[i]=read();
		if(fa[i]) t::add(fa[i],i);
	}
	t::dfs1(1,0);
	t::dfs2(1,1);
	g::init();
	seg::init();
	seg::build(1,n,1);
	S=0;T=seg::cnt+n+1;
	for(i=1;i<=n;i++){
		if(v[i]>=0){
			ans+=v[i];
			g::add(S,i,v[i]);
			g::add(i,T,0);
		}
		else{
			g::add(S,i,0);
			g::add(i,T,-v[i]);
		}
		g::add(i,i+seg::cnt,p[i]);
		link(i,k[i]);
	}
	printf("%d\n",ans-g::dinic(S,T));
}
