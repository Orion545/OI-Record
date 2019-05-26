#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;
int T, n, a[105], maxi, tmp, ans;
bool f[2500005], u;
int main(){
	freopen("money.in", "r", stdin);
	freopen("money.out", "w", stdout);
	scanf("%d", &T);
	while(T--){
		memset(f, 0, sizeof(f));
		ans = 0;
		maxi = 0;
		scanf("%d", &n);
		for(int i = 1; i <= n; i++){
			scanf("%d", &a[i]);
		}
		f[0] = 1;
		sort(a+1, a+n+1);
		tmp = n*a[n];
		for(int i = 1; i <= n; i++){
			u = 0;
			for(int j = 0; j <= tmp-a[i]; j++){
				if(f[j])
					if(!f[j+a[i]]){
						u = 1;
						f[j+a[i]] = 1;
					}
			} 
			ans += u;
		}
		printf("%d\n", ans);
	}
	return 0;
}
