#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#define rep(i,x,y) for (int i=x; i<=(y); ++i)
#define repd(i,x,y) for (int i=x; i>=(y); --i)
#define repe(i,x) for (edge *i=fst[x]; i; i=i->nxt)
#define mid ((l+r)>>1)
#define lc (t<<1)
#define rc (lc|1)
#define lson l,mid,lc
#define rson mid+1,r,rc

using namespace std;
const int inf=0x3f3f3f3f;

int get()
{
    char c;
    while (!isdigit(c=getchar()) && c!='-');
    int s=c=='-'? -1:1,k=~s? c-'0':0;
    for (; isdigit(c=getchar()); k=k*10+c-'0');
    return s*k;
}

const int N=1e5+10;

int n,m,a[N],f[N][2];
struct edge
{
    int v;
    edge *nxt;
} pool[N*2],*tp=pool,*fst[N];

void dfs(int x,int fa=0)
{
    repe(i,x)
        if (i->v!=fa)
        {
            dfs(i->v,x);
            f[x][0]+=f[i->v][1];
            f[x][1]+=min(f[i->v][0],f[i->v][1]);
        }
}

void force()
{
    int a=get(),x=get(),b=get(),y=get();
    rep(i,1,n)
        f[i][0]=0,f[i][1]=::a[i];
    f[a][1-x]=f[b][1-y]=inf;
    dfs(1);
    int ans=min(f[1][0],f[1][1]);
    printf("%d\n",ans<inf? ans:-1);
}

typedef int mtx[2][2];

void mul(mtx &c,const mtx &a,const mtx &b)
{
    c[0][0]=min(a[0][0]+b[0][0],a[0][1]+b[1][0]);
    c[0][1]=min(a[0][0]+b[0][1],a[0][1]+b[1][1]);
    c[1][0]=min(a[1][0]+b[0][0],a[1][1]+b[1][0]);
    c[1][1]=min(a[1][0]+b[0][1],a[1][1]+b[1][1]);
}

void modify(mtx &t,int f0,int f1)
{
    t[0][0]=t[1][0]=t[1][1]=f1,t[0][1]=f0;
}

const int T=1<<18|1;
mtx tr[T];

void pushup(int t)
{
    mul(tr[t],tr[lc],tr[rc]);
}

void modify(int p,int f0,int f1,int l=1,int r=n,int t=1)
{
    if (l==r)
    {
        modify(tr[t],f0,f1);
        return;
    }
    p<=mid? modify(p,f0,f1,lson):modify(p,f0,f1,rson);
    pushup(t);
}

void change(int x,bool f)
{
    if (f)
        modify(x,a[x],a[x]);
    else
        modify(x,0,inf);
}

void clr(int x)
{
    modify(x,0,a[x]);
}

void work()
{
    int a=get(),x=get(),b=get(),y=get(),ans=inf;
    change(a,x),change(b,y);
    rep(i,0,1)
        rep(j,0,1)
            ans=min(ans,tr[1][i][j]);
    clr(a),clr(b);
    printf("%d\n",ans<inf? ans:-1);
}

int main()
{
    freopen("defense.in","r",stdin);
    freopen("defense.out","w",stdout);
    n=get(),m=get(),scanf("%*s");
    rep(i,1,n)
        a[i]=get();
    rep(i,2,n)
    {
        int u=get(),v=get();
        *tp=(edge){v,fst[u]},fst[u]=tp++;
        *tp=(edge){u,fst[v]},fst[v]=tp++;
    }
    if (n<=5000 && m<=5000)
    {
        for (; m--; force());
        return 0;
    }
    for (; m--; work());
    return 0;
}
