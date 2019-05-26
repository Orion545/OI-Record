#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int a[105], f[25005];
int n, m, i, j, k, ans, t, maxx, cnt, min1, min2, tmp;
int ok(int p, int q, int x){
	for(int i=0; i<=a[q]; i++){
		for(int j=0; j<=a[p]; j++){
			if(i*a[p]+j*a[q]==x) return 1;
		}
	}
	return 0;
}
int okk(int x){
	for(int i=0; i<=min2; i++){
		for(int j=0; j<=min1; j++){
			if(min1*i+min2*j==x) return 1;
		}
	}
	return 0;
}
int main(){
	freopen("money.in", "r", stdin);
	freopen("money.out", "w", stdout);
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		memset(f, 0, sizeof(f));
		memset(a, 0, sizeof(a));
		for(i=1; i<=n; i++){
			scanf("%d", &a[i]);
			f[a[i]] = 1;
			maxx = max(maxx, a[i]);
		}
		sort(a+1, a+n+1);
		for(i=1; i<=n; i++){
			for(j=2; a[i]*j<=maxx; j++){
				f[a[i]*j] = 0;
			}
		}
		cnt = 0;
		min1 = min2 = 0;
		for(i=1; i<=maxx; i++){
			if(f[i]){
				cnt++;
				if(!min1) min1 = i;
				if(min1!=i&&!min2) min2 = i;
			}
		}
		if(cnt<=2){
			printf("%d\n", cnt);
			continue;
		}
		if(cnt==3){
			for(i=maxx; i>=1; i--) if(f[i]){
				tmp = i;
				break;
			}
			if(okk(tmp)){
				printf("2\n");
			}
			else printf("3\n");
			continue;
		}
		ans = 1e9;
		for(i=1; i<=n; i++){
			for(j=i+1; j<=n; j++){
				for(k=1; k<=n; k++){
					f[a[k]] = 1;
				}
				cnt = 0;
				for(k=a[j]+1; k<=maxx; k++){
					if(!f[k]) continue;
					if(ok(i, j, k)){
						f[k] = 0;
					}
				}
				for(k=1; k<=maxx; k++){
					if(f[k]) cnt++;
				}
				ans = min(ans, cnt);
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}
