#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int mo = 1e9 + 7, M = 1e6 + 10;
typedef long long ll;
int n,m;
ll f[2][256],can[256][256],o;
int ful;
int co[20][20],ans;

int calc(int x) {
	int nx = 0, ny = 0;
	int ret = 0;
	for (int i = 1; i <= n + m - 2; i++){
		ret += co[nx][ny];
		if (x&(1<<n+m-2-i)) ny++; else nx++;
	}
	return ret+co[n-1][m-1];
}

int path[100000];
void getallpath(int x,int v,int lx,int ly){
	if (x>n+m-2){
		path[++path[0]] = v;
		return;
	}
	if (lx) getallpath(x+1,v,lx-1,ly);
	if (ly) getallpath(x+1,v+(1<<n+m-2-x),lx,ly-1);
}

bool ok(int i) {
	for (int i = 1; i <= path[0]; i++) {
		for (int j = 1; j <= path[0]; j++) {
			if (path[i]>path[j]){
				if (calc(path[i]) <= calc(path[j])) continue;
				else return 0;
			}
		}
	}
	return 1;
}

int main() {
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n>>m; ful = 1 << n;
	if (n * m <= 15) {
		getallpath(1,0,n-1,m-1);
		for (int i = 0; i < (1<<n*m); i++){
			for (int x = 0; x < n; x++) {
				for (int y = 0; y < m; y++) {
					co[x][y] = (i>>x*m+y)&1;
				}
			}
			if (ok(i)) ans++;
		}
		cout<<ans<<endl;
		return 0;
	}
	for (int i = 0; i < ful; i++)
		for (int j = 0; j < ful; j++) {
			can[i][j] = 1;
			for (int k = 0; k < n - 1; k++) {
				int vi = (i >> k + 1) & 1, vj = (j >> k) & 1;
				if (vi < vj) {
					can[i][j] = 0;
					break;
				}
			}
		}
	
	for (int i = 0; i < ful; i++) f[o][i] = 1;
	for (int i = 2; i <= m; i++) {
		memset(f[1-o],0,sizeof f[1-o]);
		for (int a = 0; a < ful; a++) {
			for (int b = 0; b < ful; b++) if (can[a][b]){
				f[1-o][b] = (f[1-o][b] + f[o][a]) % mo;
			}
		}
		o=1-o;
	}
	
	ll ans = 0;
	for (int i = 0; i < ful; i++) ans = (ans + f[o][i]) % mo;
	cout<<(ans + mo) % mo<<endl;
}
