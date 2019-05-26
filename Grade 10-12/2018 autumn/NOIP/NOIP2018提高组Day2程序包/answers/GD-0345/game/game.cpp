#include <cstdio>
using namespace std;

int DP[10][1000010],n,m;

int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	DP[0][1] = 1;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			DP[i][j] = DP[i-1][j]+DP[i][j-1];
	printf("%d",DP[n][m]);
	
	return 0;
}
