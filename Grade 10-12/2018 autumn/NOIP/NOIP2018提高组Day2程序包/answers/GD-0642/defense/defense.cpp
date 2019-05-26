#include<cstdio>
#include<cctype>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll inf=1e14,N=3e5+500;

int gti(void)
{
    char c=getchar();
    int ret=0,st=1;
    for (;!isdigit(c);c=getchar()) if (c=='-') st=-1;
    for (;isdigit(c);c=getchar()) ret=ret*10+c-'0';
    return ret*st;
}

struct edge{edge *nxt;int to;}pool[N<<1],*pt[N],*ep=pool;
void add(int a,int b)
{
    *(++ep)=(edge){pt[a],b},pt[a]=ep;
    *(++ep)=(edge){pt[b],a},pt[b]=ep;
}
ll f[N][2],p[N][2];
void dfs(int v,int fa=0)
{
    f[v][0]=p[v][0],f[v][1]=p[v][1];
    for (edge *i=pt[v];i;i=i->nxt)
        if (i->to!=fa)
        {
            dfs(i->to,v);
            f[v][0]+=f[i->to][1];
            f[v][1]+=min(f[i->to][0],f[i->to][1]);
        }
}

char tp[10];
int main(void)
{
    freopen("defense.in","r",stdin);
    freopen("defense.out","w",stdout);
    int n=gti(),m=gti();
    scanf("%s",tp);
    for (int i=1;i<=n;i++) p[i][1]=gti();
    for (int i=1;i<n;i++)
    {
        int u=gti(),v=gti();
        add(u,v);
    }
    for (int i=1;i<=m;i++)
    {
        int a=gti(),x=gti(),b=gti(),y=gti();
        int tmp1=p[a][!x],tmp2=p[b][!y];
        p[a][!x]=inf,p[b][!y]=inf;
        dfs(1);
        ll ans=min(f[1][0],f[1][1]);
        if (ans>=inf)
            puts("-1");
        else printf("%lld\n",ans);
        p[a][!x]=tmp1,p[b][!y]=tmp2;
    }
    return 0;
}
