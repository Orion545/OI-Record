#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<queue>
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
int T,n,m,op,ed,st[1010],td[1010];
struct graph{
	int first[1010],dfn[1010],low[1010],clk,s[1010],top,ins[1010];
	int belong[1010],bcc,cnt;
	struct edge{
		int from,to,next;
	}a[10010];
	void clear(){
		memset(first,-1,sizeof(first));memset(a,0,sizeof(a));
		memset(dfn,0,sizeof(dfn));memset(low,0,sizeof(low));memset(belong,0,sizeof(belong));
		clk=top=bcc=cnt=0;
	}
	inline void add(int u,int v){
		a[++cnt]=(edge){u,v,first[u]};first[u]=cnt;
	}
	void tarjan(int u){
		int i,v;dfn[u]=low[u]=++clk;ins[u]=1;s[++top]=u;
		for(i=first[u];~i;i=a[i].next){
			v=a[i].to;
			if(!dfn[v]){
				tarjan(v);low[u]=min(low[u],low[v]);
			}
			else if(ins[v]) low[u]=min(low[u],dfn[v]);
		}
		if(dfn[u]!=low[u]) return;
		bcc++;
		while(s[top]!=u){
			belong[s[top]]=bcc;
			ins[s[top]]=0;s[top--]=0;
		}
		belong[s[top]]=bcc;
		ins[s[top]]=0;s[top--]=0;
	}
}g;
struct netflow{
	int first[10010],dis[10010],cnt,vis[10010],ans;
	struct edge{
		int to,next,w,cap;
	}a[100010];
	void clear(){
		memset(first,-1,sizeof(first));memset(a,0,sizeof(a));
		cnt=-1;ans=0;
	}
	inline void add(int u,int v,int w,int cap){
//		cout<<"add netflow "<<u<<' '<<v<<' '<<w<<' '<<cap<<'\n';
		a[++cnt]=(edge){v,first[u],-w,cap};first[u]=cnt;
		a[++cnt]=(edge){u,first[v],w,0};first[v]=cnt;
	}
	bool spfa(int s,int t){
//		cout<<"begin spfa "<<s<<' '<<t<<'\n';
		queue<int>q;int i,u,v;
		for(i=s;i<=t;i++) dis[i]=1e9,vis[i]=0;
		q.push(t);vis[t]=1;dis[t]=0;
		while(!q.empty()){
			u=q.front();q.pop();vis[u]=0;
//			cout<<"	spfa "<<u<<' '<<dis[u]<<'\n';
			for(i=first[u];~i;i=a[i].next){
				v=a[i].to;if(!a[i^1].cap) continue;
//				cout<<"		try "<<v<<'\n';
				if(dis[v]>dis[u]-a[i].w){
//					cout<<"		renew "<<v<<' '<<dis[v]<<' '<<dis[u]-a[i].w<<'\n';
					dis[v]=dis[u]-a[i].w;
					if(!vis[v]) vis[v]=1,q.push(v);
				}
			}
		}
		return dis[s]!=1e9;
	}
	int dfs(int u,int t,int limit){
//		cout<<"dfs "<<u<<' '<<t<<' '<<limit<<'\n';
		if(u==t||!limit) return limit;
		int i,v,f,flow=0;vis[u]=1;
		for(i=first[u];~i;i=a[i].next){
			v=a[i].to;if(vis[v]) continue;
			if(dis[v]==dis[u]-a[i].w&&(f=dfs(v,t,min(limit,a[i].cap)))){
				a[i].cap-=f;a[i^1].cap+=f;
				limit-=f;flow+=f;
				ans+=f*a[i].w;
				if(!limit){vis[u]=0;return flow;}
			}
		}
		dis[u]=1e9;return flow;
	}
	int mcmf(int s,int t){
		int re=0;
		while(spfa(s,t)){
			memset(vis,0,sizeof(vis));
			re+=dfs(s,t,1e9);
			if(ans==-g.bcc) return re;
		}
		return -1;
	}
}G;
int main(){
//	freopen("7.in","r",stdin);
//	freopen("my.out","w",stdout);
	T=read();
	while(T--){
		g.clear();G.clear();
		n=read();m=read();op=read();ed=read();int i,t1,t2;
		for(i=1;i<=op;i++) st[i]=read();
		for(i=1;i<=ed;i++) td[i]=read();
		for(i=1;i<=m;i++){
			t1=read();t2=read();
			g.add(t1,t2);
		}
		for(i=1;i<=n;i++) if(!g.dfn[i]) g.tarjan(i);
//		for(i=1;i<=n;i++) cout<<i<<" belong to bcc "<<g.belong[i]<<'\n';
		for(i=1;i<=m;i++){
			if(g.belong[g.a[i].from]==g.belong[g.a[i].to]) continue;
			G.add(g.belong[g.a[i].from]+g.bcc,g.belong[g.a[i].to],0,1e9);
		}
		for(i=1;i<=g.bcc;i++) G.add(i,i+g.bcc,1,1),G.add(i,i+g.bcc,0,1e9);
		for(i=1;i<=op;i++) G.add(0,g.belong[st[i]],0,1e9);
		for(i=1;i<=ed;i++) G.add(g.belong[td[i]]+g.bcc,g.bcc*2+1,0,1e9);
		int tans=G.mcmf(0,g.bcc*2+1);
		if(~tans) printf("%d\n",tans);
		else puts("no solution");
	}
}

