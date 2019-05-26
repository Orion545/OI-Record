#include<bits/stdc++.h>

using namespace std;

#define fore(i, l, r) for(int i = int(l); i < int(r); i++)

#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9;

const int N = 100 * 1000 + 555;

int n[2], y[2];
int x[2][N];

inline bool read() {
	fore(k, 0, 2) {
		if(!(cin >> n[k] >> y[k]))
			return false;
		fore(i, 0, n[k])
			assert(scanf("%d", &x[k][i]) == 1);
	}
	return true;
}

inline void solve() {
	int ans = 2;
	for(int dx = 1; dx < int(1e9); dx *= 2) {
		int mod = 2 * dx;
		map<int, int> cnt;
		
		int add[2] = {0, dx};
		fore(k, 0, 2) {
			fore(i, 0, n[k])
				cnt[(x[k][i] + add[k]) & (mod - 1)]++;
		}
		
		for(auto curAns : cnt)
			ans = max(ans, curAns.second);
	}
	cout << ans << endl;
}

int main() {
	if(read()) {
		solve();
	}
	return 0;
}
