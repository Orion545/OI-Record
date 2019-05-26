#include <bits/stdc++.h>
#define MAXN 100010
#define MAXD 10010
#define mid ((L + R) >> 1)
using namespace std;

int n, a[100050];
long long mini, ans;
int p, Left, Right;

int main()
{
  freopen("road.in", "r", stdin);
  freopen("road.out", "w", stdout);
  
  cin >> n;
  for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
  
  //if (n <= 1000)
  {
    while (true)
    {
  	  mini = MAXD;
      for (int j = 1; j <= n; j ++)
        if (mini > a[j] && a[j] > 0)
        {
	      mini = a[j];
	      p = j;
	    }
	
	  if (mini == MAXD) break;
	
	  Left = Right = p;
	  while (a[Left] != 0) Left --;
	  while (a[Right] != 0) Right ++;
	
	  for (int j = Left + 1; j < Right; j ++) a[j] -= mini;
	  ans += mini;
    }
    cout << ans << endl;
    return 0;
  }
  return 0;
}
