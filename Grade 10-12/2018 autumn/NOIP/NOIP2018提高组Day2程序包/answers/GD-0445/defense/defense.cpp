#include <cstdio>
#include <cstring>
#include <algorithm>

const int MaxN = 1e5 + 7;

struct Edge
{
    int dst;
    int next;
    Edge(int d = 0, int n = 0)
        : dst(d), next(n) {}
};

struct Query
{
    int a, x;
    int b, y;
    Query(int _a = 0, int _x = 0, int _b = 0, int _y = 0)
        : a(_a), x(_x), b(_b), y(_y) {}
};

int n, m;
char type[2];
int weight[MaxN];
Edge eset[MaxN];
int eamo;
int via[MaxN];
Query qlst[MaxN];
int nowq;

void addedge(int src, int dst)
{
    eset[eamo].dst = dst;
    eset[eamo].next = via[src];
    via[src] = eamo++;
}

int dpf[MaxN][4];
int dfs(int now, int stat)
{
    if (dpf[now][stat] != -1)
        return dpf[now][stat];
    // calc 0
    dpf[now][1] = 0;
    for (int i = via[now]; i != -1; i = eset[i].next)
    {
        if (qlst[nowq].b == eset[i].dst && qlst[nowq].y == 0)
        {
            dpf[now][1] = -1;
            break;
        }
        dpf[now][1] += std::min(dfs(eset[i].dst, 2), dfs(eset[i].dst, 3));
    }
    if ((stat & 2) == 0)
        return 0x7fffffff;
    // calc 1
    dpf[now][2] = dpf[now][3] = 0;
    for (int i = via[now]; i != -1; i = eset[i].next)
    {
        if (qlst[nowq].b == eset[i].dst)
            if (qlst[nowq].y == 0)
            {
                dpf[now][2] += dfs(eset[i].dst, 1);
                if (stat == 3)
                    return 0x7fffffff;
                continue;
            }
        dpf[now][2] += dfs(eset[i].dst, 1);
        dpf[now][3] += std::min(dfs(eset[i].dst, 2), dfs(eset[i].dst, 3));
    }
    return dpf[now][stat];
}

int main(void)
{
    freopen("defense.in", "r", stdin);
    freopen("defense.out", "w", stdout);
    scanf("%d %d %c%c", &n, &m, type, type + 1);
    memset(via, -1, n);
    memset(dpf, -1, sizeof(dpf));
    for (int i = 1; i <= n; ++i)
        scanf("%d", weight + i);
    for (int i = 1; i < n; ++i)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        addedge(u, v);
        addedge(v, u);
    }
    for (int i = 0; i < n; ++i)
        scanf("%d %d %d %d", &qlst[i].a, &qlst[i].x, &qlst[i].b, &qlst[i].y);

    for (nowq = 0; nowq < n; ++nowq)
    {
        // first scan for sibing
        bool sibing = false;
        if (type[1] == '2')
            sibing = true;
        else
            for (int i = via[qlst[nowq].a]; i != -1; i = eset[i].next)
                if (eset[i].dst == qlst[nowq].b)
                    sibing = true;
        if (sibing && qlst[nowq].x == 0 && qlst[nowq].y == 0)
            printf("-1\n");
        else
            printf("%d\n", std::min(
                        dfs(qlst[nowq].a, qlst[nowq].x << 1),
                        dfs(qlst[nowq].a, qlst[nowq].x << 1 | 1)));
    }

    return 0;
}

