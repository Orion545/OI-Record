#include <bits/stdc++.h>
using namespace std;
inline int rd() {
    char ch=getchar(); int i=0,f=1;
    while(!isdigit(ch)) {if(ch=='-')f=-1; ch=getchar();}
    while(isdigit(ch)) {i=(i<<1)+(i<<3)+ch-'0'; ch=getchar();}
    return i*f;
}
const int N=2e5+50,INF=0x3f3f3f3f;
int n,col[N],fa[N],sze[N];
int d1[N]; //子树最远点
int d2[N]; //父亲最远点
int d3[N]; //经过存在黑点的子树最近点
int d4[N]; //经过存在黑点的父亲最近点
int d5[N]; //不经过某子树最远点
int d6[N]; //下界 
vector <int> edge[N]; 
inline void dfs1(int x,int f) {
    fa[x]=f; sze[x]=col[x];
    if((x!=1 && edge[x].size()==1) || (x==1 && !edge[x].size())) {
        d1[x]=0; 
        d3[x]=(col[x]?0:INF);
        return;
    }
    int mx=0,mx2=INF;
    for(auto v:edge[x]) {
        if(v==f) continue;
        dfs1(v,x); sze[x]+=sze[v];
        mx=max(mx,d1[v]); 
        if(d3[v]<INF) mx2=min(mx2,d1[v]);
    }
    d1[x]=mx+1; d3[x]=mx2+1; 
    if(col[x]) d3[x]=min(d3[x],d1[x]); 
    cout<<"finish dfs "<<x<<' '<<f<<' '<<d1[x]<<' '<<d3[x]<<'\n';
}
inline void dfs2(int x,int f) {
    d2[x]=max(d2[x],(f!=0)+d2[f]);
    if(f) d5[x]=max(d5[x],d2[x]-1);
    cout<<"dfs2 "<<x<<' '<<d5[x]<<' '<<d2[x]<<'\n';
    int mx,mx2;
    mx=-1;
    for(int e=0;e<edge[x].size();++e) {
        int v=edge[x][e]; if(v==f) continue;
        d2[v]=max(d2[v],mx+2);
        mx=max(mx,d1[v]);
    }
    mx=-1;
    for(int e=edge[x].size()-1;e>=0;e--) {
        int v=edge[x][e]; if(v==f) continue;
        d2[v]=max(d2[v],mx+2);
        mx=max(mx,d1[v]);
    }
    for(auto v:edge[x]) if(v!=f) dfs2(v,x);
}
int main() { 
    n=rd();
    memset(d3,0x3f,sizeof(d3));
    memset(d4,0x3f,sizeof(d4));
    for(int i=1;i<n;i++) {
        int x=rd(), y=rd();
        edge[x].push_back(y);
        edge[y].push_back(x); 
    }
    string s; cin>>s; int bz=0;
    for(int i=0;i<n;i++) col[i+1]=s[i]-'0', bz|=col[i+1];
    if(!bz) {puts("0"); return 0;}
    dfs1(1,0); 
    dfs2(1,0);
    long long ans=0;
    for(int i=1;i<=n;i++) {
        if(col[i]) d6[i]=0;
        else d6[i]=min(d3[i],(sze[i]==sze[1])?INF:d2[i]);
        int u=max(d1[i],d2[i])-1;
        for(auto v:edge[i]) {
            if(v==fa[i]) u=min(u,d1[i]+1);
            else u=min(u,d5[v]+1);
        } 
        cout<<i<<' '<<u<<' '<<d6[i]<<'\n';
        if(u>=d6[i]) ans=ans+u-d6[i]+1;
    }
    cout<<ans+1;
}
