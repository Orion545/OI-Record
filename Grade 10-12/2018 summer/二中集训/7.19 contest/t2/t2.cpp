#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<cstdlib> 
#define inf 1e9
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
}int n,m,first[200010],ans=inf,cnt,root,sum;
int siz[200010],tmp[1000010],son[200010],vis[200010],dep[200010];ll dis[200010];
struct edge{
	int to,next,w;
}a[400010];
inline void add(int u,int v,int w){
	a[++cnt]=(edge){v,first[u],w};first[u]=cnt;
	a[++cnt]=(edge){u,first[v],w};first[v]=cnt;
}
void getroot(int u,int f){
	int i,v;siz[u]=1;son[u]=0;
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(v==f||vis[v]) continue;
		getroot(v,u);
		siz[u]+=siz[v];son[u]=max(son[u],siz[v]);
	}
	son[u]=max(son[u],sum-siz[u]);
	if(son[u]<son[root]) root=u;
}
void calc(int u,int f){
	int i,v;
//	cout<<"calc "<<u<<' '<<f<<' '<<dis[u]<<' '<<dep[u]<<' '<<tmp[m-dis[u]]<<'\n';
	if(dis[u]<=m) ans=min(ans,dep[u]+tmp[m-dis[u]]);
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(vis[v]||v==f) continue;
		dis[v]=dis[u]+a[i].w;dep[v]=dep[u]+1;
		calc(v,u);
	}
}
void update(int u,int f,int t){
	int i,v;
	if(dis[u]<=m){
		if(t) tmp[dis[u]]=min(tmp[dis[u]],dep[u]);
		else tmp[dis[u]]=inf;
	}
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(v==f||vis[v]) continue;
		update(v,u,t);
	}
}
void dfs(int u){
	int i,v;vis[u]=1;tmp[0]=0;
//	cout<<"dfs "<<u<<'\n';
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(vis[v]) continue;
		dis[v]=a[i].w;dep[v]=1;
		calc(v,0);update(v,0,1);
	}
	for(i=first[u];~i;i=a[i].next) if(!vis[a[i].to]) update(a[i].to,0,0);
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(vis[v]) continue;
		sum=siz[v];root=0;getroot(v,0);
		dfs(root);
	}
}
int main(){
	memset(first,-1,sizeof(first));
	n=read();m=read();int i,t1,t2,t3;
	for(i=1;i<=m;i++) tmp[i]=inf;
	for(i=1;i<n;i++){
		t1=read();t2=read();t3=read();
		t1++;t2++;
		add(t1,t2,t3);
	}
	son[0]=inf;root=0;sum=n;getroot(1,0);
	dfs(root);
	if(ans==inf) puts("-1");
	else printf("%d\n",ans);
}
