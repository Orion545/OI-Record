#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define inf 1e9
#define id(i,j) (i-1)*n+j
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
int n,m,cnt=-1,ans,first[1010],dis[1010],vis[1010];
struct edge{
    int to,next,w,cap;
}a[100010];
inline void add(int u,int v,int w,int cap){	
	//cout<<"add "<<u<<" "<<v<<" "<<w<<" "<<cap<<"\n";
    a[++cnt]=(edge){v,first[u],w,cap};first[u]=cnt;
    a[++cnt]=(edge){u,first[v],-w,0};first[v]=cnt;
}
bool spfa(int s,int t){
    int q[5010],head=0,tail=1,u,v,w,i;
    memset(dis,-1,sizeof(dis));memset(vis,0,sizeof(vis));
    q[0]=t;vis[t]=1;dis[t]=0;
    while(head<tail){
        u=q[head++];vis[u]=0;
        for(i=first[u];~i;i=a[i].next){
            v=a[i].to;w=a[i].w;
            if(a[i^1].cap&&((dis[v]==-1)||(dis[v]>dis[u]-w))){
                dis[v]=dis[u]-w;
                if(!vis[v]) vis[v]=1,q[tail++]=v;
            }
        }
    }
    return ~dis[s];
}
int dfs(int u,int t,int limit){
    if(u==t||!limit){vis[u]=1;return limit;}
    int i,v,f,flow=0,w;vis[u]=1;
    for(i=first[u];~i;i=a[i].next){
        v=a[i].to;w=a[i].w;
        if(!vis[v]&&a[i].cap&&(dis[v]==dis[u]-w)){
            if(!(f=dfs(v,t,min(limit,a[i].cap)))) continue;
            a[i].cap-=f;a[i^1].cap+=f;
            ans+=f*w;flow+=f;limit-=f;
            if(!limit) return flow;
        }
    }
    return flow;
}
int zkw(int s,int t){
    int re=0;
    while(spfa(s,t)){
        vis[t]=1;
        while(vis[t]){
            memset(vis,0,sizeof(vis));
            re+=dfs(s,t,inf);
        }
    }
    return re;
}
int main(){
	freopen("scoi2007_repair.in","r",stdin);
	freopen("scoi2007_repair.out","w",stdout);
    memset(first,-1,sizeof(first));int i,j,k,t1;
    m=read();n=read();
    for(i=1;i<=n;i++) add(0,i,0,1);
    for(i=1;i<=m;i++) for(j=1;j<=n;j++) add(n+id(i,j),n+n*m+1,0,1);
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            t1=read();
            for(k=1;k<=n;k++){
            	add(i,n+id(j,k),t1*k,1);
			}
        }
    }
    //cout<<"finish read in\n";
    zkw(0,n+n*m+1);
    printf("%.2lf",((double)ans)/((double)n));
}
