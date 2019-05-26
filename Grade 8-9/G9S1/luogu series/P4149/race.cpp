#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<bits/stdc++.h>
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
int n,m,cnt,sum,root,first[200010],siz[200010],son[200010];
int d[200010],dis[200010],ans=inf,tmp[1000010];
bool vis[200010];
struct edge{
    int to,next,w;
}a[400010];
inline void add(int u,int v,int w){
    //cout<<"add edge "<<u<<" "<<v<<" "<<w<<"\n";
    a[++cnt]=(edge){v,first[u],w};first[u]=cnt;
    a[++cnt]=(edge){u,first[v],w};first[v]=cnt;
}
inline int _max(int l,int r){return (l>r)?l:r;}
inline int _min(int l,int r){return (l<r)?l:r;}
void getroot(int u,int f){
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
}
void calc(int u,int f){
    int i,v;
    if(dis[u]<=m) ans=_min(ans,tmp[m-dis[u]]+d[u]);
    for(i=first[u];~i;i=a[i].next){
        v=a[i].to;
        if(v==f||vis[v]) continue;
        dis[v]=dis[u]+a[i].w;d[v]=d[u]+1;
        calc(v,u);
    }
}
void update(int u,int f,int t){
    int i,v;
    if(dis[u]<=m){
        if(t) tmp[dis[u]]=_min(tmp[dis[u]],d[u]);
        else tmp[dis[u]]=inf;
    }
    for(i=first[u];~i;i=a[i].next){
        v=a[i].to;
        if(v==f||vis[v]) continue;
        update(v,u,t);
    }
}
void dfs(int u){
    //cout<<"dfs "<<u<<" "<<ans<<"\n";
    int i,v;vis[u]=1;tmp[0]=0;
    for(i=first[u];~i;i=a[i].next){
        v=a[i].to;
        if(vis[v]) continue;
        dis[v]=a[i].w;d[v]=1;
        calc(v,0);update(v,0,1);
    }
    for(i=first[u];~i;i=a[i].next) if(!vis[a[i].to]) update(a[i].to,0,0);
    for(i=first[u];~i;i=a[i].next){
        v=a[i].to;
        if(vis[v]) continue;
        sum=siz[v];root=0;
        getroot(v,0);
        dfs(root);
    }
}
int main(){

	int size = 128 << 20;
    char *p = (char*)malloc(size) + size;  
    __asm__("movl %0, %%esp\n" :: "r"(p));

    freopen("ioi2011-race.in","r",stdin);
    freopen("ioi2011-race.out","w",stdout);
    memset(first,-1,sizeof(first));
    int i,t1,t2,t3;
    n=read();m=read();
    for(i=1;i<=m;i++) tmp[i]=inf;
    for(i=1;i<n;i++){
        t1=read();t2=read();t3=read();
        add(t1+1,t2+1,t3);
    }
    sum=n;root=0;son[0]=n;
    getroot(1,0);
    dfs(root);
    if(ans!=inf) printf("%d\n",ans);
    else printf("-1");
}
