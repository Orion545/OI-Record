#include <iostream>
#include <cstdio>
#include <cstring>
#define maxn 1000005
#define ll long long
using namespace std;
ll dp[9][maxn];
int main (){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int n , m;
	memset(dp,0,sizeof(dp));
	dp[1][1] = 1;
	dp[2][1] = 4;
	dp[1][2] = 4;
	scanf("%d %d",&n,&m);
	for(int i=2;i<=n;i++)
	for(int j=2;j<=m;j++){
		dp[i][j] += dp[i-1][j]*dp[i][j-1];
	}
	printf("%lld",dp[n][m]);
	return 0;
}
