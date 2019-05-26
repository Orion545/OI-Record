#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
#define mp make_pair
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

struct ufs{
	int n,f[2000010];
	ufs(){for(int i=1;i<=n;i++) f[i]=i;}
	int find(int x){return ((x==f[x])?x:(f[x]=find(x)));}
	void join(int x,int y){
		int fx=find(x),fy=find(y);
		f[fx]=fy;
	}
}S;

struct tree{
	int n,first[2000010],cnt,cntq,K;
	struct edge{
		int to,next,w;
	}a[4000010];
	int num[2000010],head[2000010];
	struct que{
		int to,next,w;
	}q[4000010];
	bool vis[2000010];
	int tot[30],add[2000010],del[2000010];
	
	tree(){
		memset(first,-1,sizeof(first));memset(a,0,sizeof(a));
		memset(head,-1,sizeof(head));memset(q,0,sizeof(q));
		n=cnt=0;memset(vis,0,sizeof(vis));
		memset(add,0,sizeof(add));memset(tot,0,sizeof(tot));
		for(int i=1;i<=n;i++) del[i]=(1<<K)-1;
	}
	inline void addedge(int u,int v,int w){
		a[++cnt]=(edge){v,first[u],w};first[u]=cnt;
		a[++cnt]=(edge){u,first[v],w};first[v]=cnt;
	}
	inline void query(int u,int v,int w){
		q[++cntq]=(que){v,head[u],w};head[u]=cntq;
		q[++cntq]=(que){u,head[v],w};head[v]=cntq;
	}
	inline void lca(int u,int v,int lca,int w){
		num[u]++;num[v]++;num[lca]-=2;
		add[u]|=(1<<w);add[v]|=(1<<w);del[lca]|=(1<<w);
	}
}T;

void tarjan(int u){
	int i,v;T.vis[u]=1;
	for(i=T.head[u];~i;i=T.q[i].next){
		v=T.q[i].to;
		if(T.vis[v]) T.lca(u,v,S.find(v),T.q[i].w-1);
	}
	for(i=T.first[u];~i;i=T.a[i].next){
		v=T.a[i].to;
		if(T.vis[v]) continue;
		tarjan(v);
		S.join(v,u);
	}
}

int lowbit(int x){}
pair<int,int> dfs(int u){
	int i,v,w,re=T.num[u],st=T.add[u];pair<int,int>tmp;
	for(i=T.first[u];~i;i=T.a[i].next){
		v=T.a[i].to;w=T.a[i].w;
		tmp=dfs(v);
		re+=tmp.first;st|=tmp.second;
//		ans=max(ans,w*tmp.first*lowbit(tmp.second)
	}
	return mp(re,st^T.del[u]);
}

int main(){
	
} 
