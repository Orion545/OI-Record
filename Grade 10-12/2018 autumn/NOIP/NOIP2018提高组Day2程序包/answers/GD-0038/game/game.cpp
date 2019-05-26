#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cctype>
#include<cmath>
using namespace std;
const long long mod = 1000000007;
int Trans[333][333]={};
long long F[2][333]={};
bool cond = 1;
//int countone(int x) {
//	int ret = 0;
//	while (x) {
//		if (x & 1) ++ret;
//		x >>= 1;
//	}
//	return ret;
//}
//long long qpow(long long base, int cnt) {
//	long long ret = 1ll;
//	while (cnt) {
//		if (cnt & 1) {
//			ret *= base;
//			ret %= mod;
//		}
//		base *= base;
//		base %= mod;
//		cnt >>= 1;
//	}
//	return ret;
//}
void fafa(int x) {
	while (x) {
		cout << (x & 1);
		x >>= 1;
	}cout << " ";
}
int main() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	long long n, m;
	scanf("%lld%lld", &n, &m);
	long long up = (1 << n) - 1;
	for (int i = 0; i <= up; ++i) {
		for (int j = 0; j <= up; ++j) {
			int tmp = j >> 1;
//			if (j == 2)fafa(j); fafa(tmp); fafa(tmp|i); cout << endl;
			if ((tmp | i) == i) {
				Trans[i][++Trans[i][0]] = j;
//				fafa(i); fafa(j); cout << endl;
//				cout << i << " " << j << endl;
			}
		}
		F[cond][i] = 1ll;
	}
	for (int i = 2; i <= m; ++i) {
		cond = !cond;
		memset(F[cond], 0, sizeof(F[cond]));
		for (int j = 0; j <= up; ++j) {
			for (int k = 1; k <= Trans[j][0]; ++k) {
				F[cond][Trans[j][k]] += F[!cond][j];
				F[cond][Trans[j][k]] %= mod;
			}
		}
	}
	long long ans = 0;
	for (int i = 0; i <= up; ++i) {
		ans += F[cond][i];
		ans %= mod;
	}
	printf("%lld", ans);
	return 0;
}
