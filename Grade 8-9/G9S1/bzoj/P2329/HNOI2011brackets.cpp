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
int n,m,root,cnt;
int fa[100010],ch[100010][2],siz[100010];
int w[100010],l1[100010],l2[100010],r1[100010],r2[100010],sum[100010];
int rev[100010]={0},lazy[100010]={0},inv[100010]={0};
int x[100010];
//lazy==1:  (
//lazy==-1: )
void _swap(int &x,int &y){x^=y;y^=x;x^=y;}
int _max(int x,int y){return (x<y)?y:x;}
int _min(int x,int y){return (x>y)?y:x;}
void update(int x){
    if(!x) return;
    sum[x]=sum[ch[x][0]]+sum[ch[x][1]]+w[x];
    siz[x]=siz[ch[x][0]]+siz[ch[x][1]]+1;
    l1[x]=_min(l1[ch[x][0]],sum[ch[x][0]]+w[x]+l1[ch[x][1]]);
    l2[x]=_max(l2[ch[x][0]],sum[ch[x][0]]+w[x]+l2[ch[x][1]]);
    r1[x]=_min(r1[ch[x][1]],sum[ch[x][1]]+w[x]+r1[ch[x][0]]);
    r2[x]=_max(r2[ch[x][1]],sum[ch[x][1]]+w[x]+r2[ch[x][0]]);
}
void pushdown(int x,int t){
    if(!x) return;
    inv[x]=0;w[x]=t;lazy[x]=t;
    if(~t){
        sum[x]=siz[x];
        l1[x]=r1[x]=0;
        l2[x]=r2[x]=sum[x];
    }
    else{
        sum[x]=~siz[x]+1;
        l2[x]=r2[x]=0;
        l1[x]=r1[x]=sum[x];
    }
}
void pushrev(int x){
    if(!x) return;
    _swap(ch[x][0],ch[x][1]);
    _swap(l1[x],r1[x]);
    _swap(l2[x],r2[x]);
    rev[x]^=1;
}
void pushinv(int x){
    if(!x) return;
    _swap(l1[x],l2[x]);
    _swap(r1[x],r2[x]);
    l1[x]=~l1[x]+1;l2[x]=~l2[x]+1;
    r1[x]=~r1[x]+1;r2[x]=~r2[x]+1;
    w[x]=~w[x]+1;sum[x]=~sum[x]+1;inv[x]^=1;
}
void push(int x){
    if(!x) return;
    if(rev[x]){
        pushrev(ch[x][0]);
        pushrev(ch[x][1]);
        rev[x]=0;
    }
    if(lazy[x]){
        pushdown(ch[x][0],lazy[x]);
        pushdown(ch[x][1],lazy[x]);
        lazy[x]=0;
    }
    if(inv[x]){
        pushinv(ch[x][0]);
        pushinv(ch[x][1]);
        inv[x]=0;
    }
}
int get(int x){return ch[fa[x]][1]==x;}
void rotate(int x){
    int f=fa[x],ff=fa[f],son=get(x);
    push(f);push(x);
    ch[f][son]=ch[x][son^1];
    if(ch[f][son]) fa[ch[f][son]]=f;
    fa[f]=x;ch[x][son^1]=f;
    fa[x]=ff;
    if(ff) ch[ff][ch[ff][1]==f]=x;
    update(f);update(x);
}
void splay(int x,int to){
    if(x==to||fa[x]==to) return;
    if(!to) root=x;
    for(int f;(f=fa[x])&&f!=to;rotate(x))
        if(fa[f]!=to)
            rotate(get(f)==get(x)?f:x);
    update(x);
}
int rank(int x,int pos){
    push(pos);
    if(siz[ch[pos][0]]+1==x){
        splay(pos,0);return pos;
    }
    if(siz[ch[pos][0]]>=x) return rank(x,ch[pos][0]);
    else return rank(x-siz[ch[pos][0]]-1,ch[pos][1]);
}
int build(int le,int ri,int f){
    if(le>ri) return 0;
    int mid=(le+ri)>>1,cur=++cnt;
    //cout<<"build "<<le<<" "<<ri<<" "<<mid<<" "<<x[mid]<<"\n";
    w[cur]=x[mid];fa[cur]=f;
    ch[cur][0]=build(le,mid-1,cur);
    ch[cur][1]=build(mid+1,ri,cur);
    update(cur);return cur;
}
void change(int le,int ri,int t){
    int x=rank(le,root),y=rank(ri+2,root);
    splay(x,0);splay(y,root);
    pushdown(ch[y][0],t);
    update(y);update(x);
}
void reverse(int le,int ri){
    int x=rank(le,root),y=rank(ri+2,root);
    splay(x,0);splay(y,root);
    pushrev(ch[y][0]);
    update(y);update(x);
}
void invert(int le,int ri){
    int x=rank(le,root),y=rank(ri+2,root);
    splay(x,0);splay(y,root);
    pushinv(ch[y][0]);
    update(y);update(x);
}
int query(int le,int ri){
    int x=rank(le,root),y=rank(ri+2,root);
    splay(x,0);splay(y,root);
    return ((r2[ch[y][0]]+1)>>1)-((l1[ch[y][0]]-1)/2);
}
void dfs(int u){
    if(!u) return;
    push(u);
    dfs(ch[u][0]);
    printf("%d %d %d %d\n",u,fa[u],ch[u][0],ch[u][1]);
    printf("%d %d %d %d %d\n",w[u],l1[u],l2[u],r1[u],r2[u]);
    dfs(ch[u][1]);
}
char s[100010];
int main(){
    freopen("brackets.in","r",stdin);
    freopen("brackets.out","w",stdout);
    int i,t1,t2,t4;char t3;
    n=read();m=read();
    scanf("%s",s);
    for(i=1;i<=n;i++) x[i]=((s[i-1]=='(')?1:-1);
    root=build(0,n+1,0);
    //dfs(root);printf("\n");
    for(i=1;i<=m;i++){
        scanf("%s",s);
        if(s[0]=='R'){
            t1=read();t2=read();t3=getchar();
            while(t3!='('&&t3!=')') t3=getchar();
            t4=((t3=='(')?1:-1);
            change(t1,t2,t4);
        }
        if(s[0]=='I'){
            t1=read();t2=read();
            invert(t1,t2);
        }
        if(s[0]=='Q'){
            t1=read();t2=read();
            printf("%d\n",query(t1,t2));
        }
        if(s[0]=='S'){
            t1=read();t2=read();
            reverse(t1,t2);
        }
        //dfs(root);printf("\n");
    }
}
