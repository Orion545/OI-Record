#include<cstdio>
#include<vector>
#include<cctype>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=6000;

int gti(void)
{
    char c=getchar();
    int ret=0,st=1;
    for (;!isdigit(c);c=getchar()) if (c=='-') st=-1;
    for (;isdigit(c);c=getchar()) ret=ret*10+c-'0';
    return ret*st;
}

vector<int> to[N];
typedef vector<int>::iterator I;
void add(int a,int b)
{
    to[a].push_back(b);
    to[b].push_back(a);
}

bool ins[N],c[N];
int stk[N],tp,nxt[N];
int dfs(int v,int fa=0)
{
    if (ins[v])
    {
        for (int i=tp,j=v;i>=1;i--)
        {
            c[stk[i]]=true,nxt[stk[i]]=j,j=stk[i];
            if (stk[i]==v) break;
        }
        return v;
    }
    stk[++tp]=v,ins[v]=true;
    for (I i=to[v].begin();i!=to[v].end();i++)
        if (*i!=fa)
        {
            int now=dfs(*i,v);
            if (now) return now;
        }
    --tp,ins[v]=false;
    return 0;
}

int arr[N],ans[N],tot,tag;
void solve(int v,int fa=0)
{
    arr[++tot]=v;
    for (I i=to[v].begin();i!=to[v].end();i++)
        if (*i!=fa&&(v!=tag||*i!=nxt[v])&&(*i!=tag||v!=nxt[*i]))
            solve(*i,v);
}
bool cmp(void)
{
    for (int i=1;i<=tot;i++)
    {
        if (arr[i]<ans[i]) return true;
        if (arr[i]>ans[i]) return false;
    }
    return false;
}
void upd(void)
{
    if (cmp())
        for (int i=1;i<=tot;i++)
            ans[i]=arr[i];
}

int main(void)
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int n=gti(),m=gti();
    for (int i=1;i<=m;i++)
        add(gti(),gti());
    for (int i=1;i<=n;i++)
        sort(to[i].begin(),to[i].end());
    for (int i=1;i<=n;i++) ans[i]=n;
    if (n==m)
    {
        int now=dfs(1);
        for (int i=now;i;i=nxt[i])
        {
            tot=0,tag=i,solve(1),upd();
            if (nxt[i]==now) break;
        }
    }
    else
        tot=0,solve(1),upd();
    for (int i=1;i<=n;i++)
    {
        printf("%d",ans[i]);
        if (i<n) putchar(' ');
    }
    return 0;
}
