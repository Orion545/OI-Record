#include <cstdio>
#include <vector>
#define N 9
#define M 1000020
#define G 1000000007LL
using namespace std;

long long power(long long x, long long y)
{
    long long o;

    for(o = 1LL; y; y >>= 1, (x *= x) %= G)
        if(y & 1)
            (o *= x) %= G;

    return o;
}

int n, m, a[N][M], o;
vector<pair<int, int> > v;

void play(int x, int y, int w, int s)
{
    if(x + 1 == n && y + 1 == m)
    {
        v.push_back(make_pair(w, s));

        return;
    }

    s <<= 1;
    s |= a[x][y];

    if(y + 1 < m)
        play(x    , y + 1, (w << 1) | 1, s);
    if(x + 1 < n)
        play(x + 1, y    ,  w << 1     , s);

    return;
}

bool check(void)
{
    int i, j;

    v.clear();
    play(0, 0, 0, 0);

    for(i = 0; i < (signed)v.size(); i ++)
        for(j = 0; j < (signed)v.size(); j ++)
            if(v.at(j).first < v.at(i).first && v.at(j).second < v.at(i).second)
                return false;

    return true;
}

void dfs(int x, int y)
{
    int p, q;

    if(n == x)
    {
        o += check();

        return;
    }

    p = x;
    q = y;
    if(m == ++ y)
    {
        ++ x;
        y = 0;
    }

    a[p][q] = 0;
    dfs(x, y);

    a[p][q] = 1;
    dfs(x, y);

    return;
}

int main(void)
{
    freopen("game.in" , "r", stdin );
    freopen("game.out", "w", stdout);

    scanf("%d %d", &n, &m);
    if(n == 1)
        printf("%lld\n", power(2, m));
    else
        if(n == 2)
            printf("%lld\n", 4LL * power(3, m - 1) % G);
        else
            if(n == 3 && m >= 3)
                printf("%lld\n", 112LL * power(3, m - 3) % G);
            else
            {
                dfs(0, 0);
                printf("%d\n", o);
            }

    return 0;
}
