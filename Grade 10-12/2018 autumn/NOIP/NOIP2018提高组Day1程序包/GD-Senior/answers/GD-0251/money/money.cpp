#include <iostream>
#include <algorithm>
#include <cstdio>
#define N 103
#define M 25003
using namespace std;

int a[N];
bool f[N][M];

int main(void) //money.cpp
{
    int t, n;
    int i, j, k;

    freopen("money.in" , "r", stdin );
    freopen("money.out", "w", stdout);

    scanf("%d", &t);
    while(t --)
    {
        scanf("%d", &n);
        for(i = 1; i <= n; i ++)
            scanf("%d", &a[i]);
        sort(a + 1, a + n + 1);

        f[0][0] = true;
        for(i = 1; i <= n; i ++)
            for(j = 0; j <= a[n]; j ++)
            {
                f[i][j] = f[i - 1][j];
                if(j >= a[i])
                    f[i][j] |= f[i][j - a[i]];
            }
        for(i = 1, k = n; i < n; i ++)
            k -= f[i][a[i + 1]];
        printf("%d\n", k);
    }

    return 0;
}
