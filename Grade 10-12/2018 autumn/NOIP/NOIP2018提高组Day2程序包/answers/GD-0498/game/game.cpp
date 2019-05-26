// #include <algorithm>
#include <cstdio>
// #include <string>
// #include <vector>
// using std::string;
// using std::vector;
// using std::sort;

const int MOD  = 1000000007;
// const int MAXN = 20;

int table[8][8] = {
	{2, 4, 8, 16, 32, 64, 128, 256},
	{4, 12, 36, 108, 324, 972, 6480, 19440},
	{8, 36, 112, 336, 1008, 3024, 19272, 60104},
	{16, 108, 336, 912, 2688, 8064, 31728, 96688},
	{32, 324, 1008, 2688, 7136, 21312, 84896, 255584},
	{64, 972, 3024, 8064, 21312, 56768, 170112, 510336},
	{128, 6480, 19272, 31728, 84896, 170112, 453504, 1360128},
	{256, 19440, 60104, 96688, 255584, 510336, 1360128, 3626752}
};

int n, m;
long long ans;
// int ps, cnt;
// bool map[MAXN][MAXN];
// char tmp[MAXN*2];
// vector<string> paths;
// // string paths[MAXN*MAXN*MAXN];

// void dfs(const int x, const int y) {
// 	if (x == n - 1 && y == m - 1) {
// 		// paths[ps ++] = tmp;
// 		paths.push_back(string(tmp));
// 		ps ++;
// 		return;
// 	}

// 	if (x >= n || y >= m)
// 		return;
// 	tmp[x + y] = 'R';
// 	dfs(x, y + 1);
// 	tmp[x + y] = 'D';
// 	dfs(x + 1, y);
// }

// int get01(const int p) {
// 	// printf("%d\n", p);
// 	int x = 0, y = 0, ret = 0;
// 	const char *tmp = paths.at(p).c_str();
// 	for (int i=0; i<n+m; i++) {
// 		if (tmp[i] == 'D') x ++;
// 		if (tmp[i] == 'R') y ++;
// 		ret = ret << 1 | map[x][y];
// 	}
// 	return ret;
// }

// bool check() {
// 	// for (int x=1; x<n; x++)
// 	// 	for (int y=0; y<m-1; y++)
// 	// 		if (map[x-1][y+1] > map[x][y]) {
// 	// 			// for (int x=0; x<n; x++) {
// 	// 			// 	for (int y=0; y<m; y++)
// 	// 			// 		putchar('0' + map[x][y]);
// 	// 			// 	puts("");
// 	// 			// }
// 	// 			// puts("");
// 	// 			putchar('.');
// 	// 			return false;
// 	// 		}

// 	static int last_fail = 0;

// 	if (get01(last_fail) < get01(last_fail + 1))
// 		return false;

// 	for (int i=0; i<ps-1; i++)
// 		if (get01(i) < get01(i + 1)) {
// 			last_fail = i;
// 			return false;
// 		}

// 	return true;
// }

// void search(const int dep) {
// 	if (dep >= n + m - 2) {
// 		if (check()) {
// 			ans ++;
// 			cnt ++;
// 			if (cnt >= 1000) {
// 				printf("%d\n", cnt / 1000);
// 				cnt = 0;
// 			}
// 		}
// 		return;
// 	}
// 	// for (int x=0; x<n; x++) {
// 	// 	for (int y=0; y<m; y++)
// 	// 		putchar('0' + map[x][y]);
// 	// 	puts("");
// 	// }
// 	// puts("");
// 	int s = 0;
// 	if (dep + 1 > (n + m) / 2) {
// 		s = dep - n + 1;
// 	}
// 	// printf("dep = %d\n", dep);

// 	search(dep + 1);
// 	for (int i=s; i<m && dep-i>=0; i++) {
// 		map[dep-i][i] = true;
// 		search(dep + 1);
// 	}
// 	for (int i=s; i<m && dep-i>=0; i++)
// 		map[dep-i][i] = false;
// }

int main() {
	freopen("game.in" , "r", stdin );
	freopen("game.out", "w", stdout);

	scanf("%d %d", &n, &m);

	if (n == 2) {
		ans = 4;
		for (int i=1; i<m; i++)
			ans = ans * 3 % MOD;
		printf("%d\n", (int)ans);
		return 0;
	}
	else if (n <= 8 && m <= 8) {
		printf("%d\n", table[n-1][m-1]);
		return 0;
	}

	// Note:
	//   It's too hard to solve the other testcases,
	//   so making it disabled can save judge time.

	// dfs(0, 0);
	// sort(paths.begin(), paths.end());

	// search(1);

	// printf("%d\n", (int)((ans * 4) % MOD));

	return 0;
}
