#include <cstdio>
#define MODS 1000000007
#define MAXN 5
#define MAXM 5
#define MAXK 256

using namespace std;

bool isRight(int x, int y, int suf, int matrix[MAXN][MAXM], int n, int m, int *s) {
	bool ret=true;
	suf = suf*2+matrix[x][y];
	if (x==n-1 && y==m-1) {
		for (int i=1; i<=s[0] && ret; i++) {
			ret = s[i]<=suf;
		}
		s[++s[0]] = suf;
	} else {
		if (y+1<m && ret) {
			ret &= isRight(x, y+1, suf, matrix, n, m, s);
		}
		if (x+1<n && ret) {
			ret &= isRight(x+1, y, suf, matrix, n, m, s);
		}
	}
	return ret;
}

long long solve(int x, int y, int n, int m) {
	static int matrix[MAXN][MAXM];
	static int s[MAXK+1];
	if (y>=m) {
		y = 0;
		x++;
	}
	if (x>=n) {
		s[0] = 0;
		int t=isRight(0, 0, 0, matrix, n, m, s);
		return t;
	}
	long long ret=0;
	matrix[x][y]=0;
	ret = (ret+solve(x, y+1, n, m))%MODS;
	matrix[x][y]=1;
	ret = (ret+solve(x, y+1, n, m))%MODS;
	return ret;
}

int main() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);

	for (int i=1; i<=5; i++) {
		for (int j=1; j<=5; j++) {
			printf("%8lld", solve(0, 0, i, j));
		}
		printf("\n");
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
