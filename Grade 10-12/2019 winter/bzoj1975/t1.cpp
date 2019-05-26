#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<queue>
#include<cmath>
#define mp make_pair
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
int n,m,ans,fa[5010],root[5010];double tot;
priority_queue<pair<double,int> >q;
namespace h{
	int ch[4000010][2],dis[4000010],end[4000010],cnt=0;double w[4000010];
	inline int newnode(double val,int ed){
		int cur=++cnt;
		ch[cur][0]=ch[cur][1]=0;dis[cur]=1;
		end[cur]=ed;w[cur]=val;
		return cur;
	}
	inline int merge(int x,int y){
//		cout<<"merge "<<x<<' '<<y<<'\n';
		if(!x||!y) return x^y;
		if(w[x]>w[y]) swap(x,y);
		int cur=++cnt;
		ch[cur][0]=ch[x][0];ch[cur][1]=ch[x][1];dis[cur]=dis[x];end[cur]=end[x];w[cur]=w[x];
		ch[cur][1]=merge(ch[cur][1],y);
		if(dis[ch[cur][0]]<dis[ch[cur][1]]) swap(ch[cur][0],ch[cur][1]);
		dis[cur]=dis[ch[x][1]]+1;
		return cur;
	}
}
namespace g{
	int first[5010],cnte=-1;
	void init(){memset(first,-1,sizeof(first));}
	struct edge{
		int to,next;double w;
	}a[400010];bool ontree[400010],vis[5010];
	inline void add(int u,int v,double w){
		a[++cnte]=(edge){v,first[u],w};first[u]=cnte;
		a[++cnte]=(edge){u,first[v],w};first[v]=cnte;
	}
	double dis[5010];
	void dij(){
		int i,u,v;double d;pair<double,int>tmp;
		for(i=1;i<=n;i++) dis[i]=1e18;
		dis[n]=0;q.push(mp(-dis[n],n));
		while(!q.empty()){
			tmp=q.top();q.pop();
			u=tmp.second;d=-tmp.first;
			if(fabs(d-dis[u])>1e-6) continue;
			for(i=first[u];~i;i=a[i].next){
				if((i&1)==0) continue;
				v=a[i].to;if(dis[v]-d-a[i].w<1e-6) continue;
				dis[v]=d+a[i].w;
				q.push(mp(-dis[v],v));
			}
		}
	}
	void dfs(int u){
		vis[u]=1;int i,v;
//		cout<<"dfs "<<u<<' '<<dis[u]<<' '<<fa[u]<<'\n';
		for(i=first[u];~i;i=a[i].next){
			if((i&1)==0) continue;
			v=a[i].to;
			if(fabs(dis[v]-a[i].w-dis[u])<1e-6&&!vis[v]){
				ontree[i^1]=1;fa[v]=u;dfs(v);
			}
		}
	}
	void heap(){
		int i,u,v;pair<double,int>tmp;
		for(i=0;i<=cnte;i++){
			if(i&1||ontree[i]) continue;
			u=a[i^1].to;v=a[i].to;
			if(dis[u]==1e18||dis[v]==1e18) continue;
//			cout<<"get not tree "<<u<<' '<<v<<' '<<dis[v]<<' '<<dis[u]<<' '<<a[i].w<<'\n';
			root[u]=h::merge(root[u],h::newnode(dis[v]+a[i].w-dis[u],v));
		}
		for(i=1;i<=n;i++) q.push(mp(-dis[i],i));
		while(!q.empty()){
			tmp=q.top();q.pop();
			u=tmp.second;
			if(fa[u]) root[u]=h::merge(root[u],root[fa[u]]);
		}
	}
}
void solve(){
	int i,u,v;double d,D;pair<double,int>tmp;
	if(g::dis[1]<tot) ans++,tot-=g::dis[1];
	if(root[1]) q.push(mp(-h::w[root[1]],root[1]));
	while(!q.empty()){
		tmp=q.top();q.pop();
		u=tmp.second;d=tmp.first;D=g::dis[1]-d;
//		cout<<"solve "<<u<<' '<<-d<<' '<<D<<' '<<tot<<'\n';
		if(D-tot>1e-6) break;
		tot-=D;ans++;
		if(h::ch[u][0]) q.push(mp(d+h::w[u]-h::w[h::ch[u][0]],h::ch[u][0]));
		if(h::ch[u][1]) q.push(mp(d+h::w[u]-h::w[h::ch[u][1]],h::ch[u][1]));
		if(root[h::end[u]]) q.push(mp(d-h::w[root[h::end[u]]],root[h::end[u]]));
	}
}
int main(){
	n=read();m=read();scanf("%lf",&tot);int i,j,t1,t2;double t3;
	g::init();
	for(i=1;i<=m;i++){
		t1=read();t2=read();scanf("%lf",&t3);
		g::add(t1,t2,t3);
	}
	g::dij();
	g::dfs(n);
	g::heap();
	solve();
	cout<<ans<<'\n';
}
