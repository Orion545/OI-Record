#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<cmath>
#include<vector>
#define ll long long
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
int n,m,first[300010],cnte,pos1[300010],pos2[300010],dp[300010],rt[300010],maxn[300010],pos[300010];
int dep[300010],fa[300010],siz[300010],son[300010],top[300010];
struct edge{
	int to,next;
}a[600010];
inline void add(int u,int v){
	a[++cnte]=(edge){v,first[u]};first[u]=cnte;
	a[++cnte]=(edge){u,first[v]};first[v]=cnte;
}
struct EDGE{
	EDGE(){from=to=root=0;}
	EDGE(int u1,int u2,int u3){from=u1,to=u2,root=u3;}
	int from,to,root;
};
vector<EDGE>g[300010];
void dfs(int u,int f){
	int i,v;
	siz[u]=1;
	dep[u]=dep[f]+1;fa[u]=f;
	maxn[u]=0;pos[u]=u;
	pos1[u]=pos2[u]=u;dp[u]=0;
//	cout<<"dfs "<<u<<' '<<f<<'\n';
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(v==f) continue;
		dfs(v,u);
		siz[u]+=siz[v];
		if(siz[v]>siz[son[u]]) son[u]=v;
		if(maxn[u]+maxn[v]+1>dp[u]){
			dp[u]=maxn[u]+maxn[v]+1;
			pos1[u]=pos[u];
			pos2[u]=pos[v];
		}
		if(dp[v]>dp[u]){
			dp[u]=dp[v];
			pos1[u]=pos1[v];
			pos2[u]=pos2[v];
		}
		if(maxn[v]+1>maxn[u]){
			maxn[u]=maxn[v]+1;
			pos[u]=pos[v];
		}
	}
//	cout<<"finish dfs "<<u<<' '<<dp[u]<<' '<<pos1[u]<<' '<<pos2[u]<<'\n';
}
void dfs2(int u,int f,int t){
	int i,v;
	top[u]=t;
	if(son[u]) dfs2(son[u],u,t);
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(v==f||v==son[u]) continue;
		dfs2(v,u,v);
	}
}
int lca(int l,int r){
//	cout<<"lca "<<l<<' '<<r<<' ';
	while(top[l]!=top[r]){
		if(dep[top[l]]>dep[top[r]]) swap(l,r);
//		cout<<"	do "<<l<<' '<<r<<'\n';
		r=fa[top[r]];
	}
	if(dep[l]>dep[r]) swap(l,r);
//	cout<<l<<'\n';
	return l;
}
int getdis(int l,int r){
	return dep[l]+dep[r]-(dep[lca(l,r)]<<1);
}
ll ans,ansl,ansr;
void update(int root,int u,ll dis){
	if(dis<=ans) return;
	ans=dis;
	ansl=root;ansr=u;
}
void solve(int root,int u,int from,ll dis){
//	cout<<"solve "<<root<<' '<<u<<' '<<from<<' '<<dis<<'\n';
	update(root,pos1[rt[root]],dis+getdis(u,pos1[rt[root]]));
	update(root,pos2[rt[root]],dis+getdis(u,pos2[rt[root]]));
	int i,v,rtv,pt;EDGE e;
	for(i=0;i<g[root].size();i++){
		e=g[root][i];
		pt=e.from;rtv=e.root;v=e.to;
//		cout<<"	to "<<pt<<' '<<v<<' '<<rtv<<'\n';
		if(rtv==from) continue;
		solve(rtv,v,root,dis+getdis(u,pt)+1);
	}
}
int main(){
	memset(first,-1,sizeof(first));
	n=read();m=read();int i,t1,t2,t3,t4;
	for(i=1;i<n;i++){
		t1=read();t2=read();
		add(t1,t2);
	}
	for(i=1;i<=m;i++) rt[i]=read();
	for(i=1;i<m;i++){
		t1=read();t2=read();t3=read();t4=read();
		g[t1].push_back(EDGE(t2,t4,t3));
		g[t3].push_back(EDGE(t4,t2,t1));
	}
	dfs(1,0);dfs2(1,0,1);
	ans=-1;
	solve(1,rt[1],0,0);
	ans=-1;
	solve(ansl,ansr,0,0);
	printf("%lld\n",ans+1);
}
