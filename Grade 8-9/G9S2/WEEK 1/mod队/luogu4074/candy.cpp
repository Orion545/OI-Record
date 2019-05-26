#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define ll long long
using namespace std;
inline ll read(){
    ll re=0,flag=1;char ch=getchar();
    while(ch>'9'||ch<'0'){
        if(ch=='-') flag=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9') re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
    return re*flag;
}
struct edge{
    ll to,next;
}a[200010];
ll n,m,Q,first[100010],cntt,clk,block;
ll fa[100010],dep[100010],st[100010][20],dfn[100010];
ll v[100010],w[100010],x[100010];
inline void add(ll u,ll v){
    a[++cntt]=(edge){v,first[u]};first[u]=cntt;
    a[++cntt]=(edge){u,first[v]};first[v]=cntt;
}
void dfs(ll u,ll f){
    //cout<<"dfs "<<u<<" "<<f<<"\n";
    ll i,v;
    fa[u]=st[u][0]=f;dep[u]=dep[f]+1;dfn[u]=++clk;
    for(i=first[u];~i;i=a[i].next){
        v=a[i].to;
        if(v==f) continue;
        dfs(v,u);
    }
}
void init(){
    for(ll i=1;i<=18;i++){
        for(ll j=1;j<=n;j++){
            st[j][i]=st[st[j][i-1]][i-1];
        }
    }
}
void _swap(ll &l,ll &r){l^=r;r^=l;l^=r;}
ll LCA(ll l,ll r){
    //cout<<"lca "<<l<<" "<<r<<"\n";
    if(dep[l]>dep[r]) _swap(l,r);
    ll i;
    for(i=18;i>=0;i--) if(dep[st[r][i]]>=dep[l]) r=st[r][i];
    if(l==r) return l;
    for(i=18;i>=0;i--){
        if(st[l][i]!=st[r][i]){
            l=st[l][i];r=st[r][i];
        }
    }
    return fa[l];
}
ll curl,curr,curc,cntq,cntc,cnt[1000010];bool vis[100010];
ll ans[100010],tot;
struct query{
    ll l,r,c,i;
}q[100010];
bool cmp(query l,query r){
    if(dfn[l.l]/block!=dfn[r.l]/block) return dfn[l.l]/block<dfn[r.l]/block;
    else{
        if(dfn[l.r]/block!=dfn[r.r]/block) 
            return dfn[l.r]/block<dfn[r.r]/block;
        else return l.c<r.c;
    }
}
struct change{
    ll pos,to;
}c[100010];
void rev(ll i){
    if(vis[i]) vis[i]=0,tot-=v[x[i]]*w[cnt[x[i]]],cnt[x[i]]--;
    else vis[i]=1,cnt[x[i]]++,tot+=v[x[i]]*w[cnt[x[i]]];
    //cout<<"rev node "<<i<<" "<<x[i]<<" "<<tot<<"\n";
}
void change(ll i){
    //cout<<"change node "<<i<<" "<<c[i].pos<<" "<<c[i].to<<"\n";
    if(!vis[c[i].pos]) _swap(c[i].to,x[c[i].pos]);
    else{
        rev(c[i].pos);
        _swap(c[i].to,x[c[i].pos]);
        rev(c[i].pos);
    }
}
int main(){
    freopen("park1.in","r",stdin);
    freopen("park.out","w",stdout);
    memset(first,-1,sizeof(first));
    ll i,t1,t2,t3;
    n=read();m=read();Q=read();block=(ll)pow(n,0.60);
    for(i=1;i<=m;i++) v[i]=read(); 
    for(i=1;i<=n;i++) w[i]=read();
    for(i=1;i<n;i++){
        t1=read();t2=read();add(t1,t2);
    }
    for(i=1;i<=n;i++) x[i]=read();
    dfs(1,0);init();
    //for(i=1;i<=n;i++) cout<<fa[i]<<" "<<dep[i]<<"\n";
    for(i=1;i<=Q;i++){
        t1=read();t2=read();t3=read();
        if(t1) q[++cntq].l=t2,q[cntq].r=t3,q[cntq].c=cntc,q[cntq].i=cntq;
        else c[++cntc].pos=t2,c[cntc].to=t3;
        //cout<<"finish read in "<<i<<"\n";
    }
    sort(q+1,q+cntq+1,cmp);
    //for(i=1;i<=cntq;i++) 
        //cout<<q[i].l<<" "<<q[i].r<<" "<<q[i].c<<" "<<q[i].i<<"\n";
    
    if(dfn[q[1].l]>dfn[q[1].r]) _swap(q[1].l,q[1].r);
    ll lca=LCA(q[1].l,q[1].r),l,r;curl=q[1].l;curr=q[1].r;
    l=curl;r=curr;
    while(l!=lca) rev(l),l=fa[l];
    while(r!=lca) rev(r),r=fa[r];
    while(curc<q[1].c) change(++curc);
    rev(lca);ans[q[1].i]=tot;rev(lca);
    for(i=2;i<=cntq;i++){
        //cout<<"i=="<<i<<"\n";
        if(dfn[q[i].l]>dfn[q[i].r]) _swap(q[i].l,q[i].r);
        lca=LCA(curr,q[i].r);l=curr;r=q[i].r;
        while(l!=lca) rev(l),l=fa[l];
        while(r!=lca) rev(r),r=fa[r];
        lca=LCA(curl,q[i].l);l=curl;r=q[i].l;
        while(l!=lca) rev(l),l=fa[l];
        while(r!=lca) rev(r),r=fa[r];
        while(curc>q[i].c) change(curc--);
        while(curc<q[i].c) change(++curc);
        lca=LCA(q[i].l,q[i].r);
        rev(lca);ans[q[i].i]=tot;rev(lca);
        curl=q[i].l;curr=q[i].r;
    }
    for(i=1;i<=cntq;i++) printf("%lld\n",ans[i]);
}
