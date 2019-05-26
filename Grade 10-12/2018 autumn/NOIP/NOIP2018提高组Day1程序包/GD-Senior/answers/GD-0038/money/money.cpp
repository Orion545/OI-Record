#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<cctype>
#include<cmath>
using namespace std;
#define getchar() (frS==frT&&(frT=(frS=frBB)+fread(frBB,1,1<<12,stdin),frS==frT)?EOF:*frS++)
char frBB[1<<12] = {}, *frS = frBB, *frT = frBB;
int read(int &x) {
	x = 0;
	char ch = getchar();
	while (!isdigit(ch)) ch = getchar();
	while (isdigit(ch)) x = x * 10 + ch - 48, ch = getchar();
	return x;
}
int a[105] = {}, n;
int b[105] = {}, m;
bool notin[105] = {};
bool avail[25005] = {};
int main() {
	freopen("money.in", "r", stdin);
	freopen("money.out", "w", stdout);
	int T = 0;
	read(T);
	while (T--) {
		read(n);
		for (int i = 1; i <= n; ++i) {
			read(a[i]);
		}
		sort(a+1, a+1+n);
		memset(notin, 0, sizeof(notin));
		for (int i = 1; i <= n; ++i) {
			if (notin[i]) continue;
			for (int j = 1; j < i; ++j) {
				if (notin[j]) continue;
				if (!(a[i] % a[j])) {
					notin[i] = 1;
					break;
				}
			}
		}
		m = 0;
		for (int i = 1; i <= n; ++i) {
			if (!notin[i]) b[++m] = a[i];
		}
		memset(avail, 0, sizeof(avail));
		for (int i = 1; i <= m; ++i) {
			for (int j = 1; j <= i; ++j) {
				if (b[i] + b[j] <= b[m]) avail[b[i] + b[j]] = 1;
			}
		}
		for (int i = 1; i <= m; ++i) {
			for (int j = b[i]; j <= b[m]; ++j) {
				avail[j] |= avail[j - b[i]];
			}
		}
		int ans = m;
		for (int i = 1; i <= m; ++i) {
			if (avail[b[i]]) --ans;
		}
		printf("%d\n", ans);
	}
	return 0;
}
