#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

int read() {
	int t = 0; char ch = getchar();
	while ('0' > ch || ch > '9') ch = getchar();
	while('0' <= ch && ch <= '9')
		t = (t << 3) + (t << 1) + ch - '0',
		ch = getchar();
	return t;
}
const int maxn = 1e5 + 5;
bool fl[maxn];
int n, a[maxn], fa[maxn], set_cnt, ans;
vector<int> pl[10005];

int tmp[maxn], tot_tmp;

int find(int val) {
	int l = 1, r = tot_tmp;
	while(l <= r) {
		int mid = (l + r) >> 1;
		if (tmp[mid] == val) return mid;
		if (tmp[mid] > val) r = mid - 1;
		else l = mid + 1;
	}
	return r;
}

int getfa(int v) { return v == fa[v] ? v : fa[v] = getfa(fa[v]); }

void merge(int u, int v) {
	if (!u || !v) return ;
	int fu = getfa(u), fv = getfa(v);
	if (fu == fv) return ;
	set_cnt--, fa[fu] = fv;
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	n = read();
	for (int i = 1; i <= n; i++) a[i] = tmp[i] = read(), fa[i] = i;
	sort(tmp + 1, tmp + 1 + n);
	tot_tmp = unique(tmp + 1, tmp + 1 + n) - tmp - 1;
	for (int i = 1; i <= n; i++) {
		int p = find(a[i]); pl[p].push_back(i);
	}
	for (int i = 0; i < pl[tot_tmp].size(); i++) {
		int pla = pl[tot_tmp][i];
		fl[pla] = true, set_cnt++;
		if (fl[pla + 1]) merge(pla, pla + 1);
		if (fl[pla - 1]) merge(pla, pla - 1);
	}
	for (int i = tot_tmp - 1; i >= 1; i--) {
		ans += set_cnt * (tmp[i + 1] - tmp[i]);
		for (int j = 0; j < pl[i].size(); j++) {
			int pla = pl[i][j];
			fl[pla] = true, set_cnt++;
			if (fl[pla + 1]) merge(pla, pla + 1);
			if (fl[pla - 1]) merge(pla, pla - 1);
		}
	}
	printf("%d\n", ans + tmp[1] * set_cnt);
	return 0;
}
