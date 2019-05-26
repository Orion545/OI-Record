#include <iostream>
#include <cstdio>
using namespace std;

const int MAXN = 100010, INF = 0x7FFFFFFF;

int n, d[MAXN], ans;

void solve(int l, int r){
	if(l >= r){
		if(l == r){
			/*for(int i = 0; i < n; i++)
				cout << d[i] << ' ';
			cout << '\n';
			cout << l << '-' << r << ' ' << d[l] << '\n';
			*/
			ans += d[l];
			d[l] = 0;
		}
		return;
	}
	int mind = INF;
	for(register int i = l; i <= r; i++)
		if(d[i] < mind)
			mind = d[i];
	ans += mind;
	/*for(int i = 0; i < n; i++)
		cout << d[i] << ' ';
	cout << '\n';
	cout << l << '-' << r << ' ' << mind << '\n';
	*/
	int sl = l;
	for(register int i = l; i <= r; i++){
		d[i] -= mind;
		if(!d[i]){
			solve(sl, i-1);
			while(!d[i] && i < r){
				i++;
				d[i] -= mind;
			}
			sl = i;
		}
	}
	solve(sl, r);
}

int main(){
	ios::sync_with_stdio(false), cin.tie(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n;
	for(register int i = 0; i < n; i++){
		cin >> d[i];
	}
	int l = 0, r = n-1;
	while(!d[l]) l++;
	while(!d[r]) r--;
	solve(l, r);
	cout << ans;
	return 0;
}
