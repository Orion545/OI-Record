#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <utility>
#define N 50020
using namespace std;

int n, m;
int h[N], v[N << 1], w[N << 1], x[N << 1];
set<pair<int, int> > b;
vector<pair<int, int> > d;
int o;
map<int, int> f[N];
int g[N];
bool u[N];

void DFS(int x, int p, int k)
{
    int i, c;
    map<int, int>::iterator t;
    set<pair<int, int> >::iterator s;

    f[x].clear();
    f[x][0] = 1;
    g[x] = 0;
    for(i = h[x]; i; i = ::x[i])
        if(v[i] != p)
        {
            DFS(v[i], x, k);
            g[v[i]] += w[i];
        }

    b.clear();
    d.clear();
    for(i = h[x]; i; i = ::x[i])
        if(v[i] != p)
        {
//            cout<<x+1<<' '<<v[i]+1<<' '<<k<<endl;
            c = f[v[i]].rbegin() -> first + g[v[i]];
            if(c >= k)
            {
                o ++;
                u[v[i]] = true;
            }
            else
            {
//                printf("insert [%d, %d]\n", c, v[i]);
                b.insert(make_pair(c, v[i]));
                d.push_back(make_pair(c, v[i]));
                u[v[i]] = false;
            }
        }
    sort(d.begin(), d.end());

    for(i = 0; i < (signed)d.size(); i ++)
        if(!u[d.at(i).second])
        {
            s = b.lower_bound(make_pair(k - d.at(i).first, -1));
            if(s != b.end() && *s == d.at(i))
                ++ s;
            if(s != b.end())
            {
                o ++;
                u[d.at(i).second] = true;
                u[s -> second] = true;
                b.erase(d.at(i));
                b.erase(s);
            }
        }

    for(i = h[x]; i; i = ::x[i])
        if(v[i] != p && !u[v[i]])
        {
            if(f[x].size() < f[v[i]].size())
            {
                swap(f[x], f[v[i]]);
                swap(g[x], g[v[i]]);
            }
            for(t = f[v[i]].begin(); t != f[v[i]].end(); ++ t)
                f[x][t -> first + g[v[i]] - g[x]] += t -> second;
        }

    return;
}

void Chain(int x, int p, int k, int v)
{
    int i;

//    cerr<<x<<endl;
    if(v >= k)
    {
        o ++;
        v = 0;
    }
    for(i = h[x]; i; i = ::x[i])
        if(::v[i] != p)
            Chain(::v[i], x, k, v + w[i]);

    return;
}

int Farthest(int x, int p)
{
    int i, t, o;

    for(i = h[x], o = x; i; i = ::x[i])
        if(v[i] != p)
        {
            g[v[i]] = g[x] + w[i];
            t = Farthest(v[i], x);
            if(g[o] < g[t])
                o = t;
        }

    return o;
}

void AddEdge(int u, int v, int w)
{
    static int c = 0;

    x[++ c] = h[u];
    h[u] = c;
    ::v[c] = v;
    ::w[c] = w;

    return;
}

int main(void) //track.cpp
{
    int u, v, w;
    int i, l, r, k;
    bool x;

    freopen("track.in" , "r", stdin );
    freopen("track.out", "w", stdout);

    scanf("%d %d", &n, &m);
    x = true;
    for(i = 1, r = 0, l = N; i < n; i ++)
    {
        scanf("%d %d %d", &u, &v, &w);
        if(v != u + 1)
            x = false;
        AddEdge(-- u, -- v, w);
        AddEdge(   v,    u, w);
        l = min(l, w);
        r += w;
    }

    if(m == 1)
    {
        l = Farthest(0, 0);
        g[l] = 0;
        printf("%d\n", g[Farthest(l, l)]);

        return 0;
    }

    for(r ++; l + 1 < r; )
    {
        k = (l + r) >> 1;
        o = 0;
        if(x)
            Chain(0, 0, k, 0);
        else
            DFS(0, 0, k);
        if(o >= m)
            l = k;
        else
            r = k;
    }
    printf("%d\n", l);

    return 0;
}
