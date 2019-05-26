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
int n,m,first[100010],dep[100010],s[100010],fa[100010];
struct edge{
	int to,next;
}a[200010];
int cnte=0;
inline void add(int u,int v){
	a[++cnte]=(edge){v,first[u]};first[u]=cnte;
	a[++cnte]=(edge){u,first[v]};first[v]=cnte;
}
int u,v;
void dfs(int uu,int f){
//	cout<<"dfs "<<uu<<' '<<f<<'\n';
	int i,vv;
	dep[uu]=dep[f]+1;s[uu]=(dep[uu]%2)?-1:1;fa[uu]=f;
	for(i=first[uu];~i;i=a[i].next){
		vv=a[i].to;if(vv==f) continue;
		if(dep[vv]) u=uu,v=vv;
		else dfs(vv,uu),s[uu]+=s[vv];
	}
//	cout<<"finish "<<uu<<' '<<s[uu]<<'\n';
}
int lca(int u,int v){
	if(dep[u]>=dep[v]) swap(u,v);
//	cout<<"getlca "<<u<<' '<<v<<'\n';
	while(dep[fa[v]]>=dep[u]) v=fa[v];
	while(u!=v&&dep[u]>1) u=fa[u],v=fa[v];
	return u;
}
int b[100010],cnt;
int main(){
	memset(first,-1,sizeof(first));
	n=read();m=read();int i,t1,t2;
	for(i=1;i<=m;i++){
		t1=read();t2=read();
		add(t1,t2);
	}
	dfs(1,0);int ans=0,mid;
	if(m==n-1){
		if(s[1]){
			puts("-1");return 0;
		}
		for(i=1;i<=n;i++) ans+=abs(s[i]); 
		cout<<ans;return 0;
	}
//	cout<<u<<' '<<v<<' '<<mid<<'\n';
	if(((dep[u]^dep[v])&1)==0){//Ææ 
		if(s[1]&1){
			puts("-1");return 0;
		}
		int w=(-s[1])/2;ans=abs(w);
		while(u) s[u]+=w,u=fa[u];
		while(v) s[v]+=w,v=fa[v];
		for(i=1;i<=n;i++) ans+=abs(s[i]);
		cout<<ans;return 0;
	}
	if(s[1]){
		puts("-1");return 0;
	}
	mid=lca(u,v);
	while(u!=mid) b[++cnt]=s[u],dep[u]=-1,u=fa[u];
	while(v!=mid) b[++cnt]=-s[v],dep[v]=-1,v=fa[v];
	b[++cnt]=0;
	nth_element(b+1,b+(cnt/2),b+cnt+1);int w=b[cnt/2];
	for(i=1;i<=n;i++) if(~dep[i]) ans+=abs(s[i]);
	for(i=1;i<=cnt;i++) ans+=abs(b[i]-w);
	cout<<ans<<'\n';
}
