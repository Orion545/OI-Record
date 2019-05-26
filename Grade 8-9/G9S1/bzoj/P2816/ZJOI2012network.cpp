#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<unistd.h>
#define col(i,c) n*c+i
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
struct edge{
    int to,next,w;
}e[200010];
int n,m,C,cnt=-1,q,first[100010],color[10010][11];
int fa[100010]={0},ch[100010][2]={0},w[100010],a[100010];
bool rev[100010]={0},rt[100010]={0};
void _swap(int &l,int &r){l^=r;r^=l;l^=r;}
void update(int x){a[x]=max(a[ch[x][0]],max(a[ch[x][1]],w[x]));};
void pushrev(int x){
    if(!x) return;
    _swap(ch[x][0],ch[x][1]);
    rev[x]^=1;
}
void pushdown(int x){
    if(!x) return;
    if(rev[x]){
        pushrev(ch[x][0]);
        pushrev(ch[x][1]);
        rev[x]=0;
    }
}
void push(int x){
    //cout<<"push "<<x<<' '<<rt[x]<<'\n';
    if(!x) sleep(1000);
    if(!rt[x]) push(fa[x]);
    pushdown(x);
}
int get(int x){return ch[fa[x]][1]==x;}
void rotate(int x){
    //cout<<"rotate "<<x<<'\n';
    int f=fa[x],ff=fa[f],son=get(x);
    ch[f][son]=ch[x][son^1];
    if(ch[f][son]) fa[ch[f][son]]=f;
    ch[x][son^1]=f;fa[f]=x;
    fa[x]=ff;
    if(rt[f]) rt[x]=1,rt[f]=0;
    else ch[ff][ch[ff][1]==f]=x;
    update(f);update(x);
}
void splay(int x){
    //cout<<"splay "<<x<<'\n';
    push(x);
    for(int f;!rt[x];rotate(x))
        if(!rt[f=fa[x]])
            rotate((get(x)==get(f))?f:x);
    update(x);
}
void access(int x){
    //cout<<"access "<<x<<'\n';
    int y=0;
    do{
        splay(x);
        rt[ch[x][1]]=1;
        rt[ch[x][1]=y]=0;
        x=fa[y=x];
        update(x);
    }while(x);
}
void makeroot(int x){
    //cout<<"makeroot "<<x<<'\n';
    access(x);splay(x);pushrev(x);
}
bool judge(int x,int y){
    while(fa[x]) x=fa[x];
    while(fa[y]) y=fa[y];
    return x==y;
}
void init(int x,int y){
    //cout<<"init "<<x<<' '<<y<<'\n';
    makeroot(x);fa[x]=y;
}
int link(int x,int y){
    if(judge(x,y)) return 0; 
    makeroot(x);fa[x]=y;
    return 1;
}
int cut(int x,int y){
    if(!judge(x,y)) return 0;
    makeroot(x);splay(y);
    fa[ch[y][0]]=fa[y];
    rt[ch[y][0]]=1;
    fa[y]=0;ch[y][0]=0;
    return 1;
}
void add(int u,int v,int w){
    e[++cnt]=(edge){v,first[u],w};first[u]=cnt;
    e[++cnt]=(edge){u,first[v],w};first[v]=cnt;
}
int split(int u,int v){
    if(!judge(u,v)) return -1;
    makeroot(u);access(v);splay(v);
    return a[v];
}
int main(){
    freopen("networkzj.in","r",stdin);
    freopen("networkzj.out","w",stdout);
    memset(first,-1,sizeof(first));
    int i,j,t1,t2,t3,t4;
    n=read();m=read();C=read();q=read();
    for(i=1;i<=n;i++){
        t1=read();
        for(j=0;j<C;j++) a[col(i,j)]=w[col(i,j)]=t1,rt[col(i,j)]=1;
    }
   
    for(i=1;i<=m;i++){
        t1=read();t2=read();t3=read();
        init(col(t1,t3),col(t2,t3));
        add(t1,t2,t3);
        color[t1][t3]++;color[t2][t3]++;
    }
    //for(i=1;i<=n;i++){
        //for(j=0;j<C;j++) cout<<color[i][j]<<' ';
        //cout<<'\n';
    //}
    for(i=1;i<=q;i++){
        //cout<<"operation "<<i<<'\n';
        t1=read();
        if(t1==0){
            t2=read();t3=read();
            for(j=0;j<C;j++){
                makeroot(col(t2,j));w[col(t2,j)]=t3;update(col(t2,j));
            }
        }
        if(t1==1){
            t2=read();t3=read();t4=read();bool flag=1,f=1;
            for(j=first[t2];~j;j=e[j].next) 
                if(e[j].to==t3){
                    flag=0;
                    if(e[j].w==t4) f=0;
                }
            if(flag){
                printf("No such edge.\n");
                continue;
            } 
            if(f&&(color[t2][t4]==2||color[t3][t4]==2)){
                printf("Error 1.\n");continue;
            }
            if(f&&(judge(col(t2,t4),col(t3,t4)))){
                printf("Error 2.\n");continue;
            }
            for(j=first[t2];~j;j=e[j].next){
                if(e[j].to==t3){
                    color[t2][e[j].w]--;color[t3][e[j].w]--;
                    cut(col(t2,e[j].w),col(t3,e[j].w));
                    e[j].w=e[j^1].w=t4;
                    color[t2][t4]++;color[t3][t4]++;
                    link(col(t2,t4),col(t3,t4));
                    printf("Success.\n");break;
                } 
            }
        }
        if(t1==2){
            t2=read();t3=read();t4=read();
            printf("%d\n",split(col(t3,t2),col(t4,t2)));
        }
    }
}
