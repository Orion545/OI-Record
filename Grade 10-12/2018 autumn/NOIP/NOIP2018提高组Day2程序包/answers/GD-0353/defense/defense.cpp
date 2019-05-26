#include <bits/stdc++.h>
using namespace std;

string type;
int n, m, u, v, x, xx, y, yy, a[100050];
bool E[20][20], p[20];
int ans;

struct DT{bool self, left, right;} vis[100050], vis_[100050];
int ans1, ans2, sum;

void find_(int k)
{
  if (k > n)
  {
  	bool viss[20]; int sum = 0;
  	memset(viss, false, sizeof(viss));
  	
    for (int i = 1; i <= n; i++)
      if (p[i])
      {
      	viss[i] = true;
	    for (int j = 1; j <= n; j ++)
	      if (E[i][j]) viss[j] = true;
	    sum += a[i];
	  }
	
	for (int i = 1; i <= n; i ++)
	  if (!viss[i]) return;
	
	ans = min(ans, sum);
	
    return;
  }
  
  if (k == x)
  {
    if (xx)
    {
	  p[k] = 1;
	  find_(k + 1);
	}
	else
	{
	  p[k] = 0;
	  find_(k + 1);
	}
	return;
  }
  if (k == y)
  {
    if (yy)
    {
	  p[k] = 1;
	  find_(k + 1);
	}
	else
	{
	  p[k] = 0;
	  find_(k + 1);
	}
	return;
  }
  
  p[k] = 1;
  find_(k + 1);
  p[k] = 0;
  find_(k + 1);
}

int main()
{
  freopen("defense.in", "r", stdin);
  freopen("defense.out", "w", stdout);
  
  scanf("%d %d ", &n , &m); cin >> type;
  for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
  for (int i = 1; i < n; i ++)
  {
    scanf("%d%d", &u, &v);
    E[u][v] = E[v][u] = true;
  }
  
  if (n <= 10)
  {
  	while (m --)
    {
	  scanf("%d%d%d%d", &x, &xx, &y, &yy);
	  
	  ans = 100000 * n + 5;
	  
	  find_(1);
	  
	  cout << (ans == 100000 * n + 5 ? -1 : ans) << endl;
	}
	return 0;
  }
  
  if (type[0] == 'A')
  {
    for (int i = 1; i <= n; i ++)
    {
      if (vis[i].left || vis[i].right || vis[i].self) continue;
      if (a[i] >= a[i - 1] * (!(vis[i - 1].left || vis[i - 1].self || vis[i - 1].right)) + a[i + 1] && !vis[i].self && !vis[i].left && !vis[i].right)
      {
      	if (i - 1 > 0) vis[i - 1].self = true;
		if (i + 1 <= n) vis[i + 1].self = true;
	    if (i - 2 > 0) vis[i - 2].right = true;
		if (i + 2 <= n) vis[i + 2].left = true;
	    vis[i].left = vis[i].right = true;
	  }
	  else
	  if (!vis[i].self)
	  {
	    vis[i].self = vis[i].right = vis[i].left = true;
	  }
	  /*
	  for (int j = 1; j <= n; j ++) cout << (int)(vis[j].left) << ' ';cout << endl;
      
      for (int j = 1; j <= n; j ++) cout << (int)(vis[j].self) << ' ';cout << endl;
      for (int j = 1; j <= n; j ++) cout << (int)(vis[j].right) << ' ';cout << endl;
      cout << endl;*/
    }
    
	for (int i = 1; i <= n; i ++) sum += a[i] * (vis[i].self);
	
	//cout << sum << endl << endl;
	
	while (m --)
	{
	  scanf("%d%d%d%d", &x, &xx, &y, &yy);
	  
	  for (int i = x - 5; i <= x + 5; i ++) vis_[i].self = vis_[i].left = vis_[i].right = false;
	  ans1 = sum;
	  if (x > y) swap(x, y), swap(xx, yy);	  
	  if (xx == 0 && vis[x].self == true)
	  {
	    if (!vis[x].left && !vis[x].right)
	    {
	      ans1 -= a[x];
		  if (a[x - 1] < a[x + 1])
		  {
		    ans1 += a[x - 1];
		    vis_[x - 1].self = true;
		    vis_[x].left = vis_[x - 2].right = true;
		  }
		  if (a[x - 1] >= a[x + 1])
		  {
		    ans1 += a[x + 1];
			vis_[x + 1].self = true;
			vis_[x].right = vis_[x + 2].left = true;
		  }
		}
	  }
	  
	  if (xx == 1 && vis[x].self == false)
	  {
	    vis_[x].self = vis[x - 1].right = vis[x + 1].left = true;
	    ans1 += a[x];
	  }
	  
	  if (yy == 0 && vis[y].self == true)
	  {
	    if (!vis[y].left && !vis[y].right && !vis_[x].self && !vis_[x].right && !vis_[x].left)
	    {
	      ans1 -= a[y];
		  if (a[y - 1] < a[y + 1])
		    ans1 += a[y - 1];
		  if (a[y - 1] > a[y + 1])
		    ans1 += a[y + 1];
		}
	  }
	  
	  if (yy == 1 && vis[y].self == false)
	    ans1 += a[y];
	  
	  //
	  
	  for (int i = y - 5; i <= y + 5; i ++) vis_[i].self = vis_[i].left = vis_[i].right = false;
	  ans2 = sum;
	  if (x < y) swap(x, y), swap(xx, yy);
	  if (yy == 0 && vis[y].self == true)
	  {
	    if (!vis[y].left && !vis[y].right)
	    {
	      ans2 -= a[y];
		  if (a[y - 1] < a[y + 1])
		  {
		    ans2 += a[y - 1];
		    vis_[y - 1].self = true;
		    vis_[y].left = vis_[y - 2].right = true;
		  }
		  if (a[y - 1] >= a[y + 1])
		  {
		    ans2 += a[y + 1];
			vis_[y + 1].self = true;
			vis_[y].right = vis_[y + 2].left = true;
		  }
		}
	  }
	  
	  if (yy == 1 && vis[y].self == false)
	  {
	    vis_[y].self = vis[y - 1].right = vis[y + 1].left = true;
	    ans2 += a[y];
	  }
	  
	  if (xx == 0 && vis[x].self == true)
	  {
	    if (!vis[x].left && !vis[x].right && !vis_[x].self && !vis_[x].right && !vis_[x].left)
	    {
	      ans2 -= a[x];
		  if (a[x - 1] < a[x + 1])
		    ans2 += a[x - 1];
		  if (a[x - 1] > a[x + 1])
		    ans2 += a[x + 1];
		}
	  }
	  
	  if (xx == 1 && vis[x].self == false)
	    ans2 += a[x];
	  
	  cout << min(ans1, ans2) << endl;
	}
  }
  
  return 0;
}
