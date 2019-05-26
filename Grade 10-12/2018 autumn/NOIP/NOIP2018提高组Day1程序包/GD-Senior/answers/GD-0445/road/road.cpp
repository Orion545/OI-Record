#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
using std::max;
using std::min;

typedef std::pair<int, int> Pii;

const int MaxN = 1e5 + 7;

int n;
int data[MaxN];

struct SegTree
{
    int dat[MaxN << 2];
    int pos[MaxN << 2];
    int lc(int now) { return now << 1; }
    int rc(int now) { return (now << 1) + 1; }
    void pull(int now)
    {
        if (dat[lc(now)] < dat[rc(now)])
        {
            dat[now] = dat[lc(now)];
            pos[now] = pos[lc(now)];
        }
        else
        {
            dat[now] = dat[rc(now)];
            pos[now] = pos[rc(now)];
        }
    }
    void build(int now, int lb, int rb)
    {
        if (lb == rb)
        {
            dat[now] = data[lb];
            pos[now] = lb;
            return;
        }
        int mid = (lb + rb) >> 1;
        build(lc(now), lb, mid);
        build(rc(now), mid + 1, rb);
        pull(now);
    }
    Pii query(int now, int lb, int rb, int invl, int invr)
    {
        if (invl <= lb && rb <= invr)
        {
            return std::make_pair(dat[now], pos[now]);
        }
        int mid = (lb + rb) >> 1;
        Pii res = std::make_pair(0x3f3f3f3f, -1);
        if (invl <= mid)
        {
            Pii nd = query(lc(now), lb, mid, invl, invr);
            if (nd.first < res.first)
                res = nd;
        }
        if (mid < invr)
        {
            Pii nd = query(rc(now), mid + 1, rb, invl, invr);
            if (nd.first < res.first)
                res = nd;
        }
        return res;
    }
}tree;

int solve(int l, int r, int dec)
{
    if (l == r)
    {
        return data[l] - dec;
    }
    Pii nn = tree.query(1, 1, n, l, r);
    int ans = nn.first - dec;
    if (nn.second - 1 >= l)
        ans += solve(l, nn.second - 1, nn.first);
    if (nn.second + 1 <= r)
        ans += solve(nn.second + 1, r, nn.first);
    return ans;
}

int main(void)
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", data + i);
    }
    tree.build(1, 1, n);

    printf("%d\n", solve(1, n, 0));

    return 0;
}

