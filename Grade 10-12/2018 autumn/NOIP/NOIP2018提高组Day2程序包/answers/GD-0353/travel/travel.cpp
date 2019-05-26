#include <bits/stdc++.h>
using namespace std;

vector<int> E[5005];
int n, m, u[5005], v[5005];
bool p[5005][5005], vis[5005];
int t, q[5005], ans[5005];

void bfs(int now)
{
  printf("%d ", now);
  
  int to;
  
  for (int i = 0; i < E[now].size(); i ++)
  {
  	to = E[now][i];
    if (!vis[to])
    {
	  vis[to] = true;
	  bfs(to);
	}
  }
}

void bfs(int now, int uu, int vv)
{
  t ++;
  q[t] = now;
  
  int to;
  
  for (int i = 0; i < E[now].size(); i ++)
  {
  	to = E[now][i];
  	if (uu == now && vv == to) continue;
  	if (uu == to && vv == now) continue;
    if (!vis[to])
    {
	  vis[to] = true;
	  bfs(to, uu, vv);
	}
  }
}

int main()
{
  freopen("travel.in", "r", stdin);
  freopen("travel.out", "w", stdout);
  
  cin >> n >> m;
  
  memset(p, false, sizeof(E));
  memset(vis, false, sizeof(vis));
  
  for (int i = 1; i <= m; i ++)
  {
    scanf("%d%d", &u[i], &v[i]);
    p[u[i]][v[i]] = p[v[i]][u[i]] = true;
  }
  
  for (int i = 1; i <= n; i ++)
    for (int j = i + 1; j <= n; j ++)
      if (p[i][j])
      {
	    E[i].push_back(j);
	    E[j].push_back(i);
	  }
  
  if (m == n - 1)
  {
    vis[1] = true;
    bfs(1);
    return 0;
  }
  
  if (m == n)
  {
  	for (int i = 1; i <= n; i ++) ans[i] = 5005;
  	
    for (int i = 1; i <= m; i++)
    {
      t = 0;
      memset(vis, false, sizeof(vis));
      
      vis[1] = true;
	  bfs(1, u[i], v[i]);
	  
	  for (int j = 1; j <= n; j ++)
	    if (!vis[j]) goto next;
	  	  
	  for (int j = 1; j <= n; j ++)
	  {
	    if (q[j] > ans[j]) goto next;
	    if (q[j] == ans[j]) continue;
	    if (q[j] < ans[j]) break;
	  }
	  
	  for (int j = 1; j <= n; j ++) ans[j] = q[j];
	  
	  next:;
	}
	
	for (int i = 1; i <= n; i ++) printf("%d ", ans[i]);
	return 0;
  }
  
  return 0;
}
