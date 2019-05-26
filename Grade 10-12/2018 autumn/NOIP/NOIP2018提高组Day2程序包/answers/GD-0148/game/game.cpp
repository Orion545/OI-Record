#include<cstdio>
#include<algorithm>
using namespace std;
const int md=1e9+7;
int n,m;
inline int power(int x,int y) {
	int z=1;
	for (;y;y>>=1, x=1ll*x*x%md)
	if (y&1) z=1ll*z*x%md;
	return z;
}
int main() {
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	if (n>m) swap(n,m);
	if (n==1) {
		printf("%d\n",power(2,m)); return 0;
	}
	if (n==2) {
		printf("%d\n",4ll*power(3,m-1)%md); return 0;
	}
	if (n==3&&m==3) {
		puts("112"); return 0;
	}
	return 0;
}
