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
int n,m,p,cnt=-1,sum=0,first[10010],dep[10010],cur[10010],f[10010];
int siz[30],route[30][20],r[30];
struct edge{
    int to,next,w;
}a[300010];
inline void add(int u,int v,int w){
    if(u>=10000) u=10000;
    if(v>=10000) v=10000;
    //cout<<"add edge "<<u<<" "<<v<<" "<<w<<"\n";
    a[++cnt]=(edge){v,first[u],w};first[u]=cnt;
    a[++cnt]=(edge){u,first[v],0},first[v]=cnt;
}
int find(int x){
    //cout<<"find "<<x<<"\n";
    return ((f[x]==x)?x:(f[x]=find(f[x])));
}
void join(int x,int y){
    int fx=find(x),fy=find(y);
    f[fx]=fy;
}
int q[10010];
bool bfs(int s,int t){
    int i,u,v,head=0,tail=1;
    memset(q,0,sizeof(q));
    for(i=s;i<=t;i++) dep[i]=-1,cur[i]=first[i];
    q[0]=s;dep[s]=0;
    while(head<tail){
        u=q[head++];
        for(i=first[u];~i;i=a[i].next){
            v=a[i].to;
            if(~dep[v]||!a[i].w) continue;
            dep[v]=dep[u]+1;q[tail++]=v;
        }
    }
    return ~dep[t];
}
int _min(int l,int r){return (l>r)?r:l;}
int dfs(int u,int t,int limit){
    if(u==t||!limit) return limit;
    int i,v,f,flow=0;
    for(i=first[u];~i;i=a[i].next){
        v=a[i].to;
        if(dep[v]==dep[u]+1&&(f=dfs(v,t,_min(limit,a[i].w)))){
            flow+=f;limit-=f;
            a[i].w-=f;a[i^1].w+=f;
            if(!limit) return flow;
        }
    }
    return flow;
}
void dinic(int s,int t){
    while(bfs(s,t)) sum+=dfs(s,t,inf);
}
int main(){
    freopen("home.in","r",stdin);
    freopen("home.out","w",stdout);
    int i,j,ans=0;
    memset(first,-1,sizeof(first));
    for(i=0;i<=10000;i++) f[i]=i;
    n=read();m=read();p=read();
    for(i=1;i<=m;i++){
        siz[i]=read();r[i]=read();
        for(j=1;j<=r[i];j++){
            route[i][j]=read();
            if(route[i][j]==0) route[i][j]=n+1;
            if(route[i][j]==-1) route[i][j]=10000;
        }
        for(j=1;j<r[i];j++) join(route[i][j],route[i][j+1]);
        route[i][0]=1;
    }
    if(find(n+1)!=find(10000)){
        printf("0\n");return 0;
    }
    add(0,n+1,inf);
    while(++ans){
        //cout<<"new day "<<ans<<" "<<sum<<"\n";
        add(0,(ans+1)*(n+1),inf);
        for(i=1;i<=n+1;i++) add((ans-1)*(n+1)+i,(ans-0)*(n+1)+i,inf);
        for(i=1;i<=m;i++){
            add((ans-1)*(n+1)+route[i][route[i][0]],(ans-0)*(n+1)+route[i][(route[i][0])%r[i]+1],siz[i]);
            route[i][0]=(route[i][0])%r[i]+1;
        }
        dinic(0,10000);
        if(sum>=p){
            printf("%d",ans);return 0;
        }
    }
}
