#include<bits/stdc++.h>
using namespace std;

#define Re return
#define In inline
#define St static
#define Rg register
#define Op operator
#define Ct continue
#define inc(l, i, r) for(Rg int i=l; i<r; ++i)
#define dec(l, i, r) for(Rg int i=r; i>l; --i)

typedef long long ll;

const int mxN=1<<17;

struct E
{
    int v, l, o;
    In E() {}
    In E(int v, int l, int o) : v(v), l(l), o(o) {}
} e[mxN<<1]; int h[mxN];

In void aE(int u, int v, int w) 
{
    St int t=0;
    e[++t]=E(v, w, u[h]);
    u[h]=t;
}

#define fev for(Rg int v, o=u[h]; v=o[e].v, o>0; o=o[e].o)

int mid, cnt;

int DFS(int u, int w)
{
    multiset<int> q;
    q.clear();
    fev
        if(v!=w)
        {
            Rg int d=DFS(v, u)+o[e].l;
            if(d>=mid) ++cnt;
            else q.insert(d);
        }
    Rg int r=0;
    for(;!q.empty();)
    {
        multiset<int> :: iterator it=q.lower_bound(mid-*q.begin());
        if(it==q.begin()) ++it;
        if(it!=q.end())
        {
            q.erase(it);
            q.erase(q.begin());
            ++cnt;
        }
        else
        {
            r=*q.begin();
            q.erase(q.begin());
        }
    }
    Re r;
}

int main()
{
    freopen("track.in", "r", stdin);
    freopen("track.out", "w", stdout);
    St int n, m;
    scanf("%d%d", &n, &m);
    inc(1, i, n)
    {
        St int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        aE(u, v, w), aE(v, u, w);
    }
    Rg int l=0, r=5e8+1;
    for(; l<r-1;)
    {
        mid=(l+r)>>1;
        cnt=0;
        DFS(1, 0);
        if(cnt>=m)
            l=mid;
        else
            r=mid;
    }
    printf("%d\n", l);
    Re 0;
}
