#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
#define inf 1e9
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
int n,m,cnt=-1,ans=0,first[10010],dep[10010],cur[10010],x[101][101]={0},bx[101][101],by[101][101]; 
struct edge{
    int to,next,w;
}a[500010];
inline void add(int u,int v,int w){
//	cout<<"add "<<u<<ends<<v<<ends<<w<<endl;
    a[++cnt]=(edge){v,first[u],w};first[u]=cnt;
    a[++cnt]=(edge){u,first[v],0};first[v]=cnt;
}
int q[10010];
bool bfs(int s,int t){
    int head=0,tail=1,i,u,v;
    for(i=s;i<=t;i++) dep[i]=-1,cur[i]=first[i];
    q[0]=s;dep[s]=0;
    while(head<tail){
        u=q[head++];
        for(i=first[u];~i;i=a[i].next){
            v=a[i].to;
            if(~dep[v]||!a[i].w) continue;
            dep[v]=dep[u]+1;q[tail++]=v;
        }
    }
    return ~dep[t];
}
int dfs(int u,int t,int limit){
    if(u==t||!limit) return limit;
    int i,v,f,flow=0;
    for(i=cur[u];~i;i=a[i].next){
        v=a[i].to;cur[u]=i;
        if(dep[v]==dep[u]+1&&(f=dfs(v,t,min(limit,a[i].w)))){
            a[i].w-=f;a[i^1].w+=f;
            limit-=f;flow+=f;
            if(!limit) return flow;
        }
    }
    return flow;
}
void dinic(int s,int t){
    while(bfs(s,t)) ans+=dfs(s,t,inf);
}
int main(){
    std::ios::sync_with_stdio(false);
    memset(first,-1,sizeof(first));
    cin>>n>>m;int i,j;char s[100];
    for(i=1;i<=n;i++){
        cin>>s;
//		cout<<s<<endl;
        for(j=1;j<=m;j++){
            if(s[j-1]=='x') x[i][j]=2;
            if(s[j-1]=='*') x[i][j]=1;
            if(s[j-1]=='#') x[i][j]=0;
//			cout<<i<<ends<<j<<ends<<x[i][j]<<endl;
        }
    }
    int tmp=0,tt;
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            if(!x[i][j]) continue;
            if((j==1)||(!x[i][j-1])) add(0,++tmp,1);
            bx[i][j]=tmp;
        }
    }
    for(j=1;j<=m;j++){
        for(i=1;i<=n;i++){
            if(!x[i][j]) continue;
            if((i==1)||(!x[i-1][j])) add(++tmp,n*m-1,1);
            by[i][j]=tmp;
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            if(x[i][j]==1) add(bx[i][j],by[i][j],1);
        }
    }
    dinic(0,n*m-1);
    cout<<ans<<endl;
}
