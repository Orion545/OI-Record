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
int n,q,first[1010],dep[1010],dis[1010],cnt,st[1010][20];
struct edge{
	int to,next,w;
}a[10010];
inline void add(int u,int v,int w){
	a[++cnt]=(edge){v,first[u],w};first[u]=cnt;
	a[++cnt]=(edge){u,first[v],w};first[v]=cnt;
} 
void dfs(int u,int f){
	int i,v;dep[u]=dep[f]+1;st[u][0]=f;
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(v==f) continue;
		dis[v]=dis[u]+a[i].w;dfs(v,u);
	}
}
void ST(){
	for(int j=1;j<=11;j++)
		for(int i=1;i<=n;i++)
			st[i][j]=st[st[i][j-1]][j-1];
}
int lca(int l,int r){
	int i;
	if(dep[l]>dep[r]) swap(l,r);
	for(i=11;i>=0;i--) if(dep[st[r][i]]>=dep[l]) r=st[r][i];
	if(l==r) return l;
	for(i=11;i>=0;i--){
		if(st[l][i]!=st[r][i]){
			l=st[l][i];
			r=st[r][i];
		}
	}
	return st[l][0];
}
int getdis(int l,int r){
	return dis[l]+dis[r]-2*dis[lca(l,r)];
}
int main(){
	memset(first,-1,sizeof(first));
	n=read();q=read();int i,t1,t2,t3;
	for(i=1;i<n;i++){
		t1=read();t2=read();t3=read();
		add(t1,t2,t3);
	}
	dfs(1,0);ST();
	for(i=1;i<=q;i++){
		t1=read();t2=read();
		printf("%d\n",getdis(t1,t2));
	}
}

