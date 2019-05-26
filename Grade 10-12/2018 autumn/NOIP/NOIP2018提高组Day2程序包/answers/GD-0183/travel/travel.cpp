#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

int read()
{
    int c, x = 0;
    c = getchar();
    while(c<'0'||c>'9') c = getchar();
    while(c>='0'&&c<='9')
    {
	x = x*10 + c-'0';
	c = getchar();
    }
    return x;
}

const int MAXN = 5000+5;
bool road[MAXN][MAXN];
bool vis[MAXN];

int n, m;
struct Node{
    int i;
    friend bool operator< (const Node& a, const Node& other)
    {
	return a.i > other.i;
    }
} node[MAXN];
priority_queue<Node> q;

void bfs()
{
    while(q.size() != 0)
    {
	int nowi = q.top().i;
	printf("%d ", nowi);
	q.pop();
	vis[nowi] = true;
	for(int i = 1; i <= n; i++)
	    if(!vis[i] && road[nowi][i])
	    {
		Node next;
		next.i = i;
		vis[i] = true;
		q.push(next);
	    }
    }
}
int main()
{
    memset(road, false, sizeof(road));
    memset(vis, false, sizeof(vis));
    n = read(), m = read();
    int u, v;
    for(int i = 1; i <= m; i++)
    {
	u = read(), v = read();
	road[u][v] = road[v][u]= true;
    }
    Node first;
    first.i = 1;
    q.push(first);
    bfs();
    return 0;
}
