#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<cmath>
#include<vector>
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
int n,m,k;
namespace g{
	int first[100010],cnte;
	int dis[100010],pre[100010],pval[100010];
	void init(){memset(first,-1,sizeof(first));}
	struct edge{
	    int to,next,w;
	}a[200010];
	inline void add(int u,int v,int w){
	    a[++cnte]=(edge){v,first[u],w};first[u]=cnte;
	    a[++cnte]=(edge){u,first[v],w};first[v]=cnte;
	}
	struct node{
	    int pos,val;
	    inline bool operator <(const node &b)const{
	        return val>b.val;
	    }
	};
	priority_queue<node>q;
	void dij(){
	    int i,u,v,d;node tmp;
	    for(i=1;i<=n;i++) dis[i]=1e9;
	    dis[n]=0;q.push((node){n,0});
	    while(!q.empty()){
	        tmp=q.top();q.pop();
	        u=tmp.pos;d=tmp.val;
	        if(d!=dis[u]) continue;
	        for(i=first[u];~i;i=a[i].next){
	            v=a[i].to;
	            if(dis[v]>d+a[i].w){
	                dis[v]=d+a[i].w;pre[v]=u;pval[v]=a[i].w;
	                q.push((node){v,dis[v]});
	            }
	        }
	    }
	}
}
int hay[100010];
namespace t{
	int first[100010],cnte=-1;
	int dis[100010],st[100010][20];
	void init(){memset(first,-1,sizeof(first));}
	struct edge{
		int to,next,w;
	}a[200010];
	inline void add(int u,int v,int w){
	    a[++cnte]=(edge){v,first[u],w};first[u]=cnte;
	    a[++cnte]=(edge){u,first[v],w};first[v]=cnte;
	}
	void dfs(int u,int f,int w){
		int i,v;
		dis[u]=dis[f]+w;st[u][0]=f;
		for(i=first[u];~i;i=a[i].next){
			v=a[i].to;if(v==f) continue;
			dfs(v,u,a[i].w);
		}
	}
	void ST(){
		int i,j;
		for(j=1;j<=19;j++){
			for(i=1;i<=n;i++) st[i][j]=st[st[i][j-1]][j-1];
		}
	}
	int tag[100010],ok[100010],ans[100010];
	void dohay(){
		int i,u,j;
		for(i=1;i<=n;i++){
			if(hay[i]==-1) continue;
			u=i;
			for(j=19;j>=0;j--) if((dis[i]-dis[st[u][j]])*2<=hay[i]) u=st[u][j];
			tag[i]++;tag[st[u][0]]--;
		}
	}
	int gettag(int u,int f){
		int i,v,tmp=tag[u];
		for(i=first[u];~i;i=a[i].next){
			v=a[i].to;if(v==f) continue;
			tmp+=gettag(v,u);
		}
		if(tmp>0) ok[u]=1;
//		cout<<"gettag "<<u<<' '<<ok[u]<<'\n';
		return tmp;
	}
	void getans(int u,int f,int tmp){
		int i,v;ans[u]=tmp|ok[u];
//		cout<<"getans "<<u<<' '<<f<<' '<<dis[u]<<' '<<hay[u]<<' '<<tmp<<' '<<ans[u]<<'\n';
		for(i=first[u];~i;i=a[i].next){
			v=a[i].to;if(v==f) continue;
			getans(v,u,ans[u]);
		}
	}
}
int main(){
	freopen("dining.in","r",stdin);
	freopen("dining.out","w",stdout);
	g::init();t::init();memset(hay,-1,sizeof(hay));
    n=read();m=read();k=read();int i,t1,t2,t3;
    for(i=1;i<=m;i++){
        t1=read();t2=read();t3=read();
        g::add(t1,t2,t3);
    }
	for(i=1;i<=k;i++){
		t1=read();t2=read();
		hay[t1]=max(hay[t1],t2);
	}
    g::dij();
	for(i=1;i<n;i++){
		t::add(i,g::pre[i],g::pval[i]);
	}
	t::dfs(n,0,0);t::ST();
	t::dohay();t::gettag(n,0);t::getans(n,0,0);
	for(i=1;i<n;i++) printf("%d\n",t::ans[i]=1);
}
