#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int T, n, a[110];
bool del[110];

long long exgcd(long long a, long long b, long long &x, long long &y)
{
	if (b == 0)
	{
		x = 1;
		y = 0;
		return a;
	}
	long long tx, ty, d = exgcd(b, a % b, tx, ty);
	x = ty;
	y = tx - a / b * ty;
	return d;
}
int main()
{
	freopen("money.in", "r", stdin);
	freopen("money.out", "w", stdout);
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		memset(del, 0, sizeof(del));
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
			{
				long long x, y, d = exgcd(a[i], a[j], x, y);
				for (int k = 1; k <= n; k++)
				{
					if (k == i || k == j || a[k] % d) continue;
					int hh = a[k] / d;
					long long xx = x * hh, yy = y * hh;
					if (xx < 0)
					{
						long long oo = (-xx) / (a[j] / d);
						if ((-xx) % (a[j] / d)) oo++;
						xx += oo * (a[j] / d);
						yy -= oo * (a[i] / d);
						if (yy >= 0) del[k] = 1;
					}
					else if (yy < 0)
					{
						long long oo = (-yy) / (a[i] / d);
						if ((-yy) % (a[i] / d)) oo++;
						xx -= oo * (a[j] / d);
						yy += oo * (a[i] / d);
						if (xx >= 0) del[k] = 1;
					}
					else del[k] = 1;
				}
			}
		int ans = n;
		for (int i = 1; i <= n; i++) if (del[i]) ans--;
		printf("%d\n", ans);
	}
}
