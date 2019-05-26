#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
using namespace std;
const int N = 5;
int n, m, a[N], ans = 0, cnt = 0, cnt0 = 0, cnt1 = 0;
string w[600], s[600];

int check() {
	for (int i = 1; i <= cnt; i++) {
		for (int j = 1; j <= cnt; j++) {
			if (w[i] > w[j]) {
				if (s[i] > s[j]) {
					return 0;
				}
			}
		}
	}
	return 1;
}

void work(int x, int y, string sw, string ss) {
	if (x > n || y > m) return;
	if (x == n && y == m) {
		w[++cnt] = sw;
		s[cnt] = ss;
		return;
	}
	char tmp[1] = {((a[x] >> (m - y - 1)) & 1) + '0'};
	work(x, y + 1, sw + "R", ss + tmp);
	char tmp1[1] = {((a[x + 1] >> (m - y)) & 1) + '0'};
	work(x + 1, y, sw + "D", ss + tmp1);	
}

void dfs(int x) {
	if (x > n) {
		cnt = cnt1 = 0;
		string tmp = "";
		work(1, 1, tmp, tmp);
		ans = check();
		return;
	}
	for (int i = 0; i < (1 << m); i++) {
		a[x] = i;
		dfs(x + 1);
	}
}
int main() {
	
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	scanf("%d%d", &n, &m);
	dfs(1);
	printf("%d", ans);
	fclose(stdin); fclose(stdout);
	return 0;
}
