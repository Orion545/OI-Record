#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;
typedef long long LL;
int _min(int x, int y) {return x < y ? x : y;}
int _max(int x, int y) {return x > y ? x : y;}

int read() {
	int s = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
	return s * f;
}

int s[26000];
bool f[26000];

int main() {
	freopen("money.in", "r", stdin);
	freopen("money.out", "w", stdout);
	int T = read();
	while(T--) {
		int n = read();
		int maxx = 0; memset(s, 0, sizeof(s));
		for(int i = 1; i <= n; ++i) {
			int x = read();
			maxx = _max(maxx, x), ++s[x];
		} memset(f, 0, sizeof(f));
		f[0] = 1;
		int ans = 0;
		for(int i = 1; i <= maxx; ++i) if(s[i]){
			if(f[i] == 1) continue; ans++;
			bool bk = 0;
			for(int j = 0; j <= maxx - i; ++j) f[j + i] |= f[j];
			for(int j = maxx; j >= 1; --j) if(f[j] == 0) {bk = 1; break;}
			if(!bk) break;
		} printf("%d\n", ans);
	}
	return 0;
}

