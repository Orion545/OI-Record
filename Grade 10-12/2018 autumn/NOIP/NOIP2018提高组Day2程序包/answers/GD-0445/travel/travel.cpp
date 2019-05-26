#include <cstdio>
#include <functional>
#include <algorithm>
#include <vector>

const int MaxN = 5000 + 7;

int n, m;
std::vector<int> adj[MaxN];
std::vector<int> vis;
bool used[MaxN];
int ans[MaxN];
int anslen;

int main(void)
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i)
        std::sort(adj[i].begin(), adj[i].end(), std::greater<int>());

    vis.push_back(1);
    while (!vis.empty())
    {
        // Get this one
        int now = vis.back();
        vis.pop_back();
        if (used[now])
            continue;
        // Push into ans
        ans[anslen++] = now;
        used[now] = true;
        // Prepare for next visit
        for (int i = 0; i < adj[now].size(); ++i)
        {
            if (used[adj[now][i]])
                continue;
            vis.push_back(adj[now][i]);
        }
    }

    printf("%d", ans[0]);
    for (int i = 1; i < n; ++i)
        printf(" %d", ans[i]);
    printf("\n");

    return 0;
}

