#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define left leftt
#define right rightt

using namespace std;

const int maxn = 100000;

int n, ans = 0;
int a[maxn + 5], b[maxn + 5];
int bis[maxn + 5];
int left[maxn + 5], right[maxn + 5];

void simsort(int l, int r)
{
  int mid = a[b[(l + r) / 2]];
  int i = l, j = r;
  do {
    while (a[b[i]] < mid) ++i;
    while (a[b[j]] > mid) --j;
    if (i <= j)
    {
      swap(b[i], b[j]);
      ++i; --j;
    }
  } while (i <= j);
  if (i < r) simsort(i, r);
  if (j > l) simsort(l, j);
}
void readin()
{  
  scanf("%d", &n);
  for (int i = 1;i <= n; ++i) scanf("%d", &a[i]);
  
  for (int i = 1;i <= n; ++i) b[i] = i;
  simsort(1, n);
  
//  for (int i = 1;i <= n; ++i) cout<<b[i]<<' ';
//  cout<<endl;
  
  a[0] = a[n + 1] = -1;
  for (int i = 1;i <= n; ++i) 
  {
    int j = i - 1;
    while (a[j] >= a[i]) j = left[j];
    left[i] = j;
  }
  for (int i = n;i >= 1; --i)
  {
    int j = i + 1;
    while (a[j] >= a[i]) j = right[j];
    right[i] = j;
  }
//  for (int i = 1;i <= n; ++i) cout<<left[i]<<' ';
//  cout<<endl<<endl;
//  for (int i = 1;i <= n; ++i) cout<<right[i]<<' ';
//  cout<<endl;
}
int lowbit(int now)
{
  return now & (-now);
}
int geth(int now)
{
  int ans = 0;
  while (now > 0) 
  {
  	ans += bis[now];
  	now -= lowbit(now);
  }
  return ans;
}
void change(int now, int v)
{
  while (now <= n + 1)
  {
  	bis[now] += v;
  	now += lowbit(now);
  }
}
void doing()
{
  memset(bis, 0, sizeof(bis));
  
  
  for (int i = 1;i <= n; ++i)
  {
  	int cur = b[i];
  	int val = a[cur];
//  	cout<<"cur="<<cur<<endl;
  	int nowh = geth(cur);
//  	cout<<"nowh="<<nowh<<endl;
  	
  	ans += val - nowh;
  	change(left[cur] + 1, val - nowh);
  	change(right[cur], nowh - val);
  }
  printf("%d", ans);
}
int main()
{
  freopen("road.in","r",stdin);
  freopen("road.out","w",stdout);
  readin();
  doing();
  return 0;
}
