#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<queue>
#define mp make_pair
#define ll long long
using namespace std;
inline ll read(){
	ll re=0,flag=1;char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
int n,first[200010],cnte,root;ll L,R;
struct edge{
	ll to,next,w;
}a[200010];
int siz[200010],son[200010],vis[200010],sum;
inline void add(ll u,ll v,ll w){
	a[++cnte]=(edge){v,first[u],w};first[u]=cnte;
	a[++cnte]=(edge){u,first[v],w};first[v]=cnte;
}
void getroot(int u,int f){
//	cout<<"getroot "<<u<<' '<<f<<'\n';
	int i,v;siz[u]=1;son[u]=0;
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(vis[v]||v==f) continue;
		getroot(v,u);
		siz[u]+=siz[v];
		if(son[u]<siz[v]) son[u]=siz[v];
	}
	son[u]=max(son[u],sum-siz[u]);
	if(son[u]<son[root]) root=u;
}
int maxdep[200010],dep[200010];
void getdep(int u,int f){
	int i,v;dep[u]=maxdep[u]=dep[f]+1;
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(vis[v]||v==f) continue;
		getdep(v,u);maxdep[u]=max(maxdep[u],maxdep[v]);
	}
}
struct node{
	ll pos,val,maxn;
}x[200010];int cnt;
bool cmp(node l,node r){
	return l.maxn<r.maxn;
}
ll maxn[200010],pp[200010],tmp[200010],MID,ans;ll tail,head,limd,q[200010];
queue<node>p;
void bfs(ll u,ll W){
//	cout<<"******** begin bfs "<<u<<' '<<W<<' '<<MID<<' '<<limd<<'\n';
	ll i,v,cur,from;head=0,tail=0;ll curw;
	for(i=min(limd,R-1);i>=min(limd,L-1);i--){
		assert(i<=limd&&i>=0);
		q[tail]=maxn[i];pp[tail++]=i;
		while((head<tail-1)&&q[tail-1]>q[tail-2]) q[tail-2]=q[tail-1],pp[tail-2]=pp[tail-1],q[--tail]=0,pp[tail]=0;
	}
	cur=1;p.push((node){u,0,W-MID});tmp[cur]=-1e15;
	while(!p.empty()){
		u=p.front().pos;curw=p.front().maxn;from=p.front().val;p.pop();
//		cout<<"	in bfs "<<u<<' '<<cur<<' '<<curw<<' '<<from<<' '<<head<<' '<<tail<<'\n';
		if(dep[u]>cur){
			cur++;tmp[cur]=-1e15;
			while(head<tail&&pp[head]>R-cur) q[head]=pp[head]=0,head++;
			if(L-cur>=0&&L-cur<=limd){
				q[tail]=maxn[L-cur];pp[tail++]=L-cur;
				while((head<tail-1)&&q[tail-1]>q[tail-2]) q[tail-2]=q[tail-1],pp[tail-2]=pp[tail-1],q[--tail]=0,pp[tail]=0;
			}
		}
		tmp[cur]=max(tmp[cur],curw);
		if(head<tail&&pp[head]+cur<=R&&pp[head]+cur>=L){
			ans=max(ans,q[head]+curw);
//			if(ans==q[head]+curw) cout<<"		*********** bfs renew ans "<<u<<' '<<cur<<' '<<curw<<' '<<from<<' '<<q[head]<<' '<<pp[head]<<' '<<ans<<'\n';
		}
		for(i=first[u];~i;i=a[i].next){
			v=a[i].to;if(vis[v]||v==from) continue;
//			cout<<"		to "<<v<<' '<<u<<'\n';
			p.push((node){v,u,curw+(ll)a[i].w-MID});
		}
	}
	for(i=1;i<=cur;i++){
		if(limd<i) maxn[i]=tmp[i];
		else maxn[i]=max(maxn[i],tmp[i]);
//		cout<<"			check "<<i<<' '<<maxn[i]<<'\n';
	}
	limd=cur;
}
void dfs(int u){
//	cout<<"dfs "<<u<<' '<<MID<<'\n';
	int i,v;vis[u]=1;cnt=0;
	dep[u]=0;
	for(i=first[u];~i;i=a[i].next) if(!vis[v=a[i].to]){
//		cout<<"	son of "<<u<<' '<<v<<'\n';
		getdep(v,u);x[++cnt]=(node){v,a[i].w,maxdep[v]};
	}
	sort(x+1,x+cnt+1,cmp);
	limd=0;maxn[0]=0;
	for(i=1;i<=cnt;i++)
		bfs(x[i].pos,x[i].val);
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(vis[v]) continue;
//		cout<<"	going llo "<<i<<' '<<v<<'\n';
		sum=((siz[v]>siz[u])?(sum-siz[u]):siz[v]);
		root=0;son[root]=sum;
		getroot(v,0);
		dfs(root);
	}
}
int main(){
	memset(first,-1,sizeof(first));
	n=read();ll i,maxt=0,t1,t2,t3;
	L=read();R=read();
	for(i=1;i<n;i++){
		t1=read();t2=read();t3=read();
		add(t1,t2,t3*10000);maxt=max(maxt,t3);
	}
	ll l=0,r=maxt*10000;
	while(l<r){
		MID=(l+r)>>1ll;MID++;ans=-1e15;
		memset(vis,0,sizeof(vis));
		sum=n;root=0;son[0]=n;
		getroot(1,0);
		dfs(root);
//		cout<<"erfen "<<l<<' '<<r<<' '<<MID<<' '<<ans<<'\n';
		if(ans>=0) l=MID;
		else r=MID-1;
	}
	printf("%.3lf",(double)l/10000.0);
}
