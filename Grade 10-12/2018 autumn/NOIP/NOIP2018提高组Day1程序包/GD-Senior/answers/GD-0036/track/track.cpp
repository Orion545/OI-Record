#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int Maxn = 50010;
void read(int &x) {
	char ch = getchar(); x = 0;
	for(; ch < '0' || ch > '9'; ch = getchar());
	for(; ch >= '0' && ch <= '9'; ch = getchar()) x = x*10+ch-'0';
}
int f[Maxn], g[Maxn];
struct node {
	int y, next, d;
}a[Maxn<<1]; int first[Maxn], len;
void ins(int x, int y, int d) {
	len++;
	a[len].y = y; a[len].d = d;
	a[len].next = first[x]; first[x] = len;
}
int n, m;
int b[Maxn], bl, ffa[Maxn]; bool bo[Maxn];
int ff(int x) { return ffa[x] == x ? x : ffa[x] = ff(ffa[x]); }
void dfs(int x, int fa, int mid) {
	f[x] = 0;
	for(int k = first[x]; k; k = a[k].next){
		int y = a[k].y;
		if(y == fa) continue;
		dfs(y, x, mid);
		f[x] += f[y];
	}
	bl = 0;
	for(int k = first[x]; k; k = a[k].next){
		int y = a[k].y;
		if(y == fa) continue;
		if(g[y]+a[k].d >= mid) f[x]++;
		else {
			b[++bl] = g[y]+a[k].d;
			ffa[bl] = bl;
			bo[bl] = false;
		}
	}
	sort(b+1, b+bl+1);
	ffa[bl+1] = bl+1;
	int i, j = bl+1;
	for(i = 1; i <= bl; i++){
		while(j > 1 && b[i]+b[j-1] >= mid) j--;
		if(ffa[i] != i) continue;
		ffa[i] = i+1;
		int fj = ff(j);
		if(fj <= bl){
			ffa[fj] = fj+1;
			bo[i] = bo[fj] = true;
			f[x]++;
		}
	}
	for(i = bl; i >= 1; i--) if(!bo[i]) break;
	g[x] = b[i];
}
int main() {
	freopen("track.in", "r", stdin);
	freopen("track.out", "w", stdout);
	int i, j, k;
	read(n); read(m);
	int L = 1, R = 0, ret;
	for(i = 1; i < n; i++){
		int x, y, d;
		read(x); read(y); read(d);
		ins(x, y, d); ins(y, x, d);
		R += d;
	}
	while(L <= R){
		int mid = L+R>>1;
		dfs(1, 0, mid);
		if(f[1] >= m) ret = mid, L = mid+1;
		else R = mid-1;
	}
	printf("%d\n", ret);
	return 0;
}
