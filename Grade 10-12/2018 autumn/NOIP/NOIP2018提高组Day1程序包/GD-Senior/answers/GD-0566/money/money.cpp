#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <algorithm>

typedef long long LL;

using namespace std;

const int maxn = 100;

int n;
int a[maxn + 5];
int vis[maxn + 5];
void readin()
{
  scanf("%d", &n);
  for (int i = 1;i <= n; ++i) scanf("%d", &a[i]);
}
LL gcd(LL n, LL m)
{
  if (m == 0) return n;else return gcd(m, n % m);
}
void exgcd(LL a, LL b, LL &x, LL &y, LL c)
{
  if (b == 0) {x = 1; y = 0;}
  else {exgcd(b, a % b, y, x, c); y-= (a / b) * x;}
}
LL aabs(LL now)
{
  if (now < 0) return -now;else return now;
}
bool equ(LL a, int b, int c)
{
  LL d = gcd(a, b);
  if (c % d) return false;
  LL x, y;
  exgcd(a / d, b / d, x, y, c / d);
  x = x * c;
  y = y * c;
//  cout<<"d="<<d<<endl;
//  cout<<"a="<<a<<' '<<"b="<<b<<' '<<"c="<<c<<' '<<"x="<<x<<' '<<"y="<<y<<endl;
  
//  if ((x >= 0) && (y >= 0)) return true;
//  LL t = x / b;
//  if (x % b) t = t + x / aabs(x);
//  x = (x % b + b) % b;
//  y = y + a * t;
//  cout<<"t="<<t<<endl;
//    cout<<"d="<<d<<endl;
//  cout<<"a="<<a<<' '<<"b="<<b<<' '<<"c="<<c<<' '<<"x="<<x<<' '<<"y="<<y<<endl;
  if ((x >= 0) && (y >= 0)) return true;
  
  if (x < 0)
  {
  	LL t;
  	if (x % b == 0) t = (-x) / b;else t = (-x) / b + 1;
  	x = (x % b + b) % b;
//  	y = y - a * t;
  	if (y - a * t >= 0) return true;
  }
  if (y < 0)
  {
  	LL t;
  	if (y % a == 0) t = (-y) / a;else t = (-y) / a + 1;
  	y = (y % a + a) % a;
//  	x = x - b * t;
  	if (x - b * t >= 0) return true;
  }
//    cout<<"d="<<d<<endl;
//  cout<<"a="<<a<<' '<<"b="<<b<<' '<<"c="<<c<<' '<<"x="<<x<<' '<<"y="<<y<<endl;
  
  return false;
}
bool check(int now)
{
  for (int i = 1;i <= now; ++i)
  {
  	if (vis[i]) continue;
    for (int j = i + 1;j <= now; ++j)
    {
      if (vis[j]) continue;
      if (i == now) continue;
      if (j == now) continue;
      if (i == j) continue;
      if (equ(a[i], a[j], a[now])) return true;
    }
  }
  return false;
}
    
void doing()
{
  sort(a + 1, a + n + 1);
  
  memset(vis, 0, sizeof(vis));
  
  for (int i = 1;i <= n - 1; ++i) 
    for (int j = i + 1;j <= n; ++j) if (a[j] % a[i] == 0) vis[j] = 1;
    
//    for (int i = 1;i <= n; ++i) cout<<vis[i]<<' ';cout<<endl;
  for (int i = n; i >= 3; --i) if (check(i)) vis[i] = 1;
  
  int ans = n;
  for (int i = 1;i <= n; ++i) ans -= vis[i];
  printf("%d\n", ans);
}
int main()
{
  freopen("money.in","r",stdin);
  freopen("money.out","w",stdout);
  int t;
  scanf("%d", &t);
  while (t--)
  {
    readin();
    doing();
  }
  return 0;
}
