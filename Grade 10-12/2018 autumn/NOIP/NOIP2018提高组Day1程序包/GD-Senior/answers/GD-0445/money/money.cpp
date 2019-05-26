#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

struct DatInfo
{
    int val, pos;
    bool exist;
    explicit DatInfo(int v = 0, int p = 0, bool e = true)
        : val(v), pos(p), exist(e) {}
    friend bool operator < (const DatInfo &a, const DatInfo &b)
    {
        return a.val < b.val;
    }
};

const int MaxN = 107;

int T, n;
std::vector<DatInfo> ai;
int split[MaxN][MaxN];
int splen[MaxN];
int oripos[MaxN];
int byval[25007];

void init(void);
void solve(void);

int main(void)
{
    freopen("money.in", "r", stdin);
    freopen("money.out", "w", stdout);
    scanf("%d", &T);
    while (T--)
    {
        init();
        solve();
    }
    return 0;
}

bool ifnexist(const DatInfo &a)
{
    return !a.exist;
}

void init(void)
{
    scanf("%d", &n);
    memset(splen, 0, sizeof(splen));
    memset(byval, -1, sizeof(byval));
    ai.resize(n);
    for (int i = 0; i < n; ++i)
    {
        int tmp;
        scanf("%d", &tmp);
        ai[i] = DatInfo(tmp, i);
        byval[tmp] = i;
    }
}

void solve(void)
{
    std::sort(ai.begin(), ai.end());
    for (int i = 0; i < n; ++i)
    {
        oripos[ai[i].pos] = i;
    }

    for (int i = 0; i < n - 1; ++i)
        for (int j = i + 1; j < n; ++j)
        {
            if (ai[j].val % ai[i].val == 0)
            {
                ai[oripos[j]].exist = false;
            }
        }

    ai.erase(std::remove_if(ai.begin(), ai.end(), ifnexist), ai.end());
    if (ai.size() == 1)
    {
        printf("1\n");
        return;
    }
    std::vector<DatInfo>::iterator it = std::upper_bound(ai.begin(), ai.end(),
            DatInfo(ai[0].val * ai[1].val - ai[0].val - ai[1].val));
    if (it > ai.begin() + 1)
        ai.erase(it, ai.end());
    printf("%d\n", ai.size());
}

