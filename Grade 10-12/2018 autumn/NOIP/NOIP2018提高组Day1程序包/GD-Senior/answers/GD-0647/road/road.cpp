#include <cstdio>

int n, ans, a[100005];

inline void read(int &k) {
	int f=1;
	char c=getchar();
	k = 0;
	while(c < '0' || c > '9') {
		if(c == '-') f = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9') {
		k = k * 10 + (c ^ 48);
		c = getchar();
	}
	k *= f;
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	read(n);
	for(int i=1; i<=n; i++) read(a[i]);
	for(int i=1; i<=n; i++) if(a[i] > a[i-1]) ans += a[i] - a[i-1];
	printf("%d\n", ans);
	return 0;
}
