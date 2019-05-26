#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <bitset>
using namespace std;
const int Maxn = 110;
const int Maxm = 25010;
void read(int &x) {
	char ch = getchar(); x = 0;
	for(; ch < '0' || ch > '9'; ch = getchar());
	for(; ch >= '0' && ch <= '9'; ch = getchar()) x = x*10+ch-'0';
}
bool f[Maxm];
int a[Maxn], n;
int main() {
	freopen("money.in", "r", stdin);
	freopen("money.out", "w", stdout);
	int i, j, k;
	int T;
	read(T);
	while(T--){
		read(n);
		for(i = 1; i <= n; i++) read(a[i]);
		for(i = 1; i <= 25000; i++) f[i] = 0;
		f[0] = 1;
		sort(a+1, a+n+1);
		int ans = 0;
		for(i = 1; i <= n; i++){
			if(f[a[i]] == 1) continue;
			ans++;
			for(j = a[i]; j <= 25000; j++) f[j] |= f[j-a[i]];
		}
		printf("%d\n", ans);
	}
	return 0;
}
