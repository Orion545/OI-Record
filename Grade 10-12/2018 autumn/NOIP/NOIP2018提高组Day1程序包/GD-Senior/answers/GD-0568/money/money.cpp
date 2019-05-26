//#define DEBUG
#include <cstdio>
#define INF 0x7ffffff
#define MAXN 100
#define MAXA 25000

using namespace std;

int min(int a, int b) {
	return a<b ? a : b;
}

void qsort(int *a, int l, int r) {
	int i=l, j=r, mid=a[(l+r)/2], temp;
	for (; i<=j; ) {
		for (; a[j]>mid; j--);
		for (; a[i]<mid; i++);
		if (i<=j) {
			temp=a[i], a[i]=a[j], a[j]=temp;
			i++, j--;
		}
	}
	if (i<r) {
		qsort(a, i, r);
	}
	if (j>l) {
		qsort(a, l, j);
	}
}

int main() {
	freopen("money.in", "r", stdin);
	freopen("money.out", "w", stdout);

	static int a[MAXN+1];
	static bool book[MAXA+1];
	int t, n, ans;
	scanf("%d", &t);
	for (int ti=1; ti<=t; ti++) {
		scanf("%d", &n);
		book[0] = true;
		for (int i=1; i<=n; i++) {
			scanf("%d", a+i);
		}
		qsort(a, 1, n);
		for (int i=1; i<=a[n]; i++) {
			book[i] = false;
		}
		ans = 0;
		for (int i=1; i<=n; i++) {
			if (!book[a[i]]) {
				ans++;
				for (int j=0; j<=a[n]-a[i]; j++) {
					if (book[j]) {
						book[a[i]+j] = true;
					}
				}
			}
		}
		printf("%d\n", ans);
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
