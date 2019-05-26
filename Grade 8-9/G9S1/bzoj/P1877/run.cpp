#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define inf 1e9
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
int n,m,cnt=-1,first[10010],dis[10010],vis[10010],ans;
struct edge{
    int to,next,w,cap;
}a[200010];
inline void add(int u,int v,int cap,int w){
    //cout<<u<<" "<<v<<" "<<cap<<" "<<w<<"\n";
    a[++cnt]=(edge){v,first[u],w,cap};first[u]=cnt;
    a[++cnt]=(edge){u,first[v],-w,0};first[v]=cnt;
}
int q[200010];
bool spfa(int s,int t){
    int i,u,v,head=0,tail=1;memset(q,0,sizeof(q));
    for(i=1;i<=(n<<1);i++) dis[i]=-1;memset(vis,0,sizeof(vis));
    dis[t]=0;q[0]=t;vis[t]=1;
    while(head<tail){
        u=q[head++];vis[u]=0;
        //cout<<"spfa "<<u<<" "<<dis[u]<<"\n";
        for(i=first[u];~i;i=a[i].next){
            v=a[i].to;
            //cout<<" to "<<v<<" "<<dis[v]<<" "<<a[i^1].cap<<"\n";
            if(!a[i^1].cap) continue;
            if(~dis[v]&&dis[v]<=dis[u]+a[i^1].w) continue;
            dis[v]=dis[u]+a[i^1].w;
            if(!vis[v]){
                vis[v]=1;
                q[tail++]=v;
            }
        }
    }
    return ~dis[s];
}
int dfs(int u,int t,int limit){
    //cout<<"dfs "<<u<<" "<<t<<" "<<limit<<"\n";
    if(u==t||!limit) return limit;
    int i,v,f,flow=0;vis[u]=1;
    for(i=first[u];~i;i=a[i].next){
        v=a[i].to;if(vis[v]) continue;
        if(dis[v]==dis[u]-a[i].w&&(f=dfs(v,t,min(limit,a[i].cap)))){
            flow+=f;limit-=f;
            a[i].cap-=f;a[i^1].cap+=f;
            ans+=f*a[i].w;
            //cout<<"ans added "<<f*a[i].w<<"\n";
            if(!limit) return flow;
        }
    }
    return flow;
}
int mcmf(int s,int t){
    int re=0,tmp;
    while(spfa(s,t)){
        vis[t]=1;
        while(vis[t]){
            memset(vis,0,sizeof(vis));
            re+=dfs(s,t,inf);
        }
        //cout<<"tmp re "<<re<<"\n";
    } 
    return re;
}
int main(){
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    memset(first,-1,sizeof(first));
    int i,t1,t2,t3,t4,S,T;
    n=read();m=read();S=1;T=n<<1;
    for(i=2;i<n;i++) add(i,i+n,1,0);
    add(1,n+1,inf,0);add(n,(n<<1),inf,0);
    for(i=1;i<=m;i++){
        t1=read();t2=read();t3=read();
        add(t1+n,t2,1,t3);
    }
    printf("%d ",mcmf(S,T));
    cout<<ans<<"\n";
}
