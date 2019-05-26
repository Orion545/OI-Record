#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#define N 5020
using namespace std;

vector<int> e[N], q;
int a, b, l, o[N], t[N], s[N];
bool v[N], f;

void circle(int x, int p)
{
    int i, j;

    s[l ++] = x;
    v[x] = true;

    for(i = 0; i < (signed)e[x].size(); i ++)
        if(e[x].at(i) != p)
        {
            if(v[e[x].at(i)] && !f)
            {
                f = true;
                for(j = l - 1; s[j + 1] != e[x].at(i); j --)
                    q.push_back(s[j]);
            }
            if(!v[e[x].at(i)])
                circle(e[x].at(i), x);
        }

    -- l;

    return;
}

void dfs(int x, int p)
{
    int i;

    o[l ++] = x;

    for(i = 0; i < (signed)e[x].size(); i ++)
        if(e[x].at(i) != p)
        {
            if((x == a && e[x].at(i) == b) || (x == b && e[x].at(i) == a))
                continue;
            dfs(e[x].at(i), x);
        }

    return;
}

bool cmp(int *a, int *b, int n)
{
    int i;

    for(i = 0; i < n; i ++)
        if(a[i] != b[i])
            return a[i] < b[i];

    return false;
}

int main(void)
{
    int n, m;
    int i, j;
    int u, v;

    freopen("travel.in" , "r", stdin );
    freopen("travel.out", "w", stdout);

    scanf("%d %d", &n, &m);
    for(i = 0; i < m; i ++)
    {
        scanf("%d %d", &u, &v);
        e[u].push_back(v);
        e[v].push_back(u);
    }

    for(i = 1; i <= n; i ++)
        sort(e[i].begin(), e[i].end());

    memset(o, 0x7f, sizeof o);
    if(m + 1 == n)
        dfs(1, 0);
    else
    {
        circle(1, 0);
        for(i = 1; i < (signed)q.size(); i ++)
        {
            a = q.at(i - 1);
            b = q.at(i    );
            l = 0;
            dfs(1, 0);
            if(i == 1 || cmp(o, t, n))
                for(j = 0; j < n; j ++)
                    t[j] = o[j];
        }
        for(i = 0; i < n; i ++)
            o[i] = t[i];
    }

    for(i = 0; i < n; i ++)
    {
        if(i)
            putchar(' ');
        printf("%d", o[i]);
    }

    return 0;
}