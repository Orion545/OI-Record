#include<cstdio>
#include<cstring>
using namespace std;
const int N = 100005;
int n, d[N], ans = 0;
int read() {
	int x = 0, f = 1; char ch = getchar();
	while(ch > '9' || ch < '0') {if (ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	n = read();
	memset(d, 0, sizeof(d));
	for (int i = 1; i <= n; i++) {
		d[i] = read();
		if (d[i] > d[i - 1]) {
			for (int j = 1; j <= d[i] - d[i - 1]; j++) {
				ans++;	
			}
		}
	}
	printf("%d\n", ans);
	fclose(stdin); fclose(stdout);
	return 0;
}
