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
int n,first[20010],dis[20010],cnt[3],ans,sum,root,cnte,siz[20010],son[20010],vis[20010];
struct edge{
	int to,next,w;
}a[40010];
inline void add(int u,int v,int w){
	a[++cnte]=(edge){v,first[u],w};first[u]=cnte;
	a[++cnte]=(edge){u,first[v],w};first[v]=cnte;
}
void getroot(int u,int f){
	int i,v;siz[u]=1;son[u]=0;
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(v==f||vis[v]) continue;
		getroot(v,u);siz[u]+=siz[v];
		son[u]=max(son[u],siz[v]);
	}
	son[u]=max(son[u],sum-siz[u]);
	if(son[u]<son[root]) root=u;
}
void getcnt(int u,int f){
	int i,v;cnt[dis[u]]++;
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(v==f||vis[v]) continue;
		dis[v]=(dis[u]+a[i].w)%3;getcnt(v,u);
	}
}
int calc(int u,int d){
	dis[u]=d%3;cnt[1]=cnt[2]=cnt[0]=0;
	getcnt(u,0);return cnt[1]*cnt[2]*2+cnt[0]*cnt[0];
}
void dfs(int u){
	int i,v;vis[u]=1;
//	cout<<"dfs "<<u<<'\n';
	ans+=calc(u,0);
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(vis[v]) continue;
		ans-=calc(v,a[i].w);
		root=0;sum=siz[v];
		getroot(v,0);dfs(root);
	}
}
int gcd(int x,int y){
	if(y==0) return x;
	return gcd(y,x%y);
}
int main(){
	memset(first,-1,sizeof(first));
	n=read();int i,t1,t2,t3;
	for(i=1;i<n;i++){
		t1=read();t2=read();t3=read();
		add(t1,t2,t3);
	}
	son[0]=n;root=0;sum=n;
	getroot(1,0);
	dfs(root);
	int div=gcd(n*n,ans);
	printf("%d/%d",ans/div,n*n/div);
}
