#include <cstdio>
#include <queue>
#include <cstring>

const int MaxN = 50000 + 7;

struct Edge
{
    int dst, len;
    int next;
    explicit Edge(int d = 0, int l = 0, int n = 0)
        : dst(d), len(l), next(n) {}
};
typedef std::pair<int, int> Pii;

int n, m;
Edge eset[MaxN];
int eamo;
int via[MaxN];
int parent[MaxN];
int in[MaxN];
std::queue<Pii> bfsq;
bool used[MaxN];
int ansset[MaxN];

void addedge(int src, int dst, int len)
{
    eset[eamo].dst = dst;
    eset[eamo].len = len;
    eset[eamo].next = via[src];
    via[src] = ++eamo;
    ++in[dst];
}

bool check(int nowval);

int main(void)
{
    freopen("track.in", "r", stdin);
    freopen("track.out", "w", stdout);
    scanf("%d %d", &n, &m);
    memset(via, -1, sizeof(via));
    for (int i = 1; i < n; ++i)
    {
        int s, d, l;
        scanf("%d %d %d", &s, &d, &l);
        addedge(s, d, l);
        addedge(d, s, l);
    }

    for (int i = 1; i <= n; ++i)
        if (in[i] == 1)
            bfsq.push(std::make_pair(i, 0));
    int ans = 0;
    while (!bfsq.empty())
    {
        Pii now = bfsq.front();
        bfsq.pop();
        for (int n = via[now.first]; n != -1; n = eset[n].next)
        {
            if (!used[eset[n].dst] || now.second + eset[n].len > ansset[eset[n].dst])
            {
                bfsq.push(std::make_pair(eset[n].dst, now.second + eset[n].len));
                ansset[eset[n].dst] = now.second + eset[n].len;
                used[eset[n].dst] = true;
            }
            if (now.second + eset[n].len > ans)
                ans = now.second + eset[n].len;
        }
    }
    printf("%d\n", ans);

    return 0;
}

