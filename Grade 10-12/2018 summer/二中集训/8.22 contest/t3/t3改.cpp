#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cassert>
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
int n,first[200010],fa[200010],cnte,mex[200010] ;
bool vis[200010],cir[200010];
struct edge{
	int to,next;
}a[200010];
inline void add(int u,int v){
	a[++cnte]=(edge){v,first[u]};first[u]=cnte;
}
void dfs(int u){
	int i,v;mex[u]=0;
	for(i=first[u];~i;i=a[i].next) 
		if(!cir[v=a[i].to]) dfs(v);
	for(i=first[u];~i;i=a[i].next)
		if(!cir[v=a[i].to]) vis[mex[v]]=1;
	while(vis[mex[u]]) mex[u]++;
	for(i=first[u];~i;i=a[i].next)
		if(!cir[v=a[i].to]) vis[mex[v]]=0;
}
int main(){
	memset(first,-1,sizeof(first));
	n=read();int i,u,maxn=0,minn=1e9,cnt=0;
	for(i=1;i<=n;i++) fa[i]=read(),add(fa[i],i);
	u=1;
	while(!vis[u]) vis[u]=1,u=fa[u];
	while(!cir[u]) cir[u]=1,u=fa[u];
	for(i=1;i<=n;i++){
		if(!cir[i]) continue;
		dfs(i);cnt++;
		maxn=max(maxn,mex[i]);minn=min(minn,mex[i]);
	}
	if(maxn==minn&&cnt&1) puts("IMPOSSIBLE");
	else puts("POSSIBLE");
}
