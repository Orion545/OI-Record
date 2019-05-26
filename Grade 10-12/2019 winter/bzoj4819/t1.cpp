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
	while(!isdigit(ch)){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(isdigit(ch)) re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
namespace g{
	int first[210],cnte=-1;double ans;int flow;
	struct edge{
		int to,next,w;double cost;
		edge(){}
		edge(int a,int b,int c,double d){to=a;next=b;w=c;cost=d;}
	}a[21010];
	inline void init(){
		memset(first,-1,sizeof(first));
		cnte=-1;
	}
	inline void add(int u,int v,int w,double cost){
//		cout<<"add "<<u<<' '<<v<<' '<<w<<' '<<cost<<'\n';
		a[++cnte]=edge(v,first[u],w,-cost);first[u]=cnte;
		a[++cnte]=edge(u,first[v],0,cost);first[v]=cnte;
	}
	queue<int>q;double dis[210];int vis[210];
	bool spfa(int s,int t){
		int i,u,v;
		for(i=s;i<=t;i++) dis[i]=-1;
		q.push(t);dis[t]=0;
		while(!q.empty()){
			u=q.front();q.pop();vis[u]=0;
//			cout<<"spfa "<<u<<' '<<dis[u]<<'\n';
			for(i=first[u];~i;i=a[i].next){
				v=a[i].to;
				if(!a[i^1].w||(dis[v]!=-1&&dis[v]<=dis[u]-a[i].cost)) continue;
				dis[v]=dis[u]-a[i].cost;
				if(!vis[v]) vis[v]=1,q.push(v);
			}
		}
		return dis[s]!=-1;
	}
	int dfs(int u,int t,int lim){
		if(u==t||!lim) return lim;
		int i,v,f,flow=0;vis[u]=1;
		for(i=first[u];~i;i=a[i].next){
			v=a[i].to;if(vis[v]) continue;
			if(dis[v]==dis[u]-a[i].cost&&(f=dfs(v,t,min(lim,a[i].w)))){
				a[i].w-=f;a[i^1].w+=f;
				flow+=f;lim-=f;
				ans+=1.0*f*a[i].cost;
				if(!lim){vis[u]=0;return flow;}
			}
		}
		dis[u]=-1e9;
		return flow;
	}
	void zkw(int s,int t){
		ans=flow=0;
		while(spfa(s,t)){
			vis[t]=1;
			while(vis[t]){
				memset(vis,0,sizeof(vis));
				flow+=dfs(s,t,1e9);
			}
		}
	}
}
int n,a[110][110],b[110][110];
bool check(double mid){
	int i,j;
	g::init();
	for(i=1;i<=n;i++){
		g::add(0,i,1,0);
		g::add(i+n,n*2+1,1,0);
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			g::add(i,j+n,1,1.0*a[i][j]-1.0*mid*b[i][j]);
		}
	}
	g::zkw(0,2*n+1);
	return g::ans<=-(1e-8);
}
int main(){
	n=read();int i,j;
	for(i=1;i<=n;i++) for(j=1;j<=n;j++) a[i][j]=read();
	for(i=1;i<=n;i++) for(j=1;j<=n;j++) b[i][j]=read();
	double l=-1e4,r=1e4,mid;
	while((r-l)>1e-8){
		mid=(l+r)*0.5;
		if(check(mid)) l=mid;
		else r=mid;
	}
	printf("%.6lf\n",l);
}
