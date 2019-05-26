#include<bits/stdc++.h>
using namespace std;

#define Re return
#define In inline
#define Op operator
#define St static
#define Rg //register
#define Ct continue
#define mP make_pair
#define lB lower_bound
#define inc(l, i, r) for(Rg int i=l; i<r; ++i)
#define dec(l, i, r) for(Rg int i=r; i>l; --i)

typedef long long ll;
typedef double db;
typedef pair<int, int> pInt;

const int mxN=1<<13;

vector<int> e[mxN];

In void aE(int u, int v) {e[u].push_back(v);}

#define fev for(Rg int i=0; i<(int)e[u].size(); ++i)

bool vis[mxN]; int x, y, a, b;

void DFS0(int u, int w)
{
    vis[u]=1;
    fev
        if(e[u][i]!=w)
        {
            if(!vis[e[u][i]])
            {
                DFS0(e[u][i], u);
                if(x)
                {
                    if(e[u][i]>y) a=u, b=e[u][i];
                    if(x==u) x=0;
                    Re;
                }
            }
            else
            {
                x=b=e[u][i];
                y=a=u;
                Re;
            }
        }
}

void DFS1(int u, int w)
{
    printf("%d ", u);
    fev
        if(e[u][i]!=w && (u!=a || e[u][i]!=b) && (u!=b || e[u][i]!=a))
            DFS1(e[u][i], u);
}


int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    St int n, m;
    scanf("%d%d", &n, &m);
    inc(0, i, m)
    {
        St int u, v;
        scanf("%d%d", &u, &v);
        aE(u, v), aE(v, u);
    }
    inc(1, i, n+1)
        sort(e[i].begin(), e[i].end());
    if(m==n) DFS0(1, 0);
    DFS1(1, 0);
    puts("");
    Re 0;
}
