/*

宣告——
汝身听吾号令，托付吾之命运于汝之剑，
应圣杯之召，若汝遵从此意志此理，回应吧。
在此起誓，吾愿成就世间一切之善行，吾愿诛尽世间一切之恶行。
汝为身缠三大言灵之七天，从抑止之轮显现吧，天秤之守护者！

*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<cmath>
#include<vector>
#include<queue>
#define end DEEP_DARK_FANTASY
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
int n,m,first[300010],cnte,clk;
int dep[300010],dfn[300010],end[300010],st[300010][20];
int w[300010],ans[300010];
struct edge{
	int to,next;
}a[600010];
inline void add(int u,int v){
	a[++cnte]=(edge){v,first[u]};first[u]=cnte;
	a[++cnte]=(edge){u,first[v]};first[v]=cnte;
}
void dfs(int u,int f){
	int i,v;
	st[u][0]=f;
	dfn[u]=++clk;
	dep[u]=dep[f]+1;
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(v==f) continue;
		dfs(v,u);
	}
	end[u]=clk;
}
void ST(){
	int i,j;
	for(j=1;j<=19;j++){
		for(i=1;i<=n;i++){
			st[i][j]=st[st[i][j-1]][j-1];
		}
	}
}
int lca(int l,int r){
	int i;
	if(dep[l]>dep[r]) swap(l,r);
	for(i=19;i>=0;i--) if(dep[st[r][i]]>=dep[l]) r=st[r][i];
	if(l==r) return l;
	for(i=19;i>=0;i--){
		if(st[l][i]!=st[r][i]){
			l=st[l][i];
			r=st[r][i];
		}
	}
	return st[l][0];
}
int getdis(int l,int r){
	return dep[l]+dep[r]-dep[lca(l,r)]*2;
}
int cnt[600010],opcnt[300010];
vector<int>v1[300010],v2[300010],v3[300010];
/*
v1[x]: the set of opening node of queries that positioned their LCA at node x
v2[x]: the set of opening node of queries that take x as their ending node
v3[x]: the set of ending node of queries that positioned their LCA at node x
*/
void dfs1(int u,int f){
	int pre=cnt[dep[u]+w[u]+300000],i,v;
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(v==f) continue;
		dfs1(v,u);
	}
	cnt[dep[u]+300000]+=opcnt[u];
	ans[u]+=cnt[dep[u]+w[u]+300000]-pre;
	for(i=0;i<v1[u].size();i++) cnt[dep[v1[u][i]]+300000]--;
}
void dfs2(int u,int f){
	int pre=cnt[w[u]-dep[u]+300000],i,v;
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(v==f) continue;
		dfs2(v,u);
	}
	for(i=0;i<v2[u].size();i++){
		cnt[v2[u][i]+300000]++;
	}
	ans[u]+=cnt[w[u]-dep[u]+300000]-pre;
	for(i=0;i<v3[u].size();i++){
		cnt[v3[u][i]+300000]--;
	}
}
int main(){
//	freopen("in.in","r",stdin);
//	freopen("my.out","w",stdout);
	memset(first,-1,sizeof(first));
	n=read();m=read();int i,t1,t2,f;
	for(i=1;i<n;i++){
		t1=read();t2=read();
		add(t1,t2);
	}
	dfs(1,0);ST();
	for(i=1;i<=n;i++) w[i]=read();
	for(i=1;i<=m;i++){
		t1=read();t2=read();f=lca(t1,t2);
		v1[f].push_back(t1);
		v3[f].push_back(getdis(t1,t2)-dep[t2]);
		v2[t2].push_back(getdis(t1,t2)-dep[t2]);
		opcnt[t1]++;
		if(dep[f]+w[f]==dep[t1]) ans[f]--;
	}
	dfs1(1,0);dfs2(1,0);
	for(i=1;i<=n;i++) printf("%d ",ans[i]);
}
	
