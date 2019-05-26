#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define inf 1e9
using namespace std;
char tmpch;
inline int read(){
    int re=0,flag=1;char ch=tmpch;
    //if(ch=='\n'||ch=='\r') exit(0);
    while(ch>'9'||ch<'0'){
        /*cout<<"useless char "<<(int)ch<<"\n";*/
        /*if((int)ch==-1) exit(0); */
        if(ch=='-') flag=-1; 
        ch=getchar();
    }
    while(ch>='0'&&ch<='9') re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
    tmpch=ch;
    //cout<<"read in "<<re*flag<<"\n";
    return re*flag;
}
int n,m,cnt=-1,ans=0,first[110],cur[110],dep[110];
struct edge{
    int to,next,w;
}a[10010];
inline void add(int u,int v,int w){
    //cout<<"add "<<u<<" "<<v<<" "<<w<<"\n";
    a[++cnt]=(edge){v,first[u],w};first[u]=cnt;
    a[++cnt]=(edge){u,first[v],0};first[v]=cnt;
}
bool bfs(int s,int t){
    int i,u,v,q[110],head=0,tail=1;
    for(i=s;i<=t;i++) dep[i]=-1,cur[i]=first[i];
    dep[s]=0;q[0]=s;
    while(head<tail){
        u=q[head++];
        //cout<<"bfs "<<u<<" "<<dep[u]<<"\n";
        for(i=first[u];~i;i=a[i].next){
            v=a[i].to;
            if(~dep[v]||!a[i].w) continue;
            dep[v]=dep[u]+1;q[tail++]=v;
        }
    }
    return ~dep[t];
}
int _min(int l,int r){return (l<r)?l:r;}
int dfs(int u,int t,int limit){
    if(u==t||!limit) return limit;
    int i,v,f,flow=0;
    for(i=first[u];~i;i=a[i].next){
        v=a[i].to;
        if((dep[v]==dep[u]+1)&&(f=dfs(v,t,_min(limit,a[i].w)))){
            flow+=f;limit-=f;
            a[i].w-=f;a[i^1].w+=f;
            if(!limit) return flow;
        }
    }
    return flow;
}
void dinic(int s,int t){
    while(bfs(s,t)) ans+=dfs(s,t,inf);
}
int main(){
    freopen("shuttle.in","r",stdin);
    freopen("shuttle.out","w",stdout);
    memset(first,-1,sizeof(first));
    int i,t1,sum=0;
    n=read();m=read();tmpch=0;
    for(i=1;i<=n;i++){
        t1=read();add(0,i,t1);sum+=t1;
        tmpch=0;
        //cout<<"experiment "<<i<<"\n";
        while(((t1=read())||1)&&tmpch!='\n'&&tmpch!='\r') add(i,n+t1,inf);
        tmpch=0;add(i,n+t1,inf);
    }
    //cout<<"finish experiment\n";
    for(i=1;i<=m;i++) t1=read(),add(n+i,m+n+1,t1);
    //cout<<"finish read in\n";tmpch=0;
    dinic(0,n+m+1);
    for(i=1;i<=n;i++) if(~dep[i]) printf("%d ",i);printf("\n");
    for(i=1;i<=m;i++) if(~dep[n+i]) printf("%d ",i);printf("\n");
    printf("%d\n",sum-ans);
    return 0;
}
