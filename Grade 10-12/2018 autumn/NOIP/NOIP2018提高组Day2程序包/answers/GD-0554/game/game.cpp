#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
template<class T> inline void read(T&x)
{
	char c = getchar(); T p = 1, n = 0;
	while(c < '0' || c > '9'){if(c == '-') p = -1; c = getchar();}
	while(c >= '0' && c <= '9'){n = n * 10 + c - '0'; c = getchar();}
	x = p * n;
}
template<class T, class U> inline void read(T&x, U&y){read(x), read(y);}
template<class T, class U, class V> inline void read(T&x, U&y, V&z){read(x), read(y), read(z);}
int n;
const int maxN = 1 << 9, mod = 1e9 + 7;
struct Matrix
{
	int a[maxN][maxN];
	int n, m;
	void clear(){memset(a, 0, sizeof a);}
	Matrix(){clear();}
	Matrix(int nn, int mm){n = nn, m = mm; clear();}
	void identity(){clear(); for(int i = 0; i < n; ++i) a[i][i] = 1;}
	Matrix operator*(const Matrix& rhs)
	{
		Matrix ret(n, rhs.m);
		for(int i = 0; i < n; ++i) for(int j = 0; j < m; ++j) for(int k = 0; k < rhs.m; ++k)
			(ret.a[i][k] += 1ll * a[i][j] * rhs.a[j][k] % mod) %= mod;
		return ret;
	}
	Matrix operator^(int b)
	{
		Matrix ret(n, m);
		ret.identity();
		for(; b; b >>= 1, *this = *this * *this) if(b & 1)
			ret = ret * * this;
		return ret;
	}
} M, A;
void go(int k, int v, int len = 0)
{
	if(len == n + 1) 
	{
		M.a[k][v] = 1;
		return;
	}
	go(k, v | (1 << len - 1), len + 1);
	if(len > 0 && (k >> len & 1 ^ 1)) 
		go(k, v & ~(1 << len - 1), len + 1);
}
int power(int a, int b)
{
	int ret = 1;
	for(; b; b >>= 1, a = 1ll * a * a % mod) if(b & 1)
		ret = 1ll * ret * a % mod;
	return ret;
}
int main()
{
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	int m; read(n, m); if(m < n) swap(n, m);
	int ret = 0;
	if(n == 3)
	{
		ret = 28ll * power(4, m - 2) % mod;
	}
	else
	{
		int N = 1 << n;
		M.n = M.m = N;
		for(int i = 0; i < N; ++i)
		{
			go(i, i);
		}
		M = M ^ (m - 1);
		A.n = N, A.m = 1;
		for(int i = 0; i < N; ++i) A.a[i][0] = 1;
		M = M * A;
		for(int i = 0; i < N; ++i) (ret += M.a[i][0]) %= mod;
	}
	printf("%d\n", ret);
	return 0;
}
