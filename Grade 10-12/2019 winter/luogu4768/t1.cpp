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
namespace gr{/*{{{*/
    ll first[400010],dis[400010],cnte=-1;
    struct edge{
        ll to,next,w;
    }a[800010];
    void init(ll n){
        memset(first,-1,sizeof(first));
        memset(a,0,sizeof(a));
        cnte=-1;
        for(ll i=1;i<=n*2;i++) dis[i]=1e16;
    }
    inline void add(ll u,ll v,ll w){
//		cout<<"gr add "<<u<<' '<<v<<' '<<w<<'\n';
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
        dis[1]=0;q.push((node){1,0});
        while(!q.empty()){
            tmp=q.top();q.pop();
            u=tmp.pos;d=tmp.val;
            if(d!=dis[u]) continue;
//			cout<<"dij "<<u<<' '<<d<<'\n';
            for(i=first[u];~i;i=a[i].next){
                v=a[i].to;
                if(dis[v]>d+a[i].w){
                    dis[v]=d+a[i].w;
                    q.push((node){v,dis[v]});
                }
            }
        }
    }
}/*}}}*/
namespace t{/*{{{*/
    ll cntn,first[400010],cnte=-1,val[400010];
    struct edge{
        ll to,next;
    }a[800010];
    inline void add(ll u,ll v){
//		cout<<"t add "<<u<<' '<<v<<'\n';
        a[++cnte]=(edge){v,first[u]};first[u]=cnte;
        a[++cnte]=(edge){u,first[v]};first[v]=cnte;
    }
    ll st[400010][20],dep[400010],minn[400010][20],son[400010];
    void init(ll n){
        cntn=n;cnte=-1;
        memset(st,0,sizeof(st));
        memset(dep,0,sizeof(dep));
        memset(minn,0,sizeof(minn));
        memset(son,0,sizeof(son));
        memset(a,0,sizeof(a));
        memset(first,-1,sizeof(first));
        for(ll i=1;i<=n*2;i++) val[i]=1e16;
    }
    void dfs(ll u,ll f){
        ll i,v;
        dep[u]=dep[f]+1;
        st[u][0]=f;minn[u][0]=min(val[f],val[u]);
        son[u]=gr::dis[u];
//		cout<<"dfs "<<u<<' '<<f<<' '<<dep[u]<<' '<<val[u]<<' '<<son[u]<<'\n';
        for(i=first[u];~i;i=a[i].next){
            v=a[i].to;if(v==f) continue;
            dfs(v,u);
            son[u]=min(son[u],son[v]);
        }
//		cout<<"finish dfs "<<u<<' '<<son[u]<<'\n';
    }
    void ST(){
        ll i,j;
        for(j=1;j<=19;j++){
            for(i=1;i<=cntn;i++){
                st[i][j]=st[st[i][j-1]][j-1];
                minn[i][j]=min(val[st[i][j]],min(minn[i][j-1],minn[st[i][j-1]][j-1]));
            }
        }
    }
    ll solve(ll u,ll lim){
        ll i,tmp=u;
        for(i=19;i>=0;i--){
			if(minn[tmp][i]>lim){
//				cout<<"solve "<<tmp<<' '<<minn[tmp][i]<<' '<<st[tmp][i]<<' '<<lim<<'\n';
				tmp=st[tmp][i];
			}
		}
//		cout<<"final solve "<<u<<' '<<tmp<<' '<<son[tmp]<<'\n';
        return son[tmp];
    }
}/*}}}*/
namespace g{/*{{{*/
    ll cnte=-1,f[400010];
    struct edge{
        ll from,to,w;
    }a[800010];
    void init(ll n){
    	cnte=-1;
        memset(a,0,sizeof(a));
        for(ll i=1;i<=n*2;i++) f[i]=i;
    }
    inline bool cmp(edge l,edge r){
        return l.w>r.w;
    }
    inline void add(ll u,ll v,ll w){
//		cout<<"g add "<<u<<' '<<v<<' '<<w<<'\n';
        a[++cnte]=(edge){u,v,w};
    }
    ll find(ll x){return ((x==f[x])?x:f[x]=find(f[x]));}
    void kruskal(){
        ll fx,fy,x,y;
        sort(a,a+cnte+1,cmp);
        for(register ll i=0;i<=cnte;i++){
            x=a[i].from;y=a[i].to;
//			cout<<"try "<<x<<' '<<y<<'\n';
            fx=find(x);fy=find(y);
            if(fx==fy) continue;
//			cout<<"kruskal "<<x<<' '<<fx<<' '<<y<<' '<<fy<<' '<<a[i].w<<'\n';
            t::cntn++;t::val[t::cntn]=a[i].w;
            f[fx]=(t::cntn);
            f[fy]=(t::cntn);
            t::add(fx,t::cntn);
            t::add(fy,t::cntn);
            assert(t::cntn<=400000);
            assert(t::cnte<=800000);
        }
    }
}/*}}}*/
int main(){
	freopen("return.in","r",stdin);
	freopen("return.out","w",stdout);
    ll T=read(),t1,t2,t3,i,t4,n,m,q,ans,k,s;
    while(T--){
        n=read();m=read();
        t::init(n);g::init(n);gr::init(n);
        for(i=1;i<=m;i++){
            t1=read();t2=read();t3=read();t4=read();
            gr::add(t1,t2,t3);
            g::add(t1,t2,t4);
        }
        gr::dij();
        g::kruskal();
        t::dfs(t::cntn,0);
        t::ST();
        q=read();k=read();s=read();ans=0;
        while(q--){
            t1=read();t2=read();
            t1=(t1+k*ans-1)%n+1;
            t2=(t2+k*ans)%(s+1);
            printf("%lld\n",ans=t::solve(t1,t2));
        }
    }
}
