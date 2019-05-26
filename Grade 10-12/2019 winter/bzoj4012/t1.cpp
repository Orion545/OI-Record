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
int n,q,val[200010],rk[200010],lis[200010],rb[200010],lb[200010],root[2000010],cntr=0;
ll dis[200010],totdis[200010],sumdis[200010],pred[200010],lim;
int fa[200010],siz[200010],son[200010],top[200010],dfn[200010],clk;
inline bool cmp(int l,int r){return val[l]<val[r];}
namespace seg{
	ll seg[15000010],tim[15000010];int ch[15000010][2],cnt;
	inline void insert(int &cur,int pre,int l,int r,int ql,int qr){
		cur=++cnt;
		seg[cur]=seg[pre];tim[cur]=tim[pre];ch[cur][0]=ch[pre][0];ch[cur][1]=ch[pre][1];
//		cout<<"	insert "<<cur<<' '<<l<<' '<<r<<' '<<ql<<' '<<qr<<' '<<seg[cur]<<'\n';
		if(l>=ql&&r<=qr){tim[cur]++;return;}
		seg[cur]+=(pred[qr]-pred[ql-1]);
		int mid=(l+r)>>1;
		if(mid>=ql) insert(ch[cur][0],ch[pre][0],l,mid,ql,min(mid,qr));
		if(mid<qr) insert(ch[cur][1],ch[pre][1],mid+1,r,max(ql,mid+1),qr);
	}
	inline ll query(int cur,int pre,int l,int r,int ql,int qr){
//		cout<<"	query "<<l<<' '<<r<<' '<<ql<<' '<<qr<<' '<<seg[cur]<<' '<<seg[pre]<<' '<<tim[cur]<<' '<<tim[pre]<<'\n';
		int mid=(l+r)>>1;ll re=(tim[cur]-tim[pre])*(pred[qr]-pred[ql-1]);
		if(l>=ql&&r<=qr) return re+(seg[cur]-seg[pre]);
		if(mid>=ql) re+=query(ch[cur][0],ch[pre][0],l,mid,ql,min(mid,qr));
		if(mid<qr) re+=query(ch[cur][1],ch[pre][1],mid+1,r,max(ql,mid+1),qr);
		return re;
	}
}
namespace g{
	int first[200010],cnte=-1;
	struct edge{
		int to,next,w;
	}a[400010];
	inline void init(){memset(first,-1,sizeof(first));}
	inline void add(int u,int v,int w){
		a[++cnte]=(edge){v,first[u],w};first[u]=cnte;
		a[++cnte]=(edge){u,first[v],w};first[v]=cnte;
	}
	void dfs1(int u,int f,ll w){
		int i,v;
		fa[u]=f;
		dis[u]=w;
		totdis[u]=totdis[f]+w;
		siz[u]=1;son[u]=0;
		for(i=first[u];~i;i=a[i].next){
			v=a[i].to;if(v==f) continue;
			dfs1(v,u,a[i].w);
			siz[u]+=siz[v];
			if(siz[son[u]]<siz[v]) son[u]=v;
		}
	}
	void dfs2(int u,int t){
		int i,v;
		top[u]=t;
		dfn[u]=++clk;
		pred[clk]=pred[clk-1]+dis[u];
//		cout<<"dfs2 "<<u<<' '<<dfn[u]<<' '<<dis[u]<<' '<<fa[u]<<' '<<top[u]<<'\n';
		if(son[u]) dfs2(son[u],t);
		for(i=first[u];~i;i=a[i].next){
			v=a[i].to;if(v==fa[u]||v==son[u]) continue;
			dfs2(v,v);
		}
	}
	inline void addlis(int u,int num){
		while(u){
			cntr++;if(!lb[num]) lb[num]=cntr;
//			cout<<"addlis "<<num<<' '<<u<<' '<<top[u]<<' '<<cntr<<'\n';
			seg::insert(root[cntr],root[cntr-1],1,n,dfn[top[u]],dfn[u]);
			u=fa[top[u]];
		}
		rb[num]=cntr;
	}
	inline ll ask(int u,int l,int r){
		ll re=0;
		while(u){
//			cout<<"ask "<<u<<' '<<top[u]<<' '<<l<<' '<<r<<'\n';
			re+=seg::query(root[r],root[l],1,n,dfn[top[u]],dfn[u]);
			u=fa[top[u]];
		}
		return re;
	}
}
int main(){
	n=read();q=read();lim=read();ll i,t1,t2,t3,sumu,sumv;ll lastans=0;
	for(i=1;i<=n;i++) val[i]=read(),rk[i]=i;
	sort(rk+1,rk+n+1,cmp);
	for(i=1;i<=n;i++) lis[i]=val[rk[i]];
	g::init();
	for(i=1;i<n;i++){
		t1=read();t2=read();t3=read();
		g::add(t1,t2,t3);
	}
	g::dfs1(1,0,0);g::dfs2(1,1);
	for(i=1;i<=n;i++) g::addlis(rk[i],i);
	for(i=1;i<=n;i++) sumdis[i]=sumdis[i-1]+totdis[rk[i]];

//	for(i=1;i<=n;i++) cout<<"checklis "<<i<<' '<<rk[i]<<' '<<lis[i]<<'\n';
//	for(i=1;i<=n;i++) cout<<"check bound "<<i<<' '<<lb[i]<<' '<<rb[i]<<'\n';

	while(q--){
		t1=read();t2=(1ll*read()+lastans)%lim;t3=(1ll*read()+lastans)%lim;
		if(t2>t3) swap(t2,t3);
//		cout<<"************************input query "<<t1<<' '<<t2<<' '<<t3<<'\n';

		t2=lower_bound(lis+1,lis+n+1,t2)-lis;
		t3=upper_bound(lis+1,lis+n+1,t3)-lis-1;
//		cout<<"************************input query "<<t1<<' '<<t2<<' '<<t3<<'\n';

		sumu=(t3-t2+1)*totdis[t1];
		sumv=sumdis[t3]-sumdis[t2-1];
		t2=lb[t2]-1;t3=rb[t3];
//		cout<<"************************input query "<<t1<<' '<<t2<<' '<<t3<<'\n';
		printf("%lld\n",lastans=(sumu+sumv-2*g::ask(t1,t2,t3)));
	}
}
