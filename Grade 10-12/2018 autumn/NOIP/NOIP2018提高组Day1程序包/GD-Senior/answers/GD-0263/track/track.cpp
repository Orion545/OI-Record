#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define N 50005
int dis[N];
int n, m, i, j, k, a, b, h[N], ua, uab, ans, u[N], tmp, f[10][10], cnt, sum, c[N], q[N*10];
struct AB{
	int a, b, c, n;
	bool operator < (const AB &A) const{
		return c > A.c;
	}
}d[N*2];
void bld(int a, int b, int c){
	d[++cnt].a = a, d[cnt].b = b;
	d[cnt].c = c, d[cnt].n = h[a], h[a] = cnt;
}
int main(){
	freopen("track.in", "r", stdin);
	freopen("track.out", "w", stdout);
	scanf("%d%d", &n, &m);
	ua = uab = 1;
	for(i=1; i<n; i++){
		scanf("%d%d%d", &a, &b, &c[i]);
		sum += c[i];
		if(n<=5) f[a][b] = c[i], f[b][a] = c[i];
		bld(a, b, c[i]), bld(b, a, c[i]);
		if(a!=1) ua = 0;
		if(a+1!=b) uab = 0;
	}
	if(n<=1000&&m==1){
		for(i=1; i<=n; i++){
			memset(q, 0, sizeof(q));
			memset(u, 0, sizeof(u));
			memset(dis, 0, sizeof(dis));
			int tou, wei = 1;
			q[1] = i;
			u[i] = 1;
			for(tou=1; tou<=wei; tou++){
				a = q[tou];
				for(k=h[a]; k; k=d[k].n){
					b = d[k].b;
					if(!u[b]){
						u[b] = 1;
						if(dis[b]<dis[a]+d[k].c){
							dis[b] = dis[a] + d[k].c;
							q[++wei] = b;
						}
					}
				}
			}
			for(j=1; j<=n; j++){
				ans = max(ans, dis[j]);
			}
		}
		printf("%d\n", ans);
		return 0;
	}
	if(ua){
		sort(d+1, d+cnt+1);
		if(m==1){
			printf("%d\n", d[1].c+d[3].c);
			return 0;
		}
	}
	return 0;
}
