#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;
const int Maxn = 5010;
vector <int> vec[Maxn];
int n, m;
int ans[Maxn];
int ret[Maxn], retl;
int banx, bany;
void dfs(int x, int fa) {
	ret[++retl] = x;
	for(int i = 0; i < vec[x].size(); i++){
		int y = vec[x][i];
		if(y == fa || (x == banx && y == bany) || (y == banx && x == bany) ) continue;
		dfs(y, x);
	}
}
int sta[Maxn], tp, dfn[Maxn], id; bool insta[Maxn];
int cir[Maxn], cl;
void dfss(int x, int fa) {
	dfn[x] = ++id; sta[++tp] = x; insta[x] = true;
	for(int i = 0; i < vec[x].size(); i++){
		int y = vec[x][i];
		if(y == fa) continue;
		if(!dfn[y]) dfss(y, x);
		else if(insta[y]){
			int j = tp;
			do {
				cir[++cl] = sta[j];
				j--;
			} while(sta[j+1] != y);
		}
	}
	tp--; insta[x] = false;
}
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int i, j, k;
	scanf("%d%d", &n, &m);
	for(i = 1; i <= m; i++){
		int x, y;
		scanf("%d%d", &x, &y);
		vec[x].push_back(y);
		vec[y].push_back(x);
	}
	for(i = 1; i <= n; i++) sort(vec[i].begin(), vec[i].end());
	if(m == n-1){
		dfs(1, 0);
		for(i = 1; i <= n; i++) printf("%d%c", ret[i], " \n"[i==n]);
	} else {
		dfss(1, 0);
		ans[1] = n+1;
		for(i = 1; i <= cl; i++){
			int ni = i%cl+1;
			retl = 0;
			banx = cir[i]; bany = cir[ni];
			dfs(1, 0);
			bool bk;
			for(j = 1; j <= n; j++){
				if(ret[j] < ans[j]){ bk = true; break; }
				if(ret[j] > ans[j]){ bk = false; break; }
			}
			if(bk == true) for(j = 1; j <= n; j++) ans[j] = ret[j]; 
		}
		for(i = 1; i <= n; i++) printf("%d%c", ans[i], " \n"[i==n]);
	}
	return 0;
}
