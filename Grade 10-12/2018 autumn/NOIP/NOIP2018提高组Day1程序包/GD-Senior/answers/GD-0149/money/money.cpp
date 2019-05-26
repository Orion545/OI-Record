#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#define REG register
#define FOR(x,y,z) for(REG int (x) = (y); (x) <  (z); ++x)
#define For(x,y,z) for(REG int (x) = (y); (x) <= (z); ++x)

const int kmax_num = 2.5e4 + 10;

int t, n;
int s[kmax_num];

int tmp[kmax_num];
int ans;

int main() {
  freopen("money.in", "r", stdin);
  freopen("money.out", "w", stdout);
  scanf(" %d", &t);

  while(t--) {
    scanf(" %d", &n);
    For(i,1,n)  scanf(" %d", &s[i]);
    std::sort(s + 1, s + n + 1);
    
    ans = 0;
    memset(tmp, 0, sizeof(tmp));
    For(i,1,n)  {
      ans += !(tmp[s[i]] == s[i]);
      For(h,0,s[n]) {
        if(h >= s[i]) tmp[h] = std::max(tmp[h], tmp[h - s[i]] + s[i]);
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}   
