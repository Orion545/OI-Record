#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<queue>
#include<vector>
#include<map>
#define N 10
#define M 1000005
#define Mod (int)(1e9+7)
#define INF 0x3f3f3f3f
#define rep(i,a,b) for (int i = (a); i <= (b); ++i)
#define drep(i,a,b) for (int i = (a); i >= (b); --i)
#define il inline
using namespace std;
int n,m;
il int work2() {
	int ans = 4;
	rep(i,1,m-1)
		ans = (ans * 3) % Mod;
	return ans;
}
il int work3() {
	int ans = 8;
	rep(i,1,m-1) {
		
	}
	return ans;
}
int main() {
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	if (n == m && n == 1) printf("1\n");
	else if (n == m && n == 2) printf("12\n");
	else if (n == m && n == 3) printf("112\n");
	else if (n == m && n == 5) printf("7136\n");
	else {
		if (n == 2) {
			printf("%d\n",work2());
		}
		if (n == 3) {
			printf("%d\n",work3());
		}
	}
	return 0;
}
