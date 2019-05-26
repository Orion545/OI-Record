#include <cstdio>
#include <algorithm>
#define rep(i, x, y) for(int i=x;i<y;++i)

int a[100];

int gcd(int x, int y) {
	return x%y ? gcd(y, x%y) : y;
}

int main() {
	freopen("money.in", "r", stdin);
	freopen("money.out", "w", stdout);
int T;
scanf("%d", &T);

while (T--) {
	
	int n;
	scanf("%d", &n);
	rep(i, 0, n) {
		scanf("%d", a+i);
	}
	std::sort(a, a+n);
	if (n == 2) {
		if (a[1] % a[0] == 0) {
			printf("1\n");
		} else {
			printf("2\n");
		}
		continue;
	}
	if (n == 3) {
		int ans = 3;
		if (a[1] % a[0] == 0) {
			--ans;
			if (a[2] % a[0] == 0) {
				--ans;
			}
		}
		else if (a[2] % gcd(a[0], a[1]) == 0 && a[2] > (a[0]-1) * (a[1]-1))
			--ans;
		printf("%d\n", ans);
		continue;
	}
	if (n == 4) {
		int ans = 4;
		if (a[1] % a[0] == 0)
			--ans;
		if (a[2] % gcd(a[0], a[1]) == 0 && a[2] > (a[0]-1) * (a[1]-1))
			--ans;
		if ((a[3] % gcd(a[0], a[1]) == 0 && a[3] > (a[0]-1) * (a[1]-1)) ||
		    (a[3] % gcd(a[0], a[2]) == 0 && a[3] > (a[0]-1) * (a[2]-1)) ||
		    (a[3] % gcd(a[1], a[2]) == 0 && a[3] > (a[1]-1) * (a[2]-1)) ||
	        (a[3] % gcd(a[0], gcd(a[1], a[2])) == 0 &&
			 a[3] > (a[0]-1) * (a[1]-1) * (a[2]-1))
			)
		--ans;
		printf("%d\n", ans);
		continue;
	}
	if (n == 5) {
		int ans = 5;
		if (a[1] % a[0] == 0)
			--ans;
		if (a[2] % gcd(a[0], a[1]) == 0 && a[2] > (a[0]-1) * (a[1]-1))
			--ans;
		if ((a[3] % gcd(a[0], a[1]) == 0 && a[3] > (a[0]-1) * (a[1]-1)) ||
		    (a[3] % gcd(a[0], a[2]) == 0 && a[3] > (a[0]-1) * (a[2]-1)) ||
		    (a[3] % gcd(a[1], a[2]) == 0 && a[3] > (a[1]-1) * (a[2]-1)) ||
	        (a[3] % gcd(a[0], gcd(a[1], a[2])) == 0 &&
			 a[3] > (a[0]-1) * (a[1]-1) * (a[2]-1))
			)
		--ans;
		printf("%d\n", ans);
		continue;
	}
}
	return 0;
}
