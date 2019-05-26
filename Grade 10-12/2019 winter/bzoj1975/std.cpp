# include <bits/stdc++.h>
using namespace std;
typedef long long ll;

template <class Num> inline void Cmax(Num &x, const Num y) {
    x = y > x ? y : x;
}

template <class Num> inline void Cmin(Num &x, const Num y) {
    x = y < x ? y : x;
}

const int maxn(5005);
const int maxm(2e5 + 5);
const double eps(1e-8);

int n, m, first[maxn], cnt, vis[maxn], rt[maxn], tot, cov[maxm << 1], ans, fa[maxn];
double se, e, dis[maxn];
priority_queue < pair <double, int> > q;

struct Heap {
    int ls, rs, dis, ed;
    double w;
} tr[maxm * 20];

struct Edge {
    int to, next;
    double w;
} edge[maxm << 1];

inline void Add(int u, int v, double w) {
    edge[cnt] = (Edge){v, first[u], w}, first[u] = cnt++;
    edge[cnt] = (Edge){u, first[v], w}, first[v] = cnt++;
}

inline int NewNode(double w, int ed) {
    int x = ++tot;
    tr[x].w = w, tr[x].dis = 1, tr[x].ed = ed;
    return x;
}

int Merge(int x, int y) {
    if (!x || !y) return x + y;
    if (tr[x].w - tr[y].w >= eps) swap(x, y);
    int p = ++tot;
    tr[p] = tr[x], tr[p].rs = Merge(tr[p].rs, y);
    if (tr[tr[p].ls].dis < tr[tr[p].rs].dis) swap(tr[p].ls, tr[p].rs);
    tr[p].dis = tr[tr[x].rs].dis + 1;
    return p;
}

void Dfs(int u) {
    vis[u] = 1;
    for (int e = first[u], v; e != -1; e = edge[e].next)
        if (e & 1) {
            double w = edge[e].w;
            if (fabs(dis[u] + w - dis[v = edge[e].to]) < eps && !vis[v])
                fa[v] = u, cov[e ^ 1] = 1, Dfs(v);
        }
}

int main() {
    memset(first, -1, sizeof(first));
    memset(dis, 127, sizeof(dis));
    scanf("%d%d%lf", &n, &m, &se);
    for (int i = 1, u, v; i <= m; ++i) scanf("%d%d%lf", &u, &v, &e), Add(u, v, e);
    dis[n] = 0, q.push(make_pair(0, n));
    while (!q.empty()) {
        int u = q.top().second;
        q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (int e = first[u]; ~e; e = edge[e].next)
            if (e & 1) {
                int v = edge[e].to;
                if (dis[v] - (dis[u] + edge[e].w) >= eps)
                    q.push(make_pair(-(dis[v] = dis[u] + edge[e].w), v));
            }
    }
    for (int i = 1; i <= n; ++i) vis[i] = 0;
    Dfs(n);
    for (int e = 0, u, v; e < cnt; e += 2)
        if (!cov[e]) {
            u = edge[e ^ 1].to, v = edge[e].to;
            if (dis[u] == dis[0] || dis[v] == dis[0]) continue;
            rt[u] = Merge(rt[u], NewNode(dis[v] + edge[e].w - dis[u], v));
        }
    for (int i = 1; i <= n; ++i) q.push(make_pair(-dis[i], i));
    for (int i = 1, u; i <= n; ++i) {
        u = q.top().second, q.pop();
        if (fa[u]) rt[u] = Merge(rt[u], rt[fa[u]]);
    }
    if (dis[1] - se < eps) se -= dis[1], ++ans;
    if (rt[1]) q.push(make_pair(-tr[rt[1]].w, rt[1]));
    while (!q.empty()) {
        int ed = q.top().second;
        double cur = q.top().first, w = dis[1] - cur;
		cout<<"solve "<<ed<<' '<<-cur<<' '<<w<<' '<<se<<'\n';
        if (w - se >= eps) break;
        q.pop(), se -= w, ++ans;
        for (int i = 0; i < 2; ++i) {
            int nxt = i ? tr[ed].rs : tr[ed].ls;
            if (nxt) q.push(make_pair(cur + tr[ed].w - tr[nxt].w, nxt));
        }
        if (rt[tr[ed].ed]) q.push(make_pair(cur - tr[rt[tr[ed].ed]].w, rt[tr[ed].ed]));
    }
    printf("%d\n", ans);
    return 0;
}
