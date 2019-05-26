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
int n,m,cnt=-1,ans,K,first[1010],dis[1010],vis[1010];
struct edge{
    int to,next,w,cap;
}a[25010];
inline void add(int u,int v,int w,int cap){
    //cout<<"add "<<u<<" "<<v<<" "<<w<<" "<<cap<<"\n";
    a[++cnt]=(edge){v,first[u],w,cap};first[u]=cnt;
    a[++cnt]=(edge){u,first[v],-w,0};first[v]=cnt;
}
bool spfa(int s,int t){
    //cout<<"spfa "<<s<<" "<<t<<"\n";
    int q[5010],head=0,tail=1,u,v,w,i;
    memset(dis,-1,sizeof(dis));memset(vis,0,sizeof(vis));
    q[0]=t;dis[t]=0;vis[t]=1;
    while(head<tail){
        u=q[head++];vis[u]=0;
        //cout<<" bfs "<<u<<"\n";
        for(i=first[u];~i;i=a[i].next){
            v=a[i].to;w=a[i].w;
            if(a[i^1].cap&&((dis[v]==-1)||(dis[v]>dis[u]-w))){
                dis[v]=dis[u]-w;
                if(!vis[v]) q[tail++]=v,vis[v]=1;
            }
        }
    }
    return ~dis[s];
}
int dfs(int u,int t,int limit){
    //cout<<"dfs "<<u<<" "<<t<<" "<<limit<<'\n';
    if(u==t){vis[t]=1;return limit;}
    if(!limit){vis[u]=1;return 0;}
    int i,v,f,flow=0,w;vis[u]=1;
    for(i=first[u];~i;i=a[i].next){
        v=a[i].to;w=a[i].w;
        if((dis[v]==dis[u]-w)&&(!vis[v])&&a[i].cap){
            f=dfs(v,t,min(limit,a[i].cap));if(!f) continue;
            a[i].cap-=f;a[i^1].cap+=f;
            flow+=f;limit-=f;ans+=a[i].w*f;
            if(!limit) return flow;
        }
    }
    return flow;
}
int zkw(int s,int t){
    int re=0;
    while(spfa(s,t)){
        vis[t]=1;
        while(vis[t]){
            memset(vis,0,sizeof(vis));
            re+=dfs(s,t,inf);
            //cout<<"cur re="<<re<<"\n";
        }
    }
    return re;
}
int cost[5010],u[5010],v[5010],cap[5010];
int main(){
    memset(first,-1,sizeof(first));
    int i,maxflow;
    n=read();m=read();K=read();
    for(i=1;i<=m;i++){
        u[i]=read();v[i]=read();cap[i]=read();cost[i]=read();
        add(u[i],v[i],0,cap[i]);
    }
    printf("%d ",maxflow=zkw(1,n));
    memset(first,-1,sizeof(first));memset(a,0,sizeof(a));cnt=-1;
    for(i=1;i<=m;i++){
        add(u[i],v[i],0,cap[i]);
        add(u[i],v[i],cost[i],inf);
    }
    add(n,n+1,0,maxflow+K);
    zkw(1,n+1);
    printf("%d",ans);
}
