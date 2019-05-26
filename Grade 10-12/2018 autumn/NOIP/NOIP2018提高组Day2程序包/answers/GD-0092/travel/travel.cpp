#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <vector>
#include <functional>

using namespace std;

int getint()
{
	char ch=getchar();
	int f=1,x=0;
	while(!isdigit(ch)){if(ch=='-') f=-1; ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0'; ch=getchar();}
	return f*x;
}

const int N=5050;

int n,m;
struct edge
{
    int v;
    edge *next;
}pool[N*2],*head[N],*tp=pool;
int ans[N];

void addedge(int u,int v)
{
    *tp=(edge){v,head[u]},head[u]=tp++;
    //*tp=(edge){u,head[v]},head[v]=tp++;
}

void init()
{
    n=getint(),m=getint();
    vector<int> tmp[N];
    for(int i=1; i<=m; i++){
        int u=getint(),v=getint();
        //addedge(u,v);
        tmp[u].push_back(v);
        tmp[v].push_back(u);
    }
    for(int i=1; i<=n; i++){
        sort(tmp[i].begin(),tmp[i].end(),greater<int>());
        for(int j=0; j<(int)tmp[i].size(); j++){
            addedge(i,tmp[i][j]);
        }
    }
}

namespace gdtree
{
    int len=0;
    
    void dfs(int x,int fa)
    {
        ans[++len]=x;
        for(edge *i=head[x]; i; i=i->next){
            if(i->v==fa) continue;
            dfs(i->v,x);
        }
    }
    
    void work()
    {
        dfs(1,1);
        for(int i=1; i<=n; i++){
            printf("%d ",ans[i]);
        }
        puts("");
    }
}

namespace bdloop
{
    int lp[N],lpcnt;
    bool vis[N];
    int stk[N],top;
    int len,tmp[N];
    int ban1,ban2;
    
    bool getlp(int x,int fa)
    {
        if(vis[x]){
            while(top){
                lp[++lpcnt]=stk[top];
                if(stk[top]==x) break;
                top--;
            }
            return true;
        }
        stk[++top]=x;
        vis[x]=true;
        for(edge *i=head[x]; i; i=i->next){
            if(i->v==fa) continue;
            if(getlp(i->v,x)){
                return true;
            }
        }
        top--;
        return false;
    }
    
    void dfs(int x,int fa)
    {
        tmp[++len]=x;
        for(edge *i=head[x]; i; i=i->next){
            if(i->v==fa) continue;
            if(max(x,i->v)==ban1 && min(x,i->v)==ban2) continue;
            dfs(i->v,x);
        }
    }
    
    void work()
    {
        getlp(1,1);
        len=0;
        ban1=max(lp[1],lp[lpcnt]);
        ban2=min(lp[1],lp[lpcnt]);
        dfs(1,1);
        for(int i=1; i<=n; i++){
            ans[i]=tmp[i];
        }
        for(int i=1; i<lpcnt; i++){
            len=0;
            ban1=max(lp[i],lp[i+1]);
            ban2=min(lp[i],lp[i+1]);
            dfs(1,1);
            bool flg=false;
            for(int j=1; j<=n; j++){
                if(tmp[j]<ans[j]){
                    flg=true;
                    break;
                }else if(tmp[j]>ans[j]){
                    break;
                }
            }
            if(flg){
                for(int j=1; j<=n; j++){
                    ans[j]=tmp[j];
                }
            }
        }
        for(int i=1; i<=n; i++){
            printf("%d ",ans[i]);
        }
        puts("");
    }
}

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    init();
    if(m==n-1){
        gdtree::work();
    }else{
        bdloop::work();
    }
    return 0;
}
