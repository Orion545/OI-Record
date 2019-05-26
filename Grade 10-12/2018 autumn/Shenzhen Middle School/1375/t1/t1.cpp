#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<queue>
#define ll long long
using namespace std;
inline ll read(){
	ll re=0,flag=1;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(isdigit(ch)) re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
ll n,m,l,r,cnte=1,first[1010],dis[1010],vis[1010],ans=0,maxf=0;
struct edge{
	ll to,next,w,cap;
}a[20010];
inline void add(ll u,ll v,ll w,ll cap){
//	cout<<"add "<<u<<' '<<v<<' '<<w<<' '<<cap<<'\n';
	a[++cnte]=(edge){v,first[u],w,cap};first[u]=cnte;
	a[++cnte]=(edge){u,first[v],-w,0,};first[v]=cnte;
}
queue<ll>q;
bool spfa(ll s,ll t){
	ll i,u,v;
//	cout<<"spfa "<<s<<' '<<t<<' '<<ans<<' '<<maxf<<'\n';
	for(i=s;i<=t+1;i++) dis[i]=-111111111111111ll,vis[i]=0;
	vis[t]=1;dis[t]=0;q.push(t);
	while(!q.empty()){
		u=q.front();q.pop();vis[u]=0;
//		cout<<"	bfs "<<u<<' '<<dis[u]<<'\n';
		for(i=first[u];~i;i=a[i].next){
			v=a[i].to;
//			cout<<"		try "<<v<<' '<<a[i^1].cap<<' '<<dis[v]<<'\n';
			if(!a[i^1].cap) continue;
			if(dis[v]!=-111111111111111ll&&(dis[v]>=dis[u]+a[i^1].w)) continue;
			dis[v]=dis[u]+a[i^1].w;
			if(!vis[v]){
				vis[v]=1;
				q.push(v);
			}
		}
	}
	return dis[s]!=-111111111111111ll;
}
ll dfs(ll u,ll t,ll lim){
//	cout<<"dfs "<<u<<' '<<t<<' '<<lim<<'\n';
	if(u==t||!lim) return lim;
	ll i,v,f,flow=0;vis[u]=1;
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(vis[v]) continue;
		if(dis[v]==dis[u]-a[i].w&&(f=dfs(v,t,min(lim,a[i].cap)))){
			a[i].cap-=f;
			a[i^1].cap+=f;
			flow+=f;
			lim-=f;
			ans+=f*a[i].w;
			if(!lim){vis[u]=0;return flow;}
		}
	}
	dis[u]=-111111111111111ll;
	return flow;
}
void mcmf(ll s,ll t){
	while(spfa(s,t)){
		memset(vis,0,sizeof(vis));
		vis[t]=1;
		while(vis[t]){
			memset(vis,0,sizeof(vis));
			maxf+=dfs(s,t,1e9);
		}
	}
}
ll x[1010],y[1010];
int main(){
	memset(first,-1,sizeof(first));
	n=read();m=read();l=read();r=m-read();ll i;
	for(i=1;i<=n;i++) x[i]=read(),y[i]=read(),ans+=y[i];
	add(0,n+2,0,r);
	for(i=1;i<=m;i++) add(n+2,i,0,1);
	for(i=1;i<=n;i++){
		add(i,i+1,0,r-l);
		add(i,((i<=n-m)?i+m:n+1),x[i]-y[i],1);
	}
	mcmf(0,n+1);
	cout<<ans<<'\n';
}
