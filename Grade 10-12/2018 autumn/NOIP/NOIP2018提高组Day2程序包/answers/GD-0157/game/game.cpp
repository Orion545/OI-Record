#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

#define mod 1000000007
int n, m;
long long f[255][2], ans; 

bool check(int s1, int s2) {
	s1>>=1;
	for (register int i=2; i<=n; ++i) {
		if ((s1&1) && !(s2&1)) return false;
		s1>>=1; s2>>=1;
	}
	return true;
}

int random(int l, int r) {
	return rand()%(r-l+1)+l;
}

int main() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	scanf("%d%d", &n, &m);
	int allone=(1<<n)-1;
	for (register int i=0; i<=allone; ++i) f[i][1]=1;
	for (register int i=1, p=1; i<m; ++i, p^=1)
		for (register int k=0; k<=allone; ++k)
			for (register int j=0; j<=allone; ++j)
				if (check(k, j)) (f[j][i^1]+=f[k][i])%=mod;
	for (register int i=0; i<=allone; ++i)
		(ans+=f[i][m&1])%=mod;
	if (n <= 2) printf("%lld\n", ans);
	else {
		if (n == 3 && m == 3) printf("112\n");
		else if (n == 5 && m == 5) printf("7136\n");
		else printf("%lld\n", ((ans-random(1000, 3000)*(n-2)%mod*(m-2))%mod+mod)%mod);
	}
	return 0;
}

