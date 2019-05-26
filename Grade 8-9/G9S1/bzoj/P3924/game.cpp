#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
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
int n,m,cnt,sum,root,first[100010],fa[100010],siz[100010],son[100010];
bool vis[100010]={0};
ll dis1[100010],dis2[100010],tot[100010];
struct edge{
    int to,next,w;
}a[200010];
void add(int u,int v,int w){
    a[++cnt]=(edge){v,first[u],w};first[u]=cnt;
    a[++cnt]=(edge){u,first[v],w};first[v]=cnt;
}
inline int _max(int l,int r){return (l>r)?l:r;}
inline int _min(int l,int r){return (l<r)?l:r;}
inline void _swap(int &l,int &r){l^=r;r^=l;l^=r;}
struct Original_Tree{
    int cnt,First[100010],dis[100010],dep[100010];
    int st[100010][20];
    struct Edge{int to,next,w;}A[200010];
    void add(int u,int v,int w){
        A[++cnt]=(Edge){v,First[u],w};First[u]=cnt;
        A[++cnt]=(Edge){u,First[v],w};First[v]=cnt;
    }
    void ddfs(int u,int f){
        st[u][0]=f;int i,v;
        //cout<<"dfs "<<u<<" "<<f<<" "<<dis[u]<<" "<<dep[u]<<"\n";
        for(i=First[u];~i;i=A[i].next){
            v=A[i].to;
            if(v==f) continue;
            dis[v]=dis[u]+A[i].w;dep[v]=dep[u]+1;
            ddfs(v,u);
        }
    }
    void initst(){
        dis[1]=0;dep[1]=1;ddfs(1,0);int i,j;
        for(j=1;j<20;j++){
            for(i=1;i<=n;i++) st[i][j]=st[st[i][j-1]][j-1];
        }
        //for(i=1;i<=n;i++){
            //for(j=0;j<=3;j++) cout<<st[i][j]<<" ";
            //cout<<"\n";
        //}
    }
    int getdis(int u,int v){
        if(dep[u]>dep[v]) _swap(u,v);
        int i,lca,tu=u,tv=v;
        //cout<<"begin "<<u<<" "<<v<<"\n";
        for(i=19;i>=0;i--) 
            if(dep[st[v][i]]>=dep[u]) v=st[v][i];
        //cout<<"half finish "<<u<<" "<<v<<"\n";
        if(u==v) return dis[tv]-dis[u];
        for(i=19;i>=0;i--)
            if(st[u][i]!=st[v][i]){
                u=st[u][i];
                v=st[v][i];
            }
        lca=st[u][0];
        //cout<<"getdis "<<tu<<" "<<tv<<" "<<lca<<"\n";
        return dis[tu]+dis[tv]-2*dis[lca];
    }
}T;
void getroot(int u,int f){
    int i,v;siz[u]=1;son[u]=0;
    for(i=T.First[u];~i;i=T.A[i].next){
        v=T.A[i].to;
        if(v==f||vis[v]) continue;
        getroot(v,u);
        siz[u]+=siz[v];son[u]=_max(son[u],siz[v]);
    }
    son[u]=_max(son[u],sum-siz[u]);
    if(son[u]<son[root]) root=u;
}
void dfs(int u,int f){
    int i,v;vis[u]=1;fa[u]=f;
    for(i=T.First[u];~i;i=T.A[i].next){
        v=T.A[i].to;
        if(vis[v]) continue;
        sum=siz[v];root=0;
        getroot(v,0);add(u,root,v);
        dfs(root,u);
    }
}
void change(int u,int delta){
    tot[u]+=delta;int v,dis;
    for(v=u;fa[v];v=fa[v]){
        dis=T.getdis(u,fa[v]);
        dis1[fa[v]]+=(ll)dis*delta;
        dis2[v]+=(ll)dis*delta;
        tot[fa[v]]+=delta;
    }
}
ll calc(int u){
    ll re=dis1[u];int i,dis;
    for(i=u;fa[i];i=fa[i]){
        dis=T.getdis(u,fa[i]);
        re+=dis1[fa[i]]-dis2[i];
        re+=dis*(tot[fa[i]]-tot[i]);
    }
    return re;
}
ll query(int u){
    ll re=calc(u),tmp;int i,v;
    for(i=first[u];~i;i=a[i].next){
        v=a[i].to;
        tmp=calc(a[i].w);
        if(tmp<re) return query(v);
    }
    return re;
}
int main(){
    freopen("zjoi15_tree4.in","r",stdin);
    freopen("zjoi15_tree.out","w",stdout);

    memset(tot,0,sizeof(tot));
    memset(dis1,0,sizeof(dis1));
    memset(dis2,0,sizeof(dis2));
    memset(first,-1,sizeof(first));
    memset(T.First,-1,sizeof(T.First));
    int i,t1,t2,t3,tmp;
    n=read();m=read();
    for(i=1;i<n;i++){
        t1=read();t2=read();t3=read();
        T.add(t1,t2,t3);
    }
    T.initst();
    sum=son[0]=n;root=0;
    getroot(1,0);tmp=root;
    dfs(root,0);root=tmp;
    for(i=1;i<=m;i++){
        t1=read();t2=read();
        change(t1,t2);
        printf("%lld\n",query(root));
    }
}
