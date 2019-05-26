#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#define find findd

using namespace std;

const int maxn = 5000;
const int maxm = maxn * 3;

int nxt[maxm + 5], to[maxm + 5], fir[maxn + 5];
int edn = 1;

int n, m;
int dep[maxn + 5];
int l[maxn + 5], r[maxn + 5];

int temp[maxn + 5], ans[maxn + 5];
int go[maxn + 5];
int fa[maxn + 5];
int a[maxn + 5];
int one = 0, two = 0;

void add(int one, int two)
{
  edn++;
  to[edn] = two;
  nxt[edn] = fir[one];
  fir[one] = edn;
}
void readin()
{
  scanf("%d%d", &n, &m);
  for (int i = 1;i <= m; ++i)
  {
    int j, k;
    scanf("%d%d", &j, &k);
    add(j, k);
    add(k, j);
  }
}
void dfs(int now, int fath)
{
//  cout<<"now="<<now<<endl;
  dep[now] = dep[fath] + 1;
  fa[now] = fath;
  for (int i = fir[now];i != 0; i = nxt[i])
  {
    int k = to[i];
    if (k == fath) continue;
    if (dep[k] > 0) {one = now; two = k;continue;}
    dfs(k, now);
  }
}
void findanc(int one, int two)
{
//  cout<<"one="<<one<<' '<<"two="<<two<<endl;
  if (dep[one] < dep[two]) swap(one, two);
//  cout<<"one="<<one<<' '<<"two="<<two<<endl;
  while (dep[one] != dep[two])
  {
//  	cout<<"one="<<one<<' '<<"two="<<two<<endl;
  	go[one] = 1;
  	one = fa[one];
  }
  while (one != two)
  {
//  	cout<<"one="<<one<<' '<<"two="<<two<<endl;
  	go[one] = go[two] = 1;
  	one = fa[one]; 
  	two = fa[two];
  }
}
bool isedge(int i, int j)
{
  if ((i == one) && (j == two)) return true;
  if ((i == two) && (j == one)) return true;
  return false;
}
void dfsans(int now, int fa)
{
//  cout<<"now="<<now<<endl;
  temp[++temp[0]] = now;
  l[now] = a[0];
  for (int i = fir[now];i != 0; i = nxt[i])
  {
    int k = to[i];
    if (k == fa) continue;
    if (isedge(now, k)) continue;
    a[++a[0]] = k;
  }
  r[now] = a[0];
  sort(a + l[now] + 1, a + r[now] + 1);
//  for (int i = l[now] + 1;i <= r[now] ;++i) cout<<a[i]<<' ';cout<<endl;
  for (int i = l[now] + 1;i <= r[now]; ++i) dfsans(a[i], now);
}
void comp()
{
  bool small = false;
  for (int i = 1;i <= n; ++i) 
  {
    if (temp[i] < ans[i]) {small = true;break;}
    if (temp[i] > ans[i]) {small = false; break;}
  }
  if (small) for (int i = 1; i<= n; ++i) ans[i] = temp[i];
}
void doing()
{
  for (int i = 1;i <= n; ++i) ans[i] = n;
  dep[1] = 1;
  a[0] = 0;
  dfs(1, 0);
  
  a[0] = 0;
  if (one > 0) 
  {
    findanc(one, two);
    temp[0] = 0;
    dfsans(1, 0);
    comp();
    for (int i = 1;i <= n; ++i)
    {
  	  if (go[i] && (go[fa[i]]))
  	  {
  	    one = i;
  	    two = fa[i];
  	    a[0] = 0;
  	    temp[0] = 0;
  	    dfsans(1, 0);
  	    comp();
      }
    }
  }
  else 
  {
    dfsans(1, 0);
    comp();
  }
  for (int i = 1;i <= n; ++i) printf("%d ", ans[i]);
}
int main()
{
  freopen("travel.in","r",stdin);
  freopen("travel.out","w",stdout);
  readin();
  doing();
  return 0;
}

