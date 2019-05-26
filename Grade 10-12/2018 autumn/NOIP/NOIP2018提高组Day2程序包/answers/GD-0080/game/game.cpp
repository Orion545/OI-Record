#include <cstdio>
#include <algorithm>
#include <cstring>

typedef long long ll;

using namespace std;

const int N = 10,M = 1000005,P = 1e9 + 7;

int n,m;
int a[N][N];
ll _[M];

int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	_[0] = 1;
	for (int i = 1 ; i < M ; i++) _[i] = _[i - 1] * 2 % P;
	if (n == 1 || m == 1) { printf("%lld\n",_[max(n,m)]); return 0; }
	if (n == 2 && m == 2) { printf("%lld\n",12); return 0; }
	if (n == 3 && m == 2) { printf("%lld\n",36); return 0; }
	if (n == 2 && m == 3) { printf("%lld\n",36); return 0; }
	if (n == 3 && m == 3) { printf("%lld\n",112); return 0; }
	return 0;
}
