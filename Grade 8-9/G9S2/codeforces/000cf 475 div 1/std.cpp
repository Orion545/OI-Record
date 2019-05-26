#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);++(i))
#define down(i,a,b) for(int (i)=(a);(i)>=(b);--(i))
#define gi(x) ((x)=F())
#define gii(x,y) (gi(x),gi(y))
#define giii(x,y,z) (gii(x,y),gi(z))
int F(){
	char ch;int x,a;
	while(ch=getchar(),(ch<'0'||ch>'9')&&ch!='-');
	if(ch=='-')ch=getchar(),a=-1;else a=1;x=ch-'0';
	while(ch=getchar(),ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+ch-'0';
	return a*x;
}

const int mod = 1e9 + 9;

int n, a, b, k; 

char s[100010];

long long t[100010];

int fpow(int a, int x) {
	int ret = 1;
	for (; x; x >>= 1) {
		if (x & 1) ret = 1ll * ret * a % mod;
		a = 1ll * a * a % mod;
	}
	return ret;
}

int get(int a, int n, int x) {
	if (x == 1) return 1ll * a * n % mod;
	return (fpow(x, n) - 1ll) * fpow(x - 1, mod - 2) % mod;
}

int main() {
	gii(n, a), gii(b, k);
	swap(a, b);
	scanf("%s", s);
	for (int i = 0; i < k; ++i)
		t[i] = s[i] == '+' ? 1 : -1;
	int x = 0;
	for (int i = 0; i < k; ++i)
		x = (x + t[i] * fpow(a, i) * fpow(b, n - i)) % mod;
	int first = 1, cnt = n / k, sub = 1ll * fpow(a, k) * fpow(fpow(b, k), mod - 2) % mod;
	int v = get(first, cnt, sub);
	int ans = 1ll * v * x % mod, ss = (n / k) * k;
	//cerr << ans << endl;
	for (int i = 0; i <= (n % k); ++i) {
		ans = (ans + t[i] * fpow(a, ss + i) * fpow(b, n - ss - i)) % mod;
	}
	if (ans < 0) ans += mod;
	printf("%d\n", ans);
	return 0;
}

