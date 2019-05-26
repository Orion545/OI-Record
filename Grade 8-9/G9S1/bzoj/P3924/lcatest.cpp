#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m;
void _swap(int &l,int &r){l^=r;r^=l;l^=r;}
struct Original_Tree{
    int cnt,First[100010],dis[100010],dep[100010];
    int st[100010][20];
    struct Edge{int to,next,w;}A[200010];
    void add(int u,int v,int w){
        A[++cnt]=(Edge){v,First[u],w};First[u]=cnt;
        A[++cnt]=(Edge){u,First[v],w};First[v]=cnt;
    }
    void dfs(int u,int f){
        st[u][0]=f;int i,v;
        //cout<<"dfs "<<u<<" "<<f<<" "<<dis[u]<<" "<<dep[u]<<"\n";
        for(i=First[u];~i;i=A[i].next){
            v=A[i].to;
            if(v==f) continue;
            dis[v]=dis[u]+A[i].w;dep[v]=dep[u]+1;
            dfs(v,u);
        }
    }
    void initst(){
        dis[1]=0;dep[1]=1;dfs(1,0);int i,j;
        for(j=1;j<20;j++){
            for(i=1;i<=n;i++) st[i][j]=st[st[i][j-1]][j-1];
        }
       /* for(i=1;i<=n;i++){*/
            //for(j=0;j<=3;j++) cout<<st[i][j]<<" ";
            //cout<<"\n";
        /*}*/
    }
    int getdis(int u,int v){
        if(dep[u]>dep[v]) _swap(u,v);
        int i,lca,tu=u,tv=v;
        //cout<<"begin "<<u<<" "<<v<<"\n";
        for(i=19;i>=0;i--) 
            if(dep[st[v][i]]>=dep[u]) v=st[v][i];
        //cout<<"half finish "<<u<<" "<<v<<"\n";
        if(u==v) return dis[tv]-dis[u];
        for(i=19;i>=0;i--)
            if(st[u][i]!=st[v][i]){
                u=st[u][i];
                v=st[v][i];
            }
        lca=st[u][0];
        //cout<<"getdis "<<tu<<" "<<tv<<" "<<lca<<"\n";
        return dis[tu]+dis[tv]-2*dis[lca];
    }
}T;
int main(){
    memset(T.First,-1,sizeof(T.First));
    int i,t1,t2,t3;
    cin>>n>>m;
    for(i=1;i<n;i++){
        scanf("%d%d%d",&t1,&t2,&t3);
        T.add(t1,t2,t3);
    }
    T.initst();
    for(i=1;i<=m;i++){
        scanf("%d%d",&t1,&t2);
        printf("%d\n",T.getdis(t1,t2));
    }
}
