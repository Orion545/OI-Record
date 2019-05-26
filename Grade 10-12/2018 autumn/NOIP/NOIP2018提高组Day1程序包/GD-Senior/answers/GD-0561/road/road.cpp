#include <cstdio>
#define N 100005
using namespace std;

int a[N],n;

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	int now = 0;
	long long ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (now < a[i]) ans += a[i] - now;
		now = a[i];
	}
	printf("%lld", ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
