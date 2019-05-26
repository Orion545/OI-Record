#include <bits/stdc++.h>
#define P 1000000007
using namespace std;
typedef long long ll;

int n, m, ans = 0, a[10][10];
vector<ll> v;
bool check(int x,int y) {
	for (int i=1;x+i<=n && y+i<=m;i++) if (a[x+i][y] > a[x][y+i]) return 1;
	else if (a[x+i][y] < a[x][y+i]) return 0;
	return 1;
}
bool check() {
	for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) if (!check(i,j)) return 0;
	return 1;
}

void DFS(int x,int y,ll val) {
	if (x == n && y == m) {
		v.push_back(val);
		return ;
	}
	if (y != m) DFS(x,y+1,(val<<1)|a[x][y]);
	if (x != n) DFS(x+1,y,(val<<1)|a[x][y]);
}

bool _() {
	v.clear();
	DFS(1,1,0);
	//for (int i=0;i<v.size();i++) printf("%d\n",v[i]);
	for (int i=0;i<v.size()-1;i++) {
		if (v[i] > v[i+1]) return 0;
	}
	return 1;
}
int cnt = 0;
void dfs(int x,int y) {
	if (x == n+1) {
		if (check()) {
			++cnt;
			if (_()) {
				++ans;
			}
		}
		return ;
	}
	if (x==1 || y==m || a[x-1][y+1] != 1) {
		a[x][y] = 0;
		if (y == m) dfs(x+1,1);  else dfs(x,y+1);
	}
	a[x][y] = 1;
	if (y == m) dfs(x+1,1);  else dfs(x,y+1);
}

inline ll qpow(ll a,int x) {
	ll r = 1;
	for (;x;x>>=1) {
		if (x & 1) r = r * a % P;
		a = a * a % P;
	} return r;
}

int main() {
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	if (n > m) swap(n,m);
	
	if (n == 1) {
		cout << qpow(2,m);
		return 0;
	}
	if (n == 2) {
		cout << qpow(3,m-1) * 4 % P;
		return 0;
	}
	if (n == 3) {
		cout << qpow(3,m-n) * 112 % P;
		return 0;
	}
	if (n == 4) {
		if (m == 4) cout << 912;
		else cout << qpow(3,m-n) * 896 % P;
		return 0;
	}
	if (n == 5) {
		if (m == 5) cout << 7136;
		else cout << qpow(3,m-n) * 7104 % P;
		return 0;
	}
	dfs(1,1);
	cout << ans << endl;
	return 0;
}
