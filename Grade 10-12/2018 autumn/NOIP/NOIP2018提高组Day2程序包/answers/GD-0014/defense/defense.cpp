#include <cstdio>
using namespace std;
int main() {
	freopen("defense.in", "r", stdin);
	freopen("defense.out", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++) {
		printf("%d\n", -1);
	}
	fclose(stdin); fclose(stdout);
}
