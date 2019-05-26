#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<cmath>
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
int n,Q,first[100010],cnte,dep[100010],st[100010][20],dfn[100010],lim[100010],back[100010],cntn;
int fa[100010];
struct edge{
    int to,next;
}e[200010];
inline void add(int u,int v){
    e[++cnte]=(edge){v,first[u]};first[u]=cnte;
    e[++cnte]=(edge){u,first[v]};first[v]=cnte;
}
void dfs(int u,int f){
    int i,v;dep[u]=dep[f]+1;st[u][0]=f;fa[u]=f;
    //siz=lim-dfn+1
    dfn[u]=++cntn;back[cntn]=u;
    for(i=first[u];~i;i=e[i].next){
        v=e[i].to;if(v==f) continue;
        dfs(v,u);
    }
    lim[u]=cntn;
}
void ST(){
    for(int j=1;j<=19;j++){
        for(int i=1;i<=n;i++) st[i][j]=st[st[i][j-1]][j-1];
    }
}
int lca(int l,int r){
    int i;
    if(dep[l]>dep[r]) swap(l,r);
    for(i=19;i>=0;i--) if(dep[st[r][i]]>=dep[l]) r=st[r][i];
    if(l==r) return l;
    for(i=19;i>=0;i--){
        if(st[r][i]!=st[l][i]){
            l=st[l][i];
            r=st[r][i];
        }
    }
    return st[l][0];
}
//segment tree
ll a[400010],lazy[400010];
void update(int num){
    a[num]=a[num<<1]+a[num<<1|1];
}
void push(int l,int r,int num){
    if(l==r||!lazy[num]) return;
    ll mid=(l+r)>>1;
    a[num<<1]+=(mid-(ll)l+1ll)*lazy[num];a[num<<1|1]+=((ll)r-mid)*lazy[num];
    lazy[num<<1]+=lazy[num];lazy[num<<1|1]+=lazy[num];
    lazy[num]=0;
}
void build(int l,int r,int num){
    if(l==r){a[num]=dep[back[l]];return;}
    int mid=(l+r)>>1;
    build(l,mid,num<<1);build(mid+1,r,num<<1|1);
    update(num);
}
void change(int l,int r,int ql,int qr,int num,ll ch){
    push(l,r,num);
    if(l>=ql&&r<=qr){a[num]+=(r-l+1)*ch;lazy[num]+=ch;return;}
    int mid=(l+r)>>1;
    if(mid>=ql) change(l,mid,ql,qr,num<<1,ch);
    if(mid<qr) change(mid+1,r,ql,qr,num<<1|1,ch);
    update(num);
}
ll query(int l,int r,int ql,int qr,int num){
    push(l,r,num);
    if(l>=ql&&r<=qr) return a[num];
    int mid=(l+r)>>1;ll re=0;
    if(mid>=ql) re+=query(l,mid,ql,qr,num<<1);
    if(mid<qr) re+=query(mid+1,r,ql,qr,num<<1|1);
    return re;
}
//link cut tree
int ch[100010][2]={0},rt[100010];
int get(int pos){return ch[fa[pos]][1]==pos;}
void rotate(int x){
    int f=fa[x],ff=fa[f],son=get(x);
    ch[f][son]=ch[x][son^1];
    if(ch[f][son]) fa[ch[f][son]]=f;
    fa[f]=x;ch[x][son^1]=f;
    fa[x]=ff;
    if(rt[f]) rt[x]=1,rt[f]=0;
    else ch[ff][ch[ff][1]==f]=x;
}
void splay(int pos){
    if(rt[pos]) return;
    for(int f;!rt[pos];rotate(pos)){
        if(!rt[f=fa[pos]])
            rotate((get(f)==get(pos))?f:pos);
    }
}
int pre(int pos){
    while(ch[pos][0]) pos=ch[pos][0];
    return pos;
}
void access(int pos){
    for(int tmp=0,tt;pos;tmp=pos,pos=fa[pos]){
        splay(pos);
        if(ch[pos][1]){//+1
            tt=pre(ch[pos][1]);
            change(1,n,dfn[tt],lim[tt],1,1);
        }
        rt[ch[pos][1]]=1;ch[pos][1]=tmp;rt[tmp]=0;
        if(tmp){//-1
            tt=pre(tmp);
            change(1,n,dfn[tt],lim[tt],1,-1);
        }
    }
}
int main(){
    memset(first,-1,sizeof(first));cnte=0;
    n=read();int i,t1,t2;char s[10];
    for(i=1;i<n;i++){
        t1=read();t2=read();t1++;t2++;
        add(t1,t2);
    }
    dep[0]=-1;dfs(1,0);
	ST();
	build(1,n,1);
    for(i=1;i<=n;i++) rt[i]=1;
	Q=read();
    while(Q--){
        scanf("%s",s);
        if(s[0]=='O'){
            t2=read()+1;access(t2);
        }
        if(s[0]=='q'){
            t2=read()+1;double tmp=query(1,n,dfn[t2],lim[t2],1),tt=lim[t2]-dfn[t2]+1;
            printf("%.10lf\n",tmp/tt); 
        }
    }
}
