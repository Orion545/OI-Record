#include <cstdio>
#include <cstring>
#include <vector>
#define N 100020
#define M 100020
#define INF 20000000001LL
using namespace std;

vector<int> e[N];
long long p[N], f[N][2], g[N][2];
int a[M], x[M], b[M], y[M];

void dfs(int x, int p)
{
    int i;

    for(i = 0; i < (signed)e[x].size(); i ++)
        if(e[x].at(i) != p)
        {
            dfs(e[x].at(i), x);
            f[x][0] += f[e[x].at(i)][1];
            f[x][1] += min(f[e[x].at(i)][0], f[e[x].at(i)][1]);
        }

    f[x][1] += ::p[x];

    return;
}

int main(void)
{
    int n, m;
    char t[3];
    int i, j;
    int u, v;
    long long q, w, e, r, o;

    freopen("defense.in" , "r", stdin );
    freopen("defense.out", "w", stdout);

    scanf("%d %d %s", &n, &m, t);
    for(i = 1; i <= n; i ++)
        scanf("%lld", &p[i]);
    for(i = 1; i < n; i ++)
    {
        scanf("%d %d", &u, &v);
        ::e[u].push_back(v);
        ::e[v].push_back(u);
    }

    for(i = 0; i < m; i ++)
        scanf("%d %d %d %d", &a[i], &x[i], &b[i], &y[i]);

    if(t[0] == 'A')
    {
        for(i = 1; i <= n; i ++)
        {
            g[i][0] = g[i - 1][0];
            g[i][1] = g[i - 1][1];
            g[i][i & 1] += p[i];
        }

        if(t[1] == '1')
            for(i = 0; i < m; i ++)
            {
                q = g[b[i] - 1][0] + p[1];
                w = g[b[i] - 1][1]       ;
                e = g[n][0] - g[b[i]][0];
                r = g[n][1] - g[b[i]][1];
                if(y[i])
                    printf("%lld\n", p[b[i]] + min(min(q + e, q + r), min(w + e, w + r)));
                else
                    if(b[i] & 1)
                        printf("%lld\n", q + e);
                    else
                        printf("%lld\n", w + r);
            }

        if(t[1] == '2')
            for(i = 0; i < m; i ++)
            {
                q = g[a[i] - 1][0];
                w = g[a[i] - 1][1];
                e = g[n][0] - g[b[i]][0];
                r = g[n][1] - g[b[i]][1];
                if(b[i] < a[i])
                    swap(a[i], b[i]);
                if(!x[i] && !y[i])
                {
                    puts("-1");
                    continue;
                }
                o = 0LL;
                if(a[i] & 1)
                    swap(q, w);
                if(b[i] & 1)
                    swap(e, r);
                if(x[i])
                    o += min(q, w) + p[a[i]];
                else
                    o += w;
                if(y[i])
                    o += min(e, r) + p[b[i]];
                else
                    o += r;
                printf("%lld\n", o);
            }

        return 0;
    }

    for(i = 0; i < m; i ++)
    {
        memset(f, 0, sizeof f);
        f[a[i]][x[i] ^ 1] = f[b[i]][y[i] ^ 1] = INF;
        dfs(1, 0);
        o = min(f[1][0], f[1][1]);
        if(o >= INF)
            puts("-1");
        else
            printf("%lld\n", o);
    }

    return 0;
}