#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <iostream>

using namespace std;

const int inf = 1000000000;
const int maxn = 100000;

int n, m,a ,b ,x, y;
int nxt[maxn * 2 + 5], to[maxn * 2 + 5], fir[maxn + 5];
int w[maxn *2 + 5];
int val[maxn + 5];
int f[maxn + 5][2];
int g[maxn + 5];
int edn = 0;

char ch[10];
void add(int one, int two)
{
  edn++;
  to[edn] = two;
  nxt[edn] = fir[one];
  fir[one] = edn;
}
void dfs(int now, int fa)
{
//  cout<<"now="<<now<<' '<<"fa="<<fa<<endl;
  int order = 2;
  if (now == a) order = x;
  if (now == b) order = y;
//  cout<<"order="<<order<<endl;
//  cout<<"now="<<now<<' '<<"fir[now]="<<fir[now]<<' '<<"nxt="<<nxt[fir[now]]<<endl;
  if ((nxt[fir[now]] == 0) && (to[fir[now]] == fa))
  {
  	if (order == 0) 
  	{
  	  f[now][0] = 0;
  	  g[now] = 0;
  	  return;
    }
    if (order == 1)
    {
      f[now][1] = val[now];
      g[now] = val[now];
      return;
    }
  	f[now][1] = val[now];
  	f[now][0] = 0;
  	g[now] = 0;
  	return;
  }
  int sum = 0;
  for (int i = fir[now];i != 0;i = nxt[i])
  {
    int k = to[i];
    if (k == fa) continue;
    dfs(k, now);
    sum += g[k];
  }
//  cout<<"now="<<now<<"sum="<<sum<<endl;
  for (int i = fir[now];i != 0;i = nxt[i])
  {
    int k = to[i];
    if (k == fa) continue;
  	f[now][0] = min(f[now][0],sum - g[k] + f[k][1]);
  }
  f[now][1] = val[now] + sum;
  if (order == 1) f[now][0] = inf;
  if (order == 0) f[now][1] = inf;
  g[now] = min(f[now][0], f[now][1]);
}
void calc()
{
  for (int i = 1;i <= n; ++i) f[i][1] = g[i] = f[i][0] = inf;
  dfs(1, 0);
  int ans = min(f[1][0], f[1][1]);
  if (ans >= inf) printf("%d\n", -1);
  else printf("%d\n", ans);
  for (int i  = 1;i <= n; ++i) cout<<f[i][0]<<' ';cout<<endl;
  for (int i = 1;i <= n; ++i) cout<<f[i][1] <<' ';cout<<endl;
  for (int i = 1;i <= n; ++i) cout<<g[i]<<' ';cout<<endl;
}
void doing()
{
  for (int i = 1;i <= m; ++i)
  {
  	scanf("%d%d%d%d", &a, &x, &b, &y);
  	calc();
  }
}
void readin()
{
  scanf("%d%d", &n, &m);
  scanf("%s", ch);
  for (int i =1 ;i <= n; ++i) scanf("%d", &val[i]);
  for (int i = 1;i <= n - 1; ++i)
  {
    int j , k;
    scanf("%d%d", &j, &k);
    add(j, k);
    add(k, j);
  }
}
int main()
{
  freopen("defense.in","r",stdin);
  freopen("defense.out","w",stdout);
  readin();
  doing();
  return 0;
}
