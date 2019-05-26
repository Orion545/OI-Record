#include <cstdio>
#include <cctype>
#include <vector>
#include <cstring>
#include <algorithm>
#define rep(i,x,y) for (int i=x; i<=(y); ++i)
#define repd(i,x,y) for (int i=x; i>=(y); --i)
#define repe(i,x) for (vector<int>::iterator i=trs[x].begin(); i!=trs[x].end(); ++i)

using namespace std;

int get()
{
    char c;
    while (!isdigit(c=getchar()) && c!='-');
    int s=c=='-'? -1:1,k=~s? c-'0':0;
    for (; isdigit(c=getchar()); k=k*10+c-'0');
    return s*k;
}

const int N=1e5+10;
int n,m,cir,nxt[2],t,stk[N],top;
vector<int> trs[N];
bool vis[N],incir[N],iscut;

void dfs0(int x,int fa=0)
{
    vis[x]=1,stk[++top]=x;
    repe(i,x)
    {
        int v=*i;
        if (v==fa)
            continue;
        if (vis[v])
        {
            if (cir)
                continue;
            cir=v;
            for (int i=top; stk[i]!=v; --i)
                incir[stk[i]]=1;
        }
        else
            dfs0(v,x);
    }
    --top;
}

void dfs(int x)
{
    printf("%d ",x);
    vis[x]=1;
    repe(i,x)
    {
        int v=*i;
        if (vis[v])
            continue;
        if (incir[x] && !iscut && v>nxt[1])
            iscut=1;
        else
            dfs(v);
    }
}

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    n=get(),m=get();
    rep(i,1,m)
    {
        int u=get(),v=get();
        trs[u].push_back(v);
        trs[v].push_back(u);
    }
    rep(i,1,n)
        sort(trs[i].begin(),trs[i].end());
    dfs0(1);
    repe(i,cir)
        if (incir[*i])
            nxt[t++]=*i;
    sort(nxt,nxt+2);
    memset(vis,0,sizeof(vis));
    dfs(1);
    return 0;
}
