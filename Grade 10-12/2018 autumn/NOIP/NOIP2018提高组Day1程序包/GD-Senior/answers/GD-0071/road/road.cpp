#include<cstdio>
#define fo(i, x, y) for(int i = x; i <= y; i ++)
#define mm(x, y) (a[x] < a[y] ? (x) : (y))
using namespace std;

const int N = 2e5 + 5;

int a2[17], lg[N];
int n, a[N], f[17][N], ans;

int qmin(int x, int y) {
	int l = lg[y - x + 1];
	return mm(f[l][x], f[l][y - a2[l] + 1]);
}

void dg(int x, int y, int k) {
	if(x > y) return;
	int p = qmin(x, y);	ans += a[p] - k;
	dg(x, p - 1, a[p]); dg(p + 1, y, a[p]);
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	a2[0] = 1; fo(i, 1, 16) a2[i] = a2[i - 1] * 2;
	fo(i, 1, 16) lg[a2[i]] ++;
	fo(i, 1, 100000) lg[i] += lg[i - 1]; 
	scanf("%d", &n);
	fo(i, 1, n) scanf("%d", &a[i]);
	fo(i, 1, n) f[0][i]	 = i;
	fo(j, 1, 16) fo(i, 1, n)
		if(i + a2[j - 1] > n) f[j][i] = f[j - 1][i]; else
		f[j][i] = mm(f[j - 1][i], f[j - 1][i + a2[j - 1]]);
	dg(1, n, 0);
	printf("%d", ans);
	return 0;
}
