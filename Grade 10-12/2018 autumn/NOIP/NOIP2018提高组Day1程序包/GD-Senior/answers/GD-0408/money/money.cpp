#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#define REP(i, a, b) for(register int i = (a); i < (b); i++)
#define _for(i, a, b) for(register int i = (a); i <= (b); i++)
using namespace std;

const int N = 1e2 + 10;
int a[N], vis[N], ans, n;

int gcd(int a, int b) { return !b ? a : gcd(b, a % b); }

bool dfs(int i, int sum, int num)
{
	if(i > ans) return false;
	if(sum == num) return true;
	_for(j, 0, 25000)
	{
		if(sum + a[i] * j > num) break;
		if(dfs(i + 1, sum + a[i] * j, num)) return true;
	}
	return false;
}

bool check(int ans)
{
	_for(i, ans + 1, n)
		if(!dfs(1, 0, a[i]))
			return false;
	return true;
}

void solve2()
{
	if(a[1] == a[2]) puts("1");
	else puts("2");
}

void exgcd(int a, int b, int& d, int& x, int& y)
{
	if(!b) { d = a; x = 1; y = 0; return; }
	else exgcd(b, a % b, d, y, x), y -= x * (a / b);
}

bool judge(int a, int b, int k)
{
	int d, x, y;
	exgcd(a, b, d, x, y);
	if(k % d) return false;
	return (x >= 0 && y >= 0);
}

void solve3()
{
	if(a[2] % a[1] == 0 && a[3] % a[1] == 0) puts("1");
	else if(judge(a[1], a[2], a[3])) puts("2");
	else puts("3");
}

void solve4()
{
	if(a[3] % a[1] == 0 && a[2] % a[1] == 0 && a[4] % a[1] == 0) puts("1");
	else if(judge(a[1], a[2], a[3]) && judge(a[1], a[2], a[4])) puts("2");
	else puts("3");
}

void solve5()
{
	if(a[3] % a[1] == 0 && a[2] % a[1] == 0 && a[3] % a[1] == 0) puts("1");
	else if(judge(a[1], a[2], a[3]) && judge(a[1], a[2], a[4])) puts("2");
	else puts("3");
}

int main()
{
	freopen("money.in", "r", stdin);
	freopen("money.out", "w", stdout);
	
	int T;
	scanf("%d", &T);
	
	while(T--)
	{
		scanf("%d", &n);
		sort(a + 1, a + n + 1);
		if(n == 2) solve2();
		else if(n == 3) solve3();
		else if(n == 4) solve4();
		else if(n == 5) solve5();
		else
		{
			_for(i, 1, n) scanf("%d", &a[i]);
			for(ans = 1; !check(ans); ans++);
			printf("%d\n", ans);
		}
	}

	return 0;
}
