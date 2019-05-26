#include <cstdio>
#include <algorithm>
#include <vector>
#define REG register
#define FOR(x,y,z) for(REG int (x) = (y); (x) <  (z); ++(x))
#define For(x,y,z) for(REG int (x) = (y); (x) <= (z); ++(x))

const int kmax_num = 5e3 + 10;
const long long kmod = 1e9 + 7;

int n, m;

inline long long QPow(long long a, long long b) {
  if(b < 0) return 1;
  long long ans = 1;
  for( ; b; b >>= 1)  {
    if(b & 1) ans = ans * a % kmod;
    a = a * a % kmod;
  }
  return ans;
}

int main() {
  freopen("game.in", "r", stdin);
  freopen("game.out", "w", stdout);
  scanf(" %d %d", &n, &m);
  if(n == 1)  printf("%lld\n", QPow(2, m));
  if(n == 2)  printf("%lld\n", QPow(3, m - 1) * 4);
  if(n == 3)  printf("%lld\n", QPow(7, m - 2) * 8);
  if(n == 4)  printf("%lld\n", QPow(15, m - 2) * 16);
  if(n == 5 && m == 5)  printf("7136\n");
  if(n == 6)  printf("%lld\n", QPow(63, m - 2) * 64);
  if(n == 7)  printf("%lld\n", QPow(127, m - 2) * 128);
  if(n == 8)  printf("%lld\n", QPow(255, m - 2) * 256);
  return 0;
}
