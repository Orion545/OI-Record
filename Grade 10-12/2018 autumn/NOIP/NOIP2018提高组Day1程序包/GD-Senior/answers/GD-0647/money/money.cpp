#include <cstdio>
#include <cstring>

int t, n, maxx, ans, a[105], f[25005];

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
	freopen("money.in", "r", stdin);
	freopen("money.out", "w", stdout);
	read(t);
	while(t--) {
		read(n);
		ans = n, maxx = 0;
		memset(f, 0, sizeof(f));
		for(int i=1; i<=n; i++) {
			read(a[i]);	
			maxx = a[i] > maxx ? a[i] : maxx;
		}
		f[0] = 1;
		for(int i=1; i<=n; i++) for(int j=a[i]; j<=maxx; j++) f[j] += f[j-a[i]];
		for(int i=1; i<=n; i++) if(f[a[i]] > 1) ans--;
		printf("%d\n", ans);
	}
	return 0;
}
