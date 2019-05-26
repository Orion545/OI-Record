#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int N=20005,M=100005,inf=2139062143;
int t,n,m,u,v,d,f,ns,rt,cnt,idx,head[N],to[N*2],nxt[N*2];
int dep[N],fa[N][20],siz[N],son[N],dfn[N],pos[N],top[N];
int minn[N],minv[N*4],tag[N*4];
bool use[M];
int s,mst,smst,pa[N],w[N],sont[N],num[N];
struct edge{
    int u,v,d;
    bool operator < (const edge &x)const{
        return d<x.d;
    }
}e[M];
vector<edge> link[N],edges;
void init(){
    smst=idx=cnt=rt=0;
    memset(use,0,sizeof(use));
    memset(head,0,sizeof(head));
    memset(dep,0,sizeof(dep));
    memset(fa,0,sizeof(fa));
    memset(son,0,sizeof(son));
    memset(sont,0,sizeof(sont));
    memset(w,0,sizeof(w));
    memset(minv,127,sizeof(minv));
    memset(tag,127,sizeof(tag));
    for(int i=1;i<=n;i++){
        pa[i]=i;
        link[i].clear();
    }
}
void adde(int u,int v){
    to[++cnt]=v;
    nxt[cnt]=head[u];
    head[u]=cnt;
}
int find(int u){
    return u==pa[u]?u:pa[u]=find(pa[u]);
}
void dfs(int u){
    for(int i=1;(1<<i)<=dep[u];i++){
        fa[u][i]=fa[fa[u][i-1]][i-1];
    }
    siz[u]=1;
    int v;
    for(int i=head[u];i;i=nxt[i]){
        v=to[i];
        if(v!=fa[u][0]){
            fa[v][0]=u;
            dep[v]=dep[u]+1;
            num[v]=++sont[u];
            dfs(v);
            siz[u]+=siz[v];
            if(!son[u]||siz[son[u]]<siz[v]){
                son[u]=v;
            }
        }
    }
}
void dfs(int u,int tp){
    dfn[u]=++idx;
    pos[idx]=u;
    top[u]=tp;
    if(son[u]){
        dfs(son[u],tp);
    }
    int v;
    for(int i=head[u];i;i=nxt[i]){
        v=to[i];
        if(v!=fa[u][0]&&v!=son[u]){
            dfs(v,v);
        }
    }
}
void pushdown(int o){
    minv[o*2]=min(minv[o*2],tag[o]);
    minv[o*2+1]=min(minv[o*2+1],tag[o]);
    tag[o*2]=min(tag[o*2],tag[o]);
    tag[o*2+1]=min(tag[o*2+1],tag[o]);
    tag[o]=inf;
}
void upd(int o,int l,int r,int L,int R,int x){
    if(L<=l&&R>=r){
        minv[o]=min(minv[o],x);
        tag[o]=min(tag[o],x);
        return;
    }
    if(tag[o]!=inf){
        pushdown(o);
    }
    int mid=(l+r)/2;
    if(L<=mid){
        upd(o*2,l,mid,L,R,x);
    }
    if(R>mid){
        upd(o*2+1,mid+1,r,L,R,x);
    }
    minv[o]=min(minv[o*2],minv[o*2+1]);
}
void update(int u,int v,int x){
    while(top[u]!=top[v]){
        upd(1,1,n,dfn[top[u]],dfn[u],x);
        u=fa[top[u]][0];
    }
    upd(1,1,n,dfn[v],dfn[u],x);
}
void getmin(int o,int l,int r){
    if(l==r){
        minn[pos[l]]=minv[o];
        return;
    }
    if(tag[o]!=inf){
        pushdown(o);
    }
    int mid=(l+r)/2;
    getmin(o*2,l,mid);
    getmin(o*2+1,mid+1,r);
}
void work(edge &e){
    int u=e.u,v=e.v,d;
    d=dep[u]-dep[v];
    for(int i=0;(1<<i)<=d;i++){
        if(d&(1<<i)){
            u=fa[u][i];
        }
    }
    if(u==v){
        u=e.u;
        d=dep[u]-dep[v]-2;
        if(d<0){
            return;
        }
        for(int i=0;(1<<i)<=d;i++){
            if(d&(1<<i)){
                u=fa[u][i];
            }
        }
        update(e.u,u,e.d);
        return;
    }
    int tmpu=u,tmpv=v;
    for(int i=15;i>=0;i--){
        if(fa[tmpu][i]!=fa[tmpv][i]){
            tmpu=fa[tmpu][i];
            tmpv=fa[tmpv][i];
        }
    }
    link[fa[tmpu][0]].push_back((edge){tmpu,tmpv,e.d});
    d=dep[e.u]-dep[tmpu]-1;
    if(d>=0){
        u=e.u;
        for(int i=0;(1<<i)<=d;i++){
            if(d&(1<<i)){
                u=fa[u][i];
            }
        }
        update(e.u,u,e.d);
    }
    d=dep[e.v]-dep[tmpv]-1;
    if(d>=0){
        v=e.v;
        for(int i=0;(1<<i)<=d;i++){
            if(d&(1<<i)){
                v=fa[v][i];
            }
        }
        update(e.v,v,e.d);
    }
}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        init();
        for(int i=1;i<=m;i++){
            scanf("%d%d%d%d",&e[i].u,&e[i].v,&d,&f);
            e[i].d=d*(1-f);
        }
        sort(e+1,e+m+1);
        ns=0;
        for(int i=1;i<=m&&ns<n-1;i++){
            u=find(e[i].u),v=find(e[i].v);
            if(u!=v){
                use[i]=true;
                pa[v]=u;
                ns++;
                adde(e[i].u,e[i].v);
                adde(e[i].v,e[i].u);
                w[e[i].u]+=e[i].d;
                w[e[i].v]+=e[i].d;
                smst+=e[i].d;
                if(!rt){
                    rt=e[i].u;
                }
            }
        }
        dfs(rt);
        dfs(rt,rt);
        for(int i=1;i<=m;i++){
            if(!use[i]){
                if(dep[e[i].u]<dep[e[i].v]){
                    swap(e[i].u,e[i].v);
                }
                work(e[i]);
            }
        }
        getmin(1,1,n);
        for(int i=1;i<=n;i++){
            edges.clear();
            s=sont[i];
            if(fa[i][0]){
                s++;
                for(int j=head[i];j;j=nxt[j]){
                    v=to[j];
                    if(v!=fa[i][0]&&minn[v]!=inf){
                        edges.push_back((edge){num[v],s,minn[v]});
                    }
                }
            }
            for(int j=0;j<link[i].size();j++){
                edges.push_back((edge){num[link[i][j].u],num[link[i][j].v],link[i][j].d});
            }
            sort(edges.begin(),edges.end());
//			if(i==29){
//				cout<<edges.size()<<'\n';
//				for(int j=0;j<edges.size();j++) cout<<edges[j].u<<' '<<edges[j].v<<' '<<edges[j].d<<'\n';
//			}
            mst=0;
            for(int j=1;j<=s;j++){
                pa[j]=j;
            }
            ns=0;
            for(int j=0;j<edges.size()&&ns<s-1;j++){
                u=find(edges[j].u),v=find(edges[j].v);
                if(u!=v){
                    pa[v]=u;
                    ns++;
                    mst+=edges[j].d;
                }
            }
            if(ns<s-1){
                puts("inf");
            }else{
                printf("%d\n",smst-w[i]+mst);
//				if(i==29) cout<<smst<<' '<<w[i]<<' '<<mst<<'\n';
            }
        }
    }
    return 0;
}
