#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
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
int n,m,cnt,root,sum,ans=0,first[10010];
int d[10010],dis[10010],siz[10010],son[10010];
bool vis[10010];
struct edge{
    int to,next,w;
}a[20010];
inline void add(int u,int v,int w){
    a[++cnt]=(edge){v,first[u],w};first[u]=cnt;
    a[++cnt]=(edge){u,first[v],w};first[v]=cnt;
}
void init(){
    cnt=0;ans=0;memset(first,-1,sizeof(first));
    memset(siz,0,sizeof(siz));memset(son,0,sizeof(son));
    memset(dis,0,sizeof(dis));memset(vis,0,sizeof(vis));
}
inline int _max(int l,int r){return (l>r)?l:r;}
inline int _min(int l,int r){return (l<r)?l:r;}
void getroot(int u,int f){
    //cout<<"getroot "<<u<<" "<<f<<"\n";
    int i,v;
    siz[u]=1;son[u]=0;
    for(i=first[u];~i;i=a[i].next){
        v=a[i].to;
        if(v==f||vis[v]) continue;
        getroot(v,u);
        siz[u]+=siz[v];son[u]=_max(son[u],siz[v]);
    }
    son[u]=_max(son[u],sum-siz[u]);
    if(son[u]<son[root]) root=u;
    //cout<<"finish getroot "<<u<<" "<<root<<"\n";
}
void getdis(int u,int f){
    dis[++dis[0]]=d[u];
    int i,v;
    for(i=first[u];~i;i=a[i].next){
        v=a[i].to;
        if(v==f||vis[v]) continue;
        d[v]=d[u]+a[i].w;
        getdis(v,u);
    }
}
int calc(int u,int dd){
    dis[0]=0;d[u]=dd;
    getdis(u,0);
    sort(dis+1,dis+dis[0]+1);
    int l=1,r=dis[0],re=0;
    while(l<r){
        if(dis[l]+dis[r]<=m) re+=r-l,l++;
        else r--;
    }
    return re;
}
void dfs(int u){
    //cout<<"dfs "<<u<<"\n";
    int i,v;vis[u]=1;
    ans+=calc(u,0);
    for(i=first[u];~i;i=a[i].next){
        v=a[i].to;
        if(vis[v]) continue;
        ans-=calc(v,a[i].w);
        sum=siz[v];root=0;
        getroot(v,0);
        dfs(root);
    }
}
int main(){
    //freopen("tree.in","r",stdin);
    int i,t1,t2,t3;
    while((n=read())&&(m=read())){
        init();
        for(i=1;i<n;i++){
            t1=read();t2=read();t3=read();
            add(t1,t2,t3);
        }
        sum=n;root=0;son[0]=n;
        getroot(1,0);
        dfs(root);
        printf("%d\n",ans);
    }
}
