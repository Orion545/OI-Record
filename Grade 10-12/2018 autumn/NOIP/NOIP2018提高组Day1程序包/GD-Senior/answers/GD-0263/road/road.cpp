#include <cstdio>
#include <algorithm>
using namespace std;
#define N 100005
int n, m, i, j, k, d[N], sta[N], top, ans;
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d", &n);
	for(i=1; i<=n; i++){
		scanf("%d", &d[i]);
	}
	for(i=1; i<=n; i++){
		if(d[i] >= sta[top]) sta[++top] = d[i];
		else{
			ans += (sta[top]-d[i]);
			while(d[i]<sta[top]) top--;
			sta[++top] = d[i];
		}
	}
	ans += sta[top];
	printf("%d\n", ans);
	return 0;
}
