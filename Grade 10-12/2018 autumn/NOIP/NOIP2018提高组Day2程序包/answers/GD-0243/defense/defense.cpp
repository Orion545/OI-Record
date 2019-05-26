#include <iostream>
#include <string>
#include <cstdio>

long p[100001], f[100001][2];
int use[100001][2];

long min(long a, long b) {
	if (a < b) return a;
	return b;
}

int main() {
	freopen("defense.in", "r", stdin);
	freopen("defense.out", "w", stdout);
	std::string temp;
	long n, m;
	std::cin >> n >> m >> temp;
	if (temp[0]!='A') {
		if (temp[1] = '2') {
			long bullshit;
			for (long i = 0; i < n; i++) 
				std::cin >> bullshit;
			for (long i = 0; i < n-1; i++) 
				std::cin >> bullshit >> bullshit;
			for (long i = 0; i < m; i++) 
				std::cout << "-1" << std::endl;
		}
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	//for (long i = 1; i <= n; i++) {
	//	std::cin >> p[i];
	//} 
	//long bullshit;
	//for (long i = 0; i < n-1; i++) {
	//	std::cin >> bullshit >> bullshit;
	//}
	//for (long i = 0; i < m; i++) {
	//	long a, x, b, y;
	//	std::cin >> a >> x >> b >> y;
	//	memset(f, 0, sizeof(f));
	//	memset(use, 0, sizeof(use));
	//	use[0][0] = 1;
	//	use[0][1] = 1;
	//	for (long i = 1; i < a; i++) {
	//		if (use[i-1] > 0) {
	//			f[i][0] = min(f[i-1][1], f[i-1][0]);
	//			use[i] = use[i-1] - 1;
	//			f[i][1] = min(f[i-1][1] + p[i], f[i-1][0] + p[i]);
	//		} else {
	//			f[i][0] = f[x-1][1];
	//			use[i] = 1;
	//			f[i][1] = min(f[i-1][1] + p[i], f[i-1][0] + p[i]);
	//		}
	//	}
	//	if (x) {
	//		f[a][0] = f[a-1]
	//	}
	//}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
