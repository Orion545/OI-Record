#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define N 120
#define A 25020
using namespace std;

int a[N];
int f[A];
bool g[A];

int main(void)
{
    int t;
    int n, m, o;
    int i, j;

    freopen("money.in" , "r", stdin );
    freopen("money.out", "w", stdout);

    scanf("%d", &t);
    while(t --)
    {
        memset(f,     0, sizeof f);
        memset(g, false, sizeof g);

        scanf("%d", &n);
        for(i = m = 0; i < n; i ++)
        {
            scanf("%d", &a[i]);
            g[a[i]] = true;
            m = max(m, a[i]);
        }

        for(i = 0, f[0] = 1; i < n; i ++)
            for(j = a[i]; j <= m; j ++)
                f[j] += f[j - a[i]];

        for(i = o = 0; i <= m; i ++)
            o += (f[i] == 1 && g[i]);
        printf("%d\n", o);
    }

    return 0;
}
