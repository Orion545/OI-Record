#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
struct edge{
	int to,next;
}e[50010];
int first[50010],dep[50010],fa[50010],size[50010];
int top[50010],son[50010],rank[50010],id[50010];
int a[200010];
int n,m,q,num[50010],time=0;
bool vis[50010];
void dfs1(int k,int from){
	dep[k]=dep[from]+1;fa[k]=from;vis[k]=size[k]=1;
	for(int p=first[k];p!=-1;p=e[p].next){
		if(!vis[e[p].to]){
			dfs1(e[p].to,k);
			size[k]+=size[e[p].to];
			if(!son[k]||size[e[p].to]>size[son[k]]) son[k]=e[p].to;
		}
	}
}
void dfs2(int k,int tp){
	top[k]=tp;id[k]=++time;
	rank[id[k]]=k;
	if(!son[k]) return;
	dfs2(son[k],tp);
	for(int p=first[k];p!=-1;p=e[p].next){
		int v=e[p].to;
		if(v!=fa[k]&&v!=son[k]) dfs2(v,v);
	} 
}
int main(){
	int a,b,c,u,v;
	while(~scanf("%d%d%d",&n,&m,&q)){
		memset(first,-1,sizeof(first));
		for(int i=1;i<=n;i++) scanf("%d",&num[i]);
		for(int i=1;i<n;i++){
			scanf("%d%d",&u,&v);m++;
			e[2*i].to=v;e[2*i].next=first[u];first[u]=i*2;
			e[2*i+1].to=u;e[2*i+1].next=first[v];first[v]=i*2+1;
		}
		dfs1(1,0);dfs2(1,1);
		//start here
	}
} 
