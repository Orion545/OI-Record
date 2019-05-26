#include <bits/stdc++.h>
using namespace std;

int T;
int n, a[25005], maxa;
int ans;

int b[50], g[50], f[50];

void find_(int k, int cnt)
{
  if (k > maxa)
  {
  	bool g[50];
  	memset(g, false, sizeof(g));
  	
    g[0] = true;
    for (int i = 0; i <= maxa; i ++)
      if (g[i])
        for (int j = 1; j <= maxa; j ++)
          if (b[j] && i + j <= maxa)
            g[i + j] = true;
    
    for (int i = 1; i <= maxa; i ++)
      if (f[i] != g[i]) return;
    
    ans = min(ans, cnt);
    
    return;
  }
  
  b[k] = 1;
  find_(k + 1, cnt + 1);
  b[k] = 0;
  find_(k + 1, cnt);
}

int main()
{
  freopen("money.in", "r", stdin);
  freopen("money.out", "w", stdout);
  
  cin >> T;
  while (T --)
  {
  	memset(f, false, sizeof(f));
  	
    scanf("%d", &n);
  	maxa = 0; ans = n;
  	
    for (int i = 1; i <= n; i ++)
	{
	  scanf("%d", &a[i]);
	  maxa = max(maxa, a[i]);
    }
    sort(a + 1, a + 1 + n);
    
    f[0] = true;
    for (int i = 0; i <= maxa; i ++)
      if (f[i])
        for (int j = 1; j <= n; j ++)
          f[i + a[j]] = true;
    
    if (maxa <= 16)
	{
	  find_(1, 0);
	  cout << ans << endl;
	  continue;
    }
    
    if (n == 2)
    {
      if (a[2] % a[1] == 0) cout << 1 << endl;
        else cout << 2 << endl;
	  continue;
	}
	
	if (n == 3)
	{
	  if (a[3] % a[1] == 0 && a[2] % a[1] == 0) { cout << 1 << endl; goto next_;}
	  
	  for (int i = 1; i <= a[3] / a[1] + 1; i ++)
	    for (int j = 1; j <= a[3] / a[2] + 1; j ++)
	      if (i * a[1] + j * a[2] == a[3])
	        { cout << 2 << endl; goto next_;}
	  
	  cout << 3 << endl;
	  
	  next_:;
	  continue;
	}
	
	if (n == 4)
	{
	  bool flag1 = false, flag2 = false;
	  if (a[4] % a[1] == 0 && a[3] % a[1] == 0 && a[2] % a[1] == 0) {cout << 1 << endl; goto next__;}
	  
	  for (int i = 1; i <= a[3] / a[1] + 1 && !flag1; i ++)
	    for (int j = 1; j <= a[3] / a[2] + 1; j ++)
	      if (i * a[1] + j * a[2] == a[3])
	      {
	        flag1 = true;
	        break;
	      }
	  for (int i = 1 ; i <= a[4] / a[1] + 1 && !flag2; i ++)
	    for (int j = 1; j <= a[4] / a[2] + 1; j ++)
	      if (i * a[1] + j * a[2] == a[4])
	      {
		    flag2 = true;
		    break;
		  }
	  if (flag1 && flag2) { cout << 2 << endl; goto next__;}
	  
	  for (int i = 1; i <= a[4] / a[1] + 1; i ++)
	    for (int j = 1; j <= a[4] / a[2] + 1; j ++)
	      for (int k = 1; k <= a[4] / a[3] + 1; k ++)
	        if (i * a[1] + j * a[2] + k * a[3] == a[4])
	        {
			  cout << 3 << endl;
			  goto next__;
			}
	  
	  cout << 4 << endl;
	  
	  next__:;
	  continue;
	}
	
	if (n == 5)
	{
	  if (a[5] % a[1] ==0 && a[4] % a[1] ==0 && a[3] % a[1] ==0 && a[2] % a[1] == 0) { cout << 1 << endl; goto next___;}
	  
	  for (int i = 1; i <= a[5] % a[1] + 1;i ++)
	    for (int j = 1; j <= a[5] % a[2] + 1; i ++)
	      for (int k = 1; k <= a[5] % a[3] + 1; k ++)
	        for (int h = 1; h <= a[5] % a[4] + 1; h ++)
	          if (i * a[1] + j * a[2] + k * a[3] + h * a[4] == a[5])
	          {
			    cout << 4 << endl;
			    goto next___;
			  }
		
	  cout << 5 << endl;
	  
	  next___:;
	  continue;
    }
	
	cout << n << endl;
  }
  return 0;
}
