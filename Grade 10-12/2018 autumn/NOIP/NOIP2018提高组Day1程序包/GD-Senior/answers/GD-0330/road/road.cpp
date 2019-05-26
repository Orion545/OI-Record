#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define N 100020
#define INF 0x7f7f7f7f
using namespace std;

int d[N];

class SegmentTree
{
public:
    class Node
    {
    public:
        Node *c[2];
        int p, q, d;
        int l, r, m;
        Node(int x, int y) : p(0), q(0), d(0), l(x), r(y), m((x + y) >> 1)
        {
            c[0] = c[1] = NULL;

            return;
        }

        void maintain(void)
        {
            p = min(c[0]->p, c[1]->p);
            q = max(c[0]->q, c[1]->q);

            return;
        }

        void pushDown(void)
        {
            if(d)
            {
                c[0]->p += d;
                c[0]->q += d;
                c[0]->d += d;
                c[1]->p += d;
                c[1]->q += d;
                c[1]->d += d;
                d = 0;
            }

            return;
        }
    } *r;
    SegmentTree(void) : r(NULL)
    {
        return;
    }

    void build(Node *&u, int l, int r)
    {
        u = new Node(l, r);
        if(l == r)
            u->p = u->q = d[u->l];
        else
        {
            build(u->c[0], l, u->m);
            build(u->c[1], u->m + 1, r);
            u->maintain();
        }

        return;
    }

    int queryFirst(Node *u)
    {
        int t;

        if(!u->q)
            return -1;
        if(u->l == u->r)
            return u->l;

        u->pushDown();
        if(u->c[0]->q)
        {
            t = queryFirst(u->c[0]);
            if(t != -1)
                return t;
        }

        return queryFirst(u->c[1]);
    }

    int queryMin(Node *u, int l, int r)
    {
    	if(r < u->l || u->r < l)
    		return INF;
    	if(l <= u->l && u->r <= r)
    		return u->p;
    	u->pushDown();

    	return min(queryMin(u->c[0], l, r), queryMin(u->c[1], l, r));
    }

    void update(Node *&u, int l, int r, int d)
    {
        if(r < u->l || u->r < l)
            return;
        if(l <= u->l && u->r <= r)
        {
            u->p += d;
            u->q += d;
            u->d += d;

            return;
        }

        u->pushDown();
        update(u->c[0], l, r, d);
        update(u->c[1], l, r, d);
        u->maintain();

        return;
    }
} g;

int main(void)
{
    int n;
    int i;
    int l, r, m;
    int o, t;

    freopen("road.in" , "r", stdin );
    freopen("road.out", "w", stdout);

    scanf("%d", &n);
    for(i = 0; i < n; i ++)
        scanf("%d", &d[i]);
    g.build(g.r, 0, n - 1);

    for(o = 0; ; )
    {
        i = g.queryFirst(g.r);
        if(i == -1)
            break;
        for(l = i, r = n; l + 1 < r; )
        {
        	m = (l + r) >> 1;
        	(g.queryMin(g.r, i, m) ? l : r) = m;
        }
        t = g.queryMin(g.r, i, l);
        o += t;
        g.update(g.r, i, l, -t);
    }
    printf("%d\n", o);

    return 0;
}
