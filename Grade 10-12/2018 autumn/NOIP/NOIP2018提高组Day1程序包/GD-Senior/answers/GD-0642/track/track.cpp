#include<cstdio>
#include<set>
#include<cctype>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll inf=1e18,N=5e4+50;

int gti(void)
{
    char c=getchar();
    int ret=0,st=1;
    for (;!isdigit(c);c=getchar()) if (c=='-') st=-1;
    for (;isdigit(c);c=getchar()) ret=ret*10+c-'0';
    return ret*st;
}

struct edge{edge *nxt;int to,val;}pool[N<<1],*pt[N],*p=pool;
void add(int a,int b,int c)
{
    *(++p)=(edge){pt[a],b,c},pt[a]=p;
    *(++p)=(edge){pt[b],a,c},pt[b]=p;
}

struct P
{
    ll val;
    int id;
    bool operator<(const P &b)const
    {
        if (val==b.val) return id<b.id;
        return val<b.val;
    }
};
set<P> s;
ll a[N],b[N],f[N];
int check(ll t,int v=1,int fa=0)
{
    f[v]=0;
    int ret=0;
    for (edge *i=pt[v];i;i=i->nxt)
        if (i->to!=fa)
            ret+=check(t,i->to,v);
    int cnt=0;
    s.clear();
    for (edge *i=pt[v];i;i=i->nxt)
        if (i->to!=fa)
            ++cnt,a[cnt]=f[i->to]+i->val,b[cnt]=0;
    sort(a+1,a+1+cnt);
    for (;cnt>=1;--cnt,++ret)
        if (a[cnt]<t)
            break;
    for (int i=1;i<=cnt;i++)
    {
        P now=(P){a[i],i};
        s.insert(now);
    }
    P mx=(P){inf,0};
    s.insert(mx);
    for (int i=1;i<=cnt;i++)
        if (!b[i])
        {
            P x=(P){t-a[i],0},y=(P){a[i],i+1},now=max(x,y);
            P pr=*s.lower_bound(now);
            if (i<pr.id)
            {
                b[i]=true,b[pr.id]=true;
                P x=(P){a[i],i},y=(P){a[pr.id],pr.id};
                s.erase(x),s.erase(y);
                ++ret;
            }
        }
    for (int i=cnt;i>=1;i--)
        if (!b[i])
        {
            f[v]=a[i];
            break;
        }
    return ret;
}

int main(void)
{
    freopen("track.in","r",stdin);
    freopen("track.out","w",stdout);
    int n=gti(),m=gti();
    ll l=inf,r=0,ans=0;
    for (int i=1;i<n;i++)
    {
        int u=gti(),v=gti(),w=gti();
        add(u,v,w),l=min(l,1ll*w),r+=w;
    }
    l=min(l,r),ans=l;
    while (l<=r)
    {
        ll mid=(l+r)>>1;
        if (check(mid)>=m)
            ans=mid,l=mid+1;
        else r=mid-1;
    }
    printf("%lld\n",ans);
    return 0;
}
