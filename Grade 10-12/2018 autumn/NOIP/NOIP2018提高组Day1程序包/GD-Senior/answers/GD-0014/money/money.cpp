#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 105, M = 25005;
int t, a[N], f[M];
int read() {
	int x = 0, f = 1; char ch = getchar();
	while(ch > '9' || ch < '0') {if (ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}
int main() {
	freopen("money.in", "r", stdin);
	freopen("money.out", "w", stdout);
	t = read();
	while(t--) {
		memset(f, 0, sizeof(f));
		int n = read(), maxx = 0, ans = 0;
		for (int i = 1; i <= n; i++) {
			a[i] = read();
			f[a[i]] = 1;
			maxx = max(maxx, a[i]);
		}
		for (int i = 1; i <= n; i++) {
			for (int j = a[i]; j <= maxx; j++) {
				if(f[j - a[i]]) f[j] = 2;
			}
		}
		for (int i = 1; i <= n; i++) {
			if (f[a[i]] == 2) ans++;
		}
		printf("%d\n", n - ans);
	}
	fclose(stdin); fclose(stdout);
	return 0;
}
