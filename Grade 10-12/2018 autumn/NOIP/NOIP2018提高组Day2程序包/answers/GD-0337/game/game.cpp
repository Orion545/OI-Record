#include <cstdio>
using namespace std;

const int P = 1000000007;
int n, m, f[9][1000010][2];

int main() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	scanf("%d%d", &n, &m);
	f[0][0][0] = f[0][0][1] = 1;
	for (int j = 0; j < m; ++j) {
		for (int i = 0; i < n; ++i) {
			if (i == 0 && j == 0) continue;
			if (j > 0 && i + 1 < n) {
				f[i][j][0] += f[i + 1][j - 1][1] + f[i + 1][j - 1][0];
				f[i][j][1] += f[i + 1][j - 1][1];
			} else {
				if (j == 0) {
					f[i][j][0] += f[i - 1][j][0] + f[i - 1][j][1];
					f[i][j][1] += f[i - 1][j][0] + f[i - 1][j][1];
				} else {
					f[i][j][0] += f[i][j - 1][0] + f[i][j - 1][1];
					f[i][j][1] += f[i][j - 1][0] + f[i][j - 1][1];
				}
			}
		}
	}
	printf("%d", f[n - 1][m - 1][0] + f[n - 1][m - 1][1]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
