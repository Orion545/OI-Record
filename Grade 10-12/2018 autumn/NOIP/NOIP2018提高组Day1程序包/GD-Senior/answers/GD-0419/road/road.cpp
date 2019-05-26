#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
struct th
{
	int a, pos;
} d[100010];
bool v[100010];
int ans = 0;

int read()
{
	int x = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
	return x;
}
int cmp(th x, th y)
{
	return x.a < y.a;
}
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
//	scanf("%d", &n);
	n = read();
	for (int i = 1; i <= n; i++)
	{
//		scanf("%d", &d[i].a);
		d[i].a = read();
		d[i].pos = i;
	}
//	puts("a");
	sort(d + 1, d + 1 + n, cmp);
//	puts("b");
	int now = 1;
	v[0] = v[n + 1] = 1;
	int last = 0;
	for (int i = 1; i <= n; i++)
	{/*
		printf("%lld\n", now);
		for (int i = 1; i <= n; i++)
			printf("%d ", v[i]);
		puts("");*/
		ans += now * (d[i].a - last);
		last = d[i].a;
		int hh = 1;
		if (v[d[i].pos - 1]) hh--;
		if (v[d[i].pos + 1]) hh--;
		now += hh;
		v[d[i].pos] = 1;
	}
	printf("%d\n", ans);
}
