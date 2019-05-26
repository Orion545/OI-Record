#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
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
int n,K,first[200010],cnte,siz[200010],son[200010],root,sum;
struct edge{
	int to,next,w;
}a[400010];
inline void add(int u,int v,int w){
	a[++cnte]=(edge){v,first[u],w};first[u]=cnte;
	a[++cnte]=(edge){u,first[v],w};first[v]=cnte;
}
bool vis[200010];
void getroot(int u,int f){
	int i,v;
	siz[u]=1;son[u]=0;
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(v==f||vis[v]) continue;
		getroot(v,u);siz[u]+=siz[v];
		if(son[u]<siz[v]) son[u]=siz[v];
	}
	son[u]=max(son[u],sum-siz[u]);
	if(son[u]<son[root]) root=u;
}
int tmp[1000010],ans=1e9;
void getinfo(int u,int f,int dis,int cnt){
	int i,v;
	if(dis>K) return;
	ans=min(ans,tmp[K-dis]+cnt);
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(v==f||vis[v]) continue;
		getinfo(v,u,dis+a[i].w,cnt+1);
	}
}
void update(int u,int f,int dis,int cnt){
	int i,v;
	if(dis>K) return;
	tmp[dis]=min(tmp[dis],cnt);
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(v==f||vis[v]) continue;
		update(v,u,dis+a[i].w,cnt+1);
	}
}
void clear(int u,int f,int dis){
	int i,v;
	if(dis>=K) return;
	tmp[dis]=1e9;
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(v==f||vis[v]) continue;
		clear(v,u,dis+a[i].w);
	}
}
void dfs(int u,int sz){
	int i,v;tmp[0]=0;vis[u]=1;
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(vis[v]) continue;
		getinfo(v,u,a[i].w,1);
		update(v,u,a[i].w,1);
	}
	clear(u,0,0);
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(vis[v]) continue;
		sum=((siz[v]>siz[u])?(sz-siz[u]):siz[v]);
		root=0;son[0]=sum;
		getroot(v,0);
		dfs(root,sum);
	}
}
int main(){
	int size = 128 << 20;
	char *p = (char*)malloc(size) + size;  
	__asm__("movl %0, %%esp\n" :: "r"(p));//有些OJ上不扩栈会RE
	freopen("ioi2011-race.in","r",stdin);
	freopen("ioi2011-race.out","w",stdout);
	memset(first,-1,sizeof(first));
	n=read();K=read();int i,t1,t2,t3;
	for(i=1;i<n;i++){
		t1=read();t2=read();t3=read();
		add(t1+1,t2+1,t3);
	}
	for(i=0;i<=K;i++) tmp[i]=1e9;
	sum=n;root=0;son[0]=n;
	getroot(1,0);
	dfs(root,n);
	if(ans!=1e9) printf("%d\n",ans);
	else puts("-1");
}
