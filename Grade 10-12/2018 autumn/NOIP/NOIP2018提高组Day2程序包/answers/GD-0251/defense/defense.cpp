#include <iostream>
#include <algorithm>
#include <cstdio>
#include <utility>
#define N 100020
#define oo 9999999999999LL
using namespace std;

int a[N];
int h[N], v[N << 1], x[N << 1];
pair<int, int> p, q;
long long f[N][2], g[N][2], t[N][2];

void DFS(int x, int p)
{
    int i;

    f[x][0] = 0;
    f[x][1] = a[x];
    for(i = h[x]; i; i = ::x[i])
        if(v[i] != p)
        {
            DFS(v[i], x);
            f[x][0] += f[v[i]][1];
            f[x][1] += min(f[v[i]][0], f[v[i]][1]);
        }
    if(x == ::p.first)
        f[x][::p.second ^ 1] = oo;
    if(x == q.first)
        f[x][q.second ^ 1] = oo;

    return;
}

void AddEdge(int u, int v)
{
    static int c = 0;

    x[++ c] = h[u];
    h[u] = c;
    ::v[c] = v;

    return;
}

int main(void) //defense.cpp
{
    int n, m, u, v;
    int i;
    char k[3];

    freopen("defense.in" , "r", stdin );
    freopen("defense.out", "w", stdout);

    scanf("%d %d %s", &n, &m, k);
    for(i = 1; i <= n; i ++)
        scanf("%d", &a[i]);
    for(i = 1; i < n; i ++)
    {
        scanf("%d %d", &u, &v);
        AddEdge(u, v);
        AddEdge(v, u);
    }

    if(k[0] == 'A' && n > 2000)
    {
        if(k[1] == '1')
        {
            f[1][0] = oo;
            f[1][1] = a[1];
            for(i = 2; i <= n; i ++)
            {
                f[i][0] = f[i - 1][1];
                f[i][1] = min(f[i - 1][0], f[i - 1][1]) + a[i];
            }
            for(i = n; i >= 1; i --)
            {
                g[i][0] = g[i + 1][1];
                g[i][1] = min(g[i + 1][0], g[i + 1][1]) + a[i];
            }
            g[1][0] = oo;

            while(m --)
            {
                scanf("%d %d %d %d", &p.first, &p.second, &q.first, &q.second);
                if(p.first > q.first)
                     swap(p, q);
                if(q.second)
                    printf("%lld\n", f[q.first][q.second] + g[q.first][q.second] - a[q.first]);
                else
                    printf("%lld\n", f[q.first][q.second] + g[q.first][q.second]);
            }
        }
        else
        {
            for(i = 1; i <= n; i ++)
            {
                f[i][0] = f[i - 1][1];
                f[i][1] = min(f[i - 1][0], f[i - 1][1]) + a[i];
            }
            for(i = n; i >= 1; i --)
            {
                g[i][0] = g[i + 1][1];
                g[i][1] = min(g[i + 1][0], g[i + 1][1]) + a[i];
            }

            while(m --)
            {
                scanf("%d %d %d %d", &p.first, &p.second, &q.first, &q.second);
                if(k[1] == '2')
                {
                    if(p.first > q.first)
                        swap(p, q);
                    if(!p.second && !q.second)
                        printf("-1\n");
                    else
                        printf("%lld\n", f[p.first][p.second] + g[q.first][q.second]);
                }
                else
                {
                    if(p.first > q.first)
                        swap(p, q);

                    if(p.second)
                    {
                        t[p.first][0] = oo;
                        t[p.first][1] = a[p.first];
                    }
                    else
                    {
                        t[p.first][0] = 0;
                        t[p.first][1] = oo;
                    }
                    for(i = p.first + 1; i <= q.first; i ++)
                    {
                        t[i][0] = t[i - 1][1];
                        t[i][1] = min(t[i - 1][0], t[i - 1][1]) + a[i];
                    }

                    if(p.first + 1 == q.first && !p.second && !q.second)
                        printf("-1\n");
                    else
                        printf("%lld\n", f[p.first][p.second] + t[q.first][q.second] + g[q.first][q.second] - (p.second ? a[p.first] : 0) - (q.second ? a[q.first] : 0));
                }
            }
        }
    }
    else
    {
        while(m --)
        {
            scanf("%d %d %d %d", &p.first, &p.second, &q.first, &q.second);
            DFS(1, 1);
            printf("%lld\n", min(f[1][0], f[1][1]) >= oo ? -1 : min(f[1][0], f[1][1]));
        }
    }

    return 0;
}

