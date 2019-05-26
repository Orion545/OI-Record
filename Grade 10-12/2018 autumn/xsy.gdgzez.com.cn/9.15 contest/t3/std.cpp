#include <cstdio>
#include <iostream>
#include <cctype>
#include <vector>
#include <deque>
#include <set>
#define vector std::vector
#define deque std::deque
#define set std::set
using namespace std;

namespace Zeonfai
{
    inline int getInt()
    {
        int a = 0, sgn = 1;
        char c;
        while(! isdigit(c = getchar())) if(c == '-') sgn *= -1;
        while(isdigit(c)) a = a * 10 + c - '0', c = getchar();
        return a * sgn;
    }
}
const int N = 200;
int n, m, S, T;
struct point
{
    int x, y;
    inline point() {}
    inline point(int _x, int _y) {x = _x; y = _y;}
    inline int friend operator <(point a, point b) {return a.x == b.x ? a.y < b.y : a.x < b.x;}
    inline int friend operator ==(point a, point b) {return a.x == b.x && a.y == b.y;}
};
double slope(point a, point b) {return a.x == b.x ? 1e50 : (double)(a.y - b.y) / (a. x - b.x);}
struct graph
{
    struct node;
    struct edge
    {
        node *v; int x, y;
        inline edge(node *_v, int _x, int _y) {v = _v; x = _x; y = _y;}
    };
    struct node
    {
        vector<edge> edg;
        set<point> st;
        inline node() {edg.clear(); st.clear();}
        inline int check(point p) {return st.find(p) != st.end();}
        inline int insert(point p)
        {
            st.insert(p);
            static point stk[N * N]; int tp = 0;
            for(auto cur : st)
            {
                while(tp >= 2 && slope(stk[tp - 1], stk[tp - 2]) > slope(cur, stk[tp - 1])) -- tp;
                while(tp >= 1 && slope(cur, stk[tp - 1]) < 0) -- tp;
                if(! tp || slope(cur, stk[tp - 1]) <= 1) stk[tp ++] = cur;
            }
            st.clear();
            for(int i = 0; i < tp; ++ i) st.insert(stk[i]);
            return st.find(p) != st.end();
        }
        inline double getAnswer()
        {
            static point p[N * N]; int cnt = 0;
            for(auto cur : st) p[cnt ++] = cur,cout<<"***final "<<cur.x<<' '<<cur.y<<'\n';;
            if(cnt == 0) return 0;
            else if(cnt == 1) return (double)(p[0].y - p[0].x + p[0].y) / 2;
            else
            {
                double res = 0;
                res += (double)(p[0].y - slope(p[1], p[0]) * p[0].x + p[0].y) * slope(p[1], p[0]) / 2;
                res += (double)(- slope(p[cnt - 1], p[cnt - 2]) * p[cnt - 1].x + p[cnt - 1].y - p[cnt - 1].x + p[cnt - 1].y) * (1 - slope(p[cnt - 1], p[cnt - 2])) / 2;
                for(int i = 1; i < cnt - 1; ++ i)
                    res += (double)(- slope(p[i], p[i - 1]) * p[i].x + p[i].y - slope(p[i + 1], p[i]) * p[i].x + p[i].y) * (slope(p[i + 1], p[i]) - slope(p[i], p[i - 1])) / 2;
                return res;
            }
        }
    } nd[N + 1];
    inline void addEdge(int u, int v, int x, int y)
    {
        nd[u].edg.push_back(edge(nd + v, x, y)); nd[v].edg.push_back(edge(nd + u, x, y));
    }
    struct record
    {
        node *u; int x, y;
        inline record(node *_u, int _x, int _y)
        {
            u = _u; x = _x; y = _y;
        }
    };
    inline void SPFA()
    {
        deque<record> que; que.clear(); que.push_back(record(nd + S, 0, 0)); nd[S].st.insert(point(0, 0));
        for(; ! que.empty(); que.pop_front())
        {
            record cur = que.front();
			cout<<"spfa "<<cur.x<<' '<<cur.y<<'\n';
            if(! cur.u->check(point(cur.y - cur.x, cur.y))) continue;
            for(auto edg : cur.u->edg) if(edg.v->insert(point(edg.y + cur.y - edg.x - cur.x, edg.y + cur.y))) que.push_back(record(edg.v, cur.x + edg.x, cur.y + edg.y));
        }
    }
}G;
int main()
{

    #ifndef ONLINE_JUDGE

//  freopen("path.in", "r", stdin);
//  freopen("path.out", "w", stdout);

    #endif

    using namespace Zeonfai;
    n = getInt(), m = getInt(), S = getInt(), T = getInt();
    for(int i = 0; i < m; ++ i)
    {
        int u = getInt(), v = getInt(), x = getInt(), y = getInt();
        G.addEdge(u, v, x, y);
    }
    G.SPFA();
    printf("%.5lf", G.nd[T].getAnswer());
}
