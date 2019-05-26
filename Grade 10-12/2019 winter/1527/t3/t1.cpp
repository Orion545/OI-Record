#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#define MOD 64123
#define uint unsigned int
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
inline void add(uint &x,uint y){
	x+=y;
	if(x>=MOD) x-=MOD;
}
int n,m,lim,first[2010],cnte=-1;
struct edge{
	int to,next;
}a[4010];
inline void add(int u,int v){
	a[++cnte]=(edge){v,first[u]};first[u]=cnte;
	a[++cnte]=(edge){u,first[v]};first[v]=cnte;
}
int w[2010],root;
uint dp[2010][2010],ans;
inline void dfs(int u,int f,uint g[2010]){
	int i,v;
	if(w[u]>w[root]||((w[u]==w[root])&&(u>root))){
//		for(i=1;i<=m;i++) dp[u][i]=g[i-1];
		memcpy(dp[u]+1,g,sizeof(uint)*m);
	}
	else{
//		for(i=1;i<=m;i++) dp[u][i]=g[i];
		memcpy(dp[u]+1,g+1,sizeof(uint)*m);
	}
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(v==f) continue;
		dfs(v,u,dp[u]);
	}
	for(i=1;i<=m;i++) add(g[i],dp[u][i]);
}
inline void calc(int u){
	root=u;int i,tot=0;
	for(i=1;i<=n;i++) if(w[i]>w[u]||(w[i]==w[u]&&(i>=u))) tot++;
	if(tot<m) return;
//	cout<<"calc "<<u<<' '<<tot<<' '<<w[u]<<'\n';
	memset(dp[u],0,sizeof(dp[u]));
	dp[u][1]=1;
	for(i=first[u];~i;i=a[i].next) dfs(a[i].to,u,dp[u]);
	add(ans,dp[u][m]*(uint)w[u]%MOD);
}
int main(){
	memset(first,-1,sizeof(first));
	n=read();m=read();lim=read();int i,t1,t2;
	for(i=1;i<=n;i++) w[i]=read();
	for(i=1;i<n;i++){
		t1=read();t2=read();
		add(t1,t2);
	}
	for(i=1;i<=n;i++) calc(i);
	cout<<ans<<'\n';
}
