#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <algorithm>

typedef long long LL;

using namespace std;

const int maxn = 50000;

int fir[maxn + 5], nxt[maxn * 2 + 5], to[maxn * 2 + 5];
int edn = 0;
int w[maxn + 5];
int dist1[maxn + 5], dist2[maxn + 5];
int n, m;

void dfs1(int now,int fa)
{
  for (int i = fir[now];i != 0;i = nxt[i])
  {
    int k = to[i];
    if (k != fa)
    {
      dist1[k] = dist1[now] + w[i];
      dfs1(k, now);
    }
  }
}
void dfs2(int now, int fa)
{
  for (int i = fir[now];i != 0;i = nxt[i])
  {
  	int k = to[i];
  	if (k != fa)
  	{
  	  dist2[k] = dist2[now] + w[i];
  	  dfs2(k, now);
    }
  }
}
void doing()
{
  memset(dist1, 0, sizeof(dist1));
  dfs1(1, 0);
  
  int rt = 1;
  for (int i = 2;i <= n; ++i) if (dist1[i] > dist1[rt]) rt = i;
  
  memset(dist2, 0, sizeof(dist2));
  dfs2(rt, 0);
  
  int ans = 0;
  for (int i = 1;i <= n; ++i) ans = max(ans, dist2[i]);
  printf("%d", ans);
}
void add(int ai, int bi, int ci)
{
  edn++;
  w[edn] = ci;
  to[edn] = bi;
  nxt[edn] = fir[ai];
  fir[ai] = edn;
}
void readin()
{
  scanf("%d%d", &n, &m);
  for (int i = 1;i <= n - 1; ++i)
  {
    int ai, bi, ci;
    scanf("%d%d%d", &ai, &bi, &ci);
    add(ai, bi, ci);
    add(bi, ai, ci);
  }
}
int main()
{
  freopen("track.in","r",stdin);
  freopen("track.out","w",stdout);
  readin();
  doing();
  return 0;
}
