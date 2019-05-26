#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 100005
int n, m, i, j, k, a, b, h[N], fa[N], u[N], x, y, w[N], ans, f[N][2];
char s[5];
struct AB{
	int a, b, n;
}d[N*2];
void bld(int a, int b){
	d[++j].a = a, d[j].b = b;
	d[j].n = h[a], h[a] = j;
}
void dfs(int x){
	int b, i;
	u[x] = 1;
	for(i=h[x]; i; i=d[i].n){
		b = d[i].b;
		if(!u[b]){
			fa[b] = x;
			dfs(b);
		}
	}
}
int main(){
	freopen("defense.in", "r", stdin);
	freopen("defense.out", "w", stdout);
	scanf("%d%d%s", &n, &m, s);
	for(i=1; i<=n; i++) scanf("%d", &w[i]);
	for(i=1; i<n; i++){
		scanf("%d%d", &a, &b);
		bld(a, b), bld(b, a);
	}
	fa[1] = 0;
	dfs(1);
	if(n<=2000&&m<=2000){
		while(m--){
			scanf("%d%d%d%d", &a, &x, &b, &y);
			if(s[0]=='A'){
				memset(f, 127, sizeof(f));
				f[1][1] = w[1];
				f[1][0] = w[2];
				for(i=2; i<=n; i++){
					if(i==a){
						if(x==1) f[i][1] += w[i];
						else f[i+1][1] += w[i+1];
					}
					if(i==b){
						if(x==1) f[i][1] += w[i];
						else f[i][0] = min(f[i-1][1], f[i-1][0]), f[i+1][1] += w[i+1];
					}
					f[i][0] = f[i-1][1];
					f[i][1] = min(f[i-1][0]+f[i-2][1]+w[i], min(f[i-2][0]+f[i-1][1]+w[i], f[i-1][0]+f[i-2][0]+w[i]));
				}
				for(i=1; i<n; i++){
					if(f[i][0]==f[i+1][0]){
						printf("-1\n");
						y = -1;
					}
				}
				if(y!=-1) printf("%d\n", min(f[n][1], f[n][0]));
			}
		}
	}
	return 0;
}
