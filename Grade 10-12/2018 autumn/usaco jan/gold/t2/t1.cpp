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
ll n,m,len,ans=0;
ll dis[10010],pre[10010],siz[10010],num[10010];
namespace g{
	ll first[10010],cnte=-1;
	struct edge{
		ll to,next,w;
	}a[100010];
	void init(){
		memset(first,-1,sizeof(first));
	}
	inline void add(ll u,ll v,ll w){
		a[++cnte]=(edge){v,first[u],w};first[u]=cnte;
		a[++cnte]=(edge){u,first[v],w};first[v]=cnte;
	}
	struct node{
	    ll pos,val;
	    inline bool operator <(const node &b)const{
	        return val>b.val;
	    }
	};
	priority_queue<node>q;
	void dij(){
	    ll i,u,v,d;node tmp;
	    for(i=1;i<=n;i++) dis[i]=1e9,pre[i]=1e9;
	    dis[1]=0;q.push((node){1,0});pre[1]=0;
	    while(!q.empty()){
	        tmp=q.top();q.pop();
	        u=tmp.pos;d=tmp.val;
	        if(d!=dis[u]) continue;
	        for(i=first[u];~i;i=a[i].next){
	            v=a[i].to;
	            if(dis[v]>d+a[i].w||(dis[v]==d+a[i].w&&u<pre[v])){
	                dis[v]=d+a[i].w;pre[v]=u;
	                q.push((node){v,dis[v]});
	            }
	        }
	    }
	}
}
namespace t{
	ll first[10010],cnte=-1;
	struct edge{
		ll to,next;
	}a[100010];
	inline void add(ll u,ll v){
		a[++cnte]=(edge){v,first[u]};first[u]=cnte;
		a[++cnte]=(edge){u,first[v]};first[v]=cnte;
	}
	void init(){
		memset(first,-1,sizeof(first));
		for(ll i=2;i<=n;i++) add(i,pre[i]);
	}
	void dfs(ll u,ll f){
		ll i,v;siz[u]=num[u];
		for(i=first[u];~i;i=a[i].next){
			v=a[i].to;if(v==f) continue;
			dfs(v,u);
			siz[u]+=siz[v];
		}
		if(dis[u]<=len) return;
		ans=max(ans,siz[u]*(dis[u]-len));
	}
}
int main(){
	freopen("shortcut.in","r",stdin);
	freopen("shortcut.out","w",stdout); 
	n=read();m=read();len=read();ll i,t1,t2,t3;
	g::init();
	for(i=1;i<=n;i++) num[i]=read();
	for(i=1;i<=m;i++){
		t1=read();t2=read();t3=read();
		g::add(t1,t2,t3);
	}
	g::dij();
	t::init();
	t::dfs(1,0);
	cout<<ans<<'\n';
}
