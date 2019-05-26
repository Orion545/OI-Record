#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
#define N 500020
#define INF 1000000001
using namespace std;

typedef pair<int, int> pii;

vector<pii> e[N];
int n, m, d[N];

int bfs(int s)
{
    queue<int> q;
    int x, i, o;

    for(; !q.empty(); q.pop())
        ;
    memset(d, 0x7f, sizeof d);
    for(q.push(s), d[s] = 0; !q.empty(); )
    {
        x = q.front();
        q.pop();

        for(i = 0; i < (signed)e[x].size(); i ++)
            if(d[x] + e[x].at(i).second < d[e[x].at(i).first])
            {
                d[e[x].at(i).first] = d[x] + e[x].at(i).second;
                q.push(e[x].at(i).first);
            }
    }

    for(i = 2, o = 1; i <= n; i ++)
        if(d[o] < d[i])
            o = i;

    return o;
}

inline int subtask0(void)
{
    return d[bfs(bfs(1))];
}

// ================================================================

inline bool cmp(pii x, pii y)
{
    return x.second < y.second;
}

bool check1(int x)
{
    int l, r, m;
    int i, j, c;

    for(l = -1, r = e[1].size() - 1; l + 1 < r; )
    {
        m = (l + r) >> 1;
        (x <= e[1].at(m).second? r : l) = m;
    }

    for(i = 0, j = l, c = e[1].size() - r - 1; i < j; i ++)
        if(x <= e[1].at(i).second + e[1].at(j).second)
        {
            -- j;
            ++ c;
        }

    return ::m <= c;
}

int subtask1(void)
{
	int i;
    int l, r, m;

    sort(e[1].begin(), e[1].end(), cmp);
    e[1].push_back(make_pair(0, INF));

    for(l = 1, r = 20001; l + 1 < r; )
    {
        m = (l + r) >> 1;
        (check1(m) ? l : r) = m;
    }

    return l;
}

// ================================================================

int a[N];

bool check2(int x)
{
    int i, s, c;

    for(i = 1, s = c = 0; i < n; i ++)
    {
        s += a[i];
        if(x <= s)
        {
            s = 0;
            ++ c;
        }
    }

    return ::m <= c;
}

int subtask2(void)
{
    int i;
    int l, r, m;

    for(i = 1; i < n; i ++)
        a[i] = e[i].at(e[i].size() - 1).second;

    for(l = 1, r = 500000001; l + 1 < r; )
    {
        m = (l + r) >> 1;
        (check2(m) ? l : r) = m;
    }

    return l;
}

int main(void)
{
    int i;
    int a, b, l;
    bool _1, _2;

    freopen("track.in" , "r", stdin );
    freopen("track.out", "w", stdout);

    scanf("%d %d", &n, &m);
    for(i = 1, _1 = _2 = true; i < n; i ++)
    {
        scanf("%d %d %d", &a, &b, &l);
        if(a != 1)
            _1 = false;
        if(a + 1 != b)
            _2 = false;
        e[a].push_back(make_pair(b, l));
        e[b].push_back(make_pair(a, l));
    }

    if(m == 1)
        printf("%d\n", subtask0());
    else
		if(_1)
        	printf("%d\n", subtask1());
        else
            if(_2)
                printf("%d\n", subtask2());

    return 0;
}
