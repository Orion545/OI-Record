#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
void _swap(int &x,int &y){x^=y;y^=x;x^=y;}
int _max(int x,int y){return (x>y)?x:y;}
inline int read(){
    int re=0,flag=1;char ch=getchar();
    while(ch>'9'||ch<'0'){
        if(ch=='-') flag=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9') re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
    return re*flag;
}
int n,cnt,ans,dis[20010],first[20010],tmp[5],root,siz[20010],son[20010],sum;
bool vis[20010];
struct edge{
    int to,next,w;
}a[40010];
inline void add(int u,int v,int w){
    a[++cnt]=(edge){v,first[u],w};first[u]=cnt;
    a[++cnt]=(edge){u,first[v],w};first[v]=cnt;
}
int gcd(int x,int y){return (y?gcd(y,x%y):x);};
void getroot(int u,int f){
    //cout<<"getroot "<<u<<" "<<f<<"\n";
    int i,v;
    siz[u]=1;son[u]=0;
    for(i=first[u];~i;i=a[i].next){
        v=a[i].to;
        if(v==f||vis[v]) continue;
        getroot(v,u);
        siz[u]+=siz[v];
        son[u]=_max(son[u],siz[v]);
    }
    son[u]=_max(son[u],sum-siz[u]);
    //cout<<"finish getroot "<<son[u]<<'\n';
    if(son[u]<son[root]) root=u;
}
void gettmp(int u,int f){
    //cout<<"gettmp "<<u<<" "<<f<<"\n";
    int i,v;
    tmp[dis[u]]++;
    for(i=first[u];~i;i=a[i].next){
        v=a[i].to;
        if(v==f||vis[v]) continue;
        //cout<<" to "<<v<<'\n';
        dis[v]=(dis[u]+a[i].w)%3;
        gettmp(v,u);
    }
}
int calc(int u,int d){
    dis[u]=d%3;tmp[0]=tmp[1]=tmp[2]=0;
    gettmp(u,0);
    return tmp[1]*tmp[2]*2+tmp[0]*tmp[0];
}
void dfs(int u){
    //cout<<"dfs "<<u<<"\n";
    int i,v;
    vis[u]=1;ans+=calc(u,0);
    for(i=first[u];~i;i=a[i].next){
        v=a[i].to;
        if(vis[v]) continue;
        ans-=calc(v,a[i].w);
        sum=siz[v];root=0;
        getroot(v,u);
        dfs(root);
    }
}
int main(){
    freopen("cckk.in","r",stdin);
    freopen("cckk.out","w",stdout);
    memset(first,-1,sizeof(first));
    int i,t1,t2,t3;
    n=read();
    for(i=1;i<n;i++){
        t1=read();t2=read();t3=read();
        add(t1,t2,t3);
    }
    //cout<<"finish read in\n";
    sum=n;son[0]=n;
    getroot(1,0);
    dfs(1);
    int div=gcd(n*n,ans);
    printf("%d/%d",ans/div,n*n/div);
}
