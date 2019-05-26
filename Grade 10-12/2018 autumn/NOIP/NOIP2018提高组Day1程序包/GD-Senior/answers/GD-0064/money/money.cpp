#include <iostream>
#include <cstdio>
#define repu(i, x, y) for (int i = x; i <= y; ++i)
using namespace std;
const int MAXN = 111;
int a[MAXN], d[MAXN];
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int n;
bool search2(int depth, int curp, int cur, int tp)
{
	if (depth == n)
	{
		if (cur == a[tp])
			return true;
		else return false;
	}
	if (curp == tp) return search2(depth, curp + 1, cur, tp);
	if (d[curp]) return search2(depth + 1, curp + 1, cur, tp);
	for (int i = 0; cur + i * a[curp] <= a[tp]; i++)
	{
		if (search2(depth + 1, curp + 1, cur + i * a[curp], tp)) return true;
	}
	return false;
}
int main()
{
	freopen("money.in", "r", stdin);
	freopen("money.out", "w", stdout);
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		repu(i, 1, n) scanf("%d", &a[i]);
		repu(i, 1, n) d[i] = false;
		if (n == 2)
		{
			if (max(a[1], a[2]) % min(a[1], a[2]) == 0)
				puts("1");
			else puts("2");
		}
		else
		{
			int ans = n;
			repu(i, 1, n)
			{
				repu(j, 1, i - 1)
				{
					int x, y;
					if (a[i] < a[j]) { x = i; y = j; }
					else { y = i; x = j; }
					if (!d[y] && a[y] % a[x] == 0)
					{
						d[y] = true;
						ans--;
					}
				}
			}
			repu(i, 1, n)
			{
				if (d[i]) continue;
				if (search2(1, 1, 0, i))
				{
					d[i] = true;
					ans--;
				}
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}
