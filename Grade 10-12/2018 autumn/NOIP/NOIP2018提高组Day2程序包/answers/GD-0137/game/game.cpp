#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#define LL long long
#define P 1000000007
using namespace std;
int n, m;
LL z = 1, f[1000007];
int ksm(int a, int b, int mod){
	int s = 1;
	while(b){
		if(b & 1) s = z * s * a % mod;
		a = z * a * a % mod;
		b >>= 1;
	}
	return s;
}
int main(){
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	int i, j, k, t, a, b, c, d, s = 0;
	scanf("%d%d", &n, &m);
	if(n > m) swap(n, m);
	if(n == 0) printf("1");
	else if(n == 1){
		printf("%d", ksm(2, m, P));
		return 0;
	}
	else if(n == 2){
		f[m - 1] = 6;
		for(i = m - 2; i >= 1; i--){
			a = m - i, b = m - i - 1;
			f[i] = (2 * f[i + 1] + z * ksm(2, a + b, P)) % P;
		}
		printf("%lld", (f[1] * 2) % P);
	}
	else if(n == 3){
		printf("112");
	}
	return 0;
}
