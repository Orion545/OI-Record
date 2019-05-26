#include <cstdio>
#include <cstring>
#include <cstdlib>

const int N = 107;

int T, n, a[N], del[N];

int exgcd(int a, int b, int &x, int &y)
{
	if (!b)
	{
		x = 1, y = 0;
		return a;
	}
	int tmp = exgcd(b, a % b, y, x);
	y -= a / b * x;
	return tmp;
}

int main()
{
	freopen("money.in", "r", stdin);
	freopen("money.out", "w", stdout);

	scanf("%d", &T);
	while (T--)
	{
		memset(del, 0, sizeof(del));
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (del[i]) break;
				for (int k = j + 1; k <= n; k++)
					if (j != i && k != i)
					{
						int a1 = a[j], b1 = a[k], c1 = a[i], p, q;
						int g = exgcd(a1, b1, p, q);
						a1 /= g, b1 /= g;
						if (c1 % g == 0) continue;
						c1 /= g, p *= c1, q *= c1;
						while (p < 0) p += b1, q -= a1;
						while (q < 0) p -= b1, q += a1;
						if (p >= 0 && q >= 0) { del[i] = 1; break; }
					}
			}
			for (int j = 1; j <= n; j++) if (i != j && a[i] % a[j] == 0) { del[i] = 1; break; }
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) if (!del[i]) ans++;
		printf("%d\n", ans);
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
