#include<bits/stdc++.h>
using namespace std;

#define Re return
#define In inline
#define Op operator
#define St static
#define Rg register
#define Ct continue
#define mP make_pair
#define lB lower_bound
#define inc(l, i, r) for(Rg int i=l; i<r; ++i)
#define dec(l, i, r) for(Rg int i=r; i>l; --i)

typedef long long ll;
typedef double db;
typedef pair<int, int> pInt;

const int mxN=1<<13, inf=1<<29;

struct E
{
    int v, o;
    In E() {}
    In E(int v, int o) : v(v), o(o) {}
} e[mxN<<1]; int h[mxN];

In void aE(int u, int v) {St int t=0; e[++t]=E(v, u[h]); u[h]=t;}

int f[mxN][2], p[mxN], a, b, x, y;

#define fev for(Rg int v, o=u[h]; v=o[e].v, o>0; o=o[e].o)

In void mne(int& a, int b) {if(a>b) a=b;}

void DFS(int u, int w)
{
    f[u][0]=0, f[u][1]=p[u];
    fev
        if(v!=w)
        {
            DFS(v, u);
            f[u][0]=min(f[u][0]+f[v][1], inf);
            f[u][1]=min(f[u][1]+min(f[v][0], f[v][1]), inf);
        }
    if(u==a) f[u][!x]=inf;
    if(u==b) f[u][!y]=inf;
}

int main()
{
    freopen("defense.in", "r", stdin);
    freopen("defense.out", "w", stdout);
    St int n, m; St char s[233];
    scanf("%d%d%s", &n, &m, s);
    inc(1, i, n+1)
        scanf("%d", p+i);
    inc(1, i, n)
    {
        St int u, v;
        scanf("%d%d", &u, &v);
        aE(u, v), aE(v, u);
    }
    for(;m--;)
    {
        scanf("%d%d%d%d", &a, &x, &b, &y);
        inc(1, i, n+1) f[i][0]=f[i][1]=inf;
        DFS(1, 0);
        Rg int r=min(f[1][0], f[1][1]);
        printf("%d\n", r==inf? -1: r);
    }
    Re 0;
}
