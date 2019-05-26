#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
const int N = 2e3 + 10;
int n,m;
char type[10];
ll p[N],f[N][2];
int la,lb,sa,sb;
int final[N],to[N*2],nex[N*2],tot;
void link(int x,int y){
	to[++tot] = y,nex[tot] = final[x],final[x]=tot;
}

void dp(int x,int fa) {
	f[x][1] = p[x];
	f[x][0] = 0;
	for (int i = final[x]; i; i=nex[i]) {
		int y = to[i]; if (y != fa) {
			dp(y,x);
			f[x][1]+=min(f[y][0],f[y][1]);
			f[x][0]+=f[y][1];
		}
	}
	if (la == x) f[x][1-sa] = f[0][0];
	if (lb == x) f[x][1-sb] = f[0][0];
}

int main() {
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	cin>>n>>m>>type;
	for (int i = 1; i <= n; i++) scanf("%lld",&p[i]);
	for (int i = 1; i < n; i++) {
		int u,v; scanf("%d %d\n",&u,&v);
		link(u,v), link(v,u);
	}
	for (int i = 1; i <= m; i++) {
		scanf("%d %d %d %d",&la,&sa,&lb,&sb);
		for (int j = 0; j <= n; j++) f[j][0] = f[j][1] = 1e13;
		dp(1,0);
		ll rz = min(f[1][0],f[1][1]);
		if (rz>=f[0][0]) printf("-1\n"); else printf("%lld\n",rz);
	}
}
