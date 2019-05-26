#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<cmath>
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
int n,k,first[3010],cnte,dep[3010],siz[3010],root,son[3010],vis[3010],sum,ans=0x7fffffff;
struct edge{
	int to,next,w;
}a[6010];
inline void add(int u,int v,int w){
	a[++cnte]=(edge){v,first[u],w};first[u]=cnte;
	a[++cnte]=(edge){u,first[v],w};first[v]=cnte;
}
void getroot(int u,int f){
	int i,v;dep[u]=dep[f]+1;siz[u]=1;son[u]=0;
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(vis[v]||v==f) continue;
		getroot(v,u);siz[u]+=siz[v];
		son[u]=max(son[u],siz[v]);
	}
	son[u]=max(son[u],sum-siz[u]);
	if(son[u]<son[root]) root=u;
}
int tmp[3010];
void calc(int u,int f,int dis,int w){
	int i,v;
	ans=min(ans,tmp[k-dis]+w);
	cout<<"calc "<<u<<' '<<f<<' '<<dis<<' '<<w<<' '<<ans<<'\n';
	siz[u]=1;
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(v==f||vis[v]) continue;
		calc(v,u,dis+1,w+a[i].w);siz[u]+=siz[v];
	}
	tmp[dis]=min(tmp[dis],w);
	cout<<"finish calc "<<u<<' '<<dis<<' '<<w<<' '<<tmp[dis]<<'\n';
}
void dfs(int u){
	cout<<"dfs "<<u<<'\n'; 
	vis[u]=1;int i,v;
	for(i=1;i<=n;i++) tmp[i]=1e9;
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(vis[v]) continue;
		calc(v,u,1,a[i].w);
	}
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(vis[v]) continue;
		sum=siz[v];root=0;getroot(v,0);
		dfs(root);
	}
}
int main(){
	memset(first,-1,sizeof(first));
	n=read();k=read();int i,t1,t2,t3;k--;
	for(i=1;i<n;i++){
		t1=read();t2=read();t3=read();
		add(t1,t2,t3);
	}
	sum=n;son[0]=n;root=0;
	getroot(1,0);dfs(root);
	printf("%d\n",ans);
}

