#include <cstdio>
#include <cctype>
#include <algorithm>
#include <queue>
#define REG register
#define FOR(x,y,z) for(REG int (x) = (y); (x) <  (z); ++x)
#define For(x,y,z) for(REG int (x) = (y); (x) <= (z); ++x)

const int kmax_num = 1e5 + 10;

int n;
int s[kmax_num * 2];
long long f[kmax_num * 2];

long long ans;

inline bool Check() {
  For(i,1,n)  if(s[i]) return false;
  return true;
}

inline void Work() {
  int l = 0;
  while(!s[l])  ++l;
  int r = l;
  while(s[r + 1]) ++r;
  For(i,l,r)  --s[i];
  return ;
}

int main() {
  freopen("road.in", "r", stdin);
  freopen("road.out", "w", stdout);
  scanf(" %d", &n);
  if(n <= 1000) {
    For(i,1,n)  scanf(" %d", &s[i]), s[i + n] = s[i];
    while(!Check()) {
      Work();
      ++ans;
    }
    printf("%lld\n", ans);
  }
  else  {
    ans = 1ll << 50;
    For(i,1,n)  scanf(" %d", &s[i]), s[i + n] = s[i];
    
    int nn = n * 2;
    For(i,1,nn)  {
      f[i] = f[i - 1];
      if(s[i] <= s[i - 1])  f[i] += s[i - 1] - s[i];
    }
    
    For(i,1,n)  ans = std::min(ans, f[i + n] - f[i]);
    printf("%lld\n", ans + s[1]);
  }
  return 0;
}   
