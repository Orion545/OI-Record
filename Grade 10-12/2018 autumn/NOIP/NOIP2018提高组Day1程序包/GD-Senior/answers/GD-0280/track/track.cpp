#include <set>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#define rep(i,x,y) for (int i=x; i<=(y); ++i)
#define repe(i,x) for (edge *i=fst[x]; i; i=i->nxt)

using namespace std;

int get()
{
    char c;
    while (!isdigit(c=getchar()) && c!='-');
    int s=c=='-'? -1:1,k=~s? c-'0':0;
    for (; isdigit(c=getchar()); k=k*10+c-'0');
    return s*k;
}

const int N=5e4+10;

int n,m,sw,lim,f[N],g[N],w[N],pre[N],nxt[N],t;

struct edge
{
    int v,w;
    edge *nxt;
} pool[N*2],*tp=pool,*fst[N];

void erase(int x)
{
    nxt[pre[x]]=nxt[x],pre[nxt[x]]=pre[x];
}

void dfs(int x,int fa=0)
{
    int v;
    f[x]=g[x]=0;
    repe(i,x)
        if (i->v!=fa)
            dfs(i->v,x);
    t=0;
    repe(i,x)
        if ((v=i->v)==fa)
            continue;
        else if (f[x]+=f[v],g[v]+i->w>=lim)
            ++f[x];
        else
            w[++t]=g[v]+i->w;
    sort(w+1,w+t+1);
    rep(i,1,t+1)
        pre[i]=i-1,nxt[i]=i+1;
    for (int i=1,j=t; i<=t; i=nxt[i])
    {
        for (; i+1<j && w[i]+w[j]>=lim; j=pre[j]);
        for (; j<=t && w[i]+w[j]<lim; j=nxt[j]);
        if (i==j)
            j=nxt[j];
        if (j>t)
            g[x]=w[i],j=pre[j];
        else
            ++f[x],erase(j),j=nxt[j]>t? pre[j]:nxt[j];
        erase(i);
    }
}

bool check(int t)
{
    lim=t,dfs(1);
    return f[1]>=m;
}

int main()
{
    freopen("track.in","r",stdin);
    freopen("track.out","w",stdout);
    n=get(),m=get();
    rep(i,2,n)
    {
        int u=get(),v=get(),w=get();
        sw+=w;
        *tp=(edge){v,w,fst[u]},fst[u]=tp++;
        *tp=(edge){u,w,fst[v]},fst[v]=tp++;
    }
    int l=0,r=sw,mid;
    while (l<=r)
        if (check(mid=(l+r)>>1))
            l=mid+1;
        else
            r=mid-1;
    printf("%d",l-1);
    return 0;
}
