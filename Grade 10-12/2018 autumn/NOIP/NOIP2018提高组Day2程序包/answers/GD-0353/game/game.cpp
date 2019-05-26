#include <bits/stdc++.h>
using namespace std;

const int MODN = 1e9 + 7;

int n, m, ans, cnt;
string st[105];
char ch[10];
int p[5][5];

void _find(int x, int y, int k)
{
  if (k == n + m - 2)
  {
  	cnt ++;
  	st[cnt] = ch;
    return;
  }
  
  if (y < m)
  {
    ch[k] = 'R';
    _find(x, y + 1, k + 1);
  }
  if (x < n)
  {
    ch[k] = 'D';
    _find(x + 1, y, k + 1);
  }
}

void find_(int x, int y)
{
  if (x > n)
  {
  	int a[105], xx, yy;
  	
  	for (int i = 1; i <= cnt; i ++)
  	{
  	  xx = yy = 1; a[i] = p[xx][yy];
  	  for (int j = 0; j < st[i].size(); j ++)
  	    if (st[i][j] == 'D')
  	    {
		  xx ++;
		  a[i] = (a[i] << 1) | p[xx][yy];
		}
		else
		{
		  yy ++;
		  a[i] = (a[i] << 1) | p[xx][yy];
		}
    }
    
    for (int i = 1; i <= cnt; i ++)
      for (int j = 1; j <= cnt; j ++)
        if (st[i] > st[j])
		{
		  if (a[i] <= a[j]) ;
            else return;
        }
    
    ans ++;
    
    return;
  }
  
  p[x][y] = 1;
  find_(x + (y + 1> m), (y + 1 > m ? 1 : y + 1));
  p[x][y] = 0;
  find_(x + (y + 1> m), (y + 1 > m ? 1 : y + 1));
}

int main()
{
  freopen("game.in", "r", stdin);
  freopen("game.out", "w", stdout);

  cin >> n >> m;
  
  if (n <= 3 && m <= 3)
  {
  	_find(1, 1, 0);
	find_(1, 1);
    cout << ans << endl;
    return 0;
  }
  
  if (n == 2)
  {
    if (m <= 5) { cout << m + 3 << endl; return 0; }
    
    long long ans, tmp = 1;
    
    ans = 8;
    m -= 5;
    while (m --)
    {
	  tmp = (tmp * 2) % MODN;
	  ans = (ans + tmp) % MODN;
	}
	cout << ans << endl;
	
	return 0;
  }
  
  
  if (n == 3)
  {
    if (m <= 5) {cout << m + 7 << endl; return 0;}
    
    long long ans, tmp = 1;
    ans = 12;
    m -= 5;
    while (m --)
    {
	  tmp = (tmp * 2)%MODN*2%MODN;
	  ans = (ans + tmp) % MODN;
	}
	
	cout << ans << endl;
  }
  
  return 0;
}
