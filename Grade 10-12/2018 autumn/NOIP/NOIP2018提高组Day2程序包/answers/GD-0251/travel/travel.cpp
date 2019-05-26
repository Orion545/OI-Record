#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <utility>
#define N 5020
using namespace std;

vector<pair<int, int> > e[N];
int h[N], v[N << 1], w[N << 1], x[N << 1];
int k[N], c;
int o[N];
bool u[N];

void DFS(int x, int p, int g)
{
    int i;

    if(u[x])
        return;
    u[x] = true;

    k[c ++] = x;
    for(i = h[x]; i; i = ::x[i])
        if(v[i] != p && w[i] != g)
            DFS(v[i], x, g);

    return;
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

int main(void) //travel.cpp
{
    int n, m, u, v;
    int i, j;

    freopen("travel.in" , "r", stdin );
    freopen("travel.out", "w", stdout);

    scanf("%d %d", &n, &m);
    for(i = 0; i < m; i ++)
    {
        scanf("%d %d", &u, &v);
        e[-- u].push_back(make_pair(-- v, i));
        e[   v].push_back(make_pair(   u, i));
    }
    for(i = 0; i < n; i ++)
        sort(e[i].begin(), e[i].end());
    for(i = 0; i < n; i ++)
        for(j = e[i].size() - 1; j > -1; j --)
            AddEdge(i, e[i].at(j).first, e[i].at(j).second);

    if(m == n - 1)
    {
        DFS(0, 0, -1);
        for(i = 0; i < n; i ++)
        {
            if(i)
                putchar(' ');
            printf("%d", k[i] + 1);
        }
        printf("\n");
    }
    else
    {
        o[0] = n;
        for(i = 0; i < m; i ++)
        {
            c = 0;
            memset(::u, false, sizeof(::u));
            DFS(0, 0, i);
            if(c == n)
            {
                for(j = 0; j < n; j ++)
                    if(o[j] < k[j])
                        break;
                    else if(o[j] > k[j])
                    {
                        for(j = 0; j < n; j ++)
                            o[j] = k[j];
                        break;
                    }
            }
        }

        for(i = 0; i < n; i ++)
        {
            if(i)
                putchar(' ');
            printf("%d", o[i] + 1);
        }
        printf("\n");
    }

    return 0;
}

