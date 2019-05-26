#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
typedef long long ll;
const int N=100001;
const ll MOD=20160501;
int n,m,tot,dfx,lst,head[N],v[N<<1],nxt[N<<1],num[N],dep[N],f[N],sum[N],son[N],id[N],dfn[N],pre[N];
void addedge(int x,int y){v[++tot]=y;nxt[tot]=head[x];head[x]=tot;}
void dfs1(int u=1){
    sum[u]=1;
    for(int i=head[u];~i;i=nxt[i]){
        if(v[i]!=f[u]){
            f[v[i]]=u;
            dep[v[i]]=dep[u]+1;
            dfs1(v[i]);
            sum[u]+=sum[v[i]];
            if(!son[u]||sum[v[i]]>sum[son[u]])son[u]=v[i];
        }
    }
}
void dfs2(int u=1,int top=1){
    id[u]=top;
    dfn[u]=++dfx;
    pre[dfx]=u;
    if(!son[u])return;
    dfs2(son[u],top);
    for(int i=head[u];~i;i=nxt[i])if(v[i]!=son[u]&&v[i]!=f[u])dfs2(v[i],v[i]);
}
struct PresidentTree{
    int nowrt,idx,rtx,rt[N];
    struct node{
        int ls,rs;
        ll sum,dep,dep2,sudep,sudep2,add;
    }t[N*50];
    void pushup(int o){
        t[o].sum=(t[t[o].ls].sum+t[t[o].rs].sum)%MOD;
        t[o].dep=(t[t[o].ls].dep+t[t[o].rs].dep)%MOD;
        t[o].dep2=(t[t[o].ls].dep2+t[t[o].rs].dep2)%MOD;
        t[o].sudep=(t[t[o].ls].sudep+t[t[o].rs].sudep)%MOD;
        t[o].sudep2=(t[t[o].ls].sudep2+t[t[o].rs].sudep2)%MOD;
    }
    void build(int &o,int l,int r){
        o=++idx;
        if(l==r){
            t[o].sum=num[pre[l]];
            t[o].dep=dep[pre[l]];
            t[o].dep2=dep[pre[l]]*dep[pre[l]]%MOD;
            t[o].sudep=t[o].sum*t[o].dep%MOD;
            t[o].sudep2=t[o].sum*t[o].dep2%MOD;
            return;
        }
        int mid=(l+r)>>1;
        build(t[o].ls,l,mid);
        build(t[o].rs,mid+1,r);
        pushup(o);
    }
    pair<ll,ll> update(int rt,int l,int r,int &o,int ql,int qr,ll c){
        if(ql>qr)swap(ql,qr);
        if(!o){
            o=++idx;
            t[o]=t[rt];
            t[o].ls=t[o].rs=0;
        }
        if(ql<=l&&r<=qr){
            t[o].add=(t[o].add+c)%MOD;
            t[o].ls=t[rt].ls;
            t[o].rs=t[rt].rs;
            return make_pair(t[o].dep,t[o].dep2);
        }
        int mid=(l+r)>>1;
        pair<ll,ll>p,tmp;
        if(qr<=mid){
            if(!t[o].rs)t[o].rs=t[rt].rs;
            if(t[o].ls==t[rt].ls)t[o].ls=0;
            p=update(t[rt].ls,l,mid,t[o].ls,ql,qr,c);
        }else if(ql>mid){
            if(!t[o].ls)t[o].ls=t[rt].ls;
            if(t[o].rs==t[rt].rs)t[o].rs=0;
            p=update(t[rt].rs,mid+1,r,t[o].rs,ql,qr,c);
        }else{
            if(t[o].ls==t[rt].ls)t[o].ls=0;
            p=update(t[rt].ls,l,mid,t[o].ls,ql,qr,c);
            if(t[o].rs==t[rt].rs)t[o].rs=0;
            tmp=update(t[rt].rs,mid+1,r,t[o].rs,ql,qr,c);
            p.first+=tmp.first;
            p.second+=tmp.second;
        }
        t[o].sum=(t[o].sum+c*(min(qr,r)-max(ql,l)+1))%MOD;
        t[o].sudep=(t[o].sudep+c*p.first)%MOD;
        t[o].sudep2=(t[o].sudep2+c*p.second)%MOD;
        return p;
    }
    ll query(int o,int l,int r,int ql,int qr,ll tag,ll s1,ll s2){
        tag=(tag+t[o].add)%MOD;
        if(ql>qr)swap(ql,qr);
        if(ql<=l&&r<=qr)return ((t[o].sum+tag*(r-l+1))%MOD*s1+(t[o].sudep+tag*t[o].dep)%MOD*s2+(t[o].sudep2+tag*t[o].dep2)%MOD)%MOD;
        ll re=0;
        int mid=(l+r)>>1;
        if(ql<=mid)re+=query(t[o].ls,l,mid,ql,qr,tag,s1,s2);
        if(qr>mid)re+=query(t[o].rs,mid+1,r,ql,qr,tag,s1,s2);
        return re%MOD;
    }
}pt;
void update(int x,int y,ll del){
    ++pt.rtx;
    while(id[x]!=id[y]){
        if(dep[id[x]]<dep[id[y]])swap(x,y);
        pt.update(pt.rt[pt.nowrt],1,n,pt.rt[pt.rtx],dfn[id[x]],dfn[x],del);
        x=f[id[x]];
    }
    pt.update(pt.rt[pt.nowrt],1,n,pt.rt[pt.rtx],dfn[x],dfn[y],del);
    pt.nowrt=pt.rtx;
}
int LCA(int x,int y){
    while(id[x]!=id[y]){
        if(dep[id[x]]<dep[id[y]])swap(x,y);
        x=f[id[x]];
    }
    return dep[x]<=dep[y]?x:y;
}
ll query(int x,int y){
    ll ans=0;
    int b=y,lca=LCA(x,y);
    while(id[x]!=id[y]){
        if(dep[id[x]]>dep[id[y]]){
            ans=(ans+pt.query(pt.rt[pt.nowrt],1,n,dfn[id[x]],dfn[x],0,((ll)dep[b]*(dep[b]+1)-2*dep[lca]*(2*dep[b]-2*dep[lca]+1)+MOD)%MOD,(1+2*dep[b]-4*dep[lca]+MOD)%MOD))%MOD;
            x=f[id[x]];
        }else{
            ans=(ans+pt.query(pt.rt[pt.nowrt],1,n,dfn[id[y]],dfn[y],0,((ll)dep[b]*(dep[b]+1))%MOD,(-1-2*dep[b]+MOD)%MOD))%MOD;
            y=f[id[y]];
        }
    }
    if(dep[x]>dep[y])ans=(ans+pt.query(pt.rt[pt.nowrt],1,n,dfn[y],dfn[x],0,((ll)dep[b]*(dep[b]+1)-2*dep[lca]*(2*dep[b]-2*dep[lca]+1)+MOD)%MOD,(1+2*dep[b]-4*dep[lca]+MOD)%MOD))%MOD;
    else ans=(ans+pt.query(pt.rt[pt.nowrt],1,n,dfn[x],dfn[y],0,((ll)dep[b]*(dep[b]+1))%MOD,(MOD-1-2*dep[b])%MOD))%MOD;
    return ans&1?(ans+MOD)>>1:ans>>1;
}
int main(){
    memset(head,-1,sizeof(head));
    scanf("%d%d",&n,&m);
    for(int i=1;i<n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        addedge(x,y);
        addedge(y,x);
    }
    for(int i=1;i<=n;i++)scanf("%d",&num[i]);
    dfs1();
    dfs2();
    pt.build(pt.rt[0],1,n);
    for(int i=1;i<=m;i++){
        int opt,x,y;
        ll del;
        scanf("%d",&opt);
        if(opt==1){
            scanf("%d%d%lld",&x,&y,&del);
            update(x^lst,y^lst,del);
        }else if(opt==2){
            scanf("%d%d",&x,&y);
            printf("%d\n",lst=query(x^lst,y^lst));
        }else if(opt==3){
            scanf("%d",&x);
            pt.nowrt=x^lst;
        }
    }
}
