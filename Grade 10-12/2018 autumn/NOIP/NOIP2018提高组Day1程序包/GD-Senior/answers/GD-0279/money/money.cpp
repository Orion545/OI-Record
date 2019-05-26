#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#define MAXN 111
#define INF 0x3f3f3f3f
using namespace std;
int T;
int n, a[MAXN];
int flag[66666];
int main(){
	freopen("money.in", "r", stdin);
	freopen("money.out", "w", stdout);
	scanf("%d", &T);
	while(T--){
		memset(flag, 0, sizeof flag);
		scanf("%d", &n);
		int maxn = -1, minn = INF;
		for(int i = 1; i <= n; i++) scanf("%d", &a[i]), flag[a[i]] = 2, minn = min(minn, a[i]), maxn = max(maxn, a[i]);
		sort(a + 1, a + 1 + n);
		for(int i = minn; i <= maxn; i++){
			if(flag[i])	for(int j = 1; j <= n; j++) flag[i + a[j]] = 1;
		}
		int ans = 0;
		for(int i = 1; i <= n; i++)	if(flag[a[i]] == 2) ans++;
		printf("%d\n", ans);
	}
	fclose(stdin);
	fclose(stdout);
}
