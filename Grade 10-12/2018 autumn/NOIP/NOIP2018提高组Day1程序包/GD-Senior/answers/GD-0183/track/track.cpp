#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

int read()
{
    int c, x =0;
    c = getchar();
    while(c<'0'||c>'9')
		c = getchar();
    while(c>='0' && c <='9')
    {
		x = x*10 + c-'0';
		c=getchar();
    }
    return x;
}

int n, m;
int road[1000+10][1000+10];
bool vis[1000+10][1000+10];
int maxl;

void dfs(int cur, int nowl)
{
    for(int i = 1; i <= n; i++)
    {
	if(i != cur && road[cur][i] && !vis[cur][i])
	{
	    vis[cur][i] = vis[i][cur] = true;
	    maxl = max(maxl, nowl+road[cur][i]);
	    dfs(i, nowl+road[cur][i]);
	    vis[cur][i] = vis[i][cur] = false;
	}
    }
}

int main()
{
    n = read(), m = read();
    int a, b;
    memset(road, 0, sizeof(road));
    memset(vis, false, sizeof(vis));
    for(int i =1; i<n; i++)
    {
	a = read(), b = read();
	road[a][b] = road[b][a] = read();
    }
    for(int i = 1; i<=n; i++)
    	dfs(i, 0);
    printf("%d", maxl);
    return 0;
}


