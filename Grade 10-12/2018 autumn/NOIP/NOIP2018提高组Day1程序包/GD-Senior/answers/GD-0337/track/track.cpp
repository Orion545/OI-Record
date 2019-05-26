#include <cstdio>
#include <vector>
using namespace std;

int n, m, x, y, z, ans = 0;
struct Road{
	int to;
	int value;
} temp;
vector<Road> v[50010];
bool b[50010];

inline int max(const int &a,const int &b) {
	return a > b ? a : b;
}

void dfs(int current, int left, int tot) {
	bool flag = false;
	Road temp;
	for (int i = 0; i < v[current].size(); ++i) {
		temp = v[current][i];
		if (b[temp.to]) continue;
		flag = true;
		b[temp.to] = true;
		dfs(temp.to, left, tot + temp.value);
		b[temp.to]= false;
	}
	if (!flag) {
		if (left == 0) {
			ans = max(ans, tot);
			return;
		}
		for (int i = 0; i < n; ++i) {
			int c = 0;
			for (int j = 0; j < v[i].size(); ++j) if (!b[v[i][j].to]) ++c;
			if (c <= 1 && !b[i]) {
				b[i] = true;
				dfs(i, left - 1, tot);
				b[i] = false;
			}
		}
	}
	return;
}

int main () {
	freopen("track.in", "r", stdin);
	freopen("track.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n - 1; ++i) {
		b[i] = false;
		scanf("%d%d%d", &x, &y, &z);
		--x; --y;
		temp.to = y;
		temp.value = z;
		v[x].push_back(temp);
		temp.to = x;
		v[y].push_back(temp);
	}
	b[n - 1] = false;
	for (int i = 0; i < n; ++i) {
		if (v[i].size() == 1) {
			b[i] = true;
			dfs(i, m - 1, 0);
			b[i] = false;
		}
	}
	printf("%d\n", ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
