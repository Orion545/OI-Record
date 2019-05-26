#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct rd {
	int to, n;
};

vector<rd> a[30005];

bool comp(rd a, rd b)
{
	return a.to < b.to;
}

bool ccomp(rd a, rd b)
{
	return a.n > b.n;
}

int main(void)
{
	freopen("track.in",  "r",  stdin);
	freopen("track.out", "w", stdout);
	int n = 0, m = 0;
	scanf("%d%d", &n, &m);
	bool flag = 1;
	for (int i = 1; i <= n; ++ i) {
		int ai = 0, bi = 0, s = 0;
		scanf("%d%d%d", &ai, &bi, &s);
		if (ai > bi)
			swap(ai, bi);
		a[ai].push_back((rd){bi, s});
		a[bi].push_back((rd){ai, s});
		if (ai != 1)
			flag = 0;
	}
	int ans = 0;
	if (flag) {
		sort(a[1].begin(), a[1].end(), ccomp);
		for (int i = 0; i < m; ++ i)
			ans += a[1][i].n;
	}
	printf("%d", ans);
	return 0;
}
