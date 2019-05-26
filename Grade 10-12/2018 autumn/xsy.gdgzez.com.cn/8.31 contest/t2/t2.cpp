#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
#define fpos DEEP_DARK_FANTASY_1
#define gpos DEEP_DARK_FANTASY_2
using namespace std;
inline int read(){
	int re=0,flag=1;char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
int n,first[50010],cnte;
struct edge{
	int to,next;
}a[100010];
inline void add(int u,int v){
	a[++cnte]=(edge){v,first[u]};first[u]=cnte;
	a[++cnte]=(edge){u,first[v]};first[v]=cnte;
}
int dep[50010],maxdep[50010],fpos[50010],gpos[50010],cntf,cntg,son[50010],siz[50010],top[50010];
ll f[200010],g[200010];
int getf(int u,int i){
//	cout<<"getf "<<u<<' '<<i<<' '<<fpos[top[u]]+dep[u]-dep[top[u]]+i<<'\n';
	return fpos[top[u]]+dep[u]-dep[top[u]]+i;
}
int getg(int u,int i){
//	cout<<"getg "<<u<<' '<<i<<' '<<gpos[top[u]]-dep[u]+dep[top[u]]+i<<'\n';
	return gpos[top[u]]-dep[u]+dep[top[u]]+i;
}
int getlen(int u){
	return maxdep[u]-dep[u]+1;
}
int fa[50010];
void dfs1(int u,int f){
	int i,v;fa[u]=f;
	dep[u]=dep[f]+1;maxdep[u]=dep[u];
	siz[u]=1;son[u]=0;
//	cout<<"enter dfs1 "<<u<<' '<<f<<' '<<dep[u]<<'\n';
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(v==f) continue;
		dfs1(v,u);
		siz[u]+=siz[v];
		if(siz[son[u]]<siz[v]) son[u]=v;
		maxdep[u]=max(maxdep[u],maxdep[v]+1);
	}
//	cout<<"finish dfs1 "<<u<<' '<<siz[u]<<' '<<son[u]<<'\n';
}
void dfs2(int u,int t){
	int i,v;
	top[u]=t;
	if(u==t){
		int len=getlen(u);
		fpos[u]=cntf;
		gpos[u]=cntg+len;
		cntf+=len;
		cntg+=len<<1;
	}
	if(!son[u]) return;
	dfs2(son[u],t);
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(v==son[u]||v==fa[u]) continue;
		dfs2(v,v);
	}
}
ll ans=0;
void dfs(int u){
	f[getf(u,0)]=1;
//	cout<<"dfs "<<u<<' '<<top[u]<<' '<<son[u]<<' '<<ans<<'\n';
	if(son[u]){
		dfs(son[u]);
		ans+=g[getg(u,0)];
	}
	int i,v,j,lim;
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(v==fa[u]||v==son[u]) continue;
		dfs(v);lim=getlen(v);
		for(j=1;j<=lim;j++) ans+=g[getg(u,j)]*f[getf(v,j-1)];
		for(j=1;j<=lim-1;j++) ans+=g[getg(v,j)]*f[getf(u,j-1)];
		for(j=1;j<=lim;j++) g[getg(u,j)]+=f[getf(u,j)]*f[getf(v,j-1)];
		for(j=0;j<=lim-2;j++) g[getg(u,j)]+=g[getg(v,j+1)];
		for(j=1;j<=lim;j++) f[getf(u,j)]+=f[getf(v,j-1)];
	}
//	cout<<"finish dfs "<<u<<' '<<ans<<'\n';
}
void init(){
	memset(first,-1,sizeof(first));
	cnte=ans=0;cntf=cntg=1;
	memset(f,0,sizeof(f));memset(g,0,sizeof(g));
	memset(dep,0,sizeof(dep));memset(maxdep,0,sizeof(maxdep));
}
int main(){
//	freopen("in.in","r",stdin);
	int i,t1,t2;
	while((n=read())){
		init();
		for(i=1;i<n;i++){
			t1=read();t2=read();
			add(t1,t2);
		}
		dfs1(1,0);dfs2(1,1);
		dfs(1);
		printf("%lld\n",ans);
	}
}
