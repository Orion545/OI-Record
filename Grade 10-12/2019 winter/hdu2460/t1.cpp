#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#define ll long long
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
int n,m,q,first[100010],cnte=-1,ans;
struct edge{
	int to,next;
}a[400010];
inline void add(int u,int v){
	a[++cnte]=(edge){v,first[u]};first[u]=cnte;
	a[++cnte]=(edge){u,first[v]};first[v]=cnte;
}
int dfn[100010],low[100010],clk,ufs[100010],fa[100010];
inline int find(int x){return ((ufs[x]==x)?x:(ufs[x]=find(ufs[x])));}
inline void join(int x,int y){
	x=find(x);y=find(y);
	if(x==y) return;
	ufs[x]=y;
}
void tarjan(int u,int f){
	int i,v;
	dfn[u]=low[u]=++clk;fa[u]=f;
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(v==f) continue;
		if(!dfn[v]){
			tarjan(v,u);
			low[u]=min(low[u],low[v]);
			if(low[v]>=dfn[u]) ans++;
			else join(u,v);
		}
		else if(dfn[v]<dfn[u]) low[u]=min(low[u],dfn[v]);
	}
}
void insert(int u,int v){
	if(find(u)==find(v)) return;
	if(dfn[v]<dfn[u]) swap(u,v);
	while(dfn[v]>dfn[u]){
		if(find(fa[v])!=find(v)) ans--,join(fa[v],v);
		v=fa[v];
	}
	while(u!=v){
		if(find(fa[u])!=find(u)) ans--,join(fa[u],u);
		u=fa[u];
	}
}
int main(){
	n=read();m=read();int i,t1,t2,cases=0;
	while(n&&m){
		cases++;printf("Case %d:\n",cases);
		memset(first,-1,sizeof(first));
		memset(dfn,0,sizeof(dfn));
		memset(low,0,sizeof(low));
		memset(fa,0,sizeof(fa));
		cnte=-1;clk=0;ans=0;
		for(i=1;i<=n;i++) ufs[i]=i;
		for(i=1;i<=m;i++){
			t1=read();t2=read();
			add(t1,t2);
		}
		for(i=1;i<=n;i++) if(!dfn[i]) tarjan(i,0);
		q=read();
		while(q--){
			t1=read();t2=read();
			insert(t1,t2);
			printf("%d\n",ans);
		}
		n=read();m=read();
	}
}
