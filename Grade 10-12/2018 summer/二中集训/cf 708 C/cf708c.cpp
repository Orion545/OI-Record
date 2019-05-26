#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
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
int n,cnte,first[400010],siz[400010],up[400010];
int f1[400010],f2[400010];
int ans[400010];
struct edge{
	int to,next;
}a[800010];
inline void add(int u,int v){
	a[++cnte]=(edge){v,first[u]};first[u]=cnte;
	a[++cnte]=(edge){u,first[v]};first[v]=cnte;
}
void dfs(int u,int f){
	siz[u]=1;ans[u]=1;
	int i,v;
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;
		if(v==f) continue;
		dfs(v,u);siz[u]+=siz[v];
		if(siz[v]>n/2){
			if(siz[v]-f1[v]>n/2) ans[u]=-1;
		}
		f1[u]=max(f1[u],f1[v]);
		if(siz[v]<=n/2) f1[u]=max(f1[u],siz[v]);
	}
	up[u]=n-siz[u];
	if(up[u]>n/2) ans[u]=0;
}
int pre[400010],pos[400010],suf[400010];
void dfs2(int u,int f){
	int i,v,w,cnt=0;
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(v==f) continue;
		pos[++cnt]=v;
	}
	for(i=1;i<=cnt;i++){
		v=pos[i];w=f1[v];
		assert(pos[i]<=n);
		if(siz[v]<=n/2) w=max(w,siz[v]);
		pre[i]=max(pre[i-1],w);
	}
	suf[cnt+1]=0;
	for(i=cnt;i>=1;i--){
		v=pos[i];w=f1[v];
		if(siz[v]<=n/2) w=max(w,siz[v]);
		suf[i]=max(suf[i+1],w);
	}
	for(i=1;i<=cnt;i++){
		v=pos[i];w=max(f2[u],max(pre[i-1],suf[i+1]));
		if(up[v]<=n/2) w=max(up[v],w);
		f2[v]=w;
		if(!ans[v]&&up[v]-f2[v]<=n/2) ans[v]=1;
	}
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(v==f) continue;
		dfs2(v,u);
	}
}

int main(){
	memset(first,-1,sizeof(first));
	n=read();int i,t1,t2;
	for(i=1;i<n;i++) t1=read(),t2=read(),add(t1,t2);
	dfs(1,0);
	dfs2(1,0);
	for(i=1;i<=n;i++){
		if(ans[i]) putchar('1');
		else putchar('0');
		putchar(' ');
	}
}
