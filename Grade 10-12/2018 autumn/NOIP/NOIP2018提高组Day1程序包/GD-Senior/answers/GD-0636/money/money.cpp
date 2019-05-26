#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

const int MAXN = 101, MAXA = 25001;

int a[MAXN], n, maxa, blist[MAXA], blen;
bool b[MAXA];

int main(){
	ios::sync_with_stdio(false), cin.tie(0);
	freopen("money.in", "r", stdin);
	freopen("money.out", "w", stdout);
	int t, ans, cura, tmp, len;
	cin >> t;
	while(t--){
		cin >> n;
		ans = n;
		for(register int i = 0; i < n; i++){
			cin >> a[i];
			if(a[i] > maxa) maxa = a[i];
		}
		sort(a, a + n);
		cura = a[0];
		if(cura == 1){
			cout << '1' << '\n';
			continue;
		}
		while(cura <= maxa){
			b[cura] = true;
			blist[blen++] = cura;
			cura += a[0];
		}
		for(register int i = 1; i < n; i++){
			if(b[a[i]]){
				ans--;
				continue;
			}
			len = blen;
			cura = a[i];
			while(cura <= maxa){
				b[cura] = true;
				blist[blen++] = cura;
				for(register int j = 0; j < len; j++){
					tmp = cura + blist[j];
					if(tmp > maxa) break;
					if(!b[tmp]){
						b[tmp] = true;
						blist[blen++] = tmp;
					}
				}
				cura += a[i];
			}
			sort(blist, blist + blen);
		}
		cout << ans << '\n';
		if(t){
			memset(b, false, sizeof(bool)*(maxa + 1));
			blen = 0;
			maxa = 0;
		}
	}
	return 0;
}
