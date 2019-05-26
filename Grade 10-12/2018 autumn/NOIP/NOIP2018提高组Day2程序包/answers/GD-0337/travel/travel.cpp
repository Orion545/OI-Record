#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int a[5010], temp[5010], n, m, x, y, last[5010];
bool b[5010];
vector<int> v[5010];

void dfs(int current, int left, int floor, int fakeFloor) {
	if (left == 0) {
		for (int i = 0; i < n; ++i) a[i] = temp[i];
		return;
	}
	if (fakeFloor != 0) dfs(last[current], left, floor, fakeFloor - 1);
	for (int i = 0; i < v[current].size(); ++i) {
		if (a[floor + 1] > v[current][i] && !b[v[current][i]]) {
			b[v[current][i]] = true;
			temp[floor + 1] = v[current][i];
			last[v[current][i]] = current;
			dfs(v[current][i], left - 1, floor + 1, fakeFloor + 1);
			b[v[current][i]] = false;
		}
	}
}

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		scanf("%d%d", &x, &y);
		--x; --y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for (int i = 0; i < n; ++i) {
		a[i] = 2147483640;
		if (v[i].size() >= 2) sort(v[i].begin(), v[i].end());
	}
	for (int i = 0; i < n; ++i) {
		b[i] = true;
		temp[0] = i;
		dfs(i, n - 1, 0, 0);
		b[i] = false;
	}
	for (int i = 0; i < n - 1; ++i) printf("%d ", a[i] + 1);
	printf("%d\n", a[n - 1] + 1);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
