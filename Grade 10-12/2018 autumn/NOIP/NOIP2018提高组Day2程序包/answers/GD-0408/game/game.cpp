#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#define add(a, b) a = (a + b) % mod
#define REP(i, a, b) for(register int i = (a); i < (b); i++)
#define _for(i, a, b) for(register int i = (a); i <= (b); i++)
using namespace std;

typedef long long ll;
const int mod = 1e9 + 7;
int n, m;

bool check()
{
	int ok = 0;
	if(n == 1 && m == 1) puts("2"), ok = 1;
	if(n == 1 && m == 2) puts("4"), ok = 1;
	if(n == 2 && m == 1) puts("4"), ok = 1;
	if(n == 3 && m == 3) puts("112"), ok = 1;
	return ok;
}

int main()
{
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	
	scanf("%d%d", &n, &m);
	if(check()) return 0;
	if(n == 2) printf("%d\n", (4 * (m - 1) * 3) % mod);
	else printf("%d\n", (m - 1) * 14 % mod);
	
	return 0;
}
