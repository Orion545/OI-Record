#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
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
int n,m,d,cnte,first[100010],dp[100010],up[100010],hurt[100010];
struct edge{
	int to,next;
}a[200010];
inline void add(int u,int v){
	a[++cnte]=(edge){v,first[u]};first[u]=cnte;
	a[++cnte]=(edge){u,first[v]};first[v]=cnte;
	assert(cnte<=n*2);
}
void dfs1(int u,int f){
//	cout<<"dfs1 "<<u<<' '<<f<<'\n'; 
	int i,v;
	assert(u<=n);
	if(!hurt[u]) dp[u]=-1;
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;
		if(v==f) continue;
		dfs1(v,u);
		if(dp[v]!=-1) dp[u]=max(dp[u],dp[v]+1);
	}
}
int pos[100010],pre[100010],suf[100010];
void dfs2(int u,int f){
	int i,v,cnt=0,mx;
	assert(u<=n);
//	cout<<"dfs2 "<<u<<' '<<f<<'\n';
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;
		if(v==f) continue;
//		cout<<"	from "<<u<<" to "<<v<<'\n';
		pos[++cnt]=v;
	}
	pre[0]=suf[cnt+1]=-1;
	for(i=1;i<=cnt;i++) pre[i]=max(pre[i-1],dp[pos[i]]);
	for(i=cnt;i>=1;i--) suf[i]=max(suf[i+1],dp[pos[i]]);
	for(i=1;i<=cnt;i++){
		up[pos[i]]=(hurt[pos[i]]?0:-1);
		if(~up[u]) up[pos[i]]=up[u]+1;
		mx=max(pre[i-1],suf[i+1]);
		if(~mx) up[pos[i]]=max(up[pos[i]],mx+2);
//		cout<<"	get up "<<pos[i]<<' '<<up[pos[i]]<<' '<<mx<<' '<<up[u]<<'\n';
	}
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;
		if(v==f) continue;
		dfs2(v,u);
	}
}
int main(){
	memset(first,-1,sizeof(first));
	n=read();m=read();d=read();int i,t1,t2;
	for(i=1;i<=m;i++) t1=read(),hurt[t1]=1;
	for(i=1;i<n;i++) t1=read(),t2=read(),add(t1,t2);
	dfs1(1,0);
	up[1]=(hurt[1]?0:-1);
	dfs2(1,0);
	int ans=0,flag;
	for(i=1;i<=n;i++){
//		cout<<i<<' '<<dp[i]<<' '<<up[i]<<'\n';
		flag=1;
		if(~dp[i]) flag=(flag&&(dp[i]<=d));
		if(~up[i]) flag=(flag&&(up[i]<=d));
		ans+=flag;
	}
	cout<<ans;
} 
