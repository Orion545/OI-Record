/**************************************************************
    Problem: 2021
    User: 131441373
    Language: C++
    Result: Accepted
    Time:232 ms
    Memory:5776 kb
****************************************************************/
 
 
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <iostream>
using namespace std;
const int M=100007;
 
inline int rd(){
    int x=0;bool f=1;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') f=0;
    for(;isdigit(c);c=getchar()) x=x*10+c-48;
    return f?x:-x;
}
 
int tcas;
int n,m;
int g[M],te;
struct edge{int y,next;}e[M<<1];
 
void addedge(int x,int y){
    e[++te].y=y;e[te].next=g[x];g[x]=te;
}
 
int dfn[M],top[M],pid[M],idx;
int pre[M],dep[M];
int sz[M],son[M];
 
void dfs1(int x){
    sz[x]=1;
    int p,y;
    for(p=g[x];p;p=e[p].next)
    if((y=e[p].y)!=pre[x]){
        dep[y]=dep[x]+1;
        pre[y]=x;
        dfs1(y);
        sz[x]+=sz[y];
        if(sz[y]>sz[son[x]]) son[x]=y;
    }
}
 
void dfs2(int x){
    int p,y;
    dfn[x]=++idx;
    pid[idx]=x;
    if(son[x]){
        top[son[x]]=top[x];
        dfs2(son[x]);
    }
    for(p=g[x];p;p=e[p].next)
    if((y=e[p].y)!=pre[x]&&y!=son[x]){
        top[y]=y;
        dfs2(y);
    }
}
 
int getlca(int x,int y){
    while(top[x]!=top[y]){
        if(dep[top[x]]<dep[top[y]]) swap(x,y);
        x=pre[top[x]];
    }
    if(dep[x]>dep[y]) swap(x,y);
    return x;
}
 
int jump(int x,int stp){
    while(dep[x]-dep[top[x]]<=stp){
        stp-=dep[x]-dep[top[x]];
        if(stp==0) return top[x];
        stp--;
        x=pre[top[x]];
    }
    return pid[dfn[x]-stp];
}
 
struct node{
    int kd,x;
    node(int kk=0,int xx=0){kd=kk;x=xx;}
};
 
node getmid(int x,int y,int lca){
    int num=dep[x]+dep[y]-2*dep[lca]+1;
    int ocp=num/2;
    if(ocp<dep[x]-dep[lca]+1) return node(1,jump(x,ocp-1));
    else return node(2,jump(y,num-ocp-1));
}
 
int calc(int x,int y,int z,int lxy,int lxz){
    node xy=getmid(x,y,lxy);
    node xz=getmid(x,z,lxz);
    std::cout<<x<<' '<<y<<' '<<z<<' '<<xy.x<<' '<<xz.x<<'\n'; 
     
    int tp=getlca(xy.x,xz.x);
    if(xy.kd>xz.kd) swap(xy,xz);
     
    if(xy.kd==1&&xz.kd==1){
        if(dep[xy.x]<dep[xz.x]) return sz[xz.x];
        else return sz[xy.x];
    }
    else if(xy.kd==1&&xz.kd==2){
        if(tp==xy.x) return sz[xy.x]-sz[xz.x];
        else return sz[xy.x];
    }
    else{ //2 2
        if(dep[xy.x]>dep[xz.x]) swap(xy,xz);
        if(tp==xy.x) return n-sz[xy.x];
        else return n-sz[xy.x]-sz[xz.x]; 
    }
}
 
int main(){
    int i,x,y,z,xy,xz,yz;
    tcas=rd();
    while(tcas--){
        memset(g,0,sizeof(g));te=1;
        n=rd();
        for(i=1;i<n;i++){
            x=rd(),y=rd();
            addedge(x,y);
            addedge(y,x);
        }
         
        pre[1]=0; dep[1]=1;
        memset(son,0,sizeof(son));
        dfs1(1);
        top[1]=1; idx=0;
        dfs2(1);
         
        m=rd();
        for(i=1;i<=m;i++){
            x=rd(),y=rd(),z=rd();
            xy=getlca(x,y);
            xz=getlca(x,z);
            yz=getlca(y,z);
            printf("%d %d %d\n",calc(x,y,z,xy,xz),calc(y,x,z,xy,yz),calc(z,x,y,xz,yz));
        }
    }
    return 0;
}
