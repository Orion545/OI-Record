#include<bits/stdc++.h>
using namespace std;
#define N 100005
#define INF 1e9
#define lowbit(i) ((i)&-(i))
int n,m,head[N],val[N],fa[N][20],dis[N][20],s[N],f[N],dep[N],rt,sz,cnt,ans;
bool vis[N];
vector<int>bit[N],fbit[N];
inline int read(){
    int x=0,f=1; char a=getchar();
    while(a>'9' || a<'0') {if(a=='-') f=-1; a=getchar();}
    while(a<='9' && a>='0') x=x*10+a-'0',a=getchar();
    return x*f;
} 
struct edges{
    int to,next;
}e[2*N];
inline void insert(){
    int u=read(),v=read();
    e[cnt]=(edges){v,head[u]};head[u]=cnt++;
    e[cnt]=(edges){u,head[v]};head[v]=cnt++;
}
void getroot(int x,int father){
    s[x]=1; f[x]=0;
    for(int i=head[x];i>=0;i=e[i].next){
        if(vis[e[i].to] || father==e[i].to) continue;
        getroot(e[i].to,x); s[x]+=s[e[i].to];
        f[x]=max(f[x],s[e[i].to]);
    }
    f[x]=max(f[x],sz-s[x]);
    if(f[x]<f[rt]) rt=x;
}
void getship(int x,int anc,int father,int d){
    for(int i=head[x];i>=0;i=e[i].next){
     int v=e[i].to;
     if(!vis[v] && v!=father) fa[v][++dep[v]]=anc,dis[v][dep[v]]=d,getship(v,anc,x,d+1);
    }
}
void Buildtree(int x){
    vis[x]=1; getship(x,x,0,1); 
    int all=sz; bit[x].resize(all+1); fbit[x].resize(all+1);
    for(int i=head[x];i>=0;i=e[i].next){
        if(vis[e[i].to]) continue;
        sz=s[e[i].to]; if(sz>s[x]) sz=all-s[x];
        rt=0; getroot(e[i].to,x); Buildtree(rt);
    }
}
inline int qsum(int x,int k){
    int ret=val[x],lim=bit[x].size()-1; k=min(k,lim); 
    for(int i=k;i;i-=lowbit(i)) ret+=bit[x][i];
    return ret;
}
inline int qsum2(int x,int k){
    int ret=0,lim=fbit[x].size()-1; k=min(k,lim);
    for(int i=k;i;i-=lowbit(i)) ret+=fbit[x][i];
    return ret;
}
inline void change(int x,int v){
    int d,lim; 
    cout<<"change "<<x<<' '<<v<<'\n';
    d=dis[x][dep[x]]; lim=bit[x].size()-1;
    cout<<"do first "<<d<<' '<<lim<<'\n';
    for(int j=d;j<=lim && j;j+=lowbit(j)) fbit[x][j]+=v;
    for(int i=dep[x];i;i--){
        d=dis[x][i]; lim=bit[fa[x][i]].size()-1;
        for(int j=d;j<=lim;j+=lowbit(j)) bit[fa[x][i]][j]+=v;
        d=dis[x][i-1];
        for(int j=d;j<=lim && j;j+=lowbit(j)) fbit[fa[x][i]][j]+=v;
    }
}
int query(int x,int k){
    int ret=qsum(x,k);
    for(int i=dep[x];i;i--) if(dis[x][i]<=k)
    ret+=qsum(fa[x][i],k-dis[x][i])-qsum2(fa[x][i+1],k-dis[x][i]);
    return ret;
}
int main(){
    n=read(); m=read(); memset(head,-1,sizeof(head));
    for(int i=1;i<=n;i++) val[i]=read();
    for(int i=1;i<n;i++) insert();
    f[0]=INF; sz=n; getroot(1,0); Buildtree(rt);
    
	for(int i=1;i<=n;i++){
		cout<<"check node "<<i<<' '<<dep[i]<<'\n';
		for(int j=1;j<=dep[i];j++) cout<<"	fa "<<fa[i][j]<<", dis "<<dis[i][j]<<'\n';
	} 
    for(int i=1;i<=n;i++) fa[i][dep[i]+1]=i;
    for(int i=1;i<=n;i++) change(i,val[i]);
    while(m--){
        int a=read(),b=read()^ans,c=read()^ans;
        if(!a) ans=query(b,c),printf("%d\n",ans);
        else change(b,c-val[b]),val[b]=c;
    }
    return 0;
}
