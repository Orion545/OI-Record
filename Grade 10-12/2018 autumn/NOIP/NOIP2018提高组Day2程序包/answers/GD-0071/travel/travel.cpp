#include<cstdio>
#include<algorithm>
#define fo(i, x, y) for(int i = x; i <= y; i ++)
using namespace std;

const int N = 5005;

int n, m, b[N][N], x, y;
int bz[N], d[N], bd[N];
int q[N * 2], bq[N];

int dg(int x, int la) {
	d[++ d[0]] = x; bd[x] = d[0];
	fo(i, 1, b[x][0]) {
		int y = b[x][i];
		if(y == la) continue;
		if(bd[y]) {
			fo(j, bd[y], d[0]) q[++ q[0]] = d[j];	
			return 1;
		} else {
			if(dg(y, x)) return 1;
		}
	}
	d[0] --; bd[x] = 0;
	return 0;
}

int g1, g2, ans[N];

void dc(int x) {
	bz[x] = 1; d[++ d[0]] = x;
	fo(i, 1, b[x][0]) {
		int y = b[x][i];
		if(x == g1 && y == g2) continue;
		if(x == g2 && y == g1) continue;
		if(!bz[y]) dc(y);
	}
}

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	scanf("%d %d", &n, &m);	
	fo(i, 1, m) {
		scanf("%d %d", &x, &y);
		b[x][++ b[x][0]] = y;
		b[y][++ b[y][0]] = x;
	}
	fo(i, 1, n) sort(b[i] + 1, b[i] + b[i][0] + 1);
	dg(1, 0);
	fo(i, 1, n) ans[i] = n;
//	fo(i, 1, q[0]) printf("%d\n", q[i]);
	fo(i, 1, q[0]) {
		g1 = q[i], g2 = i == q[0] ? q[1] : q[i + 1];
		d[0] = 0; fo(j, 1, n) bz[j] = 0;
		dc(1);
		int pd = 0;
		fo(j, 1, n) {
			if(d[j] < ans[j]) {
				pd = 1; break;
			}
			if(d[j] > ans[j]) {
				pd = 0; break;
			}
		}
		if(pd) fo(j, 1, n) ans[j] = d[j];
	}
	if(!q[0]) {
		d[0] = 0; dc(1); fo(i, 1, n) ans[i] = d[i];
	}
	fo(i, 1, n) printf("%d ", ans[i]);
}
