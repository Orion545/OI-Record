#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int a[105];
bool flag[105];

bool Find(int n, int sum)
{
	if (sum == 0)
		return 1;
	if (sum < a[1])
		return 0;
	bool tmp = 0;
	for (int i = 1; i <= n; ++ i)
		if (!flag[i]) {
			if (sum % a[i] == 0)
				return 1;
			tmp = (tmp || Find(n, sum - a[i]));
		}
	return tmp;
}

int main(void)
{
	freopen("money.in",  "r",  stdin);
	freopen("money.out", "w", stdout);
	int t = 0;
	scanf("%d", &t);
	while (t --) {
		memset(flag, 0, sizeof(flag));
		int n = 0;
		int ans = 0;
		scanf("%d", &n);
		for (int i = 1; i <= n; ++ i) {
			scanf("%d", &a[i]);
			if (a[i] == 1) {
				puts("1");
				goto nxti;
			}
		}
		sort(a + 1, a + 1 + n);
		ans = n;
		for (int i = 2; i <= n; ++ i)
			if (Find(i - 1, a[i])) {
				flag[i] = 1;
				-- ans;
			}
		printf("%d\n", ans);
		nxti:;
	}
	return 0;
}
